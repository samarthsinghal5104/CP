#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[100005];
int visited[100005];
void dfs(int cur)
{
    if (visited[cur])
    {
        return;
    }
    cout << cur << " ";
    visited[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        dfs(graph[cur][i].first);
    }
}
int main()
{
    int n, m;
    int a, b, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    cin >> a;
    dfs(a);
    return 0;
}