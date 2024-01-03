// Q#1(ii)
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    root = new node(data);

    if(data==-1) return NULL;

    cout<<"Enter data for left node of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right node of "<<root->data<<endl;
    root->right = buildTree(root->right);
     
    return root; 
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl; // previuos level completely traverse
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
void preOrder(node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(node* root){
    if(root==NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
void postOrder(node* root){
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}
void mirrorTree(node* root){
    if(root==NULL) return ;

    swap(root->left,root->right);

    mirrorTree(root->left);
    mirrorTree(root->right);
}
int main(){
    node* root = NULL;

    root = buildTree(root);
    cout<<"After PreOrder Traversal"<<endl;
    preOrder(root);
    cout<<endl<<endl;
    cout<<"After InOrder Traversal"<<endl;
    inOrder(root);
    cout<<endl<<endl;
    cout<<"After PostOrder Traversal"<<endl;
    postOrder(root);
    levelOrderTraversal(root);
    cout<<"Mirror Image"<<endl;
    mirrorTree(root);
    levelOrderTraversal(root);
    
    return 0;
}

// Q1(i)
// #include<iostream>
// using namespace std;

// class node{
//     public:
//     char data;
//     node* left;
//     node* right;

//     node(char d){
//         data = d;
//         left = right = NULL;
//     }
// };

// node* buildTree(node* root){
//     char data;
//     cout<<"Enter data: "<<endl;
//     cin>>data;
//     root = new node(data);

//     if(data =='^') return NULL;

//     cout<<"Enter data for left node of "<<root->data<<endl;
//     root->left = buildTree(root->left);
//     cout<<"Enter data for right node of "<<root->data<<endl;
//     root->right = buildTree(root->right);
     
//     return root; 
// }

// void preOrder(node* root){
//     if(root==NULL) return;

//     cout<<root->data<<" ";
//     preOrder(root->left);
//     preOrder(root->right);

// }
// void inOrder(node* root){
//     if(root==NULL) return;

//     inOrder(root->left);
//     cout<<root->data<<" ";
//     inOrder(root->right);

// }
// void postOrder(node* root){
//     if(root==NULL) return;

//     postOrder(root->left);
//     postOrder(root->right);
//     cout<<root->data<<" ";

// }

// int main(){
//     node* root = NULL;

//     root = buildTree(root);
//     cout<<"After Prefix Traversal"<<endl;
//     preOrder(root);
//     cout<<endl<<endl;
//     cout<<"After Infix Traversal"<<endl;
//     inOrder(root);
//     cout<<endl<<endl;
//     cout<<"After Postfix Traversal"<<endl;
//     postOrder(root);
    
//     return 0;
// }
