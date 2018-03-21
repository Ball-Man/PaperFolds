#ifndef PAPERFOLDS_H_
#define PAPERFOLDS_H_

#include <string>

namespace utils
{

// Utility data struct for storing big and small numbers
struct Factor
{
  int k;
  int exp;
};

bool IsDigit(char c);
bool IsNumber(std::string s);
bool IsComment(std::string s);

// Actual math behind the folds
double CalcFolds(Factor paper, Factor distance);

} // Namespace utils

#endif