#include <iostream>
#include "tokenizer.h"
#include "parser.h"

using std::cout;
using std::endl;
using namespace std;

int main () {
// Creating tokenizer object from Tokenizer Class.
  Tokenizer tokenizer;
// Creating parser object from Parser Class.
  Parser parser;
  std::string line;
  while (!std::cin.eof()) {
    std::getline (std::cin, line);
    if (!line.empty())
    {
//    Reading line from input.
      std::vector<Token> res = tokenizer.split(line);
      std::cout << "result: " << parser.parse_line(res);
    }
  }
  return 0;
}
