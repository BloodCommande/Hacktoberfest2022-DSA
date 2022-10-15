#include<bits/stdc++.h>

using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* insertintoBST(Node* root,int data)
{
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data) root->right=insertintoBST(root->right,data);
    else root->left=insertintoBST(root->left,data);
    return root;
}
void createBST(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertintoBST(root,data);
        cin>>data;
    }
}
int minval(Node* root)
{
    while(root->left)
    {
        root=root->left;
    } 
    return root->data;
    
}
Node* deletefromBST(Node* root,int val)
{
    if(root->data==val)
    {
        //Nochild 
        if(root->left==NULL&&root->right==NULL)
        {
            delete(root);
            return NULL;
        }
        //One child
        if(root->left!=NULL&&root->right==NULL)
        {
            Node* temp=root->left;
            delete(root);
            return temp;
        }
        if(root->right!=NULL&&root->left==NULL){
            Node* temp=root->right;
            delete(root);
            return temp;
        }
        //Two child
        if(root->left!=NULL&&root->right!=NULL)
        {
            int mini=minval(root->right);
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }
    }

    if(val<root->data) root->left=deletefromBST(root->left,val);
    else root->right=deletefromBST(root->right,val);
    return root;
}
void levelordertraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* root=q.front();
        q.pop();

        if(root==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<root->data<<" ";
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
    }
}

int main()
{
    Node* root=NULL;

     cout<<"enter data for BST";
     createBST(root);
     levelordertraversal(root);

// deletion
     int del;
     cout<<"enter the value to be deleted"<<endl;
     cin>>del;
     root=deletefromBST(root,del);
      levelordertraversal(root);
}
