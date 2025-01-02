#pragma once
#include <iostream>
#include "Queue.h"

class Graph
{
public:
    Graph();
    bool addVertex(GraphNode* newNode, int key, int weight);
    void deleteVertex(int key);
    void startFrom(int key);
    bool search(int key);
    bool isInArray(int arr[], int target);
    void isEmpty();

private:
    GraphNode* startPoint;
};

struct GraphNode
{
    int key;
    GraphNode* neighbors[5];  // max 5 neighbors
    int edgeWeight[5];
    int neighborCount = 0;  // tracks the number of current neighbors

    GraphNode()
    {
        // Initialize neighbors and edgeWeights to NULL and 0, respectively
        for (int i = 0; i < 5; i++)
        {
            neighbors[i] = nullptr;
            edgeWeight[i] = 0;
        }
    }

    // Adds a neighbor if space is available
    bool addNeighbor(GraphNode* neighbor, int weight)
    {
        if (neighborCount < 5)
        {
            neighbors[neighborCount] = neighbor;
            edgeWeight[neighborCount] = weight;
            neighborCount++;
            return true;
        }
        else
        {
            std::cout << "Error: No space for more neighbors for node " << key << std::endl;
            return false;  // No more space for neighbors
        }
    }
};
