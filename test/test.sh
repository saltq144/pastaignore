#!/bin/sh

cd ..

if [ -e pastaignore ]
then
	rm pastaignore
fi

make pastaignore
cd test
# TESTS

../pastaignore -i ./i/1.pastaignore -o ./o/1 -vb > ./c/1

if cmp --silent ./e/o/1 ./o/1; then
	echo "\033[42;30mPASS 1.o\033[0m"
else
	echo "\033[41;30mFAIL 1.o\033[0m"
fi
if cmp --silent ./e/c/1 ./c/1; then
	echo "\033[42;30mPASS 1.c\033[0m"
else
	echo "\033[41;30mFAIL 1.c\033[0m"
fi

../pastaignore -i i/2.pastaignore -o ./o/2 > ./c/2

if cmp --silent ./e/o/2 ./o/2; then
	echo "\033[42;30mPASS 2.o\033[0m"
else
	echo "\033[41;30mFAIL 2.o\033[0m"
fi

if cmp --silent ./e/c/2 ./c/2; then
        echo "\033[42;30mPASS 2.c\033[0m"
else
        echo "\033[41;30mFAIL 2.c\033[0m"
fi

