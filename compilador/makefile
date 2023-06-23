all: saida entrada.txt
	./saida < entrada.txt

saida: lex.yy.c y.tab.c main.cc
	g++ main.cc -o saida -ll	-std=c++17
	
lex.yy.c: glc_js.lex
	lex glc_js.lex
	
y.tab.c: glc_js.y
	yacc glc_js.y
	
clean: 
	rm -f lex.yy.c y.tab.c saida