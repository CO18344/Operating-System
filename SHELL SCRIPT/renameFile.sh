#!/bin/sh
a='new'
#'new' is original file name
touch $a
ls
mv $a new_name.txt
#file will be renamed to new_name.txt
ls
exit