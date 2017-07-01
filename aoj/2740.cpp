#include <iostream>
using namespace std;

class Tree {
public:
  Tree(Tree *parent) {
    num = -1;
    this->parent = parent;
    child[0] = child[1] = NULL;
    cnt = 0;
  }

  ~Tree() {
    for (int i = 0; i < cnt; i++) {
      delete child[i];
    }
  }
  
  // debug
  void print() {
    if (num != -1) {
      if (cnt >= 1) {
	cout << '(';
	child[0]->print();
	cout << ')';
      }
      cout << '[' << num << ']';
      if (cnt >= 2) {
	cout << '(';
	child[1]->print();
	cout << ')';
      }
    }
  }

  void merge(Tree *t) {
    num += t->num;
    for (int i = 0; i < cnt; i++) {
      if (child[i]->num != -1 && t->child[i]->num != -1) {
	child[i]->merge(t->child[i]);
      } else {
	child[i]->num = -1;
      }
    }
  }
  
  int num;
  Tree *parent;
  Tree *child[2];
  int cnt;
};

Tree *readTree() {
  char c = '\0';

  Tree *root = new Tree(NULL);
  for (Tree *t = root; c != ')' || t != root || root->cnt != 2;) {
    cin >> c;
    if (c == '(') {
      t->child[t->cnt] = new Tree(t);
      t->cnt++;
      t = t->child[t->cnt - 1];
    }
    if (c == ')') {
      t = t->parent;
    }
    if (c == '[') {
      int num;
      cin >> num;
      t->num = num;
      cin >> c;
    }
  }

  return root;
}

int main() {
  Tree *t1 = readTree();
  Tree *t2 = readTree();
  t1->merge(t2);
  t1->print();
  cout << endl;

  delete t1, t2;
  
  return 0;
}
