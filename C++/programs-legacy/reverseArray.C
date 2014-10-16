#include <string>
#include <iostream>

using namespace std;

void printArray(int a[][3], int rowlen, int collen)
{
	for(int i=0; i<rowlen; i++)
	{
		for(int j=0; j<collen; j++)
		{
			cout<<a[i][j]<<", ";
		}
		cout<<endl;
	}
}

int main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	cout<<"original array is:"<<endl;
	printArray(a, 3, 3);
	
	for(int i=0; i<3; i++)
	{
		for(int j=i; j<3; j++)
		{
			if (i == j) break;

			int swap = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = swap;
		}
	}
	
	cout<<"reverted array is:"<<endl;
	printArray(a, 3, 3);
}
