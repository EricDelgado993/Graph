#pragma once

#include <iostream>
#include "Queue.h"

class Graph
{
public:
    Graph();
    void setStartLocation(int key);
    bool addVertex(GraphNode* newNode);
    bool search(int key);
    GraphNode* BFS(int key);
    bool addEdge(int startKey, int endKey, int weight);
    GraphNode* getVertex(int key);
    bool isEmpty();

private:
    GraphNode* startPoint;
    GraphNode* vertexList[20];
};

struct GraphNode
{
    int key;
    GraphNode* neighbors[5];
    int edgeWeight[5];

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
