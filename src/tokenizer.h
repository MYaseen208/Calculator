#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>
#include "token.h"


class Tokenizer
{
public:
  std::vector<Token> split (std::string);
};



#endif
