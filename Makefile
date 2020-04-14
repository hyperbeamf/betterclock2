# This makefile is total shit and will be improved on
CC=clang
FILE=clock.c
OUT=betterclock2
betterclock2:
	${CC} ${FILE} -o ${OUT}
install:
	mv betterclock2 /usr/bin/
.PHONY: install options all
