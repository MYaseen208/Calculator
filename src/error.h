#include <iostream>
#include <string>
#include <cstdlib>

void error_exit(std::string str)
{
  std::cerr << "ERROR: " << str << std::endl;
  exit (1);
}

