#ifndef Parser_h
#define Parser_h
#include <string>
#include "token.h"
#include <iostream>

using namespace std;

class Parser {
public:
  double parse_line(const std::vector<Token> &);
private:
  
  int counter = 0;
  std::vector<Token> tokens;
  double expression ();
  double factor ();
  double term ();
};

#endif
