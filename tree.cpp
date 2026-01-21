#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

static int idx = -1;
// Node* buildTree(vector<int> preorder){ //O(n)
//     idx++;
//     if(preorder[idx] == -1) return NULL;

//     Node* root = new Node(preorder[idx]);
//     root->left = buildTree(preorder);
//     root->right = buildTree(preorder);
//     return root;
// }
Node* buildTree(Node* root,int val){ //O(n)
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    if(root > preorder[idx]){
        root->left = buildTree(preorder); 
    }
    else {
        root->right = buildTree(preorder);
    }
    return root;
}
void preOrder(Node* root){ // O(n) : Root Left Right
    if(root == NULL) return;
    cout<<root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){//O(n) : Left Root Right
    if(root == NULL) return;
        inOrder(root->left);
        cout<<root->data <<" ";
        inOrder(root->right);
}
void postOrder(Node* root){//O(n) : Left Right Root
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data <<" ";
}
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size( )>0){
        Node* cur = q.front();
        q.pop();
        cout<< cur->data<<" ";

        if(cur->left != NULL){ 
            q.push(cur->left);
        }
        if(cur->right != NULL){
            q.push(cur->right);
        }
    }
    cout<<endl;
}
void topView(Node* root){ // O(n*logn)
    queue<pair<Node*,int>> q;
    map <int, int> m;
    q.push({root,0});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int curHd = q.front().second;
        q.pop();
        if(m.find(curHd) == m.end()){
            m[curHd] = curr->data;
        }
        if(curr->left != NULL){
            q.push({curr->left,curHd-1});
        }
        if(curr->right != NULL){
            q.push({curr->right,curHd+1});
        }
    }
    for(auto val : m){
        cout<<val.second <<" ";
    }
    cout<<endl;
}
void bottomView(Node* root){ // O(n*logn)
    if(!root) return;
    queue<pair<Node*,int>> q;
    map <int, int> m;
    q.push({root,0});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int curHd = q.front().second;
        q.pop();
        m[curHd] = curr->data;
        
        if(curr->left){
            q.push({curr->left,curHd-1});
        }
        if(curr->right){
            q.push({curr->right,curHd+1});
        }
    }
    for(auto val : m){
        cout<<val.second <<" ";
    }
    cout<<endl;
}
int height(Node* root){
    if(root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) +1;
}
int nodeCount(Node* root){
    if(root == NULL) return 0;
    int leftHt = nodeCount(root->left);
    int rightHt = nodeCount(root->right);
    return leftHt + rightHt +1;
}
int nodeSum(Node* root){ 
    if(root == NULL) return 0;
    // root->data = root->left + root->right + root->data;
    root->data = nodeSum(root->left) + nodeSum(root->right) + root->data;
    return root->data;
}
void kthLevel(Node* root,int k){ //
    if(root == NULL) return ;
    if(k == 1){
        cout<< root->data<<" ";
        return;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);
}
void morrisInorder(Node* root){ //O(n)
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout<< curr->data <<" ";
            curr = curr->right;
        } 
        else{
            //create ip;
            Node* IP = curr->left;
            while(IP->right != NULL && IP->right != curr){
                IP = IP->right;
            }
            if(IP->right == NULL){
                IP->right = curr;
                IP = IP->right;
                curr = curr->left;
            }
            else{
                IP->right = NULL;
                cout<< curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}
// Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
//         if(root == NULL) return NULL;
//         if(root->val == p->val || root->val == q->val) return root;
//         Node* leftlca = lowestCommonAncestor(root->left,p,q);
//         Node* rightlca = lowestCommonAncestor(root->right,p,q);
//         if(leftlca && rightlca){
//             return root;
//         } 
//         else if(leftlca != NULL){
//             return leftlca;
//         }
//         else {
//             return rightlca;
//         }
//     }
int main (){
    vector<int> preorder = {1,4,-1,-1,3,2,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    // cout<< root->data <<endl;
    preOrder(root);
    cout<< endl;
    // inOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // levelOrder(root);
    // cout<< height(root);
    // cout<<endl;
    // cout<< nodeCount(root);
    // cout<<endl;
    cout<< nodeSum(root);
    cout<<endl;
    preOrder(root);
    cout<< endl;
    // topView(root);
    // bottomView(root);
    // kthLevel(root,2);
    // cout<<endl;
    morrisInorder(root);
    // cout<<endl;
    // lowestCommonAncestor(root,2,5);
    return 0;
}
