CC = gcc

DIR = ../bin/

PROG = c--

end:
	mkdir bin
	cd src;bison -d parser.y
	cd src;flex lexer.l
	cd src;$(CC) parser.tab.c lex.yy.c vector.c -o $(DIR)$(PROG)

clean:
	rm -f src/parser.tab.c
	rm -f src/parser.tab.y
	rm -f src/lex.yy.c
	rm -rf ./bin
