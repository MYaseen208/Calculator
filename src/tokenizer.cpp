#include "tokenizer.h"
#include <iostream>
#include <cstdlib>

std::vector<Token> Tokenizer::split (std::string str)
{
  std::vector<Token> result;
  for (int i=0; i<str.length(); ++i) {
    char c = str[i];
    if (c=='+')
    {
      std::string op;
      op += c;
      result.push_back(Token(PLUS,op));
    }
    else if (c=='-')
    {
      std::string op;
      op += c;
      result.push_back(Token(MINUS,op));
    }
    else if (c=='*')
    {
      std::string op;
      if (str[i+1]=='*') 
      {
        op+= '^';
        result.push_back(Token(POW,op));
        i++;
      }
      else  
      {
        op+= c;
        result.push_back(Token(STAR,op));
      }
    }
    else if (c=='^')
    {
      std::string op;
      op += c;
      result.push_back(Token(POW,op));
    }
    else if (c=='/')
    {
      std::string op;
      op += c;
      result.push_back(Token(SLASH,op));
    }
    else if (c=='(')
    {   
      std::string op; 
      op += c;
      result.push_back(Token(OPENPTS,op));
    }
    else if (c==')')
    {   
      std::string op; 
      op += c;
      result.push_back(Token(CLOSEPTS,op));
    }
    else if  (c=='.')
    {
      std::string number;
      number += str[i];
      i++;
      while(isdigit(str[i]))  number+=str[i++];
      if (str[i]=='.') 
      {
          std::cout<<"ERROR: Invalid float!" << std::endl;
        exit (1);        
      }
      result.push_back(Token(NUMERIC,number));
      i--;
    }
    else if (isblank(c)) continue;
    else if (isdigit(c))
    {
      int dot_counter=0; 
      std::string number;
      while(isdigit(str[i]) || (str[i]=='.'))
      {
        if (str[i]=='.') dot_counter++;
        number+=str[i++];
      }
      if (dot_counter>1) 
      {
        std::cout<<"ERROR: Invalid float!" << std::endl;
        exit (1);
      }
      result.push_back(Token(NUMERIC,number));
      i--;
    }
    else 
      std::cout<<"Unknown character"<<std::endl;
  }
  return result;
}

