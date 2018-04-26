#include <iostream>

class Node;

class Edge {
public:
  int value = 0;
  Node* nextNode;
  void configEdge(int, Node*);
};
