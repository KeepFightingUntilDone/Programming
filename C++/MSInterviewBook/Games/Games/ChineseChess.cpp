#include <iostream>
#include <string>

using namespace std;

void DoByTwoVariables()
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i % 3 != j % 3)
			{
				cout << ++count << ": (A=" << i+1 << ", B=" << j+1 << ")" << endl;
			}
		}
	}
}

void DoByOneVariableWithBits()
{
	char a = 0;
	int count = 0;
	
	while ((a & 0x0f) <= 8)
	{
		while (((a & 0xf0) >> 4) <= 8)
		{
			if ((a & 0x0f) % 3 != ((a & 0xf0) >> 4) % 3)
			{
				cout << ++count << ": (A=" << ((a & 0x0f) + 1) << ", B=" << (((a & 0xf0) >> 4) + 1) << ")" << endl;
			}

			a += 0x10;
		}
		
		a &= 0x0f;
		a += 0x01;
	}
}

/*
int main()
{
	// DoByTwoVariables();
	DoByOneVariableWithBits();

	system("pause");
	return 0;
}
*/