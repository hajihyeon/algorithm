/*
    problem : Equal Row and Column Pairs
    url : https://leetcode.com/contest/weekly-contest-303/problems/equal-row-and-column-pairs/
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid[0].size();
        // cout << n << endl;
        int Rsum[205]={0,};
        int Csum[205]={0,};
        
        for(int i=0;i<n; i++){
            for(int k=0; k<n; k++){
                Rsum[i]+=grid[i][k];
                Csum[k]+=grid[i][k];
            }
        }
        
        int count = 0;
        for(int i=0;i<n; i++){
            for(int k=0; k<n; k++){
                if(Rsum[i] != Csum[k]){
                    continue;
                }
                // cout << "i "<<i<<" k "<< k<<endl;
                for(int j=0; j<n; j++){
                    // cout << grid[i][j]<<" " << grid[j][k] << endl;
                    if(grid[i][j] != grid[j][k])
                        break;
                    if(j==n-1){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};