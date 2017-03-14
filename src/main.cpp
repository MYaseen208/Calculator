#include <iostream>
#include "tokenizer.h"
#include "parser.h"

using std::cout;
using std::endl;
using namespace std;

int main () {
  Tokenizer tokenizer;
  Parser parser;
  std::string line;
  while (!std::cin.eof()) {
    std::getline (std::cin, line);
    std::vector<Token> res = tokenizer.split(line);
    std::cout << "result: " << parser.parse_line(res) << std::endl;
  }
//   std::vector<Token> res = tokenizer.split("3*3*3*(1+2)");
//   for (Token token : res) {
//     std::cout << token.val << " is: " << token.kind << std::endl;
//   }
  return 0;
}
