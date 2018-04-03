//Chopsticks

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_INT (1 << 30)

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int k, n;
    cin >> k >> n;
    k += 8;
    vector<int> l(5010);
    std::vector<vector<int>> f(5010, vector<int>(1010));
    for (int i = 0; i < n; i++)
    {
      cin >> l[i];
    }
    for (int i = n; i >= 0; i--)
    {
      for (int j = 0; j <= k; j++)
      {
        if (j == 0)
        {
          f[i][j] = 0;
        }
        else if (n - i < 3 * j)
        {
          f[i][j] = MAX_INT;
        }
        else
        {
          int v = (l[i] - l[i + 1]) * (l[i] - l[i + 1]);
          // cout << v;
          f[i][j] = min(f[i + 2][j - 1] + v, f[i + 1][j]);
        }
      }
    }
    cout << f[0][k] << endl;
  }
}