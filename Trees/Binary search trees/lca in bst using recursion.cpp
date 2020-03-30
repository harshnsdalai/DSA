

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

//This directly prints root data;
void lca_in_bst(Node* root, int n1, int n2)
{
	
	if (root->data>n1 && root->data>n2  && root->left)
	{
		
		lca_in_bst(root->left,n1, n2);
	}
	else if (root->data<n1 && root->data<n2  && root->right)
	{
		
		lca_in_bst(root->right,n1, n2);
	}
	else

		cout<<root->data;


}

//Return node pointer according to gfg question
Node* LCA(Node* root, int n1, int n2)
{
	
	if (root->data>n1 && root->data>n2  && root->left)
	{
		
		return LCA(root->left,n1, n2);
	}
	else if (root->data<n1 && root->data<n2  && root->right)
	{
		
		return LCA(root->right,n1, n2);
	}
	return root;


}

int main()
{
	struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
    lca_in_bst(root,10,14);
    
	
	return 0;
}



