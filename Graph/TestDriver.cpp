//=============================================================================
// File: TestDriver.cpp
// Author: Eric Delgado
// Date: 01/02/2025
// 
// Description:
// This program demonstrates the functionality of the Graph class by
// dynamically creating a graph structure. It uses the addVertex and addEdge
// methods to add nodes and establish connections between them. The program
// tests the graph's ability to search for nodes and verifies its structure by
// simulating a simple graph with weighted edges.
//=============================================================================

#include "Graph.h"
#include <iostream>

using namespace std;

void testGraphFunctions()
{
    Graph myGraph;

    // Create nodes
    GraphNode* node0 = new GraphNode();
    node0->key = 0;
    GraphNode* node1 = new GraphNode();
    node1->key = 1;
    GraphNode* node2 = new GraphNode();
    node2->key = 2;
    GraphNode* node3 = new GraphNode();
    node3->key = 3;
    GraphNode* node4 = new GraphNode();
    node4->key = 4;
    GraphNode* node5 = new GraphNode();
    node5->key = 5;

    // Add nodes to the graph
    cout << "Adding Vertex 0: " << (myGraph.addVertex(node0) ? "Pass" : "Fail") << endl;
    cout << "Adding Vertex 1: " << (myGraph.addVertex(node1) ? "Pass" : "Fail") << endl;
    cout << "Adding Vertex 2: " << (myGraph.addVertex(node2) ? "Pass" : "Fail") << endl;
    cout << "Adding Vertex 3: " << (myGraph.addVertex(node3) ? "Pass" : "Fail") << endl;
    cout << "Adding Vertex 4: " << (myGraph.addVertex(node4) ? "Pass" : "Fail") << endl;

    // Attempt to add a vertex with an existing key
    GraphNode* duplicateNode = new GraphNode();
    duplicateNode->key = 0;
    cout << "Adding Duplicate Vertex 0: " << (!myGraph.addVertex(duplicateNode) ? "Pass" : "Fail") << endl;

    // Add edges between the nodes
    cout << "Adding Edge (0, 4): " << (myGraph.addEdge(0, 4, 8) ? "Pass" : "Fail") << endl;
    cout << "Adding Edge (0, 1): " << (myGraph.addEdge(0, 1, 3) ? "Pass" : "Fail") << endl;
    cout << "Adding Edge (0, 3): " << (myGraph.addEdge(0, 3, 7) ? "Pass" : "Fail") << endl;
    cout << "Adding Edge (1, 2): " << (myGraph.addEdge(1, 2, 1) ? "Pass" : "Fail") << endl;
    cout << "Adding Edge (1, 3): " << (myGraph.addEdge(1, 3, 4) ? "Pass" : "Fail") << endl;
    cout << "Adding Edge (2, 3): " << (myGraph.addEdge(2, 3, 2) ? "Pass" : "Fail") << endl;
    cout << "Adding Edge (3, 4): " << (myGraph.addEdge(3, 4, 3) ? "Pass" : "Fail") << endl;

    // Test search()
    cout << "Searching for Vertex 3: " << (myGraph.search(3) ? "Pass" : "Fail") << endl;
    cout << "Searching for Vertex 5: " << (myGraph.search(5) ? "Pass" : "Fail") << endl;

    // Test BFS
    myGraph.setStartLocation(0);
    cout << "BFS to Find Vertex 2: " << (myGraph.BFS(2) == node2 ? "Pass" : "Fail") << endl;
    cout << "BFS to Find Vertex 5: " << (myGraph.BFS(5) == node5 ? "Pass" : "Fail") << endl;

    // Test isEmpty() after adding vertices
    cout << "Testing isEmpty() after adding vertices: " << (!myGraph.isEmpty() ? "Pass" : "Fail") << endl;

    // Test removing vertices
    cout << "Removing Vertex 3: " << (myGraph.removeVertex(3) ? "Pass" : "Fail") << endl;
    cout << "Removing Vertex 3 Again: " << (myGraph.removeVertex(3) ? "Pass" : "Fail") << endl;
    cout << "Searching for Removed Vertex 3: " << (myGraph.search(3) ? "Pass" : "Fail") << endl;

    // Clean up allocated memory
    delete node0;
    delete node1;
    delete node2;
    delete node4;
    delete duplicateNode;
}

int main()
{
    testGraphFunctions();
    return 0;
}