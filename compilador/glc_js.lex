%{
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <sstream>

string trim(string str, string toRemove);
vector<string> tokeniza(string str);
string removeAsm(string str);

void acerta_coluna();
%}
D	[0-9]
L	[a-zA-Z_]

STRING_DUPLA	\"(\"\"|\\\"|[^\"])*\"
STRING_SIMPLES	\'(\'\'|\\\'|[^\'])*\'

INT	{D}+
NUM	{INT}("."{INT})?([Ee]("+"|"-")?{INT})?
ID	{L}({L}|{D})*
FPSETA ")"[\n\t ]*"=>"

%%

" "		{ coluna++; }

"\t"	{ coluna += 4; }

"\n"    { linha++; coluna = 1; }

{STRING_DUPLA}|{STRING_SIMPLES} 	{ acerta_coluna(); return _STRING; }
{NUM}   	{ acerta_coluna(); return _NUM; }
-{NUM}  	{ acerta_coluna(); return _NUM; }

"let"       { acerta_coluna(); return _LET; }
"var"       { acerta_coluna(); return _VAR; }
"const"     { acerta_coluna(); return _CONST; }
"for"       { acerta_coluna(); return _FOR; }
"if"        { acerta_coluna(); return _IF; }
"else"        { acerta_coluna(); return _ELSE; }
"function"  { acerta_coluna(); return _FUNCTION; }
"return"    { acerta_coluna(); return _RETURN; }
"while"     { acerta_coluna(); return _WHILE; }
"true"     { acerta_coluna(); return _TRUE; }
"false"     { acerta_coluna(); return _FALSE; }

"++"        { acerta_coluna(); return _INC; }
"+="       { acerta_coluna(); return _MAIS_IGUAL; }
"-="       { acerta_coluna(); return _MENOS_IGUAL; }
"=>"        { acerta_coluna(); return _SETA; }
"=="        { acerta_coluna(); return _IGUAL_IGUAL; }
{FPSETA}    { acerta_coluna(); return _FPSETA; }

{ID}		{ acerta_coluna(); return _ID; }

"asm{".*"}"  { 
                coluna += strlen( yytext ); 
                yylval.c = tokeniza( trim( removeAsm(yytext), "{}" ) ) + "^";
               
                yylval.linha = linha;
                yylval.coluna = coluna;

                return ASM; }

.       	{ acerta_coluna(); return *yytext; }

%%

void acerta_coluna() {
    coluna += strlen( yytext ); 
    yylval.c.clear();
    yylval.c.push_back( yytext );
    yylval.linha = linha;
    yylval.coluna = coluna;
}

string trim(string str, string toRemove) {
    // Função lambda para verificar se um caractere está presente em toRemove
    auto isCaracterePresente = [&](char c) {
        return (toRemove.find(c) != string::npos);
    };

    // Remover caracteres presentes em toRemove da str
    str.erase(std::remove_if(str.begin(), str.end(), isCaracterePresente), str.end());

    return str;
}

vector<string> tokeniza(string str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

string removeAsm(string str) {
    return str.substr(3,str.length() -1 );
}
