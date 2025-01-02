//==============================
// File: TestDriver.cpp
// Author: Eric Delgado
// Date: 01/02/2025
//==============================

#include <iostream>
#include "Graph.h"

using namespace std;

// Helper function to create new nodes easily
GraphNode* createNode(int key)
{
    GraphNode* newNode = new GraphNode();
    newNode->key = key;

    // Initialize neighbors and edge weights as NULL and 0
    for (int i = 0; i < 5; i++)
    {
        newNode->neighbors[i] = NULL;
        newNode->edgeWeight[i] = 0;
    }

    return newNode;
}

int main()
{
    // Create a graph object
    Graph g;

    // Create nodes with keys 0 to 4
    GraphNode* node0 = createNode(0);
    GraphNode* node1 = createNode(1);
    GraphNode* node2 = createNode(2);
    GraphNode* node3 = createNode(3);
    GraphNode* node4 = createNode(4);

    // Add nodes to the graph
    cout << "Adding node 0: " << g.addVertex(node0, 0, 0) << endl;
    cout << "Adding node 1: " << g.addVertex(node1, 1, 0) << endl;
    cout << "Adding node 2: " << g.addVertex(node2, 2, 0) << endl;
    cout << "Adding node 3: " << g.addVertex(node3, 3, 0) << endl;
    cout << "Adding node 4: " << g.addVertex(node4, 4, 0) << endl;

    std::cout << "break" << std::endl;

    // Set neighbors and edge weights according to the problem statement
    // Node 0 neighbors
    node0->neighbors[0] = node4;
    node0->edgeWeight[0] = 8;

    node0->neighbors[1] = node1; 
    node0->edgeWeight[1] = 3;

    node0->neighbors[2] = node3;
    node0->edgeWeight[2] = 7;

    // Node 1 neighbors
    node1->neighbors[0] = node0;
    node1->edgeWeight[0] = 3;

    node1->neighbors[1] = node2;
    node1->edgeWeight[1] = 1;

    node1->neighbors[2] = node3;
    node1->edgeWeight[2] = 4;

    // Node 2 neighbors
    node2->neighbors[0] = node1;
    node2->edgeWeight[0] = 1;

    node2->neighbors[1] = node3;
    node2->edgeWeight[1] = 2;

    // Node 3 neighbors
    node3->neighbors[0] = node1;
    node3->edgeWeight[0] = 4;

    node3->neighbors[1] = node2;
    node3->edgeWeight[1] = 2;

    node3->neighbors[2] = node0;
    node3->edgeWeight[2] = 7;

    node3->neighbors[3] = node4;
    node3->edgeWeight[3] = 3;

    // Node 4 neighbors
    node4->neighbors[0] = node0;
    node4->edgeWeight[0] = 8;

    node4->neighbors[1] = node3;
    node4->edgeWeight[1] = 3;

    // Test the graph structure
    cout << "Searching for node 3: " << (g.search(3) ? "Found" : "Not Found") << endl;
    cout << "Searching for node 5: " << (g.search(5) ? "Found" : "Not Found") << endl;
    cout << "Searching for node 0: " << (g.search(0) ? "Found" : "Not Found") << endl;

    return 0;
}
