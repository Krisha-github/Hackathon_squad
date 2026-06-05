# Hackathon Squad Selection

## Problem Statement

Given:
- `N` coders with skill values
- `M` conflict pairs

Select a subset of coders such that:
- no two selected coders conflict
- total skill is maximized

This problem can be modeled as a Maximum Weight Independent Set problem on a graph.

---

## Approach

Since the problem is NP-hard for large graphs, an exact solution is not feasible for the given constraints.

We use a greedy approximation algorithm.

Priority Formula:

Priority(i) = Skill(i) / (Degree(i) + 1)

Where:
- `Skill(i)` = coder skill
- `Degree(i)` = number of conflicts

Coders are sorted by priority and selected greedily while ensuring no conflicts occur.

A `blocked[]` array is used to prevent selecting conflicting coders.

---

## Complexity

- Graph Construction: `O(M)`
- Sorting: `O(N log N)`
- Greedy Traversal: `O(N + M)`

Overall Complexity: `O(N log N + M)`

---

## Features

- Fast and scalable
- Conflict-free squad generation
- Efficient for very large graphs
- Uses graph-based optimization heuristics

---

## Technologies Used

- C++
- - STL Vectors


- Greedy Algorithms
- Graph Representation using Adjacency Lists

- --
## Credits
This project was built as a group project for Coding Club by:
- Krisha Kapadia
- Devesh More
