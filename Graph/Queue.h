//=============================================================================
// File: Queue.h
// Author: Eric Delgado
// Date: 01/02/2025
//=============================================================================

#pragma once

#include <iostream>

struct GraphNode;     // Forward declaration of GraphNode so that it can be used in QueueNode

struct QueueNode
{
    GraphNode* item;  // Item is a pointer to a GraphNode
    QueueNode* next;  // Next node in the queue
};

class Queue
{
private:
    QueueNode* head;  // Head of the queue
    QueueNode* tail;  // Tail of the queue

public:
    Queue();
    ~Queue();
    void enqueue(GraphNode* newNode);
    GraphNode* dequeue();
    bool isEmpty();
    bool isFull();
    int getLength();
};