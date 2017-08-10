#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import scrapy
import json
from medword.items import SnomedItem
from scrapy.spiders import CrawlSpider, Rule
from medword.exceptions import InvalidParameterException, NoResourceFoundException
from medword.defaults import *


class SnomedSpider(CrawlSpider):
    name = 'snomed'
    allowed_domains = ['ihtsdotools.org']

    def __init__(self, query=None, *args, **kwargs):
        super(SnomedSpider, self).__init__(*args, **kwargs)
        self.query_array = []
        self.start_urls = self.mkurls(query, *args, **kwargs)

    def mkurls(self, query, *args, **kwargs):
        urls = list()
        base_search_url = '/'.join([BASE_SNOMED_API_URL, DEFAULT_SNOMED_EDITION, 
                                    DEFAULT_SNOMED_VERSION, "descriptions?"])
        self.logger.info("--------query is : {}-------type for query is: {}".format(query, type(query)))
        if isinstance(query, list):
            # check array elements valid
            for item in query:
                if not "query" in item:
                    raise InvalidParameterException("Found no query")
                else:
                    self.query_array.append(item)
        elif isinstance(query, dict):
            # check array elements valid
            if not "query" in query:
                raise InvalidParameterException("Found no query")
            else:
                self.query_array.append(query)
        elif isinstance(query, str):
            self.query_array.append({"query": query})

        self.limit = kwargs.get('limit') if kwargs.get('limit') else str(DEFAULT_SM_LIMIT)
        self.searchMode = kwargs.get('searchMode') if kwargs.get('searchMode') else DEFAULT_SM_MODE
        self.lang = kwargs.get('lang') if kwargs.get('lang') else DEFAULT_SM_LANG
        self.statusFilter = kwargs.get('statusFilter') if kwargs.get('statusFilter') else DEFAULT_SM_FILT
        self.skipTo = kwargs.get('skipTo') if kwargs.get('skipTo') else str(DEFAULT_SM_SKPT)
        self.returnLimit = kwargs.get('returnLimit') if kwargs.get('returnLimit') else str(DEFAULT_SM_RLIMIT)
        self.normallize = kwargs.get('normallize') if kwargs.get('normallize') else str(DEFAULT_SM_NOR).lower()

        for query_object in self.query_array:
            tmp_url = '&'.join([base_search_url + 'query=' + query_object.get('query'),
                                "limit=" + self.limit,
                                "searchMode=" + self.searchMode,
                                "lang=" + self.lang,
                                "statusFilter=" + self.statusFilter, 
                                "skipTo=" + self.skipTo, 
                                "returnLimit=" + self.returnLimit, 
                                "normalize=" + self.normallize])
            if "category" in query_object and query_object.get('category') != '':
                self.semanticTag = query_object.get('category')
                urls.append(tmp_url + '&semanticFilter=' + self.semanticTag)
            else:
                urls.append(tmp_url)
        return urls


    def parse(self, response):     
        results = json.loads(response.text)
        if len(results.get('matches')) == 0:
            raise NoResourceFoundException()
        else:
            for item in results.get('matches'):
                snomed_item = SnomedItem()
                snomed_item['head'] = str(item['term'])
                snomed_item['term_id'] = int(item['conceptId'])
                snomed_item['link'] = 'http://browser.ihtsdotools.org/api/snomed/en-edition/v20170131/concepts/{}/'.format(str(item['conceptId']))
                snomed_item['active'] = item['active']
                snomed_item['concept_active'] = item['conceptActive']
                snomed_item['fsn'] = str(item['fsn'])
                snomed_item['module'] = int(item['module'])
                snomed_item['definition_status'] = str(item['definitionStatus'])
                yield snomed_item
