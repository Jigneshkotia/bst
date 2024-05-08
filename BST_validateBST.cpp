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
    
    //apporach one
    bool isBST_appOne(node* root, int min, int max){
        if(root == NULL){
            return true;
        }
        if(root->data >= min && root->data <= max){
            bool left = isBST_appOne(root->left,min,root->data);
            bool right = isBST_appOne(root->right,root->data,max);
            return left && right;
        }else{
            return false;
        }
    };

    //approach two
    // pre-order traversal of BST is sorted 
    // hence we will first do pre-order travers 
    // and add it to vector and then check wheather it is sorted or not.

    bool validateBST(node * root){
        return isBST_appOne(root,INT_MIN,INT_MAX);
    }
};