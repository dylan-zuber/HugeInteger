/*
Name: Dylan Zuber
Assignment: PA 1
Course/Semester: CS343/Fall2020
Lab Section: N/A
Sources Consulted: N/A
*/

#include <iostream>
#include "HugeInteger.h"
#include <algorithm>

int main() {
  
  //all three types of initializing using 3 constructors
  HugeInteger a{"123_456"};
  HugeInteger b{"9999999"};
  HugeInteger c{b};
  HugeInteger f{"19999994949494949494949494"};

  // confirmation of all successful initializing
  std::cout << a.toString() << std::endl;
  std::cout << b.toString() << std::endl;
  std::cout << c.toString() << std::endl;

  // Example of using the overloaded '==' operator
  bool equalsTest = b == c;

  // confirmation that overoading '==' works
  std::cout << equalsTest << std::endl;

  // Example of overloading the '+' operator
  HugeInteger d{"0"};
  HugeInteger e = b + d;
  
  // confirmation that overloading '+' works
  std::cout << e.toString() << std::endl;

  // Example of overloading the '<' operator
  bool lessThanTest = a < b;

  // confirming that overloading the '<' operator works
  std::cout << lessThanTest << std::endl;

  // Confirming that std::sort works correctly 
  std::vector<HugeInteger> sortHugeInteger = {a, b, c, d, e, f};
  std::sort(sortHugeInteger.begin(), sortHugeInteger.end());
  for (HugeInteger a : sortHugeInteger) {
    std::cout << a.toString() << std::endl;
  }   

  HugeInteger x{"10000000000"};
  HugeInteger y{"3600"}
}