#! /usr/bin/python env
# -*- coding=utf-8 -*-

import os
import re

file = open("../materials/lorem.txt", 'r')
content = file.read()
array = re.split(' |\.|\;|\,',content)
for item in array:
    count = re.findall(item, content)
    if len(count) == 1:
        print item
