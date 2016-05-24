/*
* Coded By Sevki Bekir
* Date: 24.05.2016
***********************************************
*/


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

void printPreorder(TreeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->val);
        printPreorder(node->left);
        printPreorder(node->right);

}



int main(int argc, char const *argv[])
{
  int a[10] = {2,1,3,10,15,24,23,7,5,8};
  TreeNode* dummy = NULL;
  TreeNode* dummy2 = NULL;
  dummy=insert(dummy, 10);
  dummy = insert(dummy, 12);
  dummy = insert(dummy, 1);
  dummy = insert(dummy, 11);
  dummy = insert(dummy, 4);
  dummy = insert(dummy, 16);
  printPreorder(dummy);
  printf("\n");
  printf("size=>%d \n", size(dummy));

  dummy=lookup(dummy,12);
  printf("%p %d\n", (void*)dummy, (dummy? dummy->val: 0));



  dummy2=build(a,10);
  printPreorder(dummy2);
  printf("\n");
  printf("size=>%d \n", size(dummy2));
  dummy2=lookup(dummy2,12);
  printf("%p %d\n", (void*)dummy2, (dummy2? dummy2->val: 0));

  return 0;
}

/* LET'S START */

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

  if ((root->val)>val) { /* LEFT */
    /* code */

    root->left=insert(root->left,val);
  }
  else if ((root->val)<val) /* RIGHT*/
  {

    root->right=insert(root->right,val);
  }


  return root;
}


TreeNode* build(int *array, int size)
{
  int i;
  TreeNode * newItem;
  if(size==0)
    return NULL;


  newItem=NULL;
  for (i=0;i<size; i++)
  {
    newItem=insert(newItem,array[i]);
    /* code */
  }

  return newItem;

}


int size(TreeNode *root)
{
  if(root==NULL)
    return 0;
  else
    return size(root->left) + size(root->right) +1;
}



TreeNode* lookup(TreeNode *root, int val)
{
  if (root==NULL)
  {
    /* code */
    return NULL;
  }
  /*CONTROL CASE */
  if (val<(root->val)) /* LEFT */
  {
    /* code */
    return lookup(root->left,val);
  }
  else if (val>(root->val)) /* RIGHT */
  {
    /* code */
    return lookup(root->right,val);
  }
  else /* FOUND */
  {
    return root;
  }
}
