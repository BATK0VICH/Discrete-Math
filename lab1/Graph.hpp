#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <list>
#include <memory>
#include <vector>
#include <iostream>
#include "Matrix.hpp"

// TODO: every Graph constructor should 
// automatically push_back *this
// to the static vector of graphs 

typedef std::vector<std::list<int>> AdjacencyList;

// Contains Adjacency List and its number of vertices
// Used for storing Graphs (even if the Graph is declared
// using 'AdjacencyMatrix' or 'MatrixOfIncidence')
class Graph
{
public:
    Graph(int vertices);
    // to test
    // Constructs a 'Graph' object, 
    // expecting a pointer to the 'AdjacencyList'
    // and the number of vertices
    Graph(std::shared_ptr<AdjacencyList> adjListPtr, int vertices);
    // to test
    // Constructs a 'Graph' object from 'AdjacencyMatrix' object,
    Graph(AdjacencyMatrix matrix);
    void addEdge(int src, int dest);
    // prints the vector of lists(Adjacancy list) in the 
    // Graph object to Standart Output(stdout)
    //
    // How to use example:
    // std::cout << Graph object;
    friend std::ostream& operator<<(std::ostream &os, const Graph &rhs);
    // transforms Graph object to the Matrix of Incidence object
    // Graph object isn't deleted
    MatrixOfIncidence toMatrixOfIncidence();
    // transforms Graph object to the Adjacency Matrix object
    // Graph object isn't deleted
    AdjacencyMatrix toAdjacencyMatrix();
private:
    int numVertices;
    std::shared_ptr<AdjacencyList> adjList;
};

// Returns a refenece to the static vector of 'Graph' objects
// serves like a chest
std::vector<Graph>& Graphs();

#endif