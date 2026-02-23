# Graph Analytics Toolkit (C++)

## Overview
This project implements a graph analytics tool in C++ that reads relationship data from a CSV file and analyzes connectivity in a network.

## Data
- Input format: CSV edge list (source,target)
- Each row represents an undirected relationship between two nodes.

## Methods
- Graph representation: adjacency list
- Shortest path: Breadth-First Search (BFS)
- Network metrics: degree centrality
- Community detection: connected components

## Example Output
Shortest path: Ava -> Noah -> Emma -> Olivia

## What I Learned
- Implementing graph data structures in C++
- Using BFS to find shortest paths
- Parsing real-world data from CSV files
- Structuring multi-file C++ projects