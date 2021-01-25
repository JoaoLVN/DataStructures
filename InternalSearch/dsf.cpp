#include <iostream>
#include <stdlib.h>
#include <list>

void DepthSearch(std::list<int> adj[], int index, int length, int visited[], int d[], int pi[], int f[], int &time)
{
    visited[index]++;
    if (visited[index] == 1)
    {
        for (std::list<int>::iterator j = adj[index].begin(); j != adj[index].end(); ++j)
        {
            pi[*j] = index;
            d[*j] = time++;
            DepthSearch(adj, *j, length, visited, d, pi, f, time);
            visited[*j]++;
            f[*j] = time++;
        }
    }
}

int DepthSearch(std::list<int> adj[], int index, int length)
{
    int visited[length];
    int d[length];
    int pi[length];
    int f[length];
    int time = 1;
    for (int i = 0; i < length; ++i)
    {
        visited[i] = 0;
    }
    pi[index] = -1;
    DepthSearch(adj, index, length, visited, d, pi, f, time);
    for (int i = 0; i < length; ++i)
        if (visited[i] == 0)
            return 0;
    return 1;
}

int main()
{
    int n, m, u, v, p;
    std::cin >> n;
    std::cin >> m;
    std::list<int> list[n];
    for (int j = 0; j < m; ++j)
    {
        std::cin >> u >> v >> p;
        u--;
        v--;
        list[v].push_back(u);
        if (p == 2)
            list[u].push_back(v);
    }
    std::cout << DepthSearch(list, 0, n);
    return 0;
}