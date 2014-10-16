#include <stdio.h>

void myFunction(int offsite, int data)
{
	int buffer[16] = {0};
	buffer[offsite] = data;
	printf("hello world\n");
}

void /*__stdcall*/ otherFunction(int param)
{
	*(int*)(&param-1) = (int) myFunction + 0;
	printf("hello adobe\n");
}

int main(int argc, char argv[])
{
	myFunction(18, (int)otherFunction);
	return 0;
}
