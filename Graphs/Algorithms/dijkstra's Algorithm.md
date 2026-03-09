# Dijkstra's Algorithm

## Overview

Dijkstra's Algorithm is a **graph traversal algorithm** used to compute the **shortest path from a single source vertex to all other vertices** in a weighted graph.

The algorithm works for graphs with **non-negative edge weights** and is widely used in routing systems, network optimization, and pathfinding problems.

Typical applications include:

* Navigation systems (e.g., shortest routes in maps)
* Network routing protocols
* Competitive programming shortest path problems
* Resource optimization in weighted graphs

---

# Key Idea

The core idea of Dijkstra's algorithm is to **always expand the vertex with the currently smallest known distance from the source**.

At each step:

1. Select the node with the smallest distance.
2. Update the distances of its neighboring nodes.
3. Repeat until all nodes have been processed.

This process ensures that once a node's shortest distance is determined, it will **never need to be updated again**.

---

# Graph Requirements

Dijkstra's algorithm works under the following conditions:

* The graph may be **directed or undirected**
* All **edge weights must be non-negative**
* The graph can be represented using an **adjacency list or adjacency matrix**

If the graph contains **negative weight edges**, Dijkstra's algorithm should not be used. In such cases, **Bellman-Ford Algorithm** is preferred.

---

# Algorithm Steps

1. Initialize a distance array `dist[]` where all distances are set to infinity.
2. Set the distance of the source node to `0`.
3. Use a **priority queue (min-heap)** to store `(distance, node)`.
4. Insert the source node into the priority queue.
5. While the priority queue is not empty:

   * Extract the node with the smallest distance.
   * For each neighbor of that node:

     * If a shorter path is found, update the distance.
     * Push the updated distance into the priority queue.

---

# Relaxation Step

The most important step in the algorithm is **edge relaxation**.

For an edge:

```
u → v with weight w
```

If the following condition is satisfied:

```
dist[u] + w < dist[v]
```

Then update:

```
dist[v] = dist[u] + w
```

This means a **shorter path to vertex v has been discovered through vertex u**.

---

# Example

Consider the following graph:

```
A --4--> B
A --2--> C
C --1--> B
```

Initial distances:

```
dist[A] = 0
dist[B] = ∞
dist[C] = ∞
```

After processing node A:

```
dist[B] = 4
dist[C] = 2
```

After processing node C:

```
dist[B] = min(4, 2 + 1) = 3
```

Final shortest distances:

```
A → B = 3
A → C = 2
```

---

# Time Complexity

When implemented using a **priority queue (min-heap)**:

```
O((V + E) log V)
```

Where:

* `V` = number of vertices
* `E` = number of edges

---

# Space Complexity

```
O(V + E)
```

This includes storage for the adjacency list and the distance array.

---

# Pseudocode

```
function dijkstra(source):
    initialize dist[] with infinity
    dist[source] = 0

    priority_queue pq
    pq.push(0, source)

    while pq is not empty:
        (distance, node) = pq.pop()

        for each neighbor (next, weight):
            if dist[node] + weight < dist[next]:
                dist[next] = dist[node] + weight
                pq.push(dist[next], next)

    return dist
```

---

# Summary

* Computes shortest paths from a **single source node**
* Works only with **non-negative weights**
* Uses **greedy strategy**
* Efficient implementation uses a **priority queue**
* Time complexity: **O((V + E) log V)**

Dijkstra's algorithm is one of the most fundamental algorithms for solving shortest path problems in graph theory and competitive programming.

Code: 
```
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
int n, m;
cin >> n >> m;

vector<vector<pii>> adj(n + 1);

for(int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // remove if directed
}

int src;
cin >> src;

vector<ll> dist(n + 1, LLONG_MAX);
priority_queue<pii, vector<pii>, greater<pii>> pq;

dist[src] = 0;
pq.push({0, src});

while(!pq.empty()){

    auto [d, node] = pq.top();
    pq.pop();

    if(d > dist[node]) continue;

    for(auto [next, wt] : adj[node]){
        if(dist[node] + wt < dist[next]){
            dist[next] = dist[node] + wt;
            pq.push({dist[next], next});
        }
    }
}

for(int i = 1; i <= n; i++){
    cout << dist[i] << " ";
}

return 0;

}
```