 %{
// Includes em C/C++ e outras definições.
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Atributos {
  vector<string> c;
  int linha;
  int coluna;
};

vector<string> codigo;

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );

// int linha = 1;
// int coluna = 1;

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

void erro( string msg );
void imprime_codigo( vector<string> codigo );

// protótipo para o analisador léxico (gerado pelo lex)
extern int yylex(void);
// int yylex();
void yyerror( const char* );

%}

// Tokens
%token	 _ID _NUM _STRING _LET _VAR _CONST _FOR _FUNCTION _IF _ELSE _RETURN _BREAK _CONTINUE _COMENTARIO _MAIG _MEIG _IG _DIF _DO _WHILE _SWITCH _CASE _DEFAULT _EXPAND _STRING2 _EXPR

%start  S

%left ','
%right '=' 
%nonassoc '<' '>' 
%left '+' '-'
%left '*' '/' '%'
%left '[' '('

%%

S : CMDs  {/* imprime_codigo( resolve_enderecos( $1.c + "." ) ); cout << endl;*/}
  ;

CMDs : CMD CMDs             { $$.c = $1.c + $2.c; }
     | DECL_VAR ';' CMDs    { $$.c = $1.c + $3.c; }
     | DECL_FUN CMDs        { $$.c = $1.c + $2.c; }  
     | ATRIB ';' CMDs       { $$.c = $1.c + $3.c; } 
     |                      { $$.c.clear(); }
     ;
     
CMD : CMD_FOR
    | CMD_IF
    | CMD_WHILE
    | CMD_DO_WHILE
    | CMD_SWITCH_CASE
    | E_V ';'
    | '{' CMDs '}'      { $$ = $2; }
    | ';'               { $$.c.clear(); }
    ;

CMD_SWITCH_CASE : _SWITCH '(' E ')' '{' CASEs '}' 
                | _SWITCH '(' E ')' '{' CASEs _DEFAULT '}' 
                ;

CASEs : CASE CASEs
      | CASE
      ;

CASE : _CASE E ':' CMDs
    | _CASE E ':' CMDs _BREAK CMDs ';'
    ;

CMD_WHILE : _WHILE '(' E ')' CMD
          | _WHILE '(' E ')' '{' CMDs _BREAK CMDs '}' ';'
          ;

CMD_DO_WHILE : _DO CMD _WHILE '(' E ')' ';';
    
CMD_IF : _IF '(' E ')' CMD _ELSE CMD
         {  string lbl_fim = gera_label( "fim_if" ), 
                   lbl_true = gera_label( "then" ), 
                   lbl_false = gera_label( "else" );
                   
            $$.c = $3.c + lbl_true + "?" + lbl_false + "#" + 
                   (":" + lbl_true) + $5.c + lbl_fim + "#" +
                   (":" + lbl_false) + $7.c + 
                   (":" + lbl_fim);
         }
       ;
    
CMD_FOR : _FOR '(' E_OPC ';' E_OPC ';' E_OPC ')' CMD     
        | _FOR '(' DECL_VAR ';' E_OPC ';' E_OPC ')' CMD     
        ;
        
E_OPC : E_V
      |
      ;
  
DECL_VAR : _LET VARs    { $$ = $2; }  
         | _VAR VARs    { $$ = $2; }
         | _CONST CTEs  { $$ = $2; } 
         ;
         
DECL_FUN : _FUNCTION _ID '(' ')' '{' CMDs '}' 
         | _FUNCTION _ID '(' PARAMs ')' '{' CMDs '}'
         | _FUNCTION _ID '(' ')' '{' CMDs _RETURN CMDs '}'
         | _FUNCTION _ID '(' PARAMs ')' '{' CMDs _RETURN CMDs '}'
         ;
         
PARAMs : PARAM ','PARAMs
       | PARAM
       ;
       
PARAM : _ID '=' E
      | _ID
      | _ID '=' '{' DECL_OBJ '}'
      ;

    
VARs : VAR ',' VARs     { $$.c = $1.c + $3.c; }
     | VAR
     ;

DECL_OBJ : DECL_OBJ_I ',' DECL_OBJ    { $$.c = $1.c + $3.c; }
         | DECL_OBJ_I
         |
         ;

DECL_OBJ_I : _ID ':' E
        | _ID ':' '{' DECL_OBJ '}'
        | _ID
        ;

LIST : LIST_I ',' LIST    { $$.c = $1.c + $3.c; }
     | LIST_I
     ;

LIST_I : E
       | '{' DECL_OBJ '}'
       | '[' LIST ']'
       |
       ;
                    
VAR : _ID '=' E     { $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^"; }
    | _ID           { $$.c = $1.c + "&"; }
    | _ID '=' '{' DECL_OBJ '}'
    | _ID '=' '[' LIST ']'
    ;
    
CTEs : _ID '=' E ',' CTEs
     | _ID '=' E
     | _ID '=' '{' DECL_OBJ '}' ',' CTEs
     | _ID '=' '{' DECL_OBJ '}'
     | _ID '=' '[' E ']' ',' CTEs
     | _ID '=' '[' E ']'
     | '{' DECL_OBJ '}' '=' E
     
     ;
  
E_V : E_V ',' E_V
    | IDs '=' E
    | E
    ;
  
IDs : _ID '.' IDs
    | _ID
    ;
  
ATRIB : ATRIBUTO '=' E   { $$.c = $1.c + $3.c + "=" + "^"; }
      | E
      | '{' DECL_OBJ '}'
      | '[' LIST ']'
      ;

ATRIBUTO : ATRIBUTO '[' E ']'
    | _ID '[' E ']'
    | ATRIBUTO '.' Gs
    | _ID
    ;


E : E '<' E         { $$.c = $1.c + $3.c + "<"; }
  | E '*' E         { $$.c = $1.c + $3.c + "*"; }
  | E '+' E         { $$.c = $1.c + $3.c + "+"; }
  | E '-' E         { $$.c = $1.c + $3.c + "-"; }
  | E '/' E         { $$.c = $1.c + $3.c + "/"; }
  | E '>' E         { $$.c = $1.c + $3.c + ">"; }
  | E '%' E         { $$.c = $1.c + $3.c + "%"; }
  | E '[' E ']'
  | E '(' ')'
  | E '(' ARGs ')'
  | E '+''+'
  | E '.' Gs
  | F
  ;

Gs : G '.' Gs
  | G
  ;

G : _ID
  | _STRING
  ;

F : _ID     { $$.c = $1.c + "@"; }
  | _NUM
  | _STRING
  | '(' E_V ')' { $$ = $2; }   
  | '{' DECL_OBJ '}'
  ;


ARGs : ATRIB ',' ARGs
     | ATRIB
     ;
  
%%

#include "lex.yy.c"

vector<string> concatena ( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

void yyerror( const char* msg ) {
  cout << endl << "Erro: " << msg << endl
       << "Perto de : '" << yylval.c[0] << "'" << endl
       << "Linha: " << yylval.linha << ", coluna: " << yylval.coluna << endl;
  
  exit(1);
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string, int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void imprime_codigo( vector<string> codigo ) {
    for( int i = 0; i < codigo.size(); i++ )
        cout << codigo[i] << " ";
}
