// Francis Kizhakkekara
// Project 1: Find Greatest Common Divisor using Euclidean Algorithm
// Ex: (Textbook pg. 259) 
// gcd(689, 234) = ?
// 689 mod 234 = 221
// gcd(689, 234) = gcd(234, 221)
// 234 mod 221 = 13
// gcd(689, 234) = gcd(234, 221) = gcd(221, 13) = 13
// 221 mod 13 = 0

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// Function that returns the GCD of the 2 inputs
// This function does Euclidean Algorithm recursively
int findGCD(int firstNum, int secondNum, int& oneCoeff, int& twoCoeff){

  if(secondNum != 0){
    
    return findGCD(secondNum, firstNum % secondNum);
  }      
  else{

    return firstNum;      
  }    
}

int main() {
  int numOne = 0;
  int numTwo = 0;
  int coeffOne = 0;
  int coeffTwo = 0;

  cout << "This program find the Greatest Common Divisor of 2 numbers using Euclidean Algorithm." << endl;
  cout << "Enter the numbers:" << endl;
  cin >> numOne >> numTwo;

  int theGCD = 0;
  theGCD = findGCD(abs(numOne), abs(numTwo), coeffOne, coeffTwo);


  // The findGCD output 0 when both numbers are zero, but gcd(0, 0) is undefined
  if(theGCD == 0){
    cout << "The GCD is undefined." << endl;
  }
  else{
    cout << "The Greatest Common Divisor for " << numOne << " and " << numTwo << " is " <<
      theGCD << "." << endl;
  }

  return 0;
}