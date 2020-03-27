

#include <bits/stdc++.h> 

using namespace std; 

// Node of a binary tree 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// function to get a new node 
Node* newNode(int data) 
{ 
	// allocate memory for the node 
	Node *newNode = 
		(Node*)malloc(sizeof(Node)); 
	
	// put in the data	 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode;	 
} 

void util(int &s, Node* root)
{
	if (!root)
	{
		return;
	}
	if (root->left && root->left->left==NULL && root->left->right==NULL)
	{
		s = s + root->left->data;
		//cout<<root->left->data<<"  " <<s<<endl;
	}
	util(s,root->left);
	util(s,root->right);
}

int leftLeavesSum(Node *root)
{
    int s = 0;
    util(s,root);
    return s;
}

// Driver program to test above 
int main() 
{ 
	// binary tree formation 
	struct Node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12); 
    cout << "Sum of left leaves is "
         << leftLeavesSum(root); 
    return 0; 
	
	cout << leftLeavesSum(root);
		
	return 0;	 
} 

