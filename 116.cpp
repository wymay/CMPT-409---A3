#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int row, col;
    while(cin >> row >> col){
        vector<vector<int> > matrix(row, vector<int>(col));
        vector<vector<int> > minCost(row, vector<int>(col));
        vector<vector<int> > path(row, vector<int>(col));
        for(int i = 0; i < row; i++) {
            for(int j =0; j < col; j++){
                cin >> matrix[i][j];
            }
        }
        for(int i = 0; i < row; i++) {
            minCost[i][col-1] = matrix[i][col-1];
        }
        for(int j = col-2; j >= 0; j--) {
            for(int i = 0; i < row; i++){
                int upRow = (i+row-1)%row;
                int downRow = (i+row+1)%row;
                int tmpMin = min (min( minCost[upRow][j+1], minCost[i][j+1]), minCost[downRow][j+1]);
                minCost[i][j] = tmpMin + matrix[i][j];
                //cout <<  minCost[i][j] << " ";
                int tmp[] = {upRow, i, downRow};
                vector<int> tmpVec(tmp, tmp+3);
                sort(tmpVec.begin(), tmpVec.end());
                for(int k = 0; k < 3; k++){
                    if(minCost[tmpVec[k]][j+1] == tmpMin){
                        path[i][j] = tmpVec[k];
                        break;
                    }
                }
                //cout << path[i][j] << " ";
            }
            //cout <<endl;
        }
        int min = minCost[0][0];
        int p = 0;
        for(int i = 0; i < row; i++ ){
            if(minCost[i][0] < min){
                min = minCost[i][0];
                p = i;
            }
        }

        vector<int> minPath;
        minPath.push_back(p);
        for(int j = 0; j < col-1; j++){
            minPath.push_back(path[p][j]);
            p = path[p][j];
        }
        for(int j = 0; j < col-1; j++) {
            cout << minPath[j]+1 << " ";
        }
        cout << minPath[col-1]+1 << endl;
        cout << min << endl;
    }
    return 0;
}