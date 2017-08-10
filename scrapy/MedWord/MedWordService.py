#!/usr/bin/env python
# -*- coding:utf-8 -*-

from __future__ import absolute_import, print_function
import traceback
import sys
import json
import time
from flask import Flask, request, Response, stream_with_context
from globals import SERVICE_NAME, SCRAPY_PROJECT_NAME
from ScrapyManager import ScrapyManager

default_encoding = "utf-8"
if sys.getdefaultencoding() != default_encoding:
    reload(sys)
    sys.setdefaultencoding(default_encoding)

app = Flask(SERVICE_NAME)
sm = ScrapyManager()

@app.route('/')
def index():
    return 'MedWord'


@app.route('/scrapy/schedule/', methods=['POST'])
def schedule():
    def generate(iterable_object):
        for item in iterable_object:
            yield item + '\n'

    data = json.loads(request.data)
    querys = data['querys']
    spiders = data['spiders']
    results = []
    try:
        for spider in spiders:
            result = sm.schedule(SCRAPY_PROJECT_NAME, spider, query=querys)
            results.append(result)
    except:
        raise
    finally:
        return Response(stream_with_context(generate(results)))


@app.route('/scrapy/jobs/', methods=['GET'])
def list_jobs():
    try:
        result = sm.list_jobs(SCRAPY_PROJECT_NAME)
    except:
        raise
    return json.dumps(result)


@app.route('/scrapy/jobs/<job_id>/', methods=['GET'])
def job_status(job_id):
    try:
        result = sm.job_status(SCRAPY_PROJECT_NAME, job_id)
    except:
        raise
    return json.dumps(result)


@app.route('/scrapy/spiders/', methods=['GET'])
def list_spiders():
    try:
        result = sm.list_spiders(SCRAPY_PROJECT_NAME)
    except:
        raise
    return json.dumps(result)


@app.route('/scrapy/jobs/<job_id>/', methods=['PUT'])
def cancel(job_id):
    try:
        result = sm.cancel(SCRAPY_PROJECT_NAME, job_id)
    except:
        raise
    return json.dumps(result)


if __name__ == '__main__':
    logger.info("MedWord service start")
    app.run(host='0.0.0.0', threaded=True, debug=True, port=8089)
