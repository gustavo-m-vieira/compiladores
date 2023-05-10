%{
  #include <string>
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

STRING1 \"(\\.|[^\"\n]|(\"\"))*\"
STRING11 \'(\\.|[^\'\n]|(\'\'))*\'

FLOAT {DIGITO}+("."{DIGITO}+)?([eE][+-]?{DIGITO}+)?

IDSCIF ([a-zA-Z]|"_")([a-zA-Z0-9_@])*
IDCIF ("$"|("$@"{IDSCIF})){IDSCIF}*

STRING {STRING1}|{STRING11}

STRING2 \`(\\.|[^\`])*/\$
EXPR \$\{({IDSCIF}|{IDCIF})/\}
STRING22 \}(\\.|[^\`])*\`
STRING222 \`(\\.|[^\`\{])*\`

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };

INVALID_ID \$

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{COMENTARIO1}|{COMENTARIO2} { lexema = yytext; return _COMENTARIO; }

{FOR} { lexema = yytext; return _FOR; }
{IF} { lexema = yytext; return _IF; }
{WS}	{ /* ignora espaços, tabs e '\n' */ }

{IDSCIF}|{IDCIF} { lexema = yytext; return _ID; }
{STRING2} { std::string str(yytext); lexema = str.substr(1,str.length() -1 ); return _STRING2; }
{EXPR} { std::string str(yytext); lexema = str.substr(2,str.length() -1 ); return _EXPR; }
{STRING22} { std::string str(yytext); lexema = str.substr(1,str.length() -2 ); return _STRING2; }
{STRING} { std::string str(yytext); lexema = str.substr(1,str.length() -2 ); return _STRING; }
{STRING222} { std::string str(yytext); lexema = str.substr(1,str.length() -2 ); return _STRING2; }

{DIGITO}+ { lexema = yytext; return _INT; }
{FLOAT} { lexema = yytext; return _FLOAT; }
{MAIG} { lexema = yytext; return _MAIG; }
{MEIG} { lexema = yytext; return _MEIG; }
{IG} { lexema = yytext; return _IG; }
{DIF} { lexema = yytext; return _DIF; }

.       { lexema = yytext; return *yytext;
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

// Fim do arquivo
