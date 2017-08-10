#!/usr/bin/env python
# -*- coding:utf-8 -*-

from scrapyd_api import ScrapydAPI

class ScrapyManager(ScrapydAPI):
    def __init__(self, domain='http://localhost:6800', *args, **kwargs):
        super(ScrapyManager, self).__init__(domain, *args, **kwargs)
