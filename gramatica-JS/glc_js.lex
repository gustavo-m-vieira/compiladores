%{
  #include <string>
  #include <stdio.h>

  // _ID _NUM _STRING _LET _VAR _CONST _FOR _FUNCTION _IF _ELSE _RETURN _BREAK _CONTINUE _COMENTARIO _MAIG _MEIG _IG _DIF _DO _WHILE _SWITCH _CASE _DEFAULT _EXPAND _STRING2 _EXPR

  int linha = 1;
  int coluna = 1;

  void fillToken() {
    std::string str(yytext);
    coluna += str.length();
    yylval.c.clear();
    yylval.c.push_back(yytext);
    yylval.linha = linha;
    yylval.coluna = coluna;
  }

%}

WS	[ ]
LINE_BREAK [\n]
TAB [\t]
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

{COMENTARIO1}|{COMENTARIO2} { fillToken(); return _COMENTARIO; }

{FOR} { fillToken(); return _FOR; }
{IF} { fillToken(); return _IF; }
{ELSE} { fillToken(); return _ELSE; }
{WHILE} { fillToken(); return _WHILE; }
{RETURN} { fillToken(); return _RETURN; }
{BREAK} { fillToken(); return _BREAK; }
{CONTINUE} { fillToken(); return _CONTINUE; }
{FUNCTION} { fillToken(); return _FUNCTION; }
{CONST} { fillToken(); return _CONST; }
{VAR} { fillToken(); return _VAR; }
{LET} { fillToken(); return _LET; }
{SWITCH} { fillToken(); return _SWITCH; }
{CASE} { fillToken(); return _CASE; }
{DEFAULT} { fillToken(); return _DEFAULT; }
{EXPAND} { fillToken(); return _EXPAND; }
{DO} { fillToken(); return _DO; }
{LINE_BREAK} { linha++; coluna = 1; }
{WS} { coluna ++; }
{TAB} { coluna += 2; }

{INVALID_ID} { printf("Erro: Identificador inválido: %s\n", yytext); }
{ID} { fillToken(); return _ID; }
{STRING2} { std::string str(yytext); linha += str.length(); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -1 )); yylval.linha = linha; yylval.coluna = coluna;return _STRING2; }
{EXPR} { std::string str(yytext); linha += str.length(); yylval.c.clear(); yylval.c.push_back(str.substr(2,str.length() -1 )); yylval.linha = linha; yylval.coluna = coluna;return _EXPR; }
{STRING22} { std::string str(yytext);linha += str.length();  yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -2 ));yylval.linha = linha; yylval.coluna = coluna; return _STRING2; }
{STRING} { std::string str(yytext); linha += str.length(); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -2 ));yylval.linha = linha; yylval.coluna = coluna; return _STRING; }
{STRING222} { std::string str(yytext); linha += str.length(); yylval.c.clear(); yylval.c.push_back(str.substr(1,str.length() -2 ));yylval.linha = linha; yylval.coluna = coluna; return _STRING2; }


{DIGITO}+ { fillToken(); return _NUM; }
{FLOAT} { fillToken(); return _NUM; }
{MAIG} { fillToken(); return _MAIG; }
{MEIG} { fillToken(); return _MEIG; }
{IG} { fillToken(); return _IG; }
{DIF} { fillToken(); return _DIF; }

.       { fillToken(); return *yytext;
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

// Fim do arquivo
