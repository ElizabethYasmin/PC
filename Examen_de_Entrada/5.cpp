/******************************************************************************

5. Escriba una función que verifique si
un árbol es balanceado. Para el propósito 
de esta pregunta, un árbol balanceado es 
aquel árbol en el que la diferencia de alturas 
entre cada subárbol no es mayor a 1.
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){
    }
};

bool IsBalance (TreeNode *root,int & heigh){
    if(root==NULL){
        heigh=0;
        return true;
    }
    int left =0;
    int right=0;
    if(IsBalance(root->left,left)&&IsBalance(root->right,right)){
        if((left-right<=1)&& (left-right>=-1)){
            heigh=left>right?left+1:right+1;
            return true;
        }
    }
    return false;
}

bool IsBalance(TreeNode *root){
    int heigh=0;
    return IsBalance(root,heigh);
}


int main()
{
  TreeNode *p1=new TreeNode(10);
  TreeNode *p2 =new TreeNode(6);
  TreeNode *p3 =new TreeNode(15);
  TreeNode *p4 =new TreeNode(5);
  TreeNode *p5 =new TreeNode(7);
  TreeNode *p6 =new TreeNode(8);
  
  p1->left=p2;
  p1->right=p3;
  p2->left=p4;
  p2->right=p5;
  p5->right=p6;
  cout<<IsBalance(p1)<<endl;

  return 0;
}

