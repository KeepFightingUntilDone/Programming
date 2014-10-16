#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void IsBigendian()
{
	unsigned short usData = 0x1122;
	unsigned char  *pucData = (unsigned char*)&usData;

	if (*pucData == 0x22)
	{
		cout<<"Big Endian"<<endl;
	}
}

void PrintUnion()
{
	union
	{
		unsigned int d;
		unsigned short u[2];
	}temp;
	temp.u[0] = 0x00;
	temp.u[1] = 0x01;
	
	cout<<temp.d<<endl;
}

void RevertArray()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	cout<<"original array is:"<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout<<a[i][j]<<", ";
		cout<<endl;
	}

	for(int i=0; i<3; i++)
	{
		for(int j=i; j<3; j++)
		{
			if (i == j) break;

			int swap = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = swap;
		}
	}
	
	cout<<"reverted array is:"<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout<<a[i][j]<<", ";
		cout<<endl;
	}
}

void WriteFileLines()
{
	ofstream outfile("ExcerptDOI.txt");

    outfile << "We hold these truths to be self-evident";

    outfile.close();
}

void ReadFileLines()
{
    ifstream infile("StrongSayNothing.txt");

	string line;
    while (infile.peek() != EOF) {
        
        getline(infile, line);
		
        cout <<line<< endl;
    }

    infile.close();
}

void WriteFileBinary()
{
	//Set flag to make the file binary
	fstream outfile("Data.dat", ios::out | ios::binary);

    const unsigned int count = 3;
    int iaArray[count] = {1, 2, 3};
    for (unsigned int i = 0; i < count; ++i) {
        outfile.write((char*)&(iaArray[i]), sizeof(int));
    }

    outfile.close();
}

void ReadFileBinary()
{
    //Set flags to make this a binary file
    fstream infile("Data.dat", ios::in | ios::binary);

    while (infile.peek() != EOF) {
        int iRead;
        infile.read((char*)&iRead, sizeof(int)); //since type for writing was char*
        cout << iRead << endl;
    }

    infile.close();
}

void ReadWriteFileByte()
{
    ifstream infile("Original.txt");
    ofstream outfile("Copy.txt");
    char cChar;
    while (infile.get(cChar))
        outfile.put(cChar);
}

void GetFileSize()
{
	ifstream infile("ThoseWhoGrant.txt");
    infile.seekg(0);
    fstream::pos_type start = infile.tellg();
    infile.seekg(0, ios::end);
    fstream::pos_type end = infile.tellg();
    cout << (end - start) << endl;
    infile.close();
}
