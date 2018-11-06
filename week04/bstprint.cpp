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

void print_tree(TreeNode* r,int depth)
{
    if(!r){
        return ;
    }
    depth++;
    print_tree(r->right,depth);
    for(int i=1; i<depth;i++){
        cout << "...";
    }
    cout << "* " << r->val << endl;
    print_tree(r->left,depth);
}

main()
{
    int N;
    int v,depth = 0;
    TreeNode* root = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v;
        insert(root,v);
    }
    print_tree(root,depth);
}