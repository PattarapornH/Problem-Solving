/*
LANG: C++
TASK: necklace
*/

#include<iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *next;
    ListNode* last;
    ListNode(valueType val, ListNode *next = 0, ListNode* last = 0)
        : val(val), next(next), last(last) {}
};

main()
{
    int n;
    cin >> n;
    ListNode* bead[n];
    ListNode* head;
    for(int i=0; i<n; i++){
        bead[i] = new ListNode(i);
    }
    int f,b; // front,back
    for(int i=0; i<n-1; i++){
        cin >> b >> f;
        b--;
        f--;
        // cout << i << " ";
        if(bead[f] -> next == 0){
            // cout << "null\n";
            bead[f] -> next = bead[b];
            bead[b] -> last = bead[f];
        }
        else{
            // cout << "not null\n";
            ListNode* tmp = bead[f] -> next;
            bead[f]->next = bead[b];
            bead[b]->last = bead[f];
            ListNode* tmp2 = bead[b];

            while(tmp2->next != 0){
                tmp2 = tmp2 -> next;
            }
            tmp2 -> next = tmp;
            tmp -> last = tmp2;
        }
        head = bead[f];
    }
    // cout << "pass\n";
    while(head->last != 0){
        head = head->last;
    }

    while (head != 0){
        cout << head->val+1 << " ";
        head = head->next;
    }
}