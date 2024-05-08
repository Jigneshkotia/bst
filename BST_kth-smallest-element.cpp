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

    //preorder algo
    int solve(node*root, int i , int k){
        if(root== NULL){
            return -1;
        }
        //L
        int left = solve(root->left,i,k);
        if(left != -1){
            return left;
        }
        //N
        i++;
        if(i==k){
            return root->data;
        }
        //R
        return solve(root->right,i,k);
    }

    int kthsmallest(node* root, int k){
        int i =0;
        int ans = solve(root , i , k);
        return ans;
    }
    //kth largest = (n-k)+1 smallest 🔥
};