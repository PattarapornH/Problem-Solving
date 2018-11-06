/*
LANG: C++
TASK: bstfind2
*/

#include<iostream>
using namespace std;

typedef int valueType;
struct TreeNode
{
    valueType val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(valueType val,TreeNode* left = 0,TreeNode* right = 0,int height = 0)
        : val(val),left(left),right(right),height(height) {}
};

int height(TreeNode* r)
{
    if(r == 0){
        return 0;
    }
    return r->height;
}

int find_max(int x,int y)
{
    if(x > y){
        return x;
    }
    return y;
}

TreeNode* rightRotate(TreeNode* r)
{
    TreeNode* x = r -> left;
    TreeNode* y = x -> right;
    //rotate
    x->right = r;
    r->left = y;
    //update height
    r->height = find_max(height(r->left),height(r->right))+1;
    x->height = find_max(height(x->left),height(x->right))+1;
    return x;
}

TreeNode* leftRotate(TreeNode* r)
{
    TreeNode* x = r->right;
    TreeNode* y = x->right;
    //rotate
    x->left = r;
    r->right = y;
    //update height
    r->height = find_max(height(r->left),height(r->right))+1;
    x->height = find_max(height(x->left),height(x->right))+1;
    return x;
}

int balance(TreeNode* r)
{
    if(r == 0){
        return 0;
    }
    return height(r->left) - height(r->right);
}

TreeNode* insert(TreeNode* r,valueType v)
{
    if(!r){
        r = new TreeNode(v);
        return r;
    }
    else if(v < r -> val){
        r->left = insert(r->left,v);
    }
    else if(v > r -> val){
        r->right = insert(r->right,v);
    }
    else{
        return r;
    }

    //update height
    r->height = 1 + find_max(height(r->left),height(r->right));

    int bal = balance(r);

    //left left
    if(bal > 1 && v < r->left->val){
        return rightRotate(r);
    }
    //right right
    if(bal < -1 && v > r->right->val){
        return leftRotate(r);
    }
    //left right
    if(bal > 1 && v > r->left->val){
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    //right left
    if(bal < -1 && v < r->right->val){
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}

TreeNode* find(TreeNode* r,valueType v)
{
    if(!r){
        return r;
    }
    else if(v < r->val){
        find(r->left,v);
    }
    else if(v > r->val){
        find(r->right,v);
    }
    else{
        return r;
    }
}
main()
{
    int M;
    int k,v;
    TreeNode* root = 0;
    cin >> M;
    int cnt = 0;
    for(int i=0; i<M; i++){
        cin >> k >> v;
        if(k == 1){
            root = insert(root,v);
        }
        else{
            if(find(root,v)){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
    }
}