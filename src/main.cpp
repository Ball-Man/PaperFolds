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

  int paper_k = -1;
  int paper_exp;

  while(!fin.eof())
  {
    std::string line;
    std::getline(fin, line);

    if(!utils::IsComment(line) && line.length())    // Skip comments and empty lines
    {
      if(utils::IsNumber(line))
      {
        if(paper_k == -1)
          paper_k = std::stoi(line);
        else
          paper_exp = -std::stoi(line); 
      }
      else
      {
        std::cout << "-- bad config file\n";
        return 0;
      }
    }
  }

  // Input from user
  std::string line = "";
  int dis_k,
      dis_exp;

  std::cout << "Insert here the distance. The program will calculate how many time you need to fold your paper in order to get there.\n"
    << "Distances are in meters and are expressed as follows:\n"
    << "k * 10 ^ exp\n\n"
    << "  k factor: ";

  // k input
  std::getline(std::cin, line);
  while(!utils::IsNumber(line))     // Check for errors
  {
    std::cout << "-- bad input, insert an natural number\n  k factor: ";
    std::getline(std::cin, line);
  }
  dis_k = std::stoi(line);

  std::cout << "  exp factor: ";

  // exp input
  std::getline(std::cin, line);
  while(!utils::IsNumber(line))      // More check for errors
  {
    std::cout << "-- bad input, insert an natural number\n  exp factor: ";
    std::getline(std::cin, line);
  }
  dis_exp = std::stoi(line);

  // Test
  std::cout << dis_k << " * 10 ^ " << dis_exp << "\n";
}