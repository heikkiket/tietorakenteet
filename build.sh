#!/bin/bash

cmake -S src -B build
cmake --build build
build/postfix_calc 
