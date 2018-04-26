#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include "node.h"

class Graph{
  public:
    std::vector<Node*> nodeVector;
    std::vector<Node*> visitedNodes;
    void createGraph(Node*);
    int findNodeOnVector(Node*);
    int getNodeByName(std::string);
    int getMinorValueFromGraphList(int*);
    void upgradeNodeWeight(Node* node);
    int getMinorNextNode(int*);
    
    void PrimAlgorithm();
    void DijkstraAlgorihm();
};
