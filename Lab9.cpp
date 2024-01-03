// Q # 1
// #include<iostream>
// #include<queue>
// using namespace std;

// struct BSTNode{
//     int data;
//     BSTNode* left;
//     BSTNode* right;

//     BSTNode(int d){
//         data = d;
//         left = right = NULL;
//     }
// };

// void levelOrder(BSTNode* rootPtr){
//     queue<BSTNode*> q;
//     q.push(rootPtr);
//     q.push(NULL);

//     while(!q.empty()){
//         BSTNode* temp = q.front();
//         q.pop();

//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// BSTNode* insertInBST(BSTNode* rootPtr, int data){
//     if(rootPtr == NULL){
//         rootPtr = new BSTNode(data);
//         return rootPtr;
//     }
//     if(data>rootPtr->data){
//         rootPtr->right = insertInBST(rootPtr->right,data);
//     }
//     else{
//         rootPtr->left = insertInBST(rootPtr->left,data);
//     }
//     return rootPtr;
// }

// void takeInput(BSTNode* &rootPtr){
//     int data;
//     cin>>data;

//     while(data != -1){
//         rootPtr = insertInBST(rootPtr,data);
//         cin>>data;
//     }
// }

// int main(){
//     BSTNode* rootPtr = NULL;

//     cout<<"Enter data to create BST "<<endl;
//     takeInput(rootPtr);

//     levelOrder(rootPtr);
//     return 0;
// }

// Q#2

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


node* insertAtBST(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }
    if(data>root->data){
        root->right = insertAtBST(root->right,data);
    }
    else{
        root->left = insertAtBST(root->left,data);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin >> data;

    while(data!=-1){
        root = insertAtBST(root,data);
        cin>>data;
    }
}


int minVal(node *root)
    {
        node* temp = root;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp->data;
}
node* deleteInBST(node* root, int val){
    // base case
    if(root== NULL){
        return root;
    }
    // node found
    if(root->data == val){
        // 0 child
        if(root->left ==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child

        //left child
        if(root->left!=NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left==NULL && root->right!= NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right!=NULL){
            int mini = minVal(root->right);
            root->data =  mini;
            root->right = deleteInBST(root->right, mini);
            return root;
        }

    }
    else if(root->data>val){
        root->left = deleteInBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteInBST(root->right,val);
        return root;
    }
    
}


int main(){
    node* root = NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"After deleting one left-child node"<<endl;
    deleteInBST(root,8);
    levelOrderTraversal(root);

    cout<<"After deleting one right-child node"<<endl;
    deleteInBST(root,25);
    levelOrderTraversal(root);
    return 0;
}