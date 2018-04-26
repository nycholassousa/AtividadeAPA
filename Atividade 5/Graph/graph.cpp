#include "graph.h"

void Graph::createGraph(Node* node) {
  this->nodeVector.push_back(node);
}

int Graph::getNodeByName(std::string name) {
  for(int i=0; i<this->nodeVector.size(); i++) {
    if(!name.compare(this->nodeVector[i]->name)) {
      return i;
    }
  }
  return -1;
}

int Graph::findNodeOnVector(Node* node) {
  if(find(this->visitedNodes.begin(), this->visitedNodes.end(), node) == this->visitedNodes.end()) {
    return 1;
  } else {
    return 0;
  }
}

int Graph::getMinorValueFromGraphList(int* i) {
  int minorValue = INT_MAX;
  int index = 0;

  for(int k=0; k<this->visitedNodes.size(); k++){
    for(int j=0; j<this->visitedNodes[k]->vVector.size(); j++){
      if(findNodeOnVector(this->visitedNodes[k]->vVector[j].nextNode)){
        if(this->visitedNodes[k]->vVector[j].value < minorValue){
          minorValue = this->visitedNodes[k]->vVector[j].value;
          index = j;
          *i = k;
        }
      }
    }
  }
  return index;
}

void Graph::upgradeNodeWeight(Node* node) {
  for(int i=0; i<node->vVector.size(); i++){
    int sumWeight = node->weight + node->vVector[i].value;
    if(sumWeight < node->vVector[i].nextNode->weight){
      node->vVector[i].nextNode->weight = sumWeight;
    }
  }
}

int Graph::getMinorNextNode(int* k) {
  int minorValue = INT_MAX;
  int index = 0;

  for(int i=0; i<this->visitedNodes.size(); i++){
    for(int j=0; j<this->visitedNodes[i]->vVector.size(); j++){
      if(findNodeOnVector(this->visitedNodes[i]->vVector[j].nextNode)){
        if(this->visitedNodes[i]->vVector[j].nextNode->weight < minorValue){
          minorValue = this->visitedNodes[i]->vVector[j].nextNode->weight;
          index = j;
          *k = i;
        }
      }
    }
  }
  return index;
}

void Graph::PrimAlgorithm(){
  int i = 0;
  int auxindex = 0;
  int sum = 0;

  this->visitedNodes.push_back(this->nodeVector[i]);

  while(this->visitedNodes.size() < this->nodeVector.size()){
    int minorIndex = getMinorValueFromGraphList(&i);
    auxindex = getNodeByName(this->visitedNodes[i]->vVector[minorIndex].nextNode->name);
    sum += this->visitedNodes[i]->vVector[minorIndex].value;
    i = auxindex;
    this->visitedNodes.push_back(this->nodeVector[i]);
  }

  std::cout << "Sum of everything: " << sum << std::endl;
  for(int i=0; i<this->visitedNodes.size(); i++){
      std::cout << "Vector " << this->visitedNodes[i]->name << std::endl;
  }
}

void Graph::DijkstraAlgorihm(){
  int i = 0;
  int auxIndex = 0;
  this->visitedNodes.push_back(this->nodeVector[i]);
  this->visitedNodes[i]->weight = 0;


  while(this->visitedNodes.size() < this->nodeVector.size()){
    upgradeNodeWeight(this->nodeVector[auxIndex]);
    int minorIndex = getMinorNextNode(&i);
    auxIndex = getNodeByName(this->visitedNodes[i]->vVector[minorIndex].nextNode->name);
    this->visitedNodes.push_back(this->nodeVector[auxIndex]);
  }

  for(i=0;i<this->visitedNodes.size();i++){
    std::cout << "Node: " << this->visitedNodes[i]->name << std::endl;
  }
}
