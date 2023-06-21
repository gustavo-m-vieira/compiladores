#include <stdio.h>
#include <string>

using namespace std;

extern "C" int yyparse();  

#include "y.tab.c"

int main() {
  yyparse();
  // cout << "Gramática ok" << endl;
}
