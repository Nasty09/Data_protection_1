#!/bin/bash

g++ main.cpp -s -O3 -o main
strip -s main
