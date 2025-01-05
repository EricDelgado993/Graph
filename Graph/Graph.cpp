//=============================================================================
// File: Graph.cpp
// Author: Eric Delgado
// Date: 01/02/2025
//=============================================================================

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

bool Graph::addVertex(GraphNode* newVertex)
{
    for (int i = 0; i < 20; i++)
    {
        // Case if an available location is found.
        // Vertex's key correlates to the index within vertexList[]
        if (vertexList[i] == NULL && newVertex->key == i)
        {
            vertexList[newVertex->key] = newVertex;
            return true;
        }
    }

    // Location is not found.
    // Vertex with key already exists in the graph.
    return false;
}

bool Graph::removeVertex(int searchKey)
{
    GraphNode* delVertex = vertexList[searchKey];
    GraphNode* neighbor = NULL;

    // Vertex with associated key is not in the graph.
    if (delVertex == NULL)
    {
        return false;
    }

    // Locate indices at which vertex's neighbors[] contain data.
    for (int i = 0; i < 5; i++)
    {
        // Case if there is an edge.
        if (delVertex->neighbors[i] != NULL)
        {
            // Capture associated neighbor for edge removal.
            neighbor = delVertex->neighbors[i];
            
            // Remove edge between vertices.
            neighbor->neighbors[i] = NULL;
            delVertex->neighbors[i] = NULL;

            // Remove associated weight of the edge.
            neighbor->edgeWeight[i] = 0;
            delVertex->edgeWeight[i] = 0;
        }
    }

    // Remove vertex from the graph.
    vertexList[searchKey] = NULL;
    neighbor = NULL;

    delete neighbor;
    delete delVertex;
    
    return true;
}

bool Graph::search(int searchKey)
{
    return vertexList[searchKey] != NULL;
}

GraphNode* Graph::BFS(int searchKey)
{
    if (isEmpty())
    {
        return NULL;
    }

    Queue queue;        // Queue for the Breath First Search.
    bool visited[20];   // Array to track visited nodes within the search.

    // Initialize all visited[] elements to false (unvisited).
    for (int i = 0; i < 20; i++)
    {
        visited[i] = false;
    }

    // Begin the BFS from startPoint location.
    queue.enqueue(startPoint);

    // Mark the vertex as visited.
    // The vertex's key corresponds to the element within visited[].
    // This correlation keeps track of which vertex has been visited.
    // Ex. (visited[0] = true) <=> (vertex with key = 0 has been visited) 
    visited[startPoint->key] = true;

    while (!queue.isEmpty())
    {
        GraphNode* current = queue.dequeue();

        // Case if the matching vertex is found.
        if (current->key == searchKey)
        {
            return current;
        }

        // If the current vertex doesn't contain searchKey, enqueue all of its
        // neighbors onto the queue.
        for (int i = 0; i < 5; i++)
        {
            // Enqueue the current vertex's neighbor onto the queue if the
            // neighbor has not yet been visited.
            // Mark the neighbor as visited since it is now on the queue.
            if (current->neighbors[i] != NULL && !visited[current->neighbors[i]->key])
            {
                queue.enqueue(current->neighbors[i]);
                visited[current->neighbors[i]->key] = true;
            }
        }
    }

    // Vertex containing searchKey was not found in the graph.
    return NULL;
}

bool Graph::addEdge(int key1, int key2, int weight)
{
    // Case if vertices with the corresponding keys are in the graph.
    if (search(key1) == true && search(key2) == true)
    {
        GraphNode* vertex1 = getVertex(key1);
        GraphNode* vertex2 = getVertex(key2);

        // Iterate through all elements in neighbors[].
        for (int i = 0; i < 5; i++)
        {
            // Case if the corresponding indicies of neighbors[] both contain NULL.
            // The index corresponds to the edge between vertex1 and vertex2.
            if (vertex1->neighbors[i] == NULL && vertex2->neighbors[i] == NULL)
            {
                vertex1->neighbors[i] = vertex2;
                vertex2->neighbors[i] = vertex1;

                vertex1->edgeWeight[i] = weight;
                vertex2->edgeWeight[i] = weight;

                return true;
            }
        }
    }

    // Edge cannot be added between the vertices.
    return false;
}

GraphNode* Graph::getVertex(int searchKey)
{
    // Traverse through all vertices in the graph.
    for (int i = 0; i < 20; i++)
    {
        // Case if the vertex containing searchKey is found within the graph.
        if (vertexList[i]->key == searchKey)
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

    // Iterate through every element of vertexList.
    // If a vertex is found then control exits loop and returns false.
    // If list is empty then control exits loop and returns true.
    while (vertexList[index] == NULL && index < 20)
    {
        index++;
        emptyVertices += index;
    }

    return emptyVertices == 20;
}