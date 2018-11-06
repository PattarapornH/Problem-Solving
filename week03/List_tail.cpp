#include <iostream>

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
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}
void LinkedList::append(valueType x)
{
  
ListNode* tmp = header -> next;
ListNode* new_node = new ListNode(x);
while(true){
  if(tmp -> next == tail){
    tmp -> next = new_node;
    new_node -> next = tail;
    break;
  }
  tmp = tmp -> next;
}

}

void LinkedList::insert_front(valueType x)
{
  
ListNode* new_node = new ListNode(x);
if(header -> next == 0){
  header -> next = new_node;
  new_node -> next = tail;
}
else{
  header -> next = new_node -> next;
  header -> next = new_node;
}


}


main()
{
  LinkedList list;
  int t;

  cin >> t;
  for(int i = 0; i < t; i++) {
    int dir, val;
    cin >> dir >> val;
    if(dir == 1) {
      list.insert_front(val);
    } else {
      list.append(val);
    }
  }
  list.print_list();
}