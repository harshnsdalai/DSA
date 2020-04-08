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
int height(Node* node)
{
    if (node==NULL)
        return 0;
   // Your code here
   int ldepth = height(node->left);
   int rdepth = height(node->right);

   return 1+ max(ldepth,rdepth);

}
bool isBalanced(Node *root)
{
	 /* If tree is empty then return true */
    if (root == NULL) 
        return 1; 

    int l = height(root->left);
    int r = height(root->right);
    int diff = abs(l-r);
    if (diff<=1 && isBalanced(root->left) && isBalanced(root->right))
    {
    	return true;
    }
    return false;
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
    cout<<isBalanced(root);
	
	return 0;
}