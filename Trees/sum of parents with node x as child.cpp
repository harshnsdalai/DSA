

#include <bits/stdc++.h> 

using namespace std; 

// Node of a binary tree 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// function to get a new node 
Node* getNode(int data) 
{ 
	// allocate memory for the node 
	Node *newNode = 
		(Node*)malloc(sizeof(Node)); 
	
	// put in the data	 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode;	 
} 

void funcutil(Node* root, int x, int &s)
{

	if (root==NULL)
	{
		return;							
	}

	if ((root->left && root->left->data == x) || 
        (root->right && root->right->data == x)) 
        s += root->data;
	
	funcutil(root->left,x,s);funcutil(root->right,x,s);


}
int func(Node* root, int x){
	int s = 0;
	funcutil(root,x,s);
	return s;
}


// Driver program to test above 
int main() 
{ 
	// binary tree formation 
	Node *root = getNode(4);		 /*	 4	 */
	root->left = getNode(2);		 /*	 / \	 */
	root->right = getNode(5);		 /*	 2 5	 */
	root->left->left = getNode(7);	 /*	 / \ / \	 */
	root->left->right = getNode(2); /* 7 2 2 3 */
	root->right->left = getNode(2); 
	root->right->right = getNode(3); 
	
	int x = 2; 
	
	cout << "Sum = "
		<< func(root, x); 
		
	return 0;	 
} 

