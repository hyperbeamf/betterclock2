# This makefile is total shit and will be improved on
all: options betterclock2

betterclock2:
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

options:
	@echo betterclock2 build options
	@echo "CFLAGS	= ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC 	= ${CC}"

install:
	@echo "Installing betterclock to /usr/bin/"
	mv betterclock2 /usr/bin/

.PHONY: install options all
