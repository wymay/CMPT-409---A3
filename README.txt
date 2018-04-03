p1222 Bribing FIPA:
1. Read input and construct a graph. Use a map to store the graph: the key is the name of a country, and the value contains the number of diamond to bribe this country, and all other countries it controls.
2. Topology sort all countries. DFS for all countries not under control of other country. For each country, all countries it controls will be listed right after it, and the span of these countries is stored.
3. DP: f[i][j] means for the ith to (n-1)th countries, how many diamonds are needed to bribe j countries. If the ith country are bribed, all its controlled countries are bribed as well, so f[i][j] = diamond(i) + f[i+span(i)][j-span(i)-1]. If the ith country are not bribed, f[i][j] = f[i+1][j].

p10271 Chopsticks:
1. Observe that only the pair of chopsticks that affects the result need to be chosen, under the condition that there is a longer chopstick for every pair.
2. DP: f[i][j] means the minimum value to choose j pairs of chopstick from ith to (n-1)th longest chopsticks. if j=0, f[i][j]=0. if n - i < 3 * j, the chopsticks are not enough to form i pairs, so f[i][j] = maxint. Otherwise, consider using ith and (i+1)th chopsticks to form a pair, f[i][j] = min(f[i + 2][j - 1] + the cost, f[i + 1][j]);

p10069:
Data Structure:
class BigNum to realize really big integer adding. (Around 200 length integer)
BigNum[10000] vector to record the 2 lines of the data we want to record.
Algorithm:
Using Dynamic Programming to track the times of substring shows up.
If we make cal[i][j] to be the number of the substring of Z[0...(i-1)] shows in the substring of X[0...(j-1)]
And we can get the dynamic programming formula:
cal[i][j] = cal[i][j-1] if Z[i] != X[i] (because the Z[i] != X[i], the number will be the same as in position Z[i-1])
cal[i][j] = cal[i][j-1] + cal[i-1][j-1] if Z[i] == Z[i] (If Z[i] == Z[i], then the number will be addition of the number of Z[0...i] shows in X[0...(j-1)] and also the number Z[0...(i-1)] of shows in X[0...(j-1)])
To save the space, I will just leave two vector of BigNum[10000].
One temp to record cal[i-1][10000] and result to record cal[i][10000].
After calculate the cal[i][10000], I will set temo = result and use result to record the cal[i+1][10000]
The answer will be the number of string of Z shows in the string X, so the result will be result[length of X].

p116:
Data Structure:
use 2D vector minCost[i][j] to record minCost along the path from last column to the column j;
use 2D vector path[i][j] to record the chosen index of next column to indicate the min cost path.
use 2D vector matrix[i][j] to record the original input matrix
Algorithm:
Use Dynamic Programming to track the minimum cost and path for each column from back to front: 
Recursive: minCost[i][j] = Min {minCost[upRow][j+1], minCost[i][j+1], minCost[downRow][j+1]} + matrix[i][j];
Base case: minCost[i][last_col] = matrix[i][last_col] 
Path[i][j] records the lowest index of column j+1 which is in the min cost path.
At last, find the min value in the first column. Backtrack and print the path using Path[][] record.