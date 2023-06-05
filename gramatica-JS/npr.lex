%{
  #include <string>
  #include <stdio.h>

  // _ID _NUM _STRING _LET _VAR _CONST _FOR _FUNCTION _IF _ELSE _RETURN _BREAK _CONTINUE _COMENTARIO _MAIG _MEIG _IG _DIF _DO _WHILE _SWITCH _CASE _DEFAULT _EXPAND _STRING2 _EXPR _PLUSPLUS
%}

WS	[ \t\n]
DIGITO [0-9]
LETRA [a-zA-Z]
FOR [Ff][Oo][Rr]
IF [Ii][Ff]
DO [Dd][Oo]
ELSE [Ee][Ll][Ss][Ee]
WHILE [Ww][Hh][Ii][Ll][Ee]
RETURN [Rr][Ee][Tt][Uu][Rr][Nn]
BREAK [Bb][Rr][Ee][Aa][Kk]
CONTINUE [Cc][Oo][Nn][Tt][Ii][Nn][Uu][Ee]
FUNCTION [Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]
CONST [Cc][Oo][Nn][Ss][Tt]
VAR [Vv][Aa][Rr]
LET [Ll][Ee][Tt]
SWITCH [Ss][Ww][Ii][Tt][Cc][Hh]
CASE [Cc][Aa][Ss][Ee]
DEFAULT [Dd][Ee][Ff][Aa][Uu][Ll][Tt]
EXPAND "..."
MAIG >=
MEIG <=
IG ==
DIF !=
PLUSPLUS "++"
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


INVALID_ID1 ({ID}"@"+)
INVALID_ID ("@"+|("@"+{INVALID_ID1})|(\$"@"+(\$)*)|({ID}\${ID}*)|({DIGITO}{ID}+)|({DIGITO}"@"+)|("@"+[_\$]+))

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{COMENTARIO1}|{COMENTARIO2} { yylval.c.clear(); yylval.c.push_back(yytext); return _COMENTARIO; }

{FOR} { yylval.c.clear(); yylval.c.push_back(yytext); return _FOR; }
{IF} { yylval.c.clear(); yylval.c.push_back(yytext); return _IF; }
{ELSE} { yylval.c.clear(); yylval.c.push_back(yytext); return _ELSE; }
{WHILE} { yylval.c.clear(); yylval.c.push_back(yytext); return _WHILE; }
{RETURN} { yylval.c.clear(); yylval.c.push_back(yytext); return _RETURN; }
{BREAK} { yylval.c.clear(); yylval.c.push_back(yytext); return _BREAK; }
{CONTINUE} { yylval.c.clear(); yylval.c.push_back(yytext); return _CONTINUE; }
{FUNCTION} { yylval.c.clear(); yylval.c.push_back(yytext); return _FUNCTION; }
{CONST} { yylval.c.clear(); yylval.c.push_back(yytext); return _CONST; }
{VAR} { yylval.c.clear(); yylval.c.push_back(yytext); return _VAR; }
{LET} { yylval.c.clear(); yylval.c.push_back(yytext); return _LET; }
{SWITCH} { yylval.c.clear(); yylval.c.push_back(yytext); return _SWITCH; }
{CASE} { yylval.c.clear(); yylval.c.push_back(yytext); return _CASE; }
{DEFAULT} { yylval.c.clear(); yylval.c.push_back(yytext); return _DEFAULT; }
{EXPAND} { yylval.c.clear(); yylval.c.push_back(yytext); return _EXPAND; }
{DO} { yylval.c.clear(); yylval.c.push_back(yytext); return _DO; }
{WS}	{ /* ignora espaços, tabs e '\n' */ }

{INVALID_ID} { printf("Erro: Identificador inválido: %s\n", yytext); }
{ID} { yylval.c.clear(); yylval.c.push_back(yytext); return _ID; }
{STRING2} { std::string str(yytext); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -1 )); return _STRING2; }
{EXPR} { std::string str(yytext); yylval.c.clear(); yylval.c.push_back(str.substr(2,str.length() -1 )); return _EXPR; }
{STRING22} { std::string str(yytext); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -2 )); return _STRING2; }
{STRING} { std::string str(yytext); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -2 )); return _STRING; }
{STRING222} { std::string str(yytext); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -2 )); return _STRING2; }


{DIGITO}+ { yylval.c.clear(); yylval.c.push_back(yytext); return _NUM; }
{FLOAT} { yylval.c.clear(); yylval.c.push_back(yytext); return _NUM; }
{MAIG} { yylval.c.clear(); yylval.c.push_back(yytext); return _MAIG; }
{MEIG} { yylval.c.clear(); yylval.c.push_back(yytext); return _MEIG; }
{IG} { yylval.c.clear(); yylval.c.push_back(yytext); return _IG; }
{DIF} { yylval.c.clear(); yylval.c.push_back(yytext); return _DIF; }

.       { yylval.c.clear(); yylval.c.push_back(yytext); return *yytext;
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

// Fim do arquivo
