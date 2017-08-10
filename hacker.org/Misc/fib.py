#!/usr/bin/python env
# -*- coding = utf-8 -*-

def f(n):
    if n > 1:
        return f(n-1) + f(n-2)
    else:
        return 1

sum = 0
for i in range(9,17):
    sum += f(i)

print sum
