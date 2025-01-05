//=============================================================================
// File: Graph.h
// Author: Eric Delgado
// Date: 01/02/2025
//=============================================================================

#pragma once

#include <iostream>
#include "Queue.h"

class Graph
{
public:
    Graph();
    void setStartLocation(int key);
    bool addVertex(GraphNode* newNode);
    bool removeVertex(int searchKey);
    GraphNode* getVertex(int key);
    bool search(int key);
    GraphNode* BFS(int key);
    bool addEdge(int startKey, int endKey, int weight);
    bool isEmpty();

private:
    GraphNode* startPoint;      // The vertex on the graph where search functions begin.
    GraphNode* vertexList[20];  // A list of vertices on the graph. Maximum of 20 vertices.
};

struct GraphNode
{
    int key;                    
    GraphNode* neighbors[5];
    int edgeWeight[5];

    // Default constructor
    GraphNode()
    {
        key = -1;

        for (int i = 0; i < 5; i++)
        {
            neighbors[i] = NULL;
            edgeWeight[i] = 0;
        }
    }

};