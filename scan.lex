%{
  #include <stdio.h>

  string lexema;
%}

WS	[ \t\n]
DIGITO [0-9]
LETRA [a-zA-Z]
FOR [Ff][Oo][Rr]
IF [Ii][Ff]
MAIG >=
MEIG <=
IG ==
DIF !=
COMENTARIO1 "//".*[^\n]
COMENTARIO2 "/*"([^*]|[*][^/])*[*]?"/"

STRING1 \"(\\.|[^\"\n])*\"
STRING2 \'(\\.|[^\'\n])*\'

FLOAT {DIGITO}+("."{DIGITO}+)?([eE][+-]?{DIGITO}+)?

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, EXPR };


%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{COMENTARIO1}|{COMENTARIO2} { lexema = yytext; return _COMENTARIO; }
{STRING1}|{STRING2} { lexema = yytext; return _STRING; }
{WS}	{ /* ignora espaços, tabs e '\n' */ } 



{DIGITO}+ { lexema = yytext; return _INT; }
{FLOAT} { lexema = yytext; return _FLOAT; }
{FOR} { lexema = yytext; return _FOR; }
{IF} { lexema = yytext; return _IF; }
{MAIG} { lexema = yytext; return _MAIG; }
{MEIG} { lexema = yytext; return _MEIG; }
{IG} { lexema = yytext; return _IG; }
{DIF} { lexema = yytext; return _DIF; }


.       { lexema = yytext; return *yytext; 
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

// Fim do arquivo
