#include <iostream>
#include <string>
#include <cstdlib>

void error_exit(std::string)
{
  std::cerr << "ERROR: " << string << std::endl;
  exit (1);
}

