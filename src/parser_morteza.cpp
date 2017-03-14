#include "parser.h"



double Parser::number()
{
  double result = get() - '0';
  while (peek() >= '0' && peek() <= '9')
  {
    result = 10*result + get() - '0';
  }
  return result;
}

double Parser::factor()
{
  if (peek() >= '0' && peek() <= '9')
    return number();
  else if (peek() == '(')
  {
    get(); // '('
    double result = expression();
    get(); // ')'
    return result;
  }
  else if (peek() == '-')
  {
    get();
    return -expression();
  }
  return 0; // error
}

double Parser::term(const std::vector<Token> &res)
{
  double result=0;
  double result = factor();
  while (peek() == '*' || peek() == '/')
    if (get() == '*')
      result *= factor();
    else
      result /= factor();
    return result;
}

double Parser::expression(const std::vector<Token> &res)
{
  double result=0;
  for (int i=0; i<res.size();) {
    std::vector<Token> terms;
    int sign = (res[i].kind==MINUS) ? -1 : +1;
    if (res[i].kind==PLUS||res[i].kind==MINUS) i++;
    while (res[i].kind!=PLUS&&res[i].kind!=MINUS) {
      terms.push_back(res[i]);
      i++;
    }
    result += sign*term(terms);
  }
  return result;
}

