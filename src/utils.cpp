#include <utils.h>
#include <algorithm>
#include <cmath>

bool utils::IsDigit(char c)
{
  return c >= '0' && c <= '9';
}

bool utils::IsNumber(std::string s)
{
  for(char c : s)
    if(!IsDigit(c))
      return false;
    return s.length();
}

bool utils::IsComment(std::string s)
{
  return s[0] == '#';
}

// Actual math behind the folds
double utils::CalcFolds(Factor paper, Factor distance)
{
  return (paper.exp + distance.exp) * std::log2(paper.k) + std::log2(distance.k); 
}