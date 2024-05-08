#include<iostream>
using namespace std;

class BST{
    public:
    class node{
        public:
        int data ;
        node * left;
        node * right;

        node(int d){
            this->data = d;
            this->left= NULL;
            this->right = NULL;
        }
    };
    //mini value
    node * minVal(node * root){
        node* temp = root;
        while(temp->left != NULL){
            temp = temp-> left;
        }
        return temp;
    }
    //max value
    node* maxVal(node * root){
        node* temp = root;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp;
    }

    //insertion 
    node * insertIntoBST(node * &root, int d){
        //base case
        if(root == NULL){
            root = new node(d);
            return root;
        }

        if(d > root->data){
            root->right = insertIntoBST(root->right, d);
        }else{
            root->left = insertIntoBST(root->left, d);
        }
    }

    //deletion
    node* deleteFromBST(node * root, int n){
        //base case
        if(root== NULL){
            return root;
        }
        if(root->data == n){
            //0 child
            if(root->left == NULL && root->right == NULL){
                delete root ;
                return NULL;
            }
            //1 child
            //left child
            if(root->right == NULL && root-> left !=NULL){
                node*temp = root -> left;
                delete root;
                return temp;
            }
            //right child
            if(root->left == NULL && root->right != NULL){
                node*temp = root->right;
                delete root;
                return temp;
            }
            //2 child
            if(root->left !=NULL && root->right != NULL){
                int mini = minVal(root->right)->data;
                root->data = mini;
                root->right = deleteFromBST(root->right , mini);
                return root;
            }

        }
        else if(root->data>n){
            root->left = deleteFromBST(root->left,n);
        }else{
            root->right = deleteFromBST(root->right,n);
        }
    }
} ;