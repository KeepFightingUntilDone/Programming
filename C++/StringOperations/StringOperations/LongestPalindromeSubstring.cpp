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

string longestPalindrome(string s)
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
    if (str.size() <= 1)
        return str;
    max = 0;
	string substr;
	const char* s = str.c_str();
	int n = str.size();

    for (i = 0; i < n; ++i) { // i is the middle point of the palindrome  
        for (j = 0; (i - j >= 0) && (i + j < n); ++j) // if the length of the palindrome is odd  
        if (s[i - j] != s[i + j])
            break;
		j--;
        if (j * 2 + 1 > max)
		{
            max = j * 2 + 1;
			substr = str.substr(i-j, max);
		}

        for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j) // for the even case  
        if (s[i - j] != s[i + j + 1])
            break;
		j--;
        if (j * 2 + 2 > max)
		{
            max = j * 2 + 2;
			substr = str.substr(i-j, max);
		}
    }
    //return max;
	return substr;
}

int main()
{
	string input;
	
/*
	input = "aabaa";
	cout<<longestPalindrome(input)<<endl;

	input = "aabbaa";
	cout<<longestPalindrome(input)<<endl;

	input = "aabba";
	cout<<longestPalindrome(input)<<endl;

	input = "baabb";
	cout<<longestPalindrome(input)<<endl;

	input = "aa";
	cout<<longestPalindrome(input)<<endl;

	input = "a";
	cout<<longestPalindrome(input)<<endl;
*/
	input = "ccd";
	cout<<longestPalindrome(input)<<endl;

	input = "abcdce";
	//cout<<longestPalindrome(input)<<endl;

	cout<<LongestPalindrome(input.c_str())<<endl;
	
	system("pause");
	return 0;
}