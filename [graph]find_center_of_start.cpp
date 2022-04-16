/* 
    problem : Find Center of Star Graph
    url : https://leetcode.com/problems/find-center-of-star-graph/
 */


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(int i=0; i<edges.size(); i++)
        {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        for(auto i:mp){
            //모든 것과 연결된 노드가 있다는것 -> 엣지의 개수와 중심 노드와 연결된 개수가 같다
            if(i.second == edges.size()){
                return i.first;
            }
        }
        return 0;
    }
};