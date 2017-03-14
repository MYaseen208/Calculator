#include "error.h"
#include <iostream>
#include <cstdlib>

void error_exit(std::string str)
{
  std::cerr << "ERROR: " << str << std::endl;
  exit (1);
}
