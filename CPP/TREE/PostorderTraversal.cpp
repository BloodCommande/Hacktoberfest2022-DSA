#include<bits/stdc++.h>

using namespace std;
class Treenode{
    public:
      int data;
      Treenode* left;
      Treenode* right;

      Treenode(int data){
          this->data=data;
          this->left=NULL;
          this->right=NULL;
      }
};

//creating tree by recursion

Treenode* createTree(Treenode* root)
{
    int d;
    cout<<"enter data"<<endl;
    cin>>d;
     root=new Treenode(d);
     if(d==-1) return NULL;

    cout<<"enter data for left"<<endl;
    root->left=createTree(root->left);
    cout<<"enter data for right"<<endl;
    root->right=createTree(root->right);

    return root;
}
void postordertraversal(Treenode* root)
{
    if(root==NULL) return;
    if(root->left) postordertraversal(root->left);
    if(root->right) postordertraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Treenode* root=NULL;
    root=createTree(root);
   
    cout<<"postorder traversal is"<<endl;
    postordertraversal(root);
   
}
