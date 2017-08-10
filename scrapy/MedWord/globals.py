#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import sys
import logging
from scrapy.utils.log import configure_logging

configure_logging(install_root_handler=False)
logging.basicConfig(
        filename = "logs/medword_api.log",
        format='%(levelname)s: %(message)s',
        level=logging.INFO
        )


default_encoding = 'utf-8'
if sys.getdefaultencoding() != default_encoding:
    reload(sys)
    sys.setdefaultencoding(default_encoding)

SERVICE_NAME = "MedWordService"
SCRAPY_PROJECT_NAME = "medword"
