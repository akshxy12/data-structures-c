#! /bin/bash

cmake .. -G "Unix Makefiles"
cmake --build .
printf "=====BUILD COMPLETE=====\n"