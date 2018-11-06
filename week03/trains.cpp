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

class LinkedList
{
    public:
        ListNode* header;
        ListNode* tail;
        LinkedList()
        {
            header = new ListNode(0);
            tail = header;
        }
        void insert_last(valueType x)
        {
            ListNode* new_node = new ListNode(x);
            tail -> next = new_node;
            tail = new_node;
        }
        void insert_list_last(ListNode*& h,ListNode*& t)
        {
            tail -> next = h -> next;
            tail = t;
            h = new ListNode(0);
            t = h;
        }
        bool is_empty()
        {
            return header == tail;
        }
        void delete_list()
        {
            ListNode* tmp = header -> next;
            while(header->next != 0){    
                delete header;
                header = tmp;
                tmp = header -> next;
            }
        }
        void print_list()
        {
            ListNode* tmp = header -> next;
            while(tmp != 0){
                cout << tmp -> val << endl;
                tmp = tmp -> next;
            }
        }
};

main()
{
    LinkedList platform[100001];
    int M,num,plat,from,to;
    char ch;
    cin >> M;
    for(int k=0; k<M; k++){
        cin >> ch ;
        if(ch == 'N'){
            cin >> num >> plat;
            platform[plat].insert_last(num);
        }
        else if(ch == 'M'){
            cin >> from >> to;
            if(!platform[from].is_empty()){
                platform[to].insert_list_last(platform[from].header,platform[from].tail);
            }
        }
    }
    for(int i=0; i<100001; i++){
        platform[i].print_list();
    }
}