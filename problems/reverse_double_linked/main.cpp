#include <iostream>
using namespace std;

struct Node {
    Node(int _v) : v(_v), n(0), p(0) {}
    
    int v;
    Node* n;
    Node* p;
    
    void push_after(int _v) {
        Node* tmp = new Node(_v);
        tmp->n = n;
        tmp->p = this;
        n = tmp;
    }
};

void print_list(Node* list) {
    if (list == 0) {
        cout << endl;
        return;
    }
    cout << list->v << " ";
    print_list(list->n);
}

int main ()
{
  Node* list = new Node(5);
  list->push_after(10);
  list->push_after(8);
  print_list(list);
  Node* newlist = 0;
  while (list != 0) {
      Node* tmp = list->n;
      list->n = newlist;
      if (newlist) {
          newlist->p = list;
      }
      newlist = list;
      list = tmp;
      if (list) {
          list->p = 0;
      }
  }
  print_list(newlist);
  return 0;
}
