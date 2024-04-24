#include <cstdlib>
#include <vector>

// finding the route for TSP
std::vector<int> nearest_neighbor(const std::vector<std::vector<double>>& distances) {

    // creating an empty route
    std::vector<int> route;

    // marking all vertices unvisited
    int vertices = std::ssize(distances);
    std::vector<bool> colors(vertices, true);

    // starting the route from the random vertice
    int current_vertice = rand() % vertices;
    route.push_back(current_vertice);
    colors[current_vertice] = false;

    // moving to the vertice nearest to the current one
    for (int i = 2; i <= vertices; ++i) {
        int next_vertice = -1;
        for (int j = 0; j != vertices; ++j) {
            if (colors[j]) {
                next_vertice = j;
                break;
            }
        }
        for (int j = next_vertice + 1; j != vertices; ++j) {
            if (colors[j]) {
                if (distances[current_vertice][next_vertice] > distances[current_vertice][j]) {
                    next_vertice = j;
                }
            }
        }
        current_vertice = next_vertice;
        route.push_back(current_vertice);
        colors[current_vertice] = false;
    }

    // returning the route
    return route;
}
