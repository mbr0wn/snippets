#!/bin/bash -i
# Note the ^^^^^

# Run all these in the bg, then wake them all up:
./sleep_then_print.sh &
./sleep_then_print.sh &
./sleep_then_print.sh &
./sleep_then_print.sh &

RETCODE=0

while [ $RETCODE -eq 0 ]
do
	echo 'waking somone up...'
	fg &> /dev/null
	RETCODE=$?
done
echo 'woke all up'
