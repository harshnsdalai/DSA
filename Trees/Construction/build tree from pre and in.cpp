#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
	
};

struct Node* newNode(char data)
{
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node));

	Node->data = data;
	Node->left = Node->right = NULL;
	return Node;

}

Node* util(int in[],int pre[], int inStrt, int inEnd,map<int,int> &mapp, int &preindex)
{
    if(inStrt>inEnd)
    {
        return NULL;
    }
    
   
   int curr = pre[preindex++]; 
   	//It is supposed that In Preorder the first element is root so we will
   	// traverse it linearly for finding root .
    Node* root = newNode(curr); 
    if (inStrt==inEnd)
    {
    	return root ;
    }
    int mid = mapp[curr] ;
    
    root->left = util(in,pre, inStrt, mid-1,mapp, preindex);
    root->right = util(in, pre, mid+1, inEnd,mapp, preindex);
    return root;
}
    

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    map<int,int> mapp;
    for(int i=inStrt;i<=inEnd;++i)
    {
        mapp[in[i]] = i;

    }
   	//It is supposed that In Preorder the first element is root so we will
   	// traverse it linearly for finding root .
   	int preindex=0;
    return util(in,pre, inStrt,inEnd,mapp,preindex);
    
}
void postorder(Node* root)
{
	if (!root)
	{
		return;
	}
	postorder(root->left);
	cout<<root->data;
	postorder(root->right);
	
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
 //    cout<< minheight(inorder, index_map, 0, inorder.size()-1);
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    Node * root = buildTree(in,pre,0, 5);
    cout<<root->data<<endl;
    postorder(root);
	return 0;
}