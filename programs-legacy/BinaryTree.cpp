#include <iostream>
#include <stack>

using namespace std;

const int NUL = -1;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createTree(int treeData[], int index, int length){
	if(index >= length) return NULL;

	int data = treeData[index];
	if(data == NUL) return NULL;
	
	TreeNode* node = new TreeNode();
	node->data = data;

	node->left = createTree(treeData, index*2 + 1, length);
	node->right = createTree(treeData, index*2 + 2, length);
	return node;
}

void printTreeRootFirst(TreeNode* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	printTreeRootFirst(root->left);
	printTreeRootFirst(root->right);
	return;
}

void destructTree(TreeNode* root){
	if(root == NULL) return;
	destructTree(root->left);
	destructTree(root->right);
	delete root;
	return;
}

void printTreeBreadthFirst(TreeNode* root){
	if(root == NULL) return ;

	//use two stacks to store the nodes for every level
	stack<TreeNode*> curStack;
	stack<TreeNode*> backupStack;

	curStack.push(root);
	int direction = 0;

	while(!curStack.empty()){
		TreeNode* node = curStack.top();
		curStack.pop();
		cout<<node->data<<" ";

		if(direction%2 == 0){
			if(node->left) backupStack.push(node->left);
			if(node->right) backupStack.push(node->right);
		}else{
			if(node->right) backupStack.push(node->right);
			if(node->left) backupStack.push(node->left);
		}

		if(curStack.empty()){
			//swap the current stack and backup stack
			cout<<endl;
			stack<TreeNode*> tmpStack = curStack;
			curStack = backupStack;
			backupStack = tmpStack;
			direction = (direction+1)%2; //avoid overflow
		}
	}

	return;
}


int main(int argc, char* argv[]){
	//5 test cases
	int treeData[5][31] = {
		NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,
		1,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,
		1,NUL,2,NUL,NUL,3,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,
		1,2,NUL,3,4,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,
		1,2,3,4,NUL,NUL,5,7,8,NUL,NUL,NUL,NUL,9,10,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,NUL,11,12
	};

	for (int i=0; i<5; i++){
		int *p = treeData[i];
		TreeNode* root = createTree(p, 0, 31);
		printTreeBreadthFirst(root);
		//printTreeRootFirst(root);
		cout<<"------------------------------"<<endl;
		destructTree(root);
	}

	system("pause");
	return 0;

}
