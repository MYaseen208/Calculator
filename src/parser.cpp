#include "tokenizer.h"  
#include "parser.h"
#include <cmath>
#include "error.h"

double Parser::parse_line (const std::vector<Token> &t) {
  tokens = t;
  counter = 0;
  return expression ();
}

double Parser::factor ()
{
  double result = primary ();
  if (counter + 1 < tokens.size() && tokens[counter + 1].kind == POW)
  {
    counter += 2;
    if (counter >= tokens.size())
      error_exit("Syntax of power function incorrect!");
    double exponent = primary();
    return std::pow (result, exponent);
  }
  else
    return result;
}

double Parser::primary ()
{
  if (tokens[counter].kind == NUMERIC)
  {
    return stod (tokens[counter].val);
  }
  else if (tokens[counter].kind == OPENPTS)
  {
    counter++;
    return expression();
  }
  else if (tokens[counter].kind == MINUS)
  {
    counter++;
    if (tokens[counter].kind == OPENPTS)
    {
      counter++;
      return -expression();
    }
    else 
      return -stod (tokens[counter].val);
  }
  else if (tokens[counter].kind == PLUS)
  {
    counter++;
    if (tokens[counter].kind == OPENPTS) 
    {
      counter++;
      return +expression();
    }
    else
      return +stod (tokens[counter].val);
  }
  else
    return 0; // error
}

double Parser::term ()
{
  double result = factor();
  counter++;
  while (counter<tokens.size()&&(tokens[counter].kind == STAR || tokens[counter].kind == SLASH))
  {
    if (tokens[counter].kind == STAR)
    {
      counter++;
      result *= factor();
      counter++;
    }
    else
    {
      counter++;
      result /= factor();
      counter++;
    }
  }
  return result;
}

double Parser::expression ()
{
  double result = term();
  while (counter<tokens.size()&&(tokens[counter].kind == PLUS || tokens[counter].kind == MINUS))
  {
    if (tokens[counter].kind == PLUS)
    {
      counter++;
      result += term();
    }
    else
    {
      counter++;
      result -= term();
    }
  }
  return result;
}
