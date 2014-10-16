#include <iostream>

int MAX[8] = {0};
int PRE[8] = {0};
int counter = 0;

int getLargestChildArray(int* array, int size, int index){
	if(index == 0) return array[0];
	if(MAX[index] != 0) return MAX[index];

	std::cout<<"L1 counter: "<<counter++<<std::endl;

	int a = array[index];
	int b = getLargestChildArray(array, size, index-1);

	if(b<0){
		MAX[index] = a;
		PRE[index] = 0;
	}else{
		MAX[index] = a+b;
		PRE[index] = index-1;
	}

	return MAX[index];
}

int getLargestChildArray(int* array, int size){
	getLargestChildArray(array, size, size-1);
	int max = 0;
	int index = 0;
	for(int i=0; i<size; i++)
		if(max < MAX[i]) {max = MAX[i];index = i;}

	while(index){
		std::cout<<index<<"--->";
		index = PRE[index];
	}
	std::cout<<std::endl;
	return max;
}

int getLongestSequence(int* array, int size, int index){
	if(index == 0) return 1;
	if(MAX[index] != 0) return MAX[index];

	std::cout<<"L2 counter: "<<counter++<<std::endl;

	int max = 0;
	int pre = 0;
	bool found = false;
	for(int j=0; j<index; j++){
		int cur = getLongestSequence(array, size, j);
		if(array[index] > array[j]) cur += 1;
		if(cur > max) {max = cur; pre = j; found = true;}
	}
	if(found){
		MAX[index] = max;
		PRE[index] = pre;
	}else{
		MAX[index] = 1;
		PRE[index] = 0;
	}

	return max;
}

int getLongestSequence(int* array, int size){
	memset(MAX, 0, 8*4);
	memset(PRE, 0, 8*4);
	counter = 0;
	getLongestSequence(array, size, size-1);

	int max = 0;
	int index = 0;
	for(int i=0; i<size; i++)
		if(max < MAX[i]) {max = MAX[i];index = i;}

	while(true){
		std::cout<<index<<"--->";
		if(index == 0) break;
		index = PRE[index];
	}

	std::cout<<std::endl;

	return max;
}

int main(){
	std::cout<<"hello world"<<std::endl;
	int array[8] = {-3,2,1,4,3,-6,8,-14};
	std::cout<<"largest child array: "<<getLargestChildArray(array, 8)<<std::endl;
	std::cout<<"longest child sequence: "<<getLongestSequence(array, 8)<<std::endl;

	return 0;
}
