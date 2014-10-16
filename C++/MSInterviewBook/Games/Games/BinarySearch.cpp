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

char find_ins_point(const char* sortedStr, unsigned int sortedStrLength, char c)
{
	// Validation as above

	// Check the last element first
	char notfound = sortedStr[0];
	if (sortedStr[sortedStrLength - 1] <= c) return notfound;

	// Binary search
	int startIndex = 0, endIndex = sortedStrLength - 1;
	bool found = false;

	while (endIndex > startIndex)
	{
		int midIndex = (startIndex + endIndex) / 2;
		
		if (sortedStr[midIndex] <= c)
		{
			startIndex = midIndex + 1;
		}
		else if (sortedStr[midIndex] > c) 
		{
			endIndex = midIndex - 1;
		}
	}

	return sortedStr[startIndex == endIndex ? startIndex + 1 : startIndex];
}

/*
int main()
{
	char* str1 = "123456789";
	cout << BinarySearch(str1, '8', 0, strlen(str1) - 1) << endl;
	cout << BinarySearchIterative(str1, '8', 0, strlen(str1) - 1) << endl;

	char* str2 = "abcdeeeeeeeeefv";
	cout << find_ins_point(str2, strlen(str2), 'e') << endl;

	system("pause");
	return 0;
}
*/