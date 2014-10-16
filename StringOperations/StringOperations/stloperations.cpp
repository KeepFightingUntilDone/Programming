#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

#include <string>
#include <iostream>

using namespace std;

/*
vector Array 
list Doubly-linked list 
slist Singly-linked list 
queue FIFO (first-in, first-out) structure 
deque Array-like structure, with efficient insertion and removal at both ends 
set Set of unique elements 
stack LIFO (last in, first out) structure 
*/

/*
	access
	insert (insertToIndex)
	find (getItem, getIndex)
	delete (deleteItem, deleteIndex)
*/

void StackOperations()
{
	stack<string> testStack;

	//insert
	testStack.push("hello");

	//access (can only access the top item)
	string stackPop = testStack.top();  //can only access the top item
	cout<<stackPop<<endl;

	//no iterator, no find functions

	//delete
	testStack.pop(); // This removes the top item
}

void QueueOperations()
{
	queue<string> testQueue;

	//insert (can only push, no push_back) 
	testQueue.push("hello");
	testQueue.push("world");

	//access (front and back)
	string queueFront = testQueue.front();
	string queueBack = testQueue.back();
	cout<<queueFront<<endl;
	cout<<queueBack<<endl;

	//no iterator, no find function

	//delete (can only delete the first one)
	testQueue.pop();
	queueFront = testQueue.front();
	cout<<queueFront<<endl;
}

void ListOperations()
{
	list<string> testList;
	list<string>::iterator it;
	list<string>::reverse_iterator it_reverse;

	//insert (to front and back, and particular position)
	testList.push_back("hello");
	testList.push_front("world");
	it = testList.begin();
	testList.insert(it, 2, "nihao"); //insert 2 "nihao" before the begin pos
	for (it=testList.begin(); it!=testList.end(); ++it) cout << ' ' << *it;
	cout<<endl;

	it = testList.begin();
	advance(it, 2);  //double linked list dont have a [] operator
	testList.insert(it, "woyehao"); //insert 1 "woyehao" before the third pos
	for (it=testList.begin(); it!=testList.end(); ++it) cout << ' ' << *it;
	cout<<endl;

	//access (use iterator)

	//find (getItem, getIndex)
	it = find(testList.begin(), testList.end(), "woyehao");  //list itself does not have a find method, but can use Algorithm in std library
	cout<<distance(testList.begin(), it)<<"---"<<*it<<endl;  //get the index of a given item

	//delete (use iterator, or item value)
	testList.erase(it);
	testList.remove("nihao"); //this removes all "nihao"
	for (it=testList.begin(); it!=testList.end(); ++it) cout << ' ' << *it;
	cout<<endl;
}

void VectorOperations()
{
	vector<string> testVector;

	//insert (only to back, and particular position)
	testVector.push_back("hello");
	testVector.push_back("world");
	for(int i=0; i<testVector.size(); i++) cout<<" "<<testVector[i];
	cout<<endl;

	vector<string>::iterator it = testVector.begin();  //same with list
	advance(it, 1);
	testVector.insert(it, "nihao");
	for(int i=0; i<testVector.size(); i++) cout<<" "<<testVector[i];
	cout<<endl;

	//access (using either iterator or [])

	//find (using iterator)
	it = find(testVector.begin(), testVector.end(), "nihao");  //same with vector
	cout<<distance(testVector.begin(), it)<<"----"<<*it<<endl;

	//delete (use iterator only, no remove function)
	testVector.erase(it);
	for(int i=0; i<testVector.size(); i++) cout<<" "<<testVector[i];
	cout<<endl;
}

void MapOperations()
{
	map<int, string> testMap;
	map<int, string>::iterator it;
	
	//insert (only have insert, no push***)
	pair<map<int,string>::iterator,bool> ret;
	ret = testMap.insert(pair<int, string>(500,"hello"));
	if (ret.second == false)
	{
		cout<<"First time: the item has been existing already"<<endl;
	}
	ret = testMap.insert(pair<int, string>(500,"world"));
	if (ret.second == false)
	{
		cout<<"Second time: the item has been existing already"<<endl;
	}

	//access (use iterator only)
	for (it=testMap.begin(); it!=testMap.end(); ++it) cout<<it->first<<" => "<<it->second<<endl;

	//find (map supports find function, and [] operator)
	cout<<testMap[500]<<endl;
	it = testMap.find(500);
	cout<<it->first<<" => "<<it->second<<endl;

	//delete
	testMap.erase(it);
	cout<<testMap.size()<<endl;
}

void HashMapOperations()
{
	//Hash is called unordered_map in C++ stl  (usage is exactly the same as map)
	unordered_map<int, string> testHashMap;
	unordered_map<int, string>::iterator it;

	//insert 
	pair<unordered_map<int,string>::iterator,bool> ret;
	ret = testHashMap.insert(pair<int, string>(500,"hello"));
	if (ret.second == false)
	{
		cout<<"First time: the item has been existing already"<<endl;
	}
	ret = testHashMap.insert(pair<int, string>(500,"world"));
	if (ret.second == false)
	{
		cout<<"Second time: the item has been existing already"<<endl;
	}

	//access (use iterator only)
	for (it=testHashMap.begin(); it!=testHashMap.end(); ++it) cout<<it->first<<" => "<<it->second<<endl;

	//find (map supports find function, and [] operator)
	cout<<testHashMap[500]<<endl;
	it = testHashMap.find(500);
	cout<<it->first<<" => "<<it->second<<endl;

	//delete
	testHashMap.erase(it);
	cout<<testHashMap.size()<<endl;
}

void SetOperations()
{
	set<string> testSet;
	set<string>::iterator it;

	//insert (like map)
	pair<set<string>::iterator,bool> ret;
	ret = testSet.insert("hello");
	if (ret.second == false)
	{
		cout<<"First time: the item has been existing already"<<endl;
	}
	ret = testSet.insert("hello");
	if (ret.second == false)
	{
		cout<<"Second time: the item has been existing already"<<endl;
	}

	//access (use iteractor only)
	for (it=testSet.begin(); it!=testSet.end(); ++it) cout<<*it<<endl;

	//find (supports find function, so it should be implemented by map underhood)
	it = testSet.find("hello");
	cout<<*it<<endl;

	//delete
	testSet.erase(it);
	cout<<testSet.size()<<endl;
}

void StringOperations()
{
	string testString ("nishishui,woshinidie");
	//string str ("needle");
	string str = "nidie";

	//find
	size_t found = testString.find(str);
	if (found != string::npos)
		cout<<"first thing found at: "<<found<<'\n';
	else 
		cout<<"did not find anything anywhere"<<endl;

	//substring
	string substr = testString.substr(found, testString.size() - found);   
	cout<<substr<<endl;
	//same with above
	substr = testString.substr(found);
	cout<<substr<<endl;
}

int main()
{
	//StackOperations();
	//QueueOperations();
	//ListOperations();
	//VectorOperations();
	//MapOperations();
	//HashMapOperations();
	//SetOperations();
	StringOperations();

	system("pause");
}
