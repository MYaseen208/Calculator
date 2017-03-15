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
    if (!line.empty())
    {
      std::vector<Token> res = tokenizer.split(line);
      std::cout << "result: " << parser.parse_line(res);
    }
  }
  return 0;
}
