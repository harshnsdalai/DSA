
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


void connect(struct Node* root) 
{ 
    queue<Node*> q; 
    q.push(root); 

    q.push(NULL);  

    while (!q.empty()) { 
        Node *curr = q.front(); 
        q.pop(); 
        if (curr != NULL) { 
  

            curr->nextRight = q.front(); 
  

            if (curr->left) 
                q.push(curr->left);  
            if (curr->right) 
                q.push(curr->right); 
        }  
         
 
        else if (!q.empty())  
            q.push(NULL);  
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



