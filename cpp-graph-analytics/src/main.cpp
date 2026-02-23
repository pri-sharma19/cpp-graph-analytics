#include <iostream>
#include "Graph.h"

int main() {
    Graph g;

   
    if (!g.loadFromCSV("data/edges.csv")) {
        std::cout << "Failed to load CSV file. Check the path: data/edges.csv\n";
        return 1;
    }

    std::cout << "Graph loaded successfully!\n";
    std::cout << "Nodes: " << g.getNodeCount() << "\n";
    std::cout << "Edges: " << g.getEdgeCount() << "\n\n";

    std::cout << "Top nodes by degree:\n";
    auto top = g.getTopNodesByDegree(5);
    for (const auto& p : top) {
        std::cout << "  " << p.first << " : " << p.second << "\n";
    }

    std::cout << "\nConnected components:\n";
    auto comps = g.connectedComponents();
    std::cout << "Number of components: " << comps.size() << "\n";
    for (size_t i = 0; i < comps.size(); i++) {
        std::cout << "  Component " << (i + 1) << " (size " << comps[i].size() << "): ";
        for (const auto& node : comps[i]) {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nShortest path demo:\n";
    std::string start, goal;
    std::cout << "Enter start node: ";
    std::getline(std::cin, start);
    std::cout << "Enter goal node: ";
    std::getline(std::cin, goal);

    auto path = g.shortestPathBFS(start, goal);
    if (path.empty()) {
        std::cout << "No path found between '" << start << "' and '" << goal << "'.\n";
    } else {
        std::cout << "Shortest path: ";
        for (size_t i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i + 1 < path.size()) std::cout << " -> ";
        }
        std::cout << "\n";
    }

    return 0;
}