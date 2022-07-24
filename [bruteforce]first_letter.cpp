
/* 
    problem : 2351. First Letter to Appear Twice
    url : https://leetcode.com/problems/implement-strstr/
 */

class Solution {
public:
    char repeatedCharacter(string s) {
        int size = s.length();
        int count[30]={0,};
        char result='a';
        for(int i=0; i<size; i++)
        {
            count[s[i]-97]++;
            if(count[s[i]-97]==2){
                result=s[i];
                break;
            }
        }
        return result;
    }
};