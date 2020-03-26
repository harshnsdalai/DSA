	// C++ Program to find diagonal 
// sum in a Binary Tree 
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


void connect(Node *p)
{
   queue<Node*> q;
   q.push(p);
   
   while(!q.empty())
   {
   		Node* curr = q.front();
   		q.pop();
   		//cout<<curr->data;
   		curr->nextRight = q.front();
   		if (curr->left)
   		{

   			q.push(curr->left);
   		}

   		if (curr->right)
   		{
   			q.push(curr->right);
   		}

   		
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

	connect(root); 

	return 0; 
} 

// This code is contributed by Aditya Goel 

