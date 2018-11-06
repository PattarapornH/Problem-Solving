#include<iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void insert_front(ListNode* header, valueType x)
{
    ListNode* new_node = new ListNode(x);
    new_node -> next = header -> next;
    header -> next = new_node;
}

void delete_list(ListNode*& header,int* cnt,int m)
{
    ListNode* del_node = header -> next;
    ListNode* tmp = header;
    int k=1;
    while(true){
        if(k == m){
            tmp -> next = del_node -> next;
            del_node -> next = 0;
            delete del_node;
            (*cnt)--;
            break;
        }
        tmp = tmp -> next;
        del_node = del_node -> next;
        k++;
    }
}

void print_list(ListNode* node)
{
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

main()
{
    ListNode* list = new ListNode(0);
    int m=0,k,cnt=0;
    char ch;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> ch >> m;
        if(ch == 'I'){
            insert_front(list,m);
            cnt++;
        }
        else if(ch == 'D' && m<=cnt){
            delete_list(list,&cnt,m);
        }
    }
    print_list(list->next);
}