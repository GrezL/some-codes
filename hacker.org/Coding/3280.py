#! /usr/bin/python env
# -*- coding=utf-8 -*-
import operator
import re

file = open("../materials/rfc3280.txt", 'r')
content = file.read()
content = re.split(' ', content)
array = []
for word in content:
    if len(word) == 9:
        array.append(word.lower())

dict = {}

for item in array:
    if item.lower() in dict:
        dict[item.lower()] += 1
    else:
        dict[item.lower()] = 0
        
sorted_dict = sorted(dict.items(), key = operator.itemgetter(1))
print sorted_dict

