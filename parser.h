#ifndef Parser_h
#define Parser_h
#include <string>
#include "token.h"

class Parser {
public:
  int counter = 0;
  double expression(const std::vector<Token>);
  void inputing(const std::vector<Token>);
private:
  
  double factor(const std::vector<Token>);
  double term(const std::vector<Token>);
};

#endif
