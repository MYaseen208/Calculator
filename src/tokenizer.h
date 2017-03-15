#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>
#include "token.h"

// This Tokenizer class for makeing tokens from input.

class Tokenizer
{
public:
  std::vector<Token> split (std::string);
};

#endif
