#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import scrapy
import json
from medword.items import MeSHItem
from scrapy.spiders import CrawlSpider, Rule
from medword.exceptions import InvalidParameterException, NoResourceFoundException
from medword.defaults import *


class MeshSpider(CrawlSpider):
    name = 'mesh'
    allowed_domains = ['meshb.nlm.nih.gov']

    def __init__(self, query=None, *args, **kwargs):
        super(MeshSpider, self).__init__(*args, **kwargs)
        self.query_array = []
        self.start_urls = self.mkurls(query, *args, **kwargs)

    def mkurls(self, query, *args, **kwargs):
        urls = list()
        base_search_url = '/'.join([BASE_MESH_API_URL, 'api', 'search', 'record?'])
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

        self.searchInField = kwargs.get('searchInField') if kwargs.get('searchInField') else str(DEFAULT_MS_SF)
        self.sort = kwargs.get('sort') if kwargs.get('sort') else str(DEFAULT_MS_SORT)
        self.size = kwargs.get('size') if kwargs.get('size') else str(DEFAULT_MS_SIZE)
        self.searchType = kwargs.get('searchType') if kwargs.get('searchType') else str(DEFAULT_MS_STYPE)
        self.searchMethod = kwargs.get('searchMethod') if kwargs.get('searchMethod') else str(DEFAULT_MS_SMETHOD)

        for query_object in self.query_array:
            tmp_url = '&'.join([base_search_url +
                                "searchInField=" + self.searchInField,
                                "sort=" + self.sort,
                                "size=" + self.size,
                                "searchType=" + self.searchType,
                                "searchMethod=" + self.searchMethod,
                                "q=" + query_object.get('query')])
            urls.append(tmp_url)
        return urls

    def parse(self, response):
        results = json.loads(response.text)
        if results.get('hits').get('total') <= 0:
            raise NoResourceFoundException()
        else:
            for item in results.get('hits').get('hits'):
                mesh_item = MeSHItem()
                mesh_item['head'] = str(item['_source']['_generated']['RecordName'])
                mesh_item['term_id'] = str(item['_source']['_generated']['RecordUI'])
                mesh_item['link'] = BASE_MESH_CONCEPT_URL + str(item['_source']['_generated']['RecordUI'])
                mesh_item['mesh_trees'] = []
                for tree in item['_source']['TreeNumberList']['TreeNumber']:
                    mesh_item['mesh_trees'].append(str(tree.get('t')))
                mesh_item['annotation'] = str(item['_source']['Annotation']['t'])
                mesh_item['concepts'] = []
                for concept in item['_source']['ConceptList']['Concept']:
                    mesh_item['concepts'].append(concept)
                yield mesh_item
