#!/usr/bin/env python
# -*- coding:utf-8 -*-

class MedWordBaseExecption(Exception):

    def __init__(self, message):
        self.message = message

    def __str__(self):
        error_message = self.message
        return error_message

class InvalidParameterException(MedWordBaseExecption):
    pass
    
class NoResourceFoundException(MedWordBaseExecption):
    pass
