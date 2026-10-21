#ifndef INPUT_H_
#define INPUT_H_

#include <iostream>
#include <list>
#include <deque>


bool IsInteger(const std::string& str);
bool IsReal(const std::string& str);
bool IsEnglishCapsWord(const std::string& str);

int IntegerInput(const std::string& prompt);
int TaskInput(const std::string& prompt, int task_count);
double RealInput(const std::string& prompt);
std::string EnglishCapsWordInput(const std::string& prompt);

#endif  // INPUT_H_