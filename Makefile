.PHONY: clean all test

all: tool suppleLang.o 

suppleLang.o: suppleLang.c suppleLangLex.c suppleLangGram.c suppleLang.h \
Makefile
	gcc -Os -c -o suppleLang.o suppleLang.c -Wall -Wextra
	size suppleLang.o

suppleLangTest: suppleLangTest.c suppleLang.o
	gcc -Os suppleLangTest.c -o suppleLangTest -Wall -Wextra

suppleLangLex.c: suppleLangLex.re
	re2c -W -i suppleLangLex.re -o suppleLangLex.c

suppleLangGram.c: tool/lemon suppleLangGram.y
	./tool/lemon suppleLangGram.y -s -l -p -q

tool/lemon: tool/lemon.c tool/lempar.c
	gcc -Os tool/lemon.c -o tool/lemon

tool/lemon.c:
	curl https://raw.githubusercontent.com/sqlite/sqlite/master/tool/lemon.c \
	> tool/lemon.c

tool/lempar.c:
	curl https://raw.githubusercontent.com/sqlite/sqlite/master/tool/lempar.c \
	> tool/lempar.c

test: suppleLangTest
	./suppleLangTest

tool:
	mkdir tool
