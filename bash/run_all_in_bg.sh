#!/bin/bash -i
# Note the ^^^^^

# Run all these in the bg, then wake them all up:

for i in 1 2 3 4
do
	./sleep_then_print.sh &
done

RETCODE=0

while [ $RETCODE -eq 0 ]
do
	echo 'waking somone up...'
	fg &> /dev/null
	RETCODE=$?
done
echo 'woke all up'
