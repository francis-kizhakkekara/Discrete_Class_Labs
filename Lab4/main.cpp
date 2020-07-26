// Francis Kizhakkekara
// Project 4: Implement Warshall's algorithm in order 
// to find the transitive closure of a given relation, 
// using the matrices

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

int main() {

  ifstream fileName;
  fileName.open("testcase-1.txt", ifstream::in);
  
  if(fileName.fail()){
    cout << "File opening failed." << endl;
    fileName.close();
  }

  vector<int> NumStorage;
  int matrixSize = 1;
  char c = fileName.get();

  // Taking input from a file and storing it in a vector
  // This also finds the matrix size for an N x N matrix
  while (fileName.good()) {
    if(isdigit(c))
      NumStorage.push_back(c - 48);

    if( (c == '\n') && isdigit(fileName.peek()) )
      matrixSize++;

    c = fileName.get();
  }

  fileName.close();
  cout << "Matrix Size: " << matrixSize << endl;
  
  // Splitting the single dimension vector
  // to an array with right dimensions
  int theArray[matrixSize][matrixSize];
  for(int i = 0, j = 0, k = 0; i < NumStorage.size(); i++){
    if(i%matrixSize == 0 && i > 0){

      j++;
      k = 0;      
    }

    theArray[j][k] = NumStorage[i];
    k++;    
  }

  // Display the matrix
  for(int i = 0; i < matrixSize; i++){
    for(int j = 0; j < matrixSize; j++)

      cout << theArray[i][j] << " ";
      cout << endl;
  }
  cout << endl;

  // Warshall's algorithm loop
  vector<int> ColumnVal;
  vector<int> RowVal;
  for(int thePosition = 0; thePosition < matrixSize; thePosition++){

    // Finding the location of 1s in Column 
    for(int i = 0; i < matrixSize; i++){
      if(theArray[i][thePosition]){

        ColumnVal.push_back(i);
      }      
    }

    // Output of K and Column location
    cout << "K = " << thePosition + 1 << endl;
    cout << "Column " << thePosition+1 << ": " ;
    for(int i = 0; i < ColumnVal.size(); i++)
      cout << ColumnVal[i] +1 << " ";
    cout << endl;

    // Finding the location of 1s in Row 
    for(int i = 0; i < matrixSize; i++){
      if(theArray[thePosition][i]){

        RowVal.push_back(i);
      }      
    }

    // Output of Row location
    cout << "Row " << thePosition+1 << ": " ;
    for(int i = 0; i < RowVal.size(); i++)
        cout << RowVal[i] +1 << " ";
    cout << endl;
    
    // Inserting 1s in the locations found
    // Columns found as Row value
    // Rows found as Column value
    if(ColumnVal.size() > 0 && RowVal.size() > 0){

      for(int i = 0; i < ColumnVal.size(); i++){
        for(int j = 0; j < RowVal.size(); j++){

          theArray[ColumnVal[i]][RowVal[j]] = 1;
        }
      }
    }
    
    // Display the new matrix
    cout << "Matrix: " << endl;
    for(int i = 0; i < matrixSize; i++){
      for(int j = 0; j < matrixSize; j++)
        cout << theArray[i][j] << " ";
      cout << endl;
    }

    cout << endl;
    ColumnVal.clear();
    RowVal.clear();
  }

  // Final Matrix Output
  cout << "The final matrix: " << endl;
  for(int i = 0; i < matrixSize; i++){
    
    for(int j = 0; j < matrixSize; j++)
      cout << theArray[i][j] << " ";
      
    cout << endl;
  }
}