#!/bin/bash

gpio -g mode 2 out

while :
do gpio -g toggle 2
sleep 0.5
done
