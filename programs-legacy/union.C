#include <iostream>
#include <unistd.h>

using namespace std;

bool IsBigendian()
{
	unsigned short usData = 0x1122;
	unsigned char  *pucData = (unsigned char*)&usData;

	return (*pucData == 0x22);
}


int main()
{
	union
	{
		unsigned int d;
		unsigned short u[2];
	}temp;
	temp.u[0] = 0x00;
	temp.u[1] = 0x01;
	
	cout<<temp.d<<endl;
	
	sleep(3);
	
	cout<<IsBigendian()<<endl;

	return 0;
}
