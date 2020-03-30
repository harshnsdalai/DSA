
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

Node *lca_using_single_traversal(struct Node* root, int n1, int n2) 
{ 
 
    if (root == NULL) return NULL; 

    if (root->data == n1 || root->data == n2) 
        return root; 

    Node *left_lca  = lca_using_single_traversal(root->left, n1, n2); 
    Node *right_lca = lca_using_single_traversal(root->right, n1, n2); 
  

    if (left_lca && right_lca)  return root; 
  
    return (left_lca != NULL)? left_lca: right_lca; 
} 

int main()
{
	Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(9);
    root->left->left = newNode(100);
    root->left->right = newNode(NULL);
    root->right->left = newNode(3);
    root->right->right = newNode(11);
    root->right->left->left = newNode(NULL);
    root->right->left->right = newNode(6);
    root->right->right->left = newNode(10);
    root->right->right->right = newNode(13);
    root->right->left->right->left = newNode(15);
    int n1 = 100,n2=1;

	//lca(root,n1,n2);
	cout<<lca1(root,n1,n2)->data;
	
	return 0;
}



