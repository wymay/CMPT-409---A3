# CMPT 409 A3
This repository contains solutions to CMPT 409 Assignment 3.

## p1222 Bribing FIPA
### Data Structure
* A map storing information for a graph: the key is the name of a country, and the value contains the number of diamond to bribe this country, and all other countries it controls.

### Algorithm
* Topology sort all countries. 
* DFS for all countries that are not under control of other country. 
* For each country, all countries it controls will be listed right after it, and the span of these countries is stored.
* Dynamic Programming: 
  * f[i][j] means for the ith to (n-1)th countries, how many diamonds are needed to bribe j countries. 
  * If the ith country are not bribed, f[i][j] = f[i+1][j]. If the ith country are bribed, all its controlled countries are bribed as well. The recursion equation used by dynamic programming is:
```
f[i][j] = diamond(i) + f[i+span(i)][j-span(i)-1]. 
```

## p10271 Chopsticks
### Data Structure
* A 2D matrix storing the minimum value to choose j pairs of chopstick from ith to (n-1)th longest chopsticks.

### Algorithm
* Dynamic Programming:
  * f[i][j] means the minimum value to choose j pairs of chopstick from ith to (n-1)th longest chopsticks.
  * If j=0, f[i][j]=0. If n - i < 3 * j, the chopsticks are not enough to form i pairs, f[i][j] = maxint.
  * Otherwise, consider using ith and (i+1)th chopsticks to form a pair, the recursion equation used by dynamic programming is:
```
f[i][j] = min(f[i + 2][j - 1] + the cost, f[i + 1][j]);
```

## p10069
### Data Structure:
* Class BigNum to realize big integer addition. (Around 200-bit integer)
* BigNum[10000] vector to record the two lines of the data we want to record.
### Algorithm
* Dynamic Programming:
  * cal[i][j] means the number of the substring of Z[0...(i-1)] shows in the substring of X[0...(j-1)]
  * If Z[i] != X[i], cal[i][j] = cal[i][j-1]. If Z[i] == Z[i], the number will be addition of the number of Z[0...i] shows in X[0...(j-1)] and also the number Z[0...(i-1)] of shows in X[0...(j-1)]). The recursion equation used by dynamic programming is:
```
cal[i][j] = cal[i][j-1] + cal[i-1][j-1]
```
  * The solution will be result[length of X].
### Additional Feature
* To save the space, only two vectors of BigNum[10000] will be used.
* One called temp to record cal[i-1][10000] ,and another called result to record cal[i][10000].
* After calculating the cal[i][10000], temp = result and use result to record the cal[i+1][10000]

## p116
### Data Structure
* A 2D vector minCost[i][j] to record minCost along the path from the last column to the column j.
* A 2D vector path[i][j] to record the chosen index of the next column to indicate the min cost path.
* A 2D vector matrix[i][j] to record the original input matrix.
### Algorithm:
* Dynamic Programming, to track the minimum cost and path for each column from back to front:
  * Path[i][j] records the lowest index of column j+1 which is in the min cost path.
  * Recursion equation: minCost[i][j] = Min {minCost[upRow][j+1], minCost[i][j+1], minCost[downRow][j+1]} + matrix[i][j];
  * Base case: minCost[i][last_col] = matrix[i][last_col] 
  * At last, find the min value in the first column. Backtrack and print the path using Path[][] record.
