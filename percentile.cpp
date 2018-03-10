#include<iostream>
#include<math.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//create a method percentile to calculate the 25th,50th and 75th percentile
double percentile (double percent, int totalNumInFile) {
	double percentile= totalNumInFile*percent; //calculate the percentile based on total number in file
											   //formula is total number times 0.25 or 0.5 or 0.75
		return percentile;
}
int main() {
	
	//generate/open a file data.txt
	ifstream dataFile("data.txt");
	//initialize variable j for counter
	int j=0;
	//initialize variable to put all the numbers one by one from file
	int number;
	//initialize variable for the first number in the file for total numbers in file
	int totalNumber;
	//put that number from data file into the variable totalNumber
	dataFile >> totalNumber;
	//initialize an array with pointer to put all the numbers into an array
	int* listOfNumbers=new int[totalNumber];

	//a while loop to put all the numbers from file into an array
	while (!dataFile.eof()) {
		dataFile >> number;/* Process number... */
		listOfNumbers[j]=number;
		++j;
	}

	//using sort method from c++ library to sort all the numbers in the array
	sort(listOfNumbers,listOfNumbers+totalNumber);
	
	//calculate the percentiles for 25th,50th and 75th using the method "percentile"
	double firstPercentile=percentile(0.25,totalNumber);
	double fiftyPercentile=percentile(0.25*2,totalNumber);
	double lastPercentile=percentile(0.75,totalNumber);

	//convert all the numbers into an integer
	int convertedFirst=int(firstPercentile);
	int convertedSecond=int(fiftyPercentile);
	int convertedThird=int(lastPercentile);

	//output the 25th, 50th and 75th percentile based on the index of array. 
	//since they are different on each case of totalNumber in file, use if statement to justify 
	//which index of array to output
	if (totalNumber%4==0) {
		cout<<listOfNumbers[convertedFirst-1]<<endl;
		cout<<listOfNumbers[convertedSecond-1]<<endl;
		cout<<listOfNumbers[convertedThird-1]<<endl;
	}
	else if (totalNumber%2==0) {
		cout<<listOfNumbers[convertedFirst]<<endl;
		cout<<listOfNumbers[convertedSecond-1]<<endl;
		cout<<listOfNumbers[convertedThird]<<endl;
	}
	else {
		cout<<listOfNumbers[convertedFirst]<<endl;
		cout<<listOfNumbers[convertedSecond]<<endl;
		cout<<listOfNumbers[convertedThird]<<endl;
	}

	system("PAUSE");
	return 0;
}