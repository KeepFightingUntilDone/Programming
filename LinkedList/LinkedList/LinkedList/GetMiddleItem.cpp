#include <iostream>
#include <map>

using namespace std;

struct SinglyLinkedListNode
{
	int value;
	SinglyLinkedListNode* next;
};

class SinglyLinkedList
{
private:
	SinglyLinkedListNode* current;

public:
	SinglyLinkedList(SinglyLinkedListNode* head) { current = head; }

public:
	bool hasNext() const { return current != NULL && current->next != NULL; }
	SinglyLinkedListNode* next() { return current = current->next; }
};


SinglyLinkedListNode* GetMiddleElement(const SinglyLinkedList& list, SinglyLinkedListNode* head)
{
	SinglyLinkedListNode* middleElement = head; 
	int counter = 0;
	int middleElementValue = 0;

	if (NULL == head)
	{
		cout << "Middle Element: NULL" << endl;
		return NULL;
	}

    while (list.hasNext())
    {
		// Every two steps of list traverse, the middle element pointer move once
	   if (counter % 2 != 0)
	   {
		   middleElement = middleElement->next;
	   }
	   const_cast<SinglyLinkedList&>(list).next();
	   counter ++;
    }
    
	// Print here
	cout << "middle number: " << middleElement->value << endl;

    return middleElement;
}

SinglyLinkedListNode* ConstructLinkedList(int values[], int arrayLen, int constructNumber)
{
	// Recursively add nodes
	if (values == NULL || constructNumber > arrayLen || constructNumber <= 0) return NULL;

	SinglyLinkedListNode* newNode = new SinglyLinkedListNode;
	newNode->value = values[arrayLen - constructNumber];
	newNode->next = ConstructLinkedList(values, arrayLen, constructNumber - 1);

	return newNode;
}

int main()
{
	// All tests
	const int MAX_LENGTH = 10; // Change it as needed

	int test_values_array_normal[5] = {1, 2, 3, 4, 5};
	int test_values_array_even[2] = {1, 2};
	int test_values_array_single[1] = {1};
	int test_values_array_zero = 0;
	int* test_values_array_null = NULL;
	int test_values_array_verylong[MAX_LENGTH] = {1,2,3,4,5,6,7,8,9,10};

	// Put tests into a container (map here for simplicity, if want to execute tests in sequence we can use vector)
	typedef map<int*, int> TestSuiteMap;
	TestSuiteMap testSuite;
	TestSuiteMap::iterator testSuiteIter;

	testSuite[test_values_array_normal] = sizeof(test_values_array_normal)/sizeof(int);
	testSuite[test_values_array_even] = sizeof(test_values_array_even)/sizeof(int);
	testSuite[test_values_array_single] = sizeof(test_values_array_single)/sizeof(int);
	testSuite[&test_values_array_zero] = 0;
	testSuite[test_values_array_null] = 0;
	testSuite[test_values_array_verylong] = sizeof(test_values_array_verylong)/sizeof(int);

	// Traverse the container to execute every test
	for(testSuiteIter = testSuite.begin(); testSuiteIter != testSuite.end(); ++testSuiteIter)
	{
		SinglyLinkedListNode* head = ConstructLinkedList(testSuiteIter->first, testSuiteIter->second, testSuiteIter->second);
		SinglyLinkedList list(head);
		GetMiddleElement(list, head);
	}

	system("pause");
	return 0;
}