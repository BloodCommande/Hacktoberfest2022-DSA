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
}
