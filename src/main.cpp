#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <utils.h>

constexpr char kConfigFile[] = "paper.config"; 

int main(int argn, char** args)
{

  // Config file
  std::ifstream fin(kConfigFile);
  if(!fin.is_open())
  {
    std::cout << "-- file not found: " << kConfigFile << "\n";
    return 0;
  }

  int n = -1;
  int exp;

  while(!fin.eof())
  {
    std::string line;
    std::getline(fin, line);

    if(!utils::IsComment(line) && line.length())    // Skip comments and empty lines
    {
      if(utils::IsNumber(line))
      {
        if(n == -1)
          n = std::stoi(line);
        else
          exp = std::stoi(line); 
      }
      else
      {
        std::cout << "-- bad config file\n";
        return 0;
      }
    }
  }

  std::cout << n << " " << exp << "\n";

}