#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// Define kind type for tokens.
enum Kind {NUMERIC,PLUS,MINUS,STAR,SLASH,POW,OPENPTS,CLOSEPTS,IDENTIFIER};

struct Token {
  Token (Kind k, std::string str) : kind(k), val(str) {}
  Kind kind;
  std::string val;
};

#endif

