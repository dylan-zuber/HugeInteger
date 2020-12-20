/*
Name: Dylan Zuber
Assignment: PA 1
Course/Semester: CS343/Fall2020
Lab Section: N/A
Sources Consulted: N/A
*/

#include "HugeInteger.h"
#include <string>
#include <iostream>

/*
Constructor that is called when it is initialized with no parameters, initializes
to 0
*/
HugeInteger::HugeInteger() {
  hugeInt.push_back('0');
}

/*
Constructor that is called when another HugeInteger is used as a parameter
@param other HugeInteger used to be deep copied
*/
HugeInteger::HugeInteger(const HugeInteger & other) {
  std::string str = other.toString();
  for(int i = 0; i < str.length(); i++) {
    hugeInt.push_back(str[i]);
  }
}

/*
Constructor that is called when a string is passed in to use as the HugeInteger value
@param s string value to be used to create a HugeInteger
*/
HugeInteger::HugeInteger(const std::string & s) {
 // hugeInt.erase(0); // removes the 0 that was added during initialization
 std::string str = s;
  while(s.length() > 1 && s[0] == '0') {
    str = s.substr(1, s.length() - 1); // removes any possible leading zeros
  }
  for(int i = 0; i < s.length(); i++) {
    char c = s[i];
    if(c >= '0' && c <= '9') {
      hugeInt.push_back(c);
    }
  }
}

/*
Overloads the '==' operator to compare the string values of the HugeInteger
@param rightSide HugeInteger to be compared to this object
@return bool true if the string values are equal, false if not
*/
bool HugeInteger::operator==(const HugeInteger & rightSide) {
  return this->toString() == rightSide.toString();
}

/*
Overloads the '+' operator to add two HugeInteger objects together
@param rightSide HugeInteger object to be added to this HugeInteger
@return HugeInteger object representing the summation of this and rightSide
*/
const HugeInteger HugeInteger::operator+(const HugeInteger & rightSide) {
  std::string thisNum = this->toString();
  std::string rightNum = rightSide.toString();
  int min;
  bool thisCont;
  if(this->toString().length() < rightSide.toString().length()) {
    min = thisNum.length();
    thisCont = false;
  } else {
    min = rightNum.length();
    thisCont = true;
  }

  bool carry = false;
  std::string result;
  for(int i = 0; i < min; i++) {
    int thisInt = thisNum[thisNum.length() - i - 1] - '0';
    int rightInt = rightNum[rightNum.length() - i - 1] - '0';
    int total = thisInt + rightInt;
   // std::cout << total << std::endl;
    if(carry) {total++;}
    if(total >= 10) {
      carry = true;
    }
    if(total < 10) {
      carry = false;
    }
    total = total % 10;
    char add = '0' + total;
    result = result.insert(0, 1, add);

  }

  int numsLeft;
  if(thisCont) {
    numsLeft = thisNum.length() - rightNum.length();
    for(int i = 0; i < numsLeft; i++) {
      int a = thisNum[numsLeft - i - 1] - '0';

      if(carry) {
        a++;
        carry = false;
      }
      if(a >= 10) { 
        a = a % 10;
        carry = true;
      }
      char b = '0' + a;
      result = result.insert(0, 1, b);

    }
  } else {
    numsLeft = rightNum.length() - thisNum.length();
    for(int i = 0; i < numsLeft; i++) {
      int a = rightNum[numsLeft - i - 1] - '0';
      if(carry) {
        a++;
        carry = false;
      }
      if(a >= 10) { 
        a = a%10;
        carry = true;
      }
      char b = '0' + a;
      result = result.insert(0, 1, b);

      } 
   } 
  
  if(carry) {
    result = result.insert(0, 1, '1');
  }
  HugeInteger hi{result};
  return hi;
}

/*
Overloads '<' to compare the values of two HugeInteger values
@param rightSide HugeInteger value to be compared to this HugeInteger
@return bool true if this is less than rightSide, false otherwise
*/
bool HugeInteger::operator<(const HugeInteger & rightSide) {
  std::string thisString = this->toString();
  std::string rightString = rightSide.toString();
  if(thisString.length() < rightString.length()) {
    return true;
  }
  if(thisString.length() > rightString.length()) {
      return false;
  }
  
  // iterates through each number 
  for(int i = 0; i < thisString.length(); i++) {
    int thisInt = thisString[i] - '0';
    int rightInt = rightString[i] - '0';
    if(thisInt > rightInt) { return false;}
    if(thisInt < rightInt) { return true;}
  }

  return false; // meaning they are equal which does not satisfy that this < right

}

/*
Converts this object into a string representation of the object
@return std::string string representation of this object
*/
std::string HugeInteger::toString() const {
  std::string result = "";
  int length = hugeInt.size();
  for(int i = 0; i < length; i++) {
    result += hugeInt[i];
  }
  return result;
}
