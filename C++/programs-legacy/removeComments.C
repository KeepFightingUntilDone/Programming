#include <iostream>
#include <fstream>

using namespace std;

enum flag{NORMAL, DOUBLESLASH, SLASHSTAR};
char* removeComments(const char* input, flag& flagloop);


void removeCommentsFromFile(const char* fileName){
	ifstream ifs(fileName);
	if(!ifs.is_open()){
		cout<<"input file: "<<fileName<<" does not exist"<<endl;
		return;
	}
	char outputFileName[256] = {0};
	strcpy(outputFileName, fileName);
	strcat(outputFileName, ".out");
	ofstream ofs(outputFileName);
	if(!ofs.is_open()){
		cout<<"output file: "<<outputFileName<<" cannot be created"<<endl;
		return;
	}
	
	const int bufferLen = 10;
	char* buffer = new char[bufferLen+1];
	memset(buffer,0,bufferLen+1);
	
	int gcount = bufferLen;
	flag flagloop = NORMAL;
	while(gcount == bufferLen){
		ifs.read(buffer, bufferLen);
		gcount = ifs.gcount();

		char* output = removeComments(buffer, flagloop);
		if(output == NULL) break;
		ofs.write(output, strlen(output));
		delete []output;

		memset(buffer, 0, bufferLen+1);
	}
	
	delete []buffer;

	ifs.close();
	ofs.close();
	
}

char* removeComments(const char* input, flag& loopflag){
	if(input == NULL) return NULL;

	int bufferLen = strlen(input);
	const char* cursor = input;
	int start = 0;
	int end = 0;

	int base = 0;
	int sum = 0;

	char* result = new char[bufferLen + 1];
	memset(result, 0, bufferLen+1);

	while(*cursor != '\0'){
		if(*cursor == '/' && *(cursor+1) == '/' || loopflag==DOUBLESLASH){
			start = cursor-input;
			if(loopflag != DOUBLESLASH) cursor += 2;
			while(*cursor != '\n' &&  *cursor != '\0') cursor++;
			end = cursor - input;
			if(*cursor == '\0') loopflag = DOUBLESLASH;
			else loopflag = NORMAL;
		}
		else if(*cursor == '/' && *(cursor+1) == '*' || loopflag==SLASHSTAR){
			start = cursor - input;
			if(loopflag != SLASHSTAR) cursor += 2;
			while(*cursor != '*' || *(cursor+1) != '/'){
				if(*cursor == '\0') break;
				else cursor++;
			}
			if(*cursor != '\0') {cursor += 2; loopflag = NORMAL;}
			else loopflag = SLASHSTAR;
			end = cursor - input;
		}
		else{
			cursor ++;
		}

		if(start > base){
			memcpy(result+sum, input+base, start-base);
			sum += (start-base);
		}
		base = end;
	}

	if(input+end<cursor)
	{
		memcpy(result+sum, input+end, cursor-input-end);
	}

	//cout<<"result: "<<endl<<result<<endl;
	//delete []result;
	return result;
}

int main(int argc, char* argv[]){
	if(argc < 2) return 0;
	const char* fileName = argv[1];
	//const char* input = "hello\n//world\nnihao/*woshishui*/\nbushi //**//\ncross lines/*//\ncomments out\nshould be removed//?*/another line\nuncovered/*end";
	//cout<<"original:"<<endl<<input<<endl<<endl;
	//removeComments(input);
	removeCommentsFromFile(fileName);
	return 0;
}
