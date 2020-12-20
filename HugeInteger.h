/*
Name: Dylan Zuber
Assignment: PA 1
Course/Semester: CS343/Fall2020
Lab Section: N/A
Sources Consulted: N/A
*/

// Method comments/descriptions are in .cpp file

#include <string>
#include <vector>

#ifndef _HUGEINTEGER_H
#define _HUGEINTEGER_h

class HugeInteger {

public:

HugeInteger();
HugeInteger(const HugeInteger & other);
HugeInteger(const std::string & s);


bool operator==(const HugeInteger & rightSide);
const HugeInteger operator+(const HugeInteger & rightSide);
bool operator <(const HugeInteger & rightSide);

std::string toString() const;


private:
  std::vector<char> hugeInt;

};
#endif
