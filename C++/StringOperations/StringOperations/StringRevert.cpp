#include <string>
#include <iostream>

using namespace std;

string revertString(string input)
{
	// TODO: validation

	char* begin = const_cast<char*>(input.c_str());
	char* end = begin + input.size() - 1;
	
	for(char* begincursor = begin, *endcursor = end; begincursor < endcursor; begincursor ++, endcursor --)
	{
		char tmp = *begincursor;
		*begincursor = *endcursor;
		*endcursor = tmp;
	}

	return string(begin);
}

/*
int main()
{
	string input = "qianshanwanshui";

	cout<<revertString(input)<<endl;

	system("pause");

	return 0;
}
*/