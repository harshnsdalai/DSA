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
int evalTree(Node* root) {
    if (!root)  
        return 0;  
  
   
    if (!root->left && !root->right)  
        return stoi(root->data);  
  

    int l_val = evalTree(root->left);  
  
  
    int r_val = evalTree(root->right);  
   
    if (root->data=="+")  
        return l_val+r_val;  
  
    if (root->data=="-")  
        return l_val-r_val;  
  
    if (root->data=="*")  
        return l_val*r_val;  
  
    return l_val/r_val;
}


int main()
{
	
    //cout<< findDist(root, 14, 22);
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    util(root,5);
	return 0;
}