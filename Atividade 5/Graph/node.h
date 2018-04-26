#include <string>
#include <iostream>
#include <vector>
#include <limits.h>

#include "edge.h"

class Node{
  public:
    std::string name;
    int weight = INT_MAX;
    std::vector<Edge> vVector;
    Node(std::string name);
    void createEdge(int, Node*);
    void createNode(int value);
  };
