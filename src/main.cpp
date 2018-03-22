#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <utils.h>

constexpr char kConfigFile[] = "paper.config";
constexpr int kDefaultDistanceK = 1;
constexpr int kDefaultDistanceExp = 0;

int main(int argn, char** args)
{

  // Config file
  std::ifstream fin(kConfigFile);
  if(!fin.is_open())
  {
    std::cout << "-- file not found: " << kConfigFile << "\n";
    return 0;
  }

  utils::Factor paper = { -1 };

  while(!fin.eof())
  {
    std::string line;
    std::getline(fin, line);

    if(!utils::IsComment(line) && line.length())    // Skip comments and empty lines
    {
      if(utils::IsNumber(line))
      {
        if(paper.k == -1)
          paper.k = std::stoi(line);
        else
          paper.exp = std::stoi(line); 
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
  utils::Factor distance = { kDefaultDistanceK, kDefaultDistanceExp };

  std::cout << "Insert here the distance. The program will calculate how many time you need to fold your paper in order to get there.\n"
    << "Distances are in meters and are expressed as follows:\n"
    << "k * 10 ^ exp\n\n"
    << "  k factor[" << kDefaultDistanceK << "]: ";

  // k input
  std::getline(std::cin, line);
  if(line.length())
  {
    while(!utils::IsNumber(line))     // Check for errors
    {
      std::cout << "-- bad input, insert an natural number\n  k factor: ";
      std::getline(std::cin, line);
    }
    distance.k = std::stoi(line);
  }

  std::cout << "  exp factor[" << kDefaultDistanceExp << "]: ";

  // exp input
  std::getline(std::cin, line);
  if(line.length())
  {
    while(!utils::IsNumber(line))      // More check for errors
    {
      std::cout << "-- bad input, insert an natural number\n  exp factor: ";
      std::getline(std::cin, line);
    }
    distance.exp = std::stoi(line);
  }

  std::cout << "\nPaper thickness: " << paper.k << " * 10 ^ -" << paper.exp
    << "\nDistance: " << distance.k << " * 10 ^ " << distance.exp
    << "\nFolds:\n";

  double res = utils::CalcFolds(paper, distance);
  std::cout << "  Calculated value: " << res << "\n"
    << "  Real value: " << std::ceil(res) << "\n";
}