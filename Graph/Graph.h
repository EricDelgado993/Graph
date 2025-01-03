#pragma once
#include <iostream>
#include "Queue.h"

class Graph
{
public:
    Graph();
    bool addVertex(GraphNode* newNode);
    bool searchForKey(int key);
    bool addEdge(int startKey, int endKey, int weight);
    GraphNode* getVertex(int key);
    bool isEmpty();

private:
    //GraphNode* startPoint;
    GraphNode* vertexList[20];
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
            key = -1;
            neighbors[i] = nullptr;
            edgeWeight[i] = 0;
        }
    }

    // Adds a neighbor if space is available
    bool addNeighbor(GraphNode* neighbor, int weight)
    {
        if (neighborCount < 5)
        {
            // Check for duplicates before adding
            for (int i = 0; i < neighborCount; i++)
            {
                if (neighbors[i] == neighbor)
                {
                    std::cout << "Error: Duplicate neighbor for node " << key << std::endl;
                    return false;
                }
            }

            neighbors[neighborCount] = neighbor;
            edgeWeight[neighborCount] = weight;
            neighborCount++;
            return true;
        }
        else
        {
            std::cout << "Error: No space for more neighbors for node " << key << std::endl;
            return false;
        }
    }
};
