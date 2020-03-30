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

int util(Node* node, int &res)
{
	if (!node)
	{
		return 0;
	}

	int l_max = util(node->left, res);
	int r_max = util(node->right, res);


	res = max(res, 1 + l_max + r_max);
	return max(l_max,r_max) + 1;

}
int diameter(Node* node) {
        
    int res = INT_MIN;
    util(node, res);
    return res;
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
    cout<<diameter(root);
    
	
	return 0;
}