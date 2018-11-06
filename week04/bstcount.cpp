#include <iostream>
#include<stdio.h>
using namespace std;

typedef int valueType;
struct TreeNode
{
    valueType val;
    valueType rightnode;
    TreeNode *left;
    TreeNode *right;

    TreeNode(valueType val, valueType rightnode = 0, TreeNode *left = 0, TreeNode *right = 0)
        : val(val), rightnode(rightnode), left(left), right(right) {}
};

void insert(TreeNode *&r, valueType v)
{
    if (!r){
        r = new TreeNode(v);
    }
    else if (v < r->val){
        insert(r->left, v);
    }
    else if (v > r->val){
        r->rightnode++;
        insert(r->right, v);
    }
}
int count(TreeNode *r, valueType v)
{
    bool found = false;
    TreeNode *tmp = r;
    int cnt = 0;
    while (!found && tmp != 0){
        if (v < tmp->val){
            cnt += tmp->rightnode + 1;
            tmp = tmp->left;
        }
        else if (v > tmp->val){
            tmp = tmp->right;
        }
        else{
            found = true;
            cnt += tmp->rightnode;
        }
    }
    return cnt;
}

main()
{
    int m;
    int k, x;
    TreeNode *root = 0;
    scanf("%d", &m);
    int cnt = 0;
    int max = -9999999;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &k);
        scanf("%d", &x);
        if (k == 1){
            insert(root, x);
            cnt++;
            max = (x > max) ? x : max;
        }
        else if (k == 2){
            if (x >= max){
                printf("0\n");
            }
            else{
                printf("%d\n", count(root,x));
            }
        }
    }
}