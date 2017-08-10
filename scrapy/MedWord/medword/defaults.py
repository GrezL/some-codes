# -*- coding:utf-8 -*-


BASE_SNOMED_API_URL = 'http://browser.ihtsdotools.org/api/snomed'
DEFAULT_SNOMED_VERSION = "v20170131"
DEFAULT_SNOMED_EDITION = "en-edition"

# Snomed search parameters
DEFAULT_SM_LIMIT = 50
DEFAULT_SM_MODE = "partialMatching"
DEFAULT_SM_LANG = "english"
DEFAULT_SM_FILT = "activeOnly"
DEFAULT_SM_SKPT = 0
DEFAULT_SM_RLIMIT = 100
DEFAULT_SM_NOR = True


BASE_MESH_API_URL = 'https://meshb.nlm.nih.gov'
BASE_MESH_CONCEPT_URL = 'https://meshb.nlm.nih.gov/api/record/ui/'


DEFAULT_MS_SF = 'termDescriptor'
DEFAULT_MS_SORT = ''
DEFAULT_MS_SIZE = 100
DEFAULT_MS_STYPE = 'exactMatch'
DEFAULT_MS_SMETHOD = 'FullWord'
