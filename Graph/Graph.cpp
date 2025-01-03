#include "Graph.h"

Graph::Graph()
{
    startPoint = nullptr;
}

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

bool Graph::isEmpty()
{
    return (startPoint == NULL);
}
