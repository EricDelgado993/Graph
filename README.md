###### [↩️Return to Portfolio](https://github.com/EricDelgado993/Portfolio)
# Graph and Queue Implementation in C++

## Overview
This project implements a Graph and an accompanying Queue data structure in C++. The graph supports up to 20 vertices, each of which can have up to 5 neighbors. A breadth-first search (BFS) traversal is implemented using the queue.

---

## 📂 **Files**
  -[Graph.h](https://github.com/EricDelgado993/Graph/blob/master/Graph/Graph.h)
  -[Graph.cpp](https://github.com/EricDelgado993/Graph/blob/master/Graph/Graph.cpp)
  -[Queue.h](https://github.com/EricDelgado993/Graph/blob/master/Graph/Queue.h)
  -[Queue.cpp](https://github.com/EricDelgado993/Graph/blob/master/Graph/Queue.cpp)
  -[TestDriver.cpp](https://github.com/EricDelgado993/Graph/blob/master/Graph/TestDriver.cpp)

---

## Key Features
- **Dynamic Memory Management**: Efficiently manages memory for the queue using a linked list.
- **Fixed-Size Graph**: Supports up to 20 vertices, each with up to 5 neighbors.
- **BFS Traversal**: Implements breadth-first search for graph exploration.
- **Vertex and Edge Management**: Add, remove, and connect vertices with weighted edges.

---

## How It Works

### Graph Representation
- The graph is represented using an array of pointers to `GraphNode` objects (`vertexList[20]`).
- Each `GraphNode` can have up to 5 neighbors and corresponding edge weights.

### Queue
- A linked list-based queue is used for BFS traversal.
- Enqueues and dequeues vertices dynamically as the traversal progresses.

### Breadth-First Search (BFS)
- Starts from a designated `startPoint`.
- Traverses the graph level by level, using the queue to manage exploration.
- Marks visited vertices to avoid revisiting.

## TestDriver Output
<details>
  
```
Adding Vertex 0: Pass
Adding Vertex 1: Pass
Adding Vertex 2: Pass
Adding Vertex 3: Pass
Adding Vertex 4: Pass
Adding Duplicate Vertex 0: Pass
Adding Edge (0, 4): Pass
Adding Edge (0, 1): Pass
Adding Edge (0, 3): Pass
Adding Edge (1, 2): Pass
Adding Edge (1, 3): Pass
Adding Edge (2, 3): Pass
Adding Edge (3, 4): Pass
Searching for Vertex 3: Pass
Searching for Vertex 5: Fail
BFS to Find Vertex 2: Pass
BFS to Find Vertex 5: Fail
Testing isEmpty() after adding vertices: Pass
Removing Vertex 3: Pass
Removing Vertex 3 Again: Fail
Searching for Removed Vertex 3: Fail
```

</details>
