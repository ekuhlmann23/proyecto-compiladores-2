all:
	flex --header-file=lex.yy.h lex.l
	yacc -d yacc.y
.PHONY:
clean:
	rm -f *.c *.h