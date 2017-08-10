# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class MedwordItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    pass

class LonicItem(scrapy.Item):
    head = scrapy.Field()
    link = scrapy.Field()
    term_id = scrapy.Field()

class SnomedItem(scrapy.Item):
    head = scrapy.Field()
    link = scrapy.Field()
    term_id = scrapy.Field()
    active = scrapy.Field()
    concept_active = scrapy.Field()
    fsn = scrapy.Field()
    module = scrapy.Field()
    definition_status = scrapy.Field()

class MeSHItem(scrapy.Item):
    head = scrapy.Field()
    link = scrapy.Field()
    term_id = scrapy.Field()
    mesh_trees = scrapy.Field()
    annotation = scrapy.Field()
    concepts = scrapy.Field()
