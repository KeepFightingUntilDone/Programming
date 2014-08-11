#include <iostream>
#include <string>

using namespace std;

void Reverse(int*& LaoBingArray, int startIndex, int endIndex)
{
	for (int i = startIndex, j = endIndex; i < j; i++, j--)
	{
		int tmp = LaoBingArray[i];
		LaoBingArray[i] = LaoBingArray[j];
		LaoBingArray[j] = tmp;
	}
}

int FindMaxIndex(int* LaoBingArray, int arrayLen)
{
	if (arrayLen <= 0) return 0;

	int max = LaoBingArray[0];
	int maxIndex = 0;

	for (int i = 0; i < arrayLen; i++)
	{
		if (max < LaoBingArray[i])
		{
			max = LaoBingArray[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

bool AlreadySorted(int LaoBingArray[], int arrayLen)
{
	for (int i = 1; i < arrayLen; i++)
	{
		if (LaoBingArray[i] < LaoBingArray[i - 1]) return false;
	}
	 
	return true;
}

void LaoBingSort(int LaoBingArray[], int arrayLen)
{
	if (AlreadySorted(LaoBingArray, arrayLen)) return;

	int maxItemIndex = FindMaxIndex(LaoBingArray, arrayLen);
	int startIndex = 0;

	if (maxItemIndex == arrayLen - 1)
	{
		return LaoBingSort(LaoBingArray, arrayLen - 1);
	}
	else
	{
		if (maxItemIndex > startIndex)
		{
			Reverse(LaoBingArray, startIndex, maxItemIndex);
		}
		Reverse(LaoBingArray, startIndex, arrayLen - 1);
	}

	LaoBingSort(LaoBingArray, arrayLen - 1);
}

/*
int main()
{
	int LaoBingArray[8] = { 2, 4, 1, 8, 13, 9, 3, 7 };
	LaoBingSort(LaoBingArray, 8);

	for (int i = 0; i < 8; i++) cout << LaoBingArray[i] << " " << endl;
	system("pause");
	return 0;
}
*/