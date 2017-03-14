#include "tokenizer.h"  
#include "parser.h"

double Parser::parse_line (const std::vector<Token> &t) {
  tokens = t;
  counter = 0;
  return expression ();
}

double Parser::factor ()
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


