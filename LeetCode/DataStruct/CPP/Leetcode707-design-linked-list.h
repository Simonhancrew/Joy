// 双联表，尾插也是O(1)
struct Node {
  Node() : val(0), prev(nullptr), next(nullptr) {
  }
  Node(int v) : val(v), prev(nullptr), next(nullptr) {
  }
  int val;
  Node *prev, *next;
};

class MyLinkedList {
 public:
  Node *dummy, *tail;
  int size = 0;
  MyLinkedList() : dummy(new Node(-1)), tail(new Node(-1)) {
    dummy->next = tail;
    tail->prev  = dummy;
  }
  ~MyLinkedList() {
    delete dummy;
    delete tail;
  }
  int get(int index) {
    if (index > size - 1 || index < 0)
      return -1;
    auto t = dummy;
    do {
      t = t->next;
    } while (index--);
    return t->val;
  }

  void addAtHead(int val) {
    auto t            = new Node(val);
    t->next           = dummy->next;
    t->prev           = dummy;
    dummy->next->prev = t;
    dummy->next       = t;
    ++size;
  }

  void addAtTail(int val) {
    auto t           = new Node(val);
    t->next          = tail;
    t->prev          = tail->prev;
    tail->prev->next = t;
    tail->prev       = t;
    ++size;
  }

  void addAtIndex(int index, int val) {
    if (index > size)
      return;
    if (index == size) {
      addAtTail(val);
      return;
    }
    if (index < 0) {
      addAtHead(val);
      return;
    }
    auto t = dummy;
    while (index--) {
      t = t->next;
    }
    auto node     = new Node(val);
    node->next    = t->next;
    node->prev    = t;
    t->next->prev = node;
    t->next       = node;
    ++size;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size)
      return;
    auto t = dummy;
    do {
      t = t->next;
    } while (index--);
    auto pre  = t->prev;
    auto ne   = t->next;
    pre->next = ne;
    ne->prev  = pre;
    delete t;
    --size;
  }
};
