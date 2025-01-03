//================================================================================
// File: TestDriver.cpp
// Author: Eric Delgado
// Date: 01/02/2025
// Description:
// This program demonstrates the functionality of the Graph class by dynamically 
// creating a graph structure. It uses the addVertex and addEdge methods to add 
// nodes and establish connections between them. The program tests the graph's 
// ability to search for nodes and verifies its structure by simulating a simple 
// graph with weighted edges.
//================================================================================

#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    // Create a graph object
    Graph myGraph;

    // Create nodes with keys 0 to 4
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

    // Add nodes to the graph
    myGraph.addVertex(node0);
    myGraph.addVertex(node1);
    myGraph.addVertex(node2);
    myGraph.addVertex(node3);
    myGraph.addVertex(node4);

    // Add edges between the nodes
    myGraph.addEdge(0, 4, 8);  // Edge from node0 to node4 with weight 8
    myGraph.addEdge(0, 1, 3);  // Edge from node0 to node1 with weight 3
    myGraph.addEdge(0, 3, 7);  // Edge from node0 to node3 with weight 7
    myGraph.addEdge(1, 2, 1);  // Edge from node1 to node2 with weight 1
    myGraph.addEdge(1, 3, 4);  // Edge from node1 to node3 with weight 4
    myGraph.addEdge(2, 3, 2);  // Edge from node2 to node3 with weight 2
    myGraph.addEdge(3, 4, 3);  // Edge from node3 to node4 with weight 3

    // Test the graph structure
    cout << "Searching for node 3: " << (myGraph.searchForKey(3) ? "Found" : "Not Found") << endl;
    cout << "Searching for node 5: " << (myGraph.searchForKey(5) ? "Found" : "Not Found") << endl;
    cout << "Searching for node 0: " << (myGraph.searchForKey(0) ? "Found" : "Not Found") << endl;

    myGraph.setStartLocation(0);

    // Test the BFS function
    int keyToFind = 2;
    GraphNode* foundNode = myGraph.BFS(keyToFind);

    if (foundNode != nullptr)
    {
        cout << "Node with key " << keyToFind << " found!" << endl;
    }
    else
    {
        cout << "Node with key " << keyToFind << " not found." << endl;
    }

    // Test BFS for another node
    keyToFind = 5;  // This node doesn't exist
    foundNode = myGraph.BFS(keyToFind);

    if (foundNode != nullptr)
    {
        cout << "Node with key " << keyToFind << " found!" << endl;
    }
    else
    {
        cout << "Node with key " << keyToFind << " not found." << endl;
    }

    return 0;
}