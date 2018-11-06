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
        else{
            if(find(root,v)){
                res[cnt++] = 1;
            }
            else{
                res[cnt++] = 0;
            }
        }
    }

    for(int i=0; i<cnt; i++){
        cout << res[i] << endl;
    }
}