#ifndef GRAPH_H
#define GRAPH_H

#include <string> 
#include <vector> 
#include <unordered_map> 

class Graph {
private:
    //adjacencyList[node] = list of neighbors connected to node
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

    int edgeCount = 0;

public: 
    // Add a connection between two nodes (undirected)
    void addEdge(const std::string& a, const std::string& b);

    // Load edges from a CSV file: source,target
    bool loadFromCSV(const std::string& filePath); 

    // Basic stats
    int getNodeCount() const; 
    int getEdgeCount() const; 

    // Degree centrality: number of neighbors 
    std::vector<std::pair<std::string, int>> getTopNodesByDegree(int topN) const; 
    
    // Shortest path between start and goal using BFS
    // Returns empty vector if no path exists
    std::vector<std::string> shortestPathBFS(const std::string& start,
                                             const std::string& goal) const;

    // Find connected components (communities)
    std::vector<std::vector<std::string>> connectedComponents() const;
};

#endif
