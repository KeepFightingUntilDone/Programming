#include <iostream>
#include <string>

using namespace std;

int BinarySearch(char* str, char target, int startIndex, int endIndex)
{
	// validate
	if (str == NULL) return -1;

	if (startIndex > endIndex) return -1;
	
	int midIndex = (endIndex + startIndex) / 2; 
	 
	if (str[midIndex] == target) return midIndex;
	else if (str[midIndex] < target) return BinarySearch(str, target, midIndex + 1, endIndex);
	else return BinarySearch(str, target, startIndex - 1, midIndex );
}

int BinarySearchIterative(char* str, char target, int startIndex, int endIndex)
{
	while (endIndex > startIndex)
	{
		int midIndex = (startIndex + endIndex) / 2;
		
		if (str[midIndex] == target) return midIndex;
		else if (str[midIndex] < target) startIndex = midIndex + 1;
		else endIndex = midIndex - 1;
	}

	return -1;
}

/*
int main()
{
	char* str = "123456789";
	cout << BinarySearch(str, '8', 0, strlen(str) - 1) << endl;
	cout << BinarySearchIterative(str, '8', 0, strlen(str) - 1) << endl;

	system("pause");
	return 0;
}
*/