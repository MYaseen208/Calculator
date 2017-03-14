#include <iostream>
#include "tokenizer.h"
#include "parser.h"

using std::cout;
using std::endl;
using namespace std;

int main (int argc, char *argv[]) {
  Tokenizer tokenizer;
  Parser parser;
  std::vector<Token> res = tokenizer.split(argv[1]);
  return parser.parse_line(res);
}
