#! /usr/bin/python env
# -*- coding=utf-8 -*-

def calc(depth):
    cc = calc(depth - 1)
    if (depth == 0):
        return 1;
    else:
        return cc + (depth % 7) + ((((cc ^ depth) % 4) == 0) ? 1 : 0)

print calc(11589)
