//Rico Adrian
//Project 1
//Program 2

#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <set>
#include <sstream>
#include <string>
using namespace std;
int main (int argc, char* argv[]) {

	//initalize the argument to input the value of n and k
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);


	//initialize an array of string which contains digits 1 through 9
	string number[]={"0","1","2","3","4","5","6","7","8","9"};

	//create a set of string which contains all the possible permutations
	set<string> permutation;

  
  cout << "The possible permutations with k digit and n elements are "<<"\n";

  //create a do while loop to generate all possible permutations
  do {

		//create a stringstream variable stream 
		stringstream stream;
	   // put the current possible permutation into variable stringstream
	  for (int i=0;i<k;i++) {
		  stream << number[i];
	  }
		
		//combine the string together (for instance 0+1, 1+2 and so on)
		  string combinationOfNumbers=stream.str();

		  //insert all possible combinations of permutation one by one into the set
		  permutation.insert(combinationOfNumbers);
  } while ( std::next_permutation(number,number+n) ); //using next permutation method to generate all possible permutations

  //printing all the possible permutations into the screen using iterator
  for(set<string> ::iterator allPermutation=permutation.begin();allPermutation!=permutation.end();allPermutation++){
		cout<<*allPermutation<<' ';
  }
  system("pause");
  return 0;
}