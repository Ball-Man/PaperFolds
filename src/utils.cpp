#include <utils.h>
#include <algorithm>

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