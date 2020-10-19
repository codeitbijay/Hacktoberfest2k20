// Breadth First Search using maps of maps
// Time Complexity O(|V|) = O(b^d)  where |V| is the number of nodes. You need to traverse all nodes.
// Space complexity is O(| V |) as well - since at worst case you need to hold all vertices in the queue.

#include <bits/stdc++.h>
#define MOD 1000000007
#define loop(i, a, b) for (int i = a; i < b; i++)
#define ull unsigned long long int
#define ll long long int
using namespace std;

void bfs(unordered_map<int, unordered_map<int, int>> graph, int starting_node)
{
    deque<int> nodes;
    unordered_map<int, bool> visited;

    nodes.push_back(starting_node);

    while (!nodes.empty())
    {
        // Get current node
        auto current_node = nodes.front();
        nodes.pop_front();

        // If the node is already visited, move along
        if (visited[current_node])
            continue;

        // Mark the current node as visited
        visited[current_node] = true;

        // add all it's neighbours in the queue
        for (auto i : graph[current_node])
            nodes.push_back(i.first);

        cout << current_node << " ";
    }
    cout << endl;
}

void display_graph(unordered_map<int, unordered_map<int, int>> graph)
{
    for (auto i : graph)
    {
        cout << i.first << "-> ";
        for (auto j : i.second)
            cout << j.first << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    unordered_map<int, unordered_map<int, int>> graph;
    cout << "Enter the edges of the graph (u, v) : ";
    loop(i, 0, 5)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    display_graph(graph);
    bfs(graph, 0);

    return 0;
}
