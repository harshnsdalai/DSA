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

void rightview(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int no_nodes_in_a_level = q.size();
		
		while(no_nodes_in_a_level !=0)
		{
			if (no_nodes_in_a_level==1)
			{
				cout<<q.front()->data<<" ";
			}
			no_nodes_in_a_level--;
			Node* head = q.front();
			//cout<<head->data;
			if (head->left != NULL)
				q.push(head->left); 
	  
	   
	        if (head->right != NULL) 
	            q.push(head->right);
			q.pop();
		}
		
	}


}

int main() 
{ 
	Node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 

	rightview(root);

	return 0; 
} 

// This code is contributed by Aditya Goel 
