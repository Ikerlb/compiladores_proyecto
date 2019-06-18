CC = gcc

PROG = c--

end:
	bison -d parser.y
	flex lexer.l
	$(CC) parser.tab.c lex.yy.c vector.c -o $(PROG)
