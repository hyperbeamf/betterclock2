# This makefile is total shit and will be improved on
include config.mk
$(OUT):
	$CC --std=c99 ${FILE} -o ${OUT}
install:
	mv betterclock2 ${INSPATH}/bin
.PHONY: install options all
