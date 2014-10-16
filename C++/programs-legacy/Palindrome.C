#include <iostream>

using namespace std;

bool isPalindrome(const char* input, int start, int end){
	for(int i=start,j=end; i<j; i++, j--)
		if(input[i] != input[j])
			return false;

	return true; 
}

void getMaxPalindrome(const char* input){
	int maxPalindrome = 0;
	int start = 0;
	int end = 0;

	for(int i = 0; i<strlen(input); i++){
		for(int j=0; j<strlen(input); j++){
			int max = i>j?i:j;
			int min = i<j?i:j;
			if(isPalindrome(input, min, max)){
				int curPalindrome = max-min+1;
				if(curPalindrome > maxPalindrome){
					maxPalindrome = curPalindrome;
					start = min;
					end = max;
				}
			}
		}
	}	

	cout<<"max palindrome length: "<<maxPalindrome<<endl;
	
	if(maxPalindrome > 0){ 
		char* printBuffer = new char[maxPalindrome + 1];
		printBuffer[maxPalindrome] = '\0';
		strncpy(printBuffer, input+start, maxPalindrome);
		cout<<"the palindrome is: "<<printBuffer<<endl;
		delete []printBuffer;	
	}
	return ;
}

int main(int argc, char* argv[]){
	const char* input = "ABCDEDCB";
	//const char* input = "ABA";
	getMaxPalindrome(input);
	return 0;
}
