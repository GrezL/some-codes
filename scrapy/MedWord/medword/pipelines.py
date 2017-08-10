# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html

import models

class SnomedPipeline(object):
    def __init__(self):
        self.session = models.create_session()

    def process_item(self, item, spider):
        sql_snomed = models.Snomed()
        sql_snomed = models.map_orm_item(scrapy_item=item, sql_item=sql_snomed)
        try:
            self.session.merge(sql_snomed)
            self.session.commit()
            self.session.close()
        except:
            raise
        finally:
            return item


class MeshPipeline(object):
    def __init__(self):
        self.session = models.create_session()

    def process_item(self, item, spider):
        sql_mesh = models.Mesh()
        sql_mesh = models.map_orm_item(scrapy_item=item, sql_item=sql_mesh)
        try:
            self.session.merge(sql_mesh)
            self.session.commit()
            self.session.close()
        except:
            raise
        finally:
            return item


