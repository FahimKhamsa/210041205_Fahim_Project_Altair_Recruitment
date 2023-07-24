
/**********THIS PROGRAM GIVES THE DESIRESD FUNCTION WITHOUT USER INPUT**********/

#include<bits/stdc++.h>
using namespace std;

bool vis[100];                      // this array determines if the vertex is previously visited or not
vector <int> g[100];                // the graph

void dfs (int vtx) {                // dfs traversal function
    vis[vtx] = true;
    for(int child : g[vtx]) {
        if(vis[child]) continue;
        dfs(child);
    }
}

bool finding_path (vector <pair <int, int>> &edges) {
    for(int i=0; i<7; i++) {                            // representing the graph in adjacency list
        int x = edges[i].first, y = edges[i].second;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int cnt = 0;                                        // number of connected part
    for(int i=0; i<7; i++) {                            // traversing through the graph to check if they are connected or not
        if(vis[i]) continue;
        dfs(i);
        cnt++;
        if(cnt > 1) return false;                       // if more the than 1 connected graph, then it doesn't have a valid path
    }
    return true;
}

int main () {
    vector <pair <int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}, {6, 3}};  // the given input edges
    int n = 7;          // number of vertices
    int m = 7;          // number of edges
    //*** i will replace the n and m with 7 in the function ***//

    cout << (finding_path(edges) ? "true" : "false") << endl;
    return 0;
}