// Francis Kizhakkekara
// Project 3: This program implement the Inclusion-Exclusion algorithm
// to count how many derangements of length there are from a user input
// number.

#include <iostream>
#include <cmath>
using namespace std;

// This funciton returns the factorial of an integer
long double facto(int inputNum){

  long double theFactorial = 1;

  for(int i = inputNum; i > 1; i--)
    theFactorial = theFactorial * i;
   
  return theFactorial;
}

// This function does (n choose k)
long double nChooseK(int n, int k){

  return facto(n)/(facto(n-k) * facto(k));
}

// Derangement function
long double derangementFunc(int theNumber){
  long double theDerange = 0.0;

  for(int i = theNumber-1, j = 2; i > -1; i--, j++){
    theDerange += pow(-1, j) * facto(i) * nChooseK(theNumber, theNumber - i);
  }

  return facto(theNumber) - theDerange;
}

int main() {

  cout << "This program calculates the derangement of length given by the user." << endl;  
  
  int theInput = 0;
  while(theInput <= 0){
    cout << "Enter the derangement length. (1 <= input <= 10)" << endl;
    cin >> theInput;
  }

  int theResult = derangementFunc(theInput);
  cout << "The number of derangements of length " << theInput << " is " << theResult << endl;
}