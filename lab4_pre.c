#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;



void printNode(TreeNode* tr, int order);

TreeNode* insert(TreeNode *root, int val);

TreeNode* build(int *array, int size);

TreeNode* lookup(TreeNode *root, int val);

int size(TreeNode *root);

void PrintPreorder(TreeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->val);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}



int main(int argc, char const *argv[])
{
  TreeNode* dummy = NULL;
  dummy=insert(dummy, 10);
  dummy = insert(dummy, 12);
  dummy = insert(dummy, 1);
  dummy = insert(dummy, 11);
  dummy = insert(dummy, 4);
  dummy = insert(dummy, 16);
  PrintPreorder(dummy);
  printf("\n");
  return 0;
}



TreeNode* insert(TreeNode *root, int val)
{
  if(root==NULL)
  {
    TreeNode * newItem;
    newItem=(TreeNode*)malloc(sizeof(TreeNode));
    newItem->val=val;
    newItem->left=NULL;
    newItem->right=NULL;
    return newItem;

  }

  if ((root->val)>val) { //LEFT
    /* code */

    root->left=insert(root->left,val);
  }
  else if ((root->val)<val)
  {

    root->right=insert(root->right,val);
  }


  return root;
}
