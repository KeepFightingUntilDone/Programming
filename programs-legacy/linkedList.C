#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* createList(int array[10], int length)
{
	Node* head = NULL;
	Node* cur = head;
	
	//very intresting
	//cout<<"array length in function: "<<sizeof(array)/sizeof(int)<<endl;

	for(int i=0; i<length; i++)
	{
		Node* newNode = new Node();
		newNode->data = array[i];
		
		if(head == NULL) 
		{
			head = newNode;
			cur = head;
		}
		else
		{
			cur->next = newNode;
			cur = cur->next;
		}
	}
	cur->next = NULL;
	return head;
}

Node* createListRecurrence(int array[], int length, int num)
{
	if(num == 0) return NULL;
	Node* newNode = new Node();
	newNode->data = array[length - num];
	newNode->next = createListRecurrence(array, length, num-1);
	return newNode;
}	


Node* reverseList(Node* head)
{
	if(head == NULL) return NULL;
	Node* pre = head;
	Node* cur = head;
	Node* post = head->next;

	while(cur != NULL && post != NULL){
		cur = post;
		post = post->next;
		cur->next = pre;
		pre = cur;
	}

	head->next = NULL;
	head = cur;	
	return head;
}

Node* reverseListRecurrence(Node* cur, Node*& head)
{
	//if(cur == NULL) return NULL;
	if(cur->next == NULL){
		head->next = NULL;
		head = cur;
		return cur;
	}

	Node* post = reverseListRecurrence(cur->next, head);
	post->next = cur;
	//cur->next = NULL;

	return cur;
}
	
Node* mergeLists(Node* listA, Node* listB)
{
	if(listA == NULL) return listB;
	else if(listB == NULL) return listA;

	Node* p = listA;
	Node* q = listB;
	Node* cur = new Node();
	Node* head = cur;
	head->data = 0;
	
	while(p != NULL && q != NULL){
		if(p->data < q->data){
			cur->next = p;
			cur = p;
			p = p->next;
		}else{
			cur->next = q;
			cur = q;
			q = q->next;
		}
	}
	if(p == NULL) cur->next = q;
	else if(q == NULL) cur->next = p;

	return head;
}

Node* mergeLists2(Node* listA, Node* listB){
	if(listA == NULL) return listB;
	else if(listB == NULL) return listA;

	Node* p = listA;
	Node* q = listB;
	Node* cur = new Node();
	Node* head = cur;
	head->data = 0;
	
	while(p!=NULL && q!=NULL){
		while(p != NULL && p->data < q->data){
			cur = p;
			p = p->next;
		}
		cur->next = q;
		if(p != NULL){
			cur = q;
			//swap p and q
			Node* tmp = p;
			p = q;
			q = tmp;
		}
	}

	return head;
}
			

void printList(Node* head)
{
	Node* cur = head;
	while(cur != NULL)
	{
		cout<<cur->data;
		if(cur->next != NULL) cout<<" -> ";
		cur = cur->next;
	}
	cout<<endl;
	return;
}


int main(int argc, char* argv[])
{
	cout<<"hello world"<<endl;

	//int array[10] = {0,1,2,3,4,5,6,7,8,9};
	//int array[2] = {0,1};
	//int array[1] = {0};

	//very interesting
	//cout<<"array length: "<<sizeof(array)/sizeof(int)<<endl;

	//Node* listHead = createList(array, sizeof(array)/sizeof(int));
	//Node* listHead = createListRecurrence(array, sizeof(array)/sizeof(int), sizeof(array)/sizeof(int));
	//printList(listHead);

	//Node* reversedHead = reverseList(listHead);
	//Node* cur = listHead;
	//reverseListRecurrence(cur, listHead);
	//printList(listHead);

	int array1[10] = {2,5,6,7,8,11,12,14,15,16};
 	int array2[6] = {1,3,4,9,10,13};

	Node* listA = createList(array1, sizeof(array1)/sizeof(int));
	Node* listB = createListRecurrence(array2, sizeof(array2)/sizeof(int), sizeof(array2)/sizeof(int));

	printList(listA);
	cout<<endl;
	printList(listB);
	//Node* listC = mergeLists(listA, listB);
	Node* listC = mergeLists2(listA, listB);
	cout<<endl;
	printList(listC);

	return 0;
}
