

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

/* Function to find LCA of n1 and n2. The function assumes that both 
n1 and n2 are present in BST */
Node *lca(Node* root, int n1, int n2) 
{ 
	while (root != NULL) 
	{ 
		// If both n1 and n2 are smaller than root, then LCA lies in left 
		if (root->data > n1 && root->data > n2) 
		root = root->left; 

		// If both n1 and n2 are greater than root, then LCA lies in right 
		else if (root->data < n1 && root->data < n2) 
		root = root->right; 

		else break; 
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



