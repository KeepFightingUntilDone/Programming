#include <string>
#include <iostream>

using namespace std;

int getSubstring(const char* originalString, const char* pattern)
{
	// TODO: validation
	char* originalCursor = const_cast<char*>(originalString);
	char* patternCursor = const_cast<char*>(pattern);

	while(*originalCursor != '\0')
	{
		while(*patternCursor != '\0')
		{
			if (*patternCursor != *originalCursor)
			{
				originalCursor -= patternCursor - pattern;
				break;
			}
			else
			{
				originalCursor ++;
				patternCursor ++;
			}
		}

		if (*patternCursor == '\0')
		{
			// FOUND
			return originalCursor - originalString - strlen(pattern);
		}
		else
		{
			originalCursor ++;
			patternCursor = const_cast<char*>(pattern);
		}
	}

	return -1;
}

/*
int main()
{
	const char* original = "hello world";
	const char* pattern = "world";

	cout<<getSubstring(original, pattern)<<endl;

	system("pause");

	return 0;
}
*/