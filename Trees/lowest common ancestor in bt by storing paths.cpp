
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
///////////////////////////my original code
// void util(Node* root, int k, vector<int> &v, bool &iscorrectpath)
// {

// 	if (!root)
// 	{	
// 		return;
// 	}
// 	v.push_back(root->data);

// 	//If the path is correct we do not need to recurse further
// 	// and pass the root data(if node found) using the stack used by return fucntion in recursion.
// 	if (root->left && !iscorrectpath)//A good method to control recursion if some condition is met using bool;
// 	{
// 		util(root->left,k,v,iscorrectpath);
// 	}
// 	if (root->right && !iscorrectpath)
// 	{
// 		util(root->right,k,v,iscorrectpath);
// 	}
// 	if (root->data == k)
// 	{
// 		iscorrectpath = true;
// 	}
// 	if (!iscorrectpath)
// 	{
// 		//cout<<root->data<<"hhii";
// 		v.pop_back();
// 	}
	
// }
// void lca(Node* root, int n1,int n2)
// {
// 	vector<int> v1,v2;
// 	bool iscorrectpath1 = false,iscorrectpath2 = false;
// 	util(root,n1,v1,iscorrectpath1);
// 	util(root, n2, v2, iscorrectpath2);
// 	if (min(v1.size(),v2.size()) == 0)
// 	{
// 		cout<<"A node is not present in tree";
// 		return;
// 	}
// 	int size = max(v1.size(),v2.size());
// 	for (int i = 0; i <size ; ++i)
// 	{
// 		if (v1[i]!=v2[i])
// 		{
// 			cout<<v1[i-1];
// 			break;
// 		}
// 	}
    
// }

////////////////////////////////////////This code returns NODE pointer
void util2(Node* root, int k, vector<Node*> &v, bool &iscorrectpath)

{
	if (!root)
	{	
		return;
	}
	v.push_back(root);

	//If the path is correct we do not need to recurse further
	// and pass the root data(if node found) using the stack used by return fucntion in recursion.
	if (root->left && !iscorrectpath)//A good method to control recursion if some condition is met using bool;
	{
		util2(root->left,k,v,iscorrectpath);
	}
	if (root->right && !iscorrectpath)
	{
		util2(root->right,k,v,iscorrectpath);
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
Node* lca1(Node* root, int n1,int n2)
{
	vector<Node*> v1,v2;
	bool iscorrectpath1 = false,iscorrectpath2 = false;
	util2(root,n1,v1,iscorrectpath1);
	util2(root, n2, v2, iscorrectpath2);
	if (min(v1.size(),v2.size()) == 0)
	{
		cout<<"A node is not present in tree";
		return NULL;
	}
	int size = max(v1.size(),v2.size());
	for (int i = 0; i <size ; ++i)
	{
		if (v1[i]->data!=v2[i]->data)
		{
			return v1[i-1];
			
		}
	}
    
}


int main()
{
	Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(9);
    root->left->left = newNode(100);
    root->left->right = newNode(NULL);
    root->right->left = newNode(3);
    root->right->right = newNode(11);
    root->right->left->left = newNode(NULL);
    root->right->left->right = newNode(6);
    root->right->right->left = newNode(10);
    root->right->right->right = newNode(13);
    root->right->left->right->left = newNode(15);
    int n1 = 100,n2=1;

	//lca(root,n1,n2);
	cout<<lca1(root,n1,n2)->data;
	
	return 0;
}



