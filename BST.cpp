#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){ 
        data = val;
        left = right = NULL;
    }
};
    Node* insert(Node* root,int val){
        if(root == NULL) return new Node(val);
        if(val < root->data){
            root->left = insert(root->left,val);
        }else{
            root->right = insert(root->right,val);
        }
        return root;
    }

    Node* buildBST(vector<int> v){
        Node* root = NULL;
        for(auto val : v){
            root = insert(root,val);
        }
        return root;
    }

    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    bool search(Node* root,int val){ //O(height)/O(long n)
        if(root == NULL) return false;
        if(root->data == val) return true;
        if(val < root->data){
            return search(root->left,val);
        }else{
            return search(root->right,val);
        }
    }
    Node* getInorderSuccessor(Node* root){
        while(root != NULL && root->left != NULL){
            root = root->left;
        }
        return root;
    }
    Node* deleteNode(Node* root,int val){ //O(height)/O(long n)
        if(root == NULL) return NULL;

        if(val < root->data){
            root->left = deleteNode(root->left,val);
        }
        else if(val >root->data){
            root->right = deleteNode(root->right,val);
        }
        else{
            if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }else{
                Node* IS = getInorderSuccessor(root->right);
                root->data = IS->data;
                root->right = deleteNode(root->right,IS->data);
                
            }
        }
        return root;
    }

    class Info{  
    public:
    int min, max, sz;

    Info(int mn, int mx, int size){
        min = mn;
        max = mx;
        sz = size;
    } 
};

    Info helper(Node* root){//O(n);
        if(root == NULL) return Info(INT_MAX, INT_MIN, 0);
        Info left = helper(root->left);
        Info right = helper(root->right);

        if(root->data > left.max && root->data < right.min){
            int currMax = max(root->data, right.max);
            int currMin = min(root->data, left.min);
            int currSize = left.sz + right.sz + 1;

            return Info(currMin, currMax, currSize);
        }
        else{
            return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
        }
    }
    int largestBST(Node* root){
        Info info = helper(root);
        return info.sz;
    }
int main(){
    // vector<int> v = {3, 2, 1, 5, 6, 4};

    // Node* root = buildBST(v);
    // cout<<"before: ";
    // inorder(root);
    // cout<<endl; 
    // cout<< search(root,5);
    // cout<<endl; 
    // deleteNode(root,5); 
    // cout<< search(root,5);
    // cout<<endl; 
    // cout<<"after: ";
    // inorder(root);
    // // cout<<endl;

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(50);
    cout<< largestBST(root);
    return 0;
}