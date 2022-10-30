//  Andres Choque Lab 2 A Splice Arrays 

#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
int getPositiveInteger();
void fillarray(int* , int);
int* splice(int*, int, int*, int, int);
void printResults(int*, int, int*, int, int*);

int main()
{
	int arraySize1 = 0, arraySize2 = 0, splicePoint = 0;
	int* array1; 
	int* array2; 
	cout << "Splice Arrays Program \n";
	cout << "Enter the size of the First array:\n";
	arraySize1 = getPositiveInteger();
	cout << "Enter the size of the Second array:\n";
	arraySize2 = getPositiveInteger();
	cout << "Enter the Splice Point:\n";
	splicePoint = getPositiveInteger();
	while(splicePoint > arraySize1)
	{
		splicePoint = getPositiveInteger();
	}
	array1 = new int[arraySize1];
	array2 = new int[arraySize2];
	srand(100);
	fillarray(array1, arraySize1);
	fillarray(array2, arraySize2);
	int* mergedArray = splice(array1, arraySize1, array2, arraySize2, splicePoint);
	printResults(array1, arraySize1, array2, arraySize2, mergedArray);
	delete[] array1;
	delete[] array2;
	delete[] mergedArray;
}

int getPositiveInteger()
{
	int positiveInteger = 0;
	cout << "Enter a positive integer\n";
	cin >> positiveInteger;
	while (cin.fail() || positiveInteger <= 0)
	{
		cout << "Enter a positive integer\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> positiveInteger;
	}
	return positiveInteger;
}

void fillarray(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		array[i] = rand() % 100;
	
}

int* splice(int* firstArray, int firstArraySize, int* secondArray, int secondArraySize, int spliceLocation)
{
	int* arrayMerged;
	arrayMerged = new int[firstArraySize + secondArraySize];
	for (int i = 0; i < spliceLocation; i++)
		arrayMerged[i] = firstArray[i];
	for (int i = 0; i < secondArraySize; i++)
		arrayMerged[spliceLocation + i] = secondArray[i];
	for (int i = spliceLocation; i < firstArraySize; i++)
		arrayMerged[secondArraySize + i] = firstArray[i];
	return arrayMerged;
}

void printResults(int* array1, int arraySize1, int* array2, int arraySize2, int* mergedArray)
{
	cout << "\nArray 1: \n";
	for (int i = 0; i < arraySize1; i++)
		cout << array1[i] << " ";
	cout << "\nArray 2: \n";
	for (int i = 0; i < arraySize2; i++)
		cout << array2[i] << " ";
	cout << "\nMerged Array: \n";
	for (int i = 0; i < (arraySize1 + arraySize2); i++)
		cout << mergedArray[i] << " ";
}