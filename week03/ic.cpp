#include<iostream>
#include<cstring>
using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void insert_left(ListNode* header, valueType x)
{
    ListNode* new_node = new ListNode(x);
    new_node -> next = header -> next;
    header -> next = new_node;
}

void insert_right(ListNode* header,valueType x)
{
    ListNode* tmp = header -> next;
    ListNode* new_node = new ListNode(x);
    while(true){
        if(tmp -> next == 0){
            tmp -> next = new_node;
            break;
        }
        tmp = tmp -> next;
    }
}

void rotate_left(ListNode* header)
{
    insert_right(header,header->next->val);
    ListNode* tmp = header -> next;
    header -> next  = tmp -> next;
    tmp -> next = 0;
    delete tmp;
}

void rotate_right(ListNode* header)
{
    ListNode* tmp = header;
    ListNode* last = header -> next;
    while(true){
        if(last -> next == 0){
            insert_left(header,last->val);            
            tmp -> next = 0;
            delete last;
            break;
        }
        tmp = tmp -> next;
        last = last -> next;
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
    string str;
    int m,k;
    ListNode* header = new ListNode(0);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> str;
        if(str == "li" || str == "ri"){
            cin >> k;
        }
        if(str == "li"){
            insert_left(header,k);
        }
        else if(str == "ri"){
            if(header -> next == 0){
                insert_left(header,k);
            }
            else{
                insert_right(header,k);
            }
        }
        else if(str == "lr" && header->next != 0 && header->next->next != 0){
            rotate_left(header);
        }
        else if(str == "rr" && header->next != 0 && header->next->next != 0){
            rotate_right(header);
        }
    }
    print_list(header -> next);
}