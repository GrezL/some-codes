#!/usr/bin/env python
# -*- coding:utf-8 -*-

import scrapy
from medword.items import LonicItem


class LonicSpider(scrapy.Spider):
    name = "lonic"
    allowed_domains = ['loinc.org']
