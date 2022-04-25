#!/bin/bash

FLAGS="-Wall -Werror -Wextra -g"
FILES="btest.c"
INCLUDE="-I ../include -I ../vector"
LIB="-L .. -l ftprintf"

(cd .. && make)
gcc $FLAGS $FILES $INCLUDE $LIB -D EXPECTED -o expected
./expected > expected.txt
gcc $FLAGS $FILES $INCLUDE $LIB -o test
./test > got.txt
diff -u -U6 expected.txt got.txt > result.diff
diff -u expected.txt got.txt | grep '^-[^-]' > wrong.diff
if [ -s result.diff ]; then
	echo "ERROR:"
	wc -l < result.diff
	echo "check result.diff"
else
	echo "OK"
	#rm expected.txt
	#rm got.txt
	#rm result.diff
fi

rm -f expected
#rm -f test
