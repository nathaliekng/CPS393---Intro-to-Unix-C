#!/bin/bash
#SCRIPT: assign1a
#AUTHOR: Nathalie Ng 500921963
#DATE: October_3_2019
#shell program for assignment 1a

clear
date=`last | grep "wtmp begins" | cut -c 13- | cut -c -10 | tr -s "  " " "`
address=`(hostname -i)`
listName=`last | grep "pts" | cut -c -9 | sort | uniq | tr -s "\n" " " | tr -s " " "," | sed 's/.$//'`
OS=`hostnamectl | grep "Operating System" | tr -s ":" " " | cut -c 2-`
myLog=`last | grep $LOGNAME | wc -l`
users=`last | grep "pts" | cut -c -9 | sort | uniq | wc -l`
echo "-------------------------------------------------------------------------------"
echo "This machine is $HOSTNAME."
echo "$users users have logged into $HOSTNAME since $date; they are:"
echo "$listName."
echo "${HOSTNAME^} is at IP Address $address and is running $OS."
echo "You are $LOGNAME, and you have logged in $myLog times since $date."
echo "-------------------------------------------------------------------------------"


