
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

void leftview(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int no_nodes_in_a_level = q.size();
		cout<<q.front()->data<<" ";
		while(no_nodes_in_a_level !=0)
		{
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
	 Node *root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(5); 
    root->left->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(25); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14);

	leftview(root);

	return 0; 
} 

