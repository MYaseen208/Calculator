#include "tokenizer.h"  
#include "parser.h"


double Parser::factor(std::vector<Token> res)
{
  if (res[counter].kind == NUMERIC)
  {
    return stod (res[counter].val);
  }
//  else if (res[counter].kind == '(')
//   {
//     counter++; // '('
//     double result = expression(res);
//     counter++; // ')'
//     return result;
//   }
  else if (res[counter].kind == MINUS)
  {
    counter++;
    return -expression(res);
  }
  else if (res[counter].kind == PLUS)
  {
    counter++;
    return +expression(res);
  }
  else
    return 0; // error
}

double Parser::term(std::vector<Token> res)
{
  double result = factor(res);
  counter++;
  while (res[counter].kind == STAR || res[counter].kind == SLASH)
    if (res[counter].kind == STAR)
    {
      counter++;
      result *= factor(res);
    }
    else
    {
      counter++;
      result /= factor(res);
    }
  return result;
}

double Parser::expression(std::vector<Token> res)
{
  double result = term(res);
//   counter++;
  while (res[counter].kind == PLUS || res[counter].kind == MINUS)
    if (res[counter].kind == PLUS)
    {
      counter++;
      result += term(res);
    }
    else
    {
      counter++;
      result -= term(res);
    }
  return result;
}

