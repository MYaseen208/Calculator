#include "tokenizer.h"
#include <iostream>

std::vector<Token> Tokenizer::split (std::string str)
{
  std::vector<Token> result;
  for (int i=0; i<str.length(); ++i) {
    char c = str[i];
    if (c=='+' || c=='-' || c=='*' || c=='/')
    {
      std::string op;
      op += c;
      result.push_back(Token(OPERATOR,op));
    }
    else if (isblank(c)) continue;
    else if (isdigit(c))
    {
      std::string number;
      while(isdigit(str[i])) number+=str[i++];
      result.push_back(Token(NUMERIC,number));
      i--;
    }
    else 
      std::cout<<"Unknown character"<<std::endl;
  }
  return result;
}
