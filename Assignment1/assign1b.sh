#!/bin/bash
#SCRIPT: assign1b
#AUTHOR: Nathalie Ng 500921963
#DATE: October_3_2019
#shell program for assignment 1b

find /usr/courses/cps393/dwoit/courseNotes/ -name "*.h" ! -name "*t*" -group "cps393" -atime -75 -type f -ls 2>/dev/null
