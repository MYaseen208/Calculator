#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum Kind {NUMERIC,PLUS,MINUS,STAR,SLASH,IDENTIFIER};

struct Token {
  Token (Kind k, std::string str) : kind(k), val(str) {}
  Kind kind;
  std::string val;
};

#endif

