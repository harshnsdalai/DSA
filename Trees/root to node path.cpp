
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* nextRight;
};

struct Node* newNode(int data)
{
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node));

	Node->data = data;
	Node->left = Node->right = NULL;

	return Node;
}

void util(Node* root, int k, vector<int> &v, bool &iscorrectpath)
{

	if (!root)
	{	
		return;
	}
	v.push_back(root->data);

	//If the path is correct we do not need to recurse further
	// and pass the root data(if node found) using the stack used by return fucntion in recursion.
	if (root->left && !iscorrectpath)//A good method to control recursion if some condition is met using bool;
	{
		util(root->left,k,v,iscorrectpath);
	}
	if (root->right && !iscorrectpath)
	{
		util(root->right,k,v,iscorrectpath);
	}
	if (root->data == k)
	{
		iscorrectpath = true;
	}
	if (!iscorrectpath)
	{
		//cout<<root->data<<"hhii";
		v.pop_back();
	}
	
}
void ancestors(Node* root, int k)
{
	vector<int> v;
	bool iscorrectpath = false;
	util(root,k,v,iscorrectpath);
    //cout<<"harsh";
	for(auto x:v){
        cout<<x<<" ";
	}
}



int main()
{
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    int k = 4;

	ancestors(root,k);
	
	return 0;
}



