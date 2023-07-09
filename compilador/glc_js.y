%{
// Includes em C/C++ e outras definições.
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
vector<string> c;
int linha, coluna;
int contador; // contador de variáveis temporárias
};

struct Simbolo {
int linha, coluna; 
string tipo_decl; // "let", "const" e "var"
};

    // Pilha de Tabela de símbolos
vector< map< string, Simbolo > > ts = { { } };
vector<string> funcoes;

// Tenta declarar uma variável "let", "var" ou "const"
void tenta_declarar_let( string nome, int linha, int coluna );
void tenta_declarar_const( string nome, int linha, int coluna );

// Verifica se a variável já foi declarada como "var" anteriormente
bool ja_declarou_var( string nome, int linha, int coluna );
void checa_ja_declarou(string nome, int linha, int coluna);

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );
string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );
bool includesChar(const std::string& str, char ch);
vector<string> handle_neg(vector<string> c);
Simbolo get_nome(string nome);
bool find_nome(string nome);

int linha = 1;
int coluna = 1;

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

void erro( string msg );
void imprime_codigo( vector<string> codigo );

// protótipo para o analisador léxico (gerado pelo lex)
extern "C" int yylex();
void yyerror( const char* );

%}

// Tokens
%token	 _ID _NUM _STRING _LET _VAR _CONST _FOR _FUNCTION _IF _ELSE _INC _RETURN _SETA _FPSETA _MAIS_IGUAL _IGUAL_IGUAL _MENOS_IGUAL _WHILE ASM _TRUE _FALSE _AND _OR _NOT _EQ _NEQ _LT _GT _LEQ _GEQ _MOD _DIV _MULT _PLUS _MINUS _LPAREN _RPAREN _LBRACK _RBRACK _LBRACE _RBRACE _COMMA _SEMICOLON _DOT _COLON _EOF

%start  S

%left ','
%right '=' _SETA  _FPSETA _MAIS_IGUAL _MENOS_IGUAL
%nonassoc '<' '>'   _IGUAL_IGUAL
%left '+' '-'
%left '*' '/' '%'
%left '[' '(' 
%left _INC
%left '.'
%left ':'

%%

S : CMDs  { imprime_codigo( resolve_enderecos( $1.c + "." + funcoes ) ); cout << endl;}
;

CMDs : CMD CMDs             { $$.c = $1.c + $2.c; }
     | DECL_VAR ';' CMDs    { $$.c = $1.c + $3.c; }
     | DECL_FUN CMDs        { $$.c = $1.c + $2.c; } 
     |                      { $$.c.clear(); }
     ;
    
CMD : CMD_FOR
    | CMD_IF
    | CMD_WHILE
    | E_V ';'
    | '{' NOVO_ESCOPO CMD CMDs '}' DESTROI_ESCOPO     { $$.c = "<{" + $3.c + $4.c + "}>"; }    
    | '{' NOVO_ESCOPO CMDs '}' DESTROI_ESCOPO         {   $$.c = "<{" + $3.c + "}>"; }
    | ';'              { $$.c.clear(); }     
    | _RETURN ';' { $$.c = $$.c + "undefined" + "@" + "'&retorno'" + "@" + "~";}
    | _RETURN EE ';' { $$.c = $2.c + "'&retorno'" + "@" + "~";}
    | E ASM ';' 	{ $$.c = $1.c + $2.c; }
    ;
    
CMD_IF : _IF '(' E ')' CMD _ELSE CMD
        {  string lbl_fim = gera_label( "fim_if" ), 
                   lbl_true = gera_label( "then" ), 
                   lbl_false = gera_label( "else" );
                   
            $$.c = $3.c + lbl_true + "?" + lbl_false + "#" + 
                   (":" + lbl_true) + $5.c + lbl_fim + "#" +
                   (":" + lbl_false) + $7.c + 
                   (":" + lbl_fim);
         }
       | _IF '(' E ')' CMD 
       {  string lbl_fim = gera_label( "fim_if" ), 
                    lbl_true = gera_label( "then" );
                    
                $$.c = $3.c + lbl_true + "?" + lbl_fim + "#" + 
                    (":" + lbl_true) + $5.c + 
                    (":" + lbl_fim);
        }
       ;
    
CMD_FOR : _FOR '(' E_OPC ';' E_OPC ';' E_OPC ')' CMD
        {
            string lbl_fim = gera_label( "fim_for" ), lbl_true = gera_label( "then" );

            $$.c =  $3.c + $5.c + lbl_true + "?" + lbl_fim + "#" + 
                   (":" + lbl_true) + $9.c + $7.c + $5.c + lbl_true + "?" + lbl_fim + "#" +  
                   (":" + lbl_fim);
        }
        | _FOR '(' DECL_VAR ';' E_OPC ';' E_OPC ')' CMD     
        {
            string lbl_fim = gera_label( "fim_for" ), lbl_true = gera_label( "then" );

            $$.c =  $3.c + $5.c + lbl_true + "?" + lbl_fim + "#" + 
                   (":" + lbl_true) + $9.c + $7.c + $5.c + lbl_true + "?" + lbl_fim + "#" +  
                   (":" + lbl_fim);
        }
        ;

CMD_WHILE : _WHILE '(' E ')' CMD
          {
            string lbl_fim = gera_label( "fim_while" ), lbl_true = gera_label( "then" );

            $$.c = $3.c + lbl_true + "?" + lbl_fim + "#" + 
                   (":" + lbl_true) + $5.c + $3.c + lbl_true + "?" + lbl_fim + "#" +  
                   (":" + lbl_fim);
          }
          ;
        
E_OPC : E_V
    |
    ;

DECL_VAR : _LET LVARs    { $$ = $2; }  
         | _VAR VVARs    { $$ = $2; }
         | _CONST CTEs   { $$ = $2; } 
         ;
        
DECL_FUN : _FUNCTION _ID '(' ')' '{' NOVO_ESCOPO  CMDs '}' DESTROI_ESCOPO
          { 
             string lbl_func = gera_label( "func_" + $2.c[0] );
             funcoes = funcoes + (":" + lbl_func) + $7.c;
             
             // Código para declarar o objeto função. Exemplo:
             // mdc & mdc {} = '&funcao' 21 [=] ^
             $$.c = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + lbl_func +
                    "[=]" + "^";
             
             // Toda função deve retorna undefined se não retornar nada
             // undefined @ '&retorno' @ ~
             //$$.c = $$.c + "undefined" + "@" + "'&retorno'" + "@" + "~";
             funcoes = funcoes + "undefined" + "@" + "'&retorno'" + "@" + "~";
           }
         | _FUNCTION _ID '(' NOVO_ESCOPO PARAMs ')' '{'  CMDs '}' DESTROI_ESCOPO
           { 
             string lbl_func = gera_label( "func_" + $2.c[0] );
             funcoes = funcoes + (":" + lbl_func) + $5.c + $8.c;
             
             // Código para declarar o objeto função. Exemplo:
             // mdc & mdc {} = '&funcao' 21 [=] ^
             $$.c = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + lbl_func +
                    "[=]" + "^";
             
             // Toda função deve retorna undefined se não retornar nada
             // undefined @ '&retorno' @ ~
             //$$.c = $$.c + "undefined" + "@" + "'&retorno'" + "@" + "~";
             funcoes = funcoes + "undefined" + "@" + "'&retorno'" + "@" + "~";
           }
         ;
         
NOVO_ESCOPO :   { ts.push_back( {} ); } 
            ;
            
DESTROI_ESCOPO : { ts.pop_back(); }
               ;
         

       // a & a arguments @ 0 [@] = ^
PARAMs : PARAMs ',' _ID  
         { $$.c = $1.c + $3.c + "&" + $3.c + "arguments" + "@" +
                  to_string( $1.contador ) + "[@]" + "=" + "^";
           $$.contador = $1.contador + 1; }
       | _ID 
         { $$.c = $1.c + "&" + $1.c + "arguments" + "@" + "0" +
                  "[@]" + "=" + "^";
           $$.contador = 1; }
       | PARAMs ',' _ID '=' E
       | _ID '=' E
       ;
     
LVARs : LVAR ',' LVARs     { $$.c = $1.c + $3.c; }
      | LVAR
      ;
                    
VVARs : VVAR ',' VVARs     { $$.c = $1.c + $3.c; }
      | VVAR
      ;
                    
LVAR : _ID '=' EE     
       { 
        tenta_declarar_let( $1.c[0], $1.linha, $1.coluna );

        $$.c = $1.c + "&" + $1.c + handle_neg($3.c) + "=" + "^";
      }
     | _ID           
       { tenta_declarar_let( $1.c[0], $1.linha, $1.coluna );
         $$.c = $1.c + "&"; }
     ;
    
VVAR : _ID '=' EE     
        { if( ja_declarou_var( $1.c[0], $1.linha, $1.coluna ) )
            $$.c = $1.c + handle_neg($3.c) + "=" + "^";
          else
            $$.c = $1.c + "&" + $1.c + handle_neg($3.c) + "=" + "^"; }     
     | _ID           
       { if( !ja_declarou_var( $1.c[0], $1.linha, $1.coluna ) )
           $$.c = $1.c + "&";
         else
           $$.c.clear(); }
     ;
    
CTEs : _ID '=' EE ',' CTEs
       { tenta_declarar_const( $1.c[0], $1.linha, $1.coluna );
         $$.c = $1.c + "&" + $1.c + handle_neg($3.c) + "=" + "^"; }     
     | _ID '=' EE
       { tenta_declarar_const( $1.c[0], $1.linha, $1.coluna );
         $$.c = $1.c + "&" + $1.c + handle_neg($3.c) + "=" + "^"; }
     ;
  

E_V : E ',' E_V
    | E
    ;

EE  : E
    | '{' '}' {  $$.c.clear(); $$.c.push_back("{}"); }  
    ;

E   : _ID '=' EE
    {
        checa_ja_declarou( $1.c[0], $1.linha, $1.coluna );
        if ( $3.c[$3.c.size()-1] == "^" ) {
            $3.c.pop_back();
        }
        $$.c = $1.c + handle_neg($3.c) + "=" + "^";
    }
    | _ID _MAIS_IGUAL EE 
    {
        checa_ja_declarou( $1.c[0], $1.linha, $1.coluna );
        $$.c = $1.c + $1.c + "@" + $3.c + "+" + "=" + "^"; 
    }
    | _ID _MENOS_IGUAL EE 
    {
        checa_ja_declarou( $1.c[0], $1.linha, $1.coluna );
        $$.c = $1.c + $1.c + "@" + $3.c + "-" + "=" + "^"; 
    }
    | _ID _SETA EE
    | _ID _SETA '{' CMD CMDs '}'
    | EE _INC {
      if ( $1.c[$1.c.size()-1] == "@" ) {
            $1.c.pop_back();
        }
      $$.c = $1.c + "@" + $1.c + $1.c + "@" + "1" + "+" + "=" + "^"; 
    }  
    | '(' _FPSETA EE
    | '(' PARAMs _FPSETA EE
    | F '.' _ID '=' EE { $$.c = $1.c + $3.c + $5.c + "[=]" + "^"; }
    | F '.' _ID _MAIS_IGUAL EE
    { 
        $$.c =  $1.c + "@" + $3.c + $1.c + "@" + $3.c + "[@]" + $5.c + "+" + "=" + "^";
    }
    | F '[' EE ']' '=' EE
    {
      if ( $3.c[$3.c.size()-1] == "^" ) {
            $3.c.pop_back();
        }
      $$.c = $1.c + $3.c + handle_neg($6.c) + "[=]" + "^";
    }
    | F '[' EE ']' '[' EE ']' '=' EE
    {
      if ( $3.c[$3.c.size()-1] == "^" ) {
            $3.c.pop_back();
        }
      if ( $6.c[$6.c.size()-1] == "^" ) {
            $6.c.pop_back();
        }
      if ( $9.c[$9.c.size()-1] == "^" ) {
            $9.c.pop_back();
        }
      $$.c = $1.c + $3.c + "[@]" + $6.c + $9.c + "[=]" + "^";
    }
    | F '.' _ID '[' EE ']' '=' EE { $$.c = $1.c + $3.c + "[@]" + $5.c + $8.c + "[=]" + "^"; }
    | F '[' EE ']' _MAIS_IGUAL EE
    | F '.' _ID '[' EE ']' _MAIS_IGUAL EE
    { 
         $$.c =  $1.c + $3.c + "[@]" + $5.c + $1.c + $3.c + "[@]" + $5.c + "[@]" + $8.c + "+" + "[=]" + "^";
    }
    | EE '<' EE        { $$.c = $1.c + $3.c + "<"; }
    | EE '*' EE        { $$.c = $1.c + $3.c + "*"; }
    | EE '+' EE        { $$.c = $1.c + $3.c + "+"; }
    | EE '-' EE        { $$.c = $1.c + $3.c + "-"; }
    | EE '/' EE        { $$.c = $1.c + $3.c + "/"; }
    | EE '>' EE        { $$.c = $1.c + $3.c + ">"; }
    | EE '%' EE        { $$.c = $1.c + $3.c + "%"; }
    | EE _IGUAL_IGUAL EE     { $$.c = $1.c + $3.c + "=="; }
    | F
    ;

F : _ID     { $$.c = $1.c + "@"; }
  | _NUM    {
      $$.c = $1.c;
  }
  | _STRING { $$.c = $1.c; }
  | '(' EE ')' { $$ = $2; } 
  | F '(' ')'  { $$.c = to_string( 0 ) +  $1.c + "$"; }
  | F '[' EE ']' {
    $$.c = $1.c + $3.c + "[@]";
  }
  | F '[' EE ']' '[' EE ']' { $$.c = $1.c + $3.c + "[@]" + $6.c +  "[@]"; }
  | F '(' ARGs ')' { $$.c = $3.c + to_string( $3.contador ) +  $1.c + "$" + "^"; }
  | '[' ']' { $$.c.clear(); $$.c.push_back("[]");}
  | '[' ARGs ']' { $$.c = $1.c + $3.c + "[@]"; }
  | '{' CAMPOs '}' 
  | F '.' _ID { $$.c = $1.c + $3.c + "[@]"; }
  | FUNC_ANON
  | _TRUE { $$.c = $1.c ; }
  | _FALSE { $$.c = $1.c ; }
  ;

FUNC_ANON : _FUNCTION '(' ')' '{' CMDs '}' 
          | _FUNCTION '(' PARAMs ')' '{' CMDs '}'
          ;
        
        
CAMPOs : CAMPOs ',' CAMPOs
      | _ID ':' EE
      ;
    

ARGs : EE ',' ARGs {
      if ( $1.c[$1.c.size()-1] == "^" ) {
        $1.c.pop_back();
      };
      $$.c = $1.c + $3.c; $$.contador = 1 + $3.contador;
      }
     | EE {
      if ( $1.c[$1.c.size()-1] == "^" ) {
        $1.c.pop_back();
      };
      $$.c = $1.c; $$.contador = 1;
    }
    ;

%%

#include "lex.yy.c"

bool includesChar(const std::string& str, char ch) {
    return str.find(ch) != std::string::npos;
}

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

vector<string> operator+( string a, vector<string> b ) {
  vector<string> aux{ a };

  return aux + b;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
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

void tenta_declarar_let( string nome, int linha, int coluna ){   
    if( ts.back().count( nome ) > 0 ) {
       erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "let" }; 
}

void tenta_declarar_const( string nome, int linha, int coluna ){  
    if( ts.back().count( nome ) > 0 ) {
        erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "const" }; 
}

bool ja_declarou_var( string nome, int linha, int coluna ){   
    if( ts.back().count( nome ) > 0 ) {
      if( ts.back()[nome].tipo_decl != "var" ) 
        erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
      
      return true;
    }
    
    ts.back()[nome] = Simbolo{ linha, coluna, "var" }; 
    return false;
}

void checa_ja_declarou(string nome, int linha, int coluna) {
    if( find_nome(nome) ) {
        if( get_nome(nome).tipo_decl == "const" ) 
            erro("Erro: a variável '" + nome + "' já foi declarada na linha " + to_string( ts.back()[nome].linha ) + ".");
    } else {
        erro("Erro: a variável '" + nome + "' não foi declarada.");
    }
}

Simbolo get_nome(string nome) {
  for (map <string, Simbolo> space : ts) {
    if (space.count(nome) > 0) {
      return space[nome];
    }
  }
}

bool find_nome(string nome) {
  bool found = false;

  for (const auto& space : ts) {
    if (space.count(nome) > 0) {
      found = true;
      break;
    }
  }

  return found;
}



void erro( string msg ) {
    cout << msg << endl;
    exit( 1 );
}

vector<string> handle_neg(vector<string> c) {
  vector<string> v;
  v.clear();
  string s = c[0];

  if (s[0] == '-') {
    v.push_back("0");
    s = s.substr(1);
    v.push_back(s);
    v.push_back("-");
    return v;
  } else {
    return c;
  }
}