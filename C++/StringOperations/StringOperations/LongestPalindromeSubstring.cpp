#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const char* h, const char* t)
{
	if (h == NULL || t == NULL) return false;
	if (h >= t) return false;

	char* hh = const_cast<char*>(h);
	char* tt = const_cast<char*>(t);
	while (hh < tt)
	{
		if (*hh != *tt) return false;
		hh ++;
		tt --;
	}

	return true;
}

string LongestPalindrome_Wrong(string s)
{
	if (s.size() == 0 || s.size() == 1) return s;

	const char* p = s.c_str();

	char* h = (char*)&p[0];
	char* t = (char*)&p[s.size() - 1];

	while (h < t)
	{
		if (isPalindrome(h, t)) return s.substr(h-p, t-h+1);
		else if (isPalindrome(h+1, t)) return s.substr(h+1-p, t-h);
		else if (isPalindrome(h, t-1)) return s.substr(h-p, t-h);
		else {h++; t--;}
	}
}

string LongestPalindrome(string str)
{
    int i, j, max;

    max = 0;
	string substr;
	const char* s = str.c_str();
	int n = str.size();

    for (i = 0; i < n; ++i) 
	{ 
		// i is the middle point of the palindrome  

		// if the length of the palindrome is odd 
		int j = 1;
		while (i - j >= 0 && i + j < n && s[i - j] == s[i + j])
			j ++;
		j --;
        if (j * 2 + 1 > max)
		{
            max = j * 2 + 1;
			substr = str.substr(i-j, max);
		}

		// if the length of the palindrome is even
		j = 0;
		while (i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1])
			j ++;
		j --;
		if (j * 2 + 2 > max)
		{
            max = j * 2 + 2;
			substr = str.substr(i-j, max);
		}
    }
	return substr;
}

/*
int main()
{
	string input;
	
	input = "aabaa";
	cout<<LongestPalindrome(input)<<endl;

	input = "aabbaa";
	cout<<LongestPalindrome(input)<<endl;

	input = "aabba";
	cout<<LongestPalindrome(input)<<endl;

	input = "baabb";
	cout<<LongestPalindrome(input)<<endl;

	input = "aa";
	cout<<LongestPalindrome(input)<<endl;

	input = "a";
	cout<<LongestPalindrome(input)<<endl;

	input = "ccd";
	cout<<LongestPalindrome(input)<<endl;

	input = "abcdce";
	cout<<LongestPalindrome(input)<<endl;

	input ="aaa";
	cout<<LongestPalindrome(input)<<endl;
	
	system("pause");
	return 0;
}
*/