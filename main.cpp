#include <iostream>
#include "tokenizer.h"

using std::cout;
using std::endl;

int main () {
  Tokenizer tokenizer;
  std::vector<Token> res = tokenizer.split("123+2");
  for (Token token : res) {
    std::cout << token.val << std::endl;
  }
  return 0;
}
