
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};


void convert(Node *head, TreeNode *&root) {
    queue<Node*>q;
    root = new TreeNode();
    root->data = head->data;
    while(head)
    {
    	TreeNode* parent = q.front();
    	q.pop()
    	head = head->next;
    	TreeNode* left = new TreeNode(head->data);
    	q.push(left);

    	head = head->next;
    	if (head)
    	{
    		TreeNode* right = new TreeNode(head->data);
    		q.push(right);
    	}
    	parent->left = left;
    	parent->right = right;


    }	
    
}