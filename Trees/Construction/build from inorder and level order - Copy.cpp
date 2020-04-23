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

Node*  util(int* inorder, map<int, int> &index_map, int left, int right)
{
	if (left>right)
	{
		return 0;
	}
	int mid = left;
	for (int i = left+1; i < right+1; ++i)
	{
		if(index_map[inorder[i]]<index_map[inorder[mid]])
		{
			// GETTING THE ROOT IN SUBARRAY USING THE FACT THAT IN LEVEL ORDER IT WILL HAVE 
			// LOWEST INDEX
			mid = i;
		}
	}
	//cout<<mid<<endl;

	Node* root = newNode(inorder[mid]);
	root->left = util(inorder, index_map, left, mid-1);
	root->right = util(inorder, index_map, mid+1, right);
	return root;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
	map<int, int> index_map;
	    for (int i = 0; i < n; ++i)
	    {
	    	index_map[levelOrder[i]] = i;
	    	//cout<<inorder[i]<<level[i]<<i<<' '<<index_map[inorder[i]]<<endl;
	    }
	    // for(auto x:index_map)
	    // {
	    // 	cout<<x.first<<" "<<x.second<<endl;
	    // }
	    return util(inorder, index_map, iStart, iEnd);
}
int main()
{
	
   // struct Node* root = newNode(1); 
   //  root->left = newNode(3); 
   //  root->right = newNode(7); 
   //  root->left->left = newNode(6); 
   //  root->left->right = newNode(5); 
   //  root->left->right->left = newNode(10); 
   //  root->right->left = newNode(4); 
   //  root->right->right = newNode(13); 
   //  root->right->left->left = newNode(17); 
   //  root->right->left->right = newNode(15); 
   //  root->right->left->right->right = newNode(15);
  
   //  cout<<height(root);
	// vector<int> inorder = { 4, 8, 10, 12, 14, 20, 22 }; 
 //    vector<int> level = { 20, 8, 22, 4, 12, 10, 14 }; 
 //    map<int, int> index_map;
 //    for (int i = 0; i < level.size(); ++i)
 //    {
 //    	index_map[level[i]] = i;
 //    	//cout<<inorder[i]<<level[i]<<i<<' '<<index_map[inorder[i]]<<endl;
 //    }
 //    // for(auto x:index_map)
 //    // {
 //    // 	cout<<x.first<<" "<<x.second<<endl;
 //    // }
 //    cout<< (inorder, index_map, 0, inorder.size()-1);
	return 0;
}