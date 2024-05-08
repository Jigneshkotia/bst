#include<iostream>
using namespace std;

class BST{
    public:
    class node{
        public:
        int data;
        node* left;
        node *right;

        node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
    };
    //recursive approach
    node* LCAinBST_R(node* root, int left , int right){
        if(root == NULL){
            return NULL;
        }

        if(root->data < left && root->data < right){
            return LCAinBST_R(root->right,left,right);
        }
        if(root->data > left && root->data > right){
            return LCAinBST_R(root->left,left,right);
        }
        return root;
    }

    //itrative approach
    node* LCAinBST_I(node* root, int left , int right){
        while(root != NULL){
            if(root->data < left && root->data < right){
                root = root->right;
            }else if(root->data > left && root->data > right){
                root = root->left;
            }else{
            return root;
            }
        }
    }
};