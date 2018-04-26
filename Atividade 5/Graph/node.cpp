#include "node.h"

Node::Node(std::string s){
  name = s;
}

void Node::createEdge(int value, Node* nextNode){
  Edge v1;
  v1.configEdge(value, nextNode);
  vVector.push_back(v1);
}
