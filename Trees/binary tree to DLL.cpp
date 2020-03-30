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

void bToDLL(Node* root, Node** ref)
{
	if (!root)
	{
		return;
	}

	static Node* prev = NULL;
	bToDLL(root->left, ref);
	if (*ref == NULL) 
	{ 
		prev = NULL;
        *ref = root;
	} 
    else
    { 
        root->left = prev; 
        prev->right = root; 
    } 
    prev = root;

	bToDLL(root->right, ref);

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
    //cout<< findDist(root, 14, 22);
    
	
	return 0;
}



