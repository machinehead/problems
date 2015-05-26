#include <iostream>
using namespace std;

struct Node {
    Node(int _v) : v(_v), n(0) {}
    
    int v;
    Node* n;
    
    void push_after(int _v) {
        Node* tmp = new Node(_v);
        tmp->n = n;
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
      newlist = list;
      list = tmp;
  }
  print_list(newlist);
  return 0;
}
