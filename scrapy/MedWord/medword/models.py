#!/usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import create_engine
from sqlalchemy import Column, String, Integer, Boolean, DateTime, BigInteger
from sqlalchemy import JSON
from settings import DATABASE
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base
from datetime import datetime

import settings

Base = declarative_base()

class Snomed(Base):
    """
    Snomed table
    """
    __tablename__ = 'snomed'

    head = Column('head', String(512))
    term_id = Column('term_id', Integer, primary_key=True)
    link = Column('link', String(512), nullable=True)
    active = Column('active', Boolean, nullable=True)
    conceptActive = Column('concept_active', Boolean, nullable=True)
    fsn = Column('fsn', String(512), nullable=True)
    module = Column('module', BigInteger, nullable=True)
    definitionStatus = Column('definition_status', String(512), nullable=True)


class Mesh(Base):
    __tablename__ = 'mesh'

    head = Column('head', String(512))
    term_id = Column('term_id', String(512), primary_key=True)
    link = Column('link', String(512), nullable=True)
    mesh_trees = Column('mesh_trees', JSON, nullable=True)
    annotation = Column('annotation', String(512), nullable=True)
    concepts = Column('concepts', JSON, nullable=True)


def create_session():
    engine = create_engine(DATABASE['mysql_uri'].format(username=DATABASE['username'],
                                                        host=DATABASE['host'],
                                                        port=DATABASE['port'],
                                                        database=DATABASE['database']),
                                                        echo=False)
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    return session


def map_orm_item(scrapy_item, sql_item):
    for k, v in scrapy_item.iteritems():
        sql_item.__setattr__(k, v)
    return sql_item
