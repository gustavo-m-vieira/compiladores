%{
  #include <string>
  #include <stdio.h>
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

STRING1 \"(\\.|[^\"\n]|(\"\"))*\"
STRING11 \'(\\.|[^\'\n]|(\'\'))*\'

FLOAT {DIGITO}+("."{DIGITO}+)?([eE][+-]?{DIGITO}+)?

IDSCIF ([a-zA-Z]|"_")([a-zA-Z0-9_@])*
IDCIF ("$"|("$@"{IDSCIF})){IDSCIF}*
ID {IDSCIF}|{IDCIF}

STRING {STRING1}|{STRING11}

STRING2 \`(\\.|[^\`])*/\$
EXPR \$\{({IDSCIF}|{IDCIF})/\}
STRING22 \}(\\.|[^\`])*\`
STRING222 \`(\\.|[^\`\{])*\`

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };

INVALID_ID1 ({ID}"@"+)
INVALID_ID ("@"+|("@"+{INVALID_ID1})|(\$"@"+(\$)*)|({ID}\${ID}*)|({DIGITO}{ID}+)|({DIGITO}"@"+)|("@"+[_\$]+))

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{COMENTARIO1}|{COMENTARIO2} { yylval.c = yytext; return _COMENTARIO; }

{FOR} { yylval.c = yytext; return _FOR; }
{IF} { yylval.c = yytext; return _IF; }
{WS}	{ /* ignora espaços, tabs e '\n' */ }

{INVALID_ID} { printf("Erro: Identificador inválido: %s\n", yytext); }
{ID} { yylval.c = yytext; return _ID; }
{STRING2} { std::string str(yytext); yylval.c = str.substr(1,str.length() -1 ); return _STRING2; }
{EXPR} { std::string str(yytext); yylval.c = str.substr(2,str.length() -1 ); return _EXPR; }
{STRING22} { std::string str(yytext); yylval.c = str.substr(1,str.length() -2 ); return _STRING2; }
{STRING} { std::string str(yytext); yylval.c = str.substr(1,str.length() -2 ); return _STRING; }
{STRING222} { std::string str(yytext); yylval.c = str.substr(1,str.length() -2 ); return _STRING2; }


{DIGITO}+ { yylval.c = yytext; return _INT; }
{FLOAT} { yylval.c = yytext; return _FLOAT; }
{MAIG} { yylval.c = yytext; return _MAIG; }
{MEIG} { yylval.c = yytext; return _MEIG; }
{IG} { yylval.c = yytext; return _IG; }
{DIF} { yylval.c = yytext; return _DIF; }

.       { yylval.c = yytext; return *yytext;
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

// Fim do arquivo
