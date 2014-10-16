#include <iostream>

using namespace std;

const int LEN = 5;

bool getBitValue(int pos, int value){
	int mask = 1;
	value >>= pos;
	return mask&value;
}
int main(int argc, char* argv[]){
	char array[LEN] = {'a', 'b', 'c', 'd', 'e'};
	int start = 0;
	int end = 1<<LEN;
	for(int i=start; i<end; i++){
		cout<<i<<": ";
		for(int j=0; j<LEN; j++){
			cout<<char(array[j]-32*getBitValue(j,i));
		}
		cout<<endl;
	}
				
	return 0;
}
