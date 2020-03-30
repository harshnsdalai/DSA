#include <bits/stdc++.h>
using namespace std;

struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

 
struct Node* newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->data) 
		node->left = insert(node->left, key); 
	else if (key > node->data) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int level(Node* root, int k)
{
	
	if (root->data == k)
	{
		return 0;
	}
	if (root->data > k)
	{
		return 1+level(root->left, k);
	}
	else
		return 1+level(root->right, k);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() 
{ 
	/* Let us create following BST 
		  50 
		/	 \ 
		30	 70 
	   / \   / \ 
	   20 40 60 80 */
	Node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 

	cout<< level(root, 60);
} 






