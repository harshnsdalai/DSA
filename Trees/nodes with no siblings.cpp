
// C++ implementation to find the sum of all 
// the parent nodes having child node x 
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

void util(Node* root, set<int> &s)
{
	if (!root)
	{
		return;
	}
	if (!root->left && root->right)
	{
		s.insert(root->right->data);
	}
	if (root->left && !root->right)
	{
		s.insert(root->left->data);
	}
   util(root->left,s);
   util(root->right,s);
}

void printSibling(Node* root)
{
	if (root->left==NULL && root->right==NULL)
	{
		cout<<-1<<endl;
		return;
	}
	set<int> s;
	util(root, s);
	
	for(auto x: s){
		cout<<x<<" ";
	}
}



// Driver program to test above 
int main() 
{ 
	// binary tree formation 
	Node *root = newNode(1); 
    root->left = newNode(2); 
    //root->right = newNode(3); 
    root->left->right = newNode(5); 
    root->left->left = newNode(4); 

    printSibling(root);
		
	return 0;	 
} 

