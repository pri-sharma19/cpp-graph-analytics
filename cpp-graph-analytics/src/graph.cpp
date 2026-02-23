#include "Graph.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>


void Graph::addEdge(const std::string& a, const std::string& b) {
    // Why:
    // We want the graph to be undirected, so we add both directions.
    // Also, we create nodes automatically if they don't exist yet.

    adjacencyList[a].push_back(b);
    adjacencyList[b].push_back(a);
    edgeCount += 1;
}

bool Graph::loadFromCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    std::string line;

    // Read the header line first (expected: source,target)
    if (!std::getline(file, line)) {
        return false;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string source, target;

        // Split by comma
        if (!std::getline(ss, source, ',')) continue;
        if (!std::getline(ss, target, ',')) continue;

        // Clean whitespace (basic)
        source.erase(0, source.find_first_not_of(" \t\r\n"));
        source.erase(source.find_last_not_of(" \t\r\n") + 1);

        target.erase(0, target.find_first_not_of(" \t\r\n"));
        target.erase(target.find_last_not_of(" \t\r\n") + 1);

        if (!source.empty() && !target.empty()) {
            addEdge(source, target);
        }
    }

    return true;
}

int Graph::getNodeCount() const {
    return static_cast<int>(adjacencyList.size());
}

int Graph::getEdgeCount() const {
    return edgeCount;
}

std::vector<std::pair<std::string, int>> Graph::getTopNodesByDegree(int topN) const {
    // Why:
    // Degree centrality = number of neighbors.
    // We'll compute degrees and sort descending.

    std::vector<std::pair<std::string, int>> degrees;
    degrees.reserve(adjacencyList.size());

    for (const auto& entry : adjacencyList) {
        const std::string& node = entry.first;
        const std::vector<std::string>& neighbors = entry.second;

        degrees.push_back({node, static_cast<int>(neighbors.size())});
    }

    // Sort by degree descending
    std::sort(degrees.begin(), degrees.end(),
              [](const auto& x, const auto& y) {
                  return x.second > y.second;
              });

    if (topN < static_cast<int>(degrees.size())) {
        degrees.resize(topN);
    }

    return degrees;
}

std::vector<std::string> Graph::shortestPathBFS(const std::string& start,
                                                const std::string& goal) const {
    // Why BFS:
    // In an unweighted graph, BFS guarantees the shortest path (fewest edges).

    if (adjacencyList.find(start) == adjacencyList.end()) return {};
    if (adjacencyList.find(goal) == adjacencyList.end()) return {};
    if (start == goal) return {start};

    std::queue<std::string> q;
    std::unordered_set<std::string> visited;

    // parent[child] = who discovered child (used to rebuild the path)
    std::unordered_map<std::string, std::string> parent;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        const auto& neighbors = adjacencyList.at(current);

        for (const auto& nxt : neighbors) {
            if (visited.find(nxt) != visited.end()) continue;

            visited.insert(nxt);
            parent[nxt] = current;
            q.push(nxt);

            if (nxt == goal) {
                // Reconstruct path: goal -> ... -> start
                std::vector<std::string> path;
                std::string node = goal;

                while (node != start) {
                    path.push_back(node);
                    node = parent[node];
                }
                path.push_back(start);

                std::reverse(path.begin(), path.end());
                return path;
            }
        }
    }

    return {}; // no path found
}

std::vector<std::vector<std::string>> Graph::connectedComponents() const {
    // Why:
    // Connected components find groups where each node is reachable from others.
    // This is like discovering "communities" in the network.

    std::vector<std::vector<std::string>> components;
    std::unordered_set<std::string> visited;

    for (const auto& entry : adjacencyList) {
        const std::string& start = entry.first;
        if (visited.find(start) != visited.end()) continue;

        // BFS to find all nodes in this component
        std::vector<std::string> component;
        std::queue<std::string> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();

            component.push_back(current);

            const auto& neighbors = adjacencyList.at(current);
            for (const auto& nxt : neighbors) {
                if (visited.find(nxt) != visited.end()) continue;
                visited.insert(nxt);
                q.push(nxt);
            }
        }

        components.push_back(component);
    }

    return components;
}