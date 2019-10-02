int height(Node* node)
{
    if (node==NULL)
        return 0;
   // Your code here
   int ldepth = height(node->left);
   int rdepth = height(node->right);

   return 1+ max(ldepth,rdepth);

}
