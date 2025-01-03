#include "Graph.h"

Graph::Graph()
{

    for (int i = 0; i < 20; i++)
    {
        vertexList[i] = NULL;
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

bool Graph::searchForKey(int key)
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

bool Graph::addEdge(int startKey, int endKey, int weight)
{
    if (searchForKey(startKey) == true && searchForKey(endKey) == true)
    {
        for (int i = 0; i < 5; i++)
        {
            if (getVertex(startKey)->neighbors[i] == NULL && getVertex(endKey)->neighbors[i] == NULL)
            {
                getVertex(startKey)->neighbors[i] = getVertex(endKey);
                getVertex(endKey)->neighbors[i] = getVertex(startKey);

                getVertex(startKey)->edgeWeight[i] = weight;
                getVertex(endKey)->edgeWeight[i] = weight;

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

    while (vertexList[emptyVertices] == NULL)
    {
        emptyVertices++;
    }

    return emptyVertices == 20;
}

/*THROWAWAY CODE

bool Graph::addVertex(GraphNode* newNode, int key, int weight)
{
    if (startPoint == nullptr)
    {
        startPoint = newNode;
        return true;  // Successfully added the first node
    }

    // Check if a node with the given key already exists
    if (search(key))
    {
        std::cout << "Node with key " << key << " already exists." << std::endl;
        return false;  // Duplicate key, node not added
    }

    // Add the new node to the graph by connecting it as a neighbor of an existing node
    GraphNode* current = startPoint;
    while (current != nullptr)
    {
        // Attempt to add newNode as a neighbor to the current node
        if (current->addNeighbor(newNode, weight))
        {
            return true;  // Node added successfully
        }
        current = nullptr;  // This could be adjusted if the graph is more complex
    }

    std::cout << "Could not add node, all neighbor slots are full." << std::endl;
    return false;  // Graph full, node not added
}

bool Graph::search(int key)
{
    if (startPoint == nullptr)
    {
        return false;
    }

    Queue queue;

    bool visited[20] = { false };

    GraphNode* current = nullptr;

    queue.enqueue(startPoint);
    visited[startPoint->key] = true;

    while (!queue.isEmpty())
    {
        current = queue.dequeue();

        if (current->key == key)
        {
            return true;
        }

        for (int i = 0; i < 5; i++)
        {
            if (current->neighbors[i] != nullptr && !visited[current->neighbors[i]->key])
            {
                queue.enqueue(current->neighbors[i]);
                visited[current->neighbors[i]->key] = true;
            }
        }
    }

    return false;
}

void Graph::deleteVertex(int key)
{

}

void Graph::startFrom(int key)
{

}
*/