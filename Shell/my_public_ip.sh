#!/bin/bash

curl -s 'https://api.ipify.org?format=json' | cut -d'"' -f4
