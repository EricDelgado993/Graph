//=============================================================================
// File: Queue.cpp
// Author: Eric Delgado
// Date: 01/02/2025
//=============================================================================

#include "Queue.h"

// Constructor to initialize the queue as empty
Queue::Queue()
{
    head = tail = NULL;
}

// Destructor to clean up any dynamically allocated memory
Queue::~Queue()
{
    QueueNode* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;  // Free memory
    }

    head = tail = NULL;
}

// Check if the queue is empty
bool Queue::isEmpty()
{
    return (head == NULL);
}

// The queue is assumed not to be full since it's based on a linked list
bool Queue::isFull()
{
    return false;  // Linked list can grow dynamically
}

// Add an element to the queue
void Queue::enqueue(GraphNode* newNode)
{
    QueueNode* temp = new QueueNode();  // Create a new node
    temp->item = newNode;
    temp->next = NULL;

    if (head == NULL)
    {
        head = tail = temp;  // If queue is empty, new node becomes both head and tail
    }
    else
    {
        tail->next = temp;  // Otherwise, add the new node at the end
        tail = temp;  // Update the tail pointer
    }
}

// Remove and return the front element of the queue
GraphNode* Queue::dequeue()
{
    if (isEmpty())
    {
        return NULL;  // If queue is empty, return NULL
    }

    QueueNode* temp = head;
    GraphNode* item = head->item;  // Get the item at the front of the queue
    head = head->next;  // Move head pointer to the next node

    if (head == NULL)
    {
        tail = NULL;  // If the queue is now empty, reset the tail
    }

    delete temp;  // Free the old front node
    return item;   // Return the dequeued item
}

// Helper function to get the length of the queue (number of elements)
int Queue::getLength()
{
    int length = 0;
    QueueNode* temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}