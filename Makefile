# This makefile is total shit and will be improved on

betterclock2:
	gcc clock.c -o betterclock2

install:
	mv betterclock2 /usr/bin/

.PHONY: install
