#include<iostream>
using namespace std;

typedef int valueType;
struct TreeNode
{
    valueType val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(valueType val,TreeNode* left = 0,TreeNode* right = 0)
        : val(val),left(left),right(right) {}
};

void insert(TreeNode*& r,valueType v)
{
    if(!r){
        r= new TreeNode(v);
    }
    else if(v < r -> val){
        insert(r->left,v);
    }
    else if(v > r -> val){
        insert(r->right,v);
    }
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

TreeNode* find_pred(TreeNode* r)
{
    while(r->left != 0){
        r = r->left;
    }
    return r;
}

TreeNode* delete_tree(TreeNode*& r,valueType v)
{
    if(r == 0){
        return r;
    }
    else if(v < r->val){
        r->left = delete_tree(r->left,v);
    }
    else if(v > r->val){
        r->right = delete_tree(r->right,v);
    }
    else{
        // del node is leaf
        if(r->left == 0 && r->right == 0){
            delete r;
        }
        // del node has 1 child
        else if(r->left == 0){
            TreeNode* tmp = r;
            r = r->right;
            delete tmp;
        }
        else if(r->right == 0){
            TreeNode* tmp = r;
            r = r->left;
            delete tmp;
        }
        // del node has 2 child
        else{
            TreeNode* tmp = find_pred(r->right);
            r->val = tmp -> val;
            r->right = delete_tree(r->right,tmp->val);
        }
    }
    return r;
}

main()
{
    int M;
    int k,v;
    TreeNode* root = 0;
    cin >> M;
    int res[M];
    int cnt = 0;
    for(int i=0; i<M; i++){
        cin >> k >> v;
        if(k == 1){
            insert(root,v);
        }
        else if(k == 2){
            if(find(root,v)){
                res[cnt] = 1;
            }
            else{
                res[cnt] = 0;
            }
            cnt++;
        }
        else if(k == 3){
            root = delete_tree(root,v);
        }
    }

    for(int i=0; i<cnt; i++){
        cout << res[i] << endl;
    }
}