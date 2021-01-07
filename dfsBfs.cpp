#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void solution();

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int v);
    int connectedComponents();
    void BFS(int v);
};

Graph ::Graph(int v)
{
    this->V = v;
    adj = new list<int>[v];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::DFSUtil(int v, bool *visited)
{
    visited[v] = true;
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[(*i)])
        {
            DFSUtil(*i, visited);
        }
    }
}
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
    {
        visited[i] = false;
    }
    DFSUtil(v, visited);
}
void Graph::BFS(int v)
{
    int n = this->V;
    queue<int> q;
    vector<bool> used(n, false);
    vector<int> dist(n), parent(n);

    q.push(v);
    used[v] = true;
    parent[v] = -1;
    int count = 0;

    while (!q.empty())
    {
        int w = q.front();
        q.pop();
        for (int x : adj[w])
        {
            if (!used[x])
            {
                used[x] = true;
                q.push(x);
                dist[x] = dist[w] + 1;
                parent[x] = w;
            }
        }
    }
    //shortest path code of y
    // if (!used[y])
    // {
    //     // cout << "No Path!";
    //     ;
    // }
    // else
    // {
    //     vector<int> path;
    //     for (int v = y; v != -1; v = parent[v])
    //         path.push_back(v);
    //     reverse(path.begin(), path.end());
    //     cout << path.length() << "\n";
    // }
}
int Graph::connectedComponents()
{
    int count = 0;
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; ++i)
    {
        visited[i] = false;
    }
    for (int i = 0; i < this->V; ++i)
    {
        if (!visited[i])
        {
            DFSUtil(i, visited);
            count++;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution();

    return 0;
}

void solution()
{
}