#include <iostream>
#include "tokenizer.h"
#include "parser.h"

using std::cout;
using std::endl;
using namespace std;

int main () {
  Tokenizer tokenizer;
  std::vector<Token> res = tokenizer.split("1+2*3");
 // for (Token token : res) {
 //   std::cout << token.val << std::endl;
 // }
  Parser parse;
  double result = parse.expression(res);
  cout << result << endl;
  return 0;
}
