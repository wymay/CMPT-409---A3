//Bribing FIPA

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

struct node
{
  int diamond;
  vector<string> children;
};

int main()
{
  while (true)
  {
    string s;
    getline(cin, s);
    if (s[0] == '#')
      break;

    stringstream ss(s);
    int n, m;
    ss >> n >> m;
    map<string, node> graph;
    map<string, bool> hasParent;
    for (int i = 0; i < n; i++)
    {
      string name;
      cin >> name;
      graph[name] = node();
      cin >> graph[name].diamond;

      string s;
      getline(cin, s);
      stringstream ss(s);
      string child;
      while (ss >> child)
      {
        graph[name].children.push_back(child);
        hasParent[child] = true;
      }
    }
    vector<int> span(n);
    vector<int> cost(n);
    int id = 0;
    function<void(string)> toposort;
    toposort = [&](string name) {
      int i = id++;
      cost[i] = graph[name].diamond;
      for (auto j : graph[name].children)
        toposort(j);
      span[i] = id;
    };
    for (auto n : graph)
    {
      if (hasParent.find(n.first) == hasParent.end())
        toposort(n.first);
    }

    // for (int i; i < n; i++)
    // {
    //   cout << cost[i] << " " << span[i] << endl;
    // }

    vector<vector<int>> f(n + 1, vector<int>(m + 1, 1 << 29));
    f[n][0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = 0; j <= m; j++)
      {
        int num = min(j, span[i] - i);
        f[i][j] = min(f[span[i]][j - num] + cost[i], f[i + 1][j]);
      }
    }
    cout << f[0][m] << endl;
  }
}