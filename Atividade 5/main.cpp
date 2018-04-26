#include <iostream>
#include <fstream>
#include <sstream>

#include "Graph/graph.h"

int main(int argc, char* argv[]){

  if (argc != 3) {
    std::cout << "How to Use:" << std::endl;
    std::cout << "./greedy algorithm fileName" << std::endl;
    std::cout << "Algorithms: prim or dijkstra" << std::endl;

    return EXIT_FAILURE;
  }

  std::ifstream file(argv[2]);
  std::string line;
  getline(file, line);
  std::stringstream ss(line);

  int i;
  ss >> i;

  Graph graph;

  for(int j = 0; j < i; j++){
    graph.createGraph(new Node(std::to_string(j)));
  }

  int lineCounter = 0;
  int columnCounter = 1;
  while(getline(file, line)){
    int value;
    int auxiliaryColumnCounter = columnCounter;
    std::stringstream ss1(line);
    while(ss1 >> value){
      graph.nodeVector[lineCounter]->createEdge(value, graph.nodeVector[auxiliaryColumnCounter]);
      graph.nodeVector[auxiliaryColumnCounter]->createEdge(value, graph.nodeVector[lineCounter]);
      auxiliaryColumnCounter++;
    }
    columnCounter++;
    lineCounter++;
  }

  if(std::string(argv[1]).compare("prim") == 0){
    graph.PrimAlgorithm();

    return EXIT_SUCCESS;
  }
  
  if(std::string(argv[1]).compare("dijkstra") == 0){
    graph.DijkstraAlgorihm();

    return EXIT_SUCCESS;
  }
  else {
    std::cout << "Algorithm not found or not exist" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}