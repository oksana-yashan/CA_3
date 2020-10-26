 
all: build help

build:
	g++ ./parser.cpp -o parser

help:
	@echo""
	./parser -hl

example:
	@echo ""
	./parser -I5 --int=7 -D10.2
