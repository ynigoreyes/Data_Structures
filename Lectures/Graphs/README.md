# Graphs
#### In-degree:
Edges coming in the graph

#### Out-Degree:
Edges going out of the graph

#### Degree:
The number of edges that touch some graph vertex, *v*

## How to Represent a graph
- An Edge Lists: the list of edges
  ```
  [
    <from1, to1, (weight)>,
    <from2, to2, (weight)>,
    <from3, to3, (weight)>,
  ]
  ```
- A Node List: A linked list of Nodes

- An Adjacency Matrix: n x n matrix where n is the amount of nodes in the graph. Rows are From and Cols are To
  ```
  [
    [0, 1, 0, 0],
    [0, 0, 0, 1],
    [1, 0, 0, 1],
    [0, 0, 0, 0],
  ]
  ```
  - You can use a real number to represent weights
  - However, be careful if your weights span the real numbers. You may not be able to determine what nodes do and do not have edges
  - Used for finding shortest path with negative weights
  - Space is n<sup>2<sup>
  - Used for graphs with negative weights

- An Adjacency List: A Linked list of nodes/vertices where each node will have it's own list of nodes that it is connected to it
