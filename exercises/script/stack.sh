#!/bin/bash

read -p "Enter the file path: " filepath
gcc -o e.exe "$filepath" -I./include -L./lib -lstack