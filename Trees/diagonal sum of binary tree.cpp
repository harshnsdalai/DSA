// C++ Program to find diagonal 
// sum in a Binary Tree 
#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

struct Node* newNode(int data) 
{ 
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node)); 
	
	Node->data = data; 
	Node->left = Node->right = NULL; 

	return Node; 
} 

void util(Node* root,  int d, map<int, int> &m)
{
	if (!root)
	{
		return;
	}

	m[d] = m[d] + root->data;


	util(root->left, d+1,m);
	util(root->right, d, m );
}


void diagonalSum(Node* root)
{
	int s = 0;
	map<int, int> m;
	util(root, 0,m);
	
	for(auto x: m){
		cout<<x.second<<" ";
	}
}

int main() 
{ 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(9); 
	root->left->right = newNode(6); 
	root->right->left = newNode(4); 
	root->right->right = newNode(5); 
	root->right->left->right = newNode(7); 
	root->right->left->left = newNode(12); 
	root->left->right->left = newNode(11); 
	root->left->left->right = newNode(10); 

	diagonalSum(root); 

	return 0; 
} 

// This code is contributed by Aditya Goel 
