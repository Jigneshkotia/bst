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
    bool searchInBST_recursive(node* root, int x){
        //base case
        if(root == NULL){
            return false;
        }

        if(root-> data == x){
            return true;
        }

        if(root->data > x){
            searchInBST_recursive(root->right,x);
        }else{
            searchInBST_recursive(root->left ,x);
        }
    }

    //itrative approach
    bool searchInBST_itrative(node* root, int x){
       node* temp = root;
       while(temp != NULL){
        if(temp->data = x){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }else{
            temp= temp->right;
        }
       }
       return false;
    }

};