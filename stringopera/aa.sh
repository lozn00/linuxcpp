#!/bin/bash
echo start
printf "%s\n aa bb cc" 
echo \nend \n
DIRECTORY=`pwd`


echo $DIRECTORY
echo aaa
if [ $(ps -ef | grep -c "ssh") -gt 1 ]; then echo "true"; fi
if [ $(ps -ef | grep -c "ssh") -gt 1 ];then echo "not read";fi


for file in `ls  /etc`; do
	echo $file
done

