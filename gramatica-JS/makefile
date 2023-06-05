all: saida entrada.txt
	./saida < entrada.txt

saida: lex.yy.c y.tab.c main.cc
	g++ main.cc -o saida -ll	-std=c++17
	
lex.yy.c: npr.lex
	lex npr.lex
	
y.tab.c: npr.y
	yacc npr.y
	
clean: 
	rm -f lex.yy.c y.tab.c saida