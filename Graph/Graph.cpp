#include "Graph.h"

Graph::Graph()
{
    startPoint = NULL;

    for (int i = 0; i < 20; i++)
    {
        vertexList[i] = NULL;
    }
}

void Graph::setStartLocation(int key)
{
    if (search(key))
    {
        startPoint = getVertex(key);
    }
}

bool Graph::addVertex(GraphNode* newNode)
{
    for (int i = 0; i < 20; i++)
    {
        if (vertexList[i] == NULL)
        {
            vertexList[i] = newNode;
            return true;
        }
    }

    return false;
}

bool Graph::search(int key)
{
    for (int i = 0; i < 20; i++)
    {
        if (vertexList[i] != NULL && vertexList[i]->key == key)
        {
            return true;
        }
    }

    return false;
}

GraphNode* Graph::BFS(int key)
{
    if (isEmpty())
    {
        return NULL;
    }

    Queue queue;        // Queue for the Breath First Search.
    bool visited[20];   // Array to track visited nodes within the search.

    for (int i = 0; i < 20; i++)
    {
        visited[i] = false;
    }

    // Start BFS from the startPoint
    queue.enqueue(startPoint);
    visited[startPoint->key] = true;

    while (!queue.isEmpty())
    {
        GraphNode* current = queue.dequeue();

        // Check if the current node contains the key
        if (current->key == key)
        {
            return current;
        }

        // Add unvisited neighbors to the queue
        for (int i = 0; i < 5; i++)
        {
            if (current->neighbors[i] != NULL && !visited[current->neighbors[i]->key])
            {
                queue.enqueue(current->neighbors[i]);
                visited[current->neighbors[i]->key] = true;
            }
        }
    }

    // If the key was not found
    return NULL;
}

bool Graph::addEdge(int startKey, int endKey, int weight)
{
    if (search(startKey) == true && search(endKey) == true)
    {
        GraphNode* start = getVertex(startKey);
        GraphNode* end = getVertex(endKey);

        for (int i = 0; i < 5; i++)
        {
            if (start->neighbors[i] == NULL && end->neighbors[i] == NULL)
            {
                start->neighbors[i] = end;
                end->neighbors[i] = start;

                start->edgeWeight[i] = weight;
                end->edgeWeight[i] = weight;

                return true;
            }
        }
    }

    return false;
}

GraphNode* Graph::getVertex(int key)
{
    for (int i = 0; i < 20; i++)
    {
        if (vertexList[i]->key == key)
        {
            return vertexList[i];
        }
    }

    return NULL;
}

bool Graph::isEmpty()
{
    int emptyVertices = 0;
    int index = 0;

    while (vertexList[index] == NULL && index < 20)
    {
        index++;
        emptyVertices += index;
    }

    return emptyVertices == 20;
}