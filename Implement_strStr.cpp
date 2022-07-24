/* 
    problem :  Implement strStr()
    url : https://leetcode.com/problems/implement-strstr/
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.length();
        cout << size << endl;
        int nSize = needle.length();
        int result = -1;
        for(int i=0; i<size; i++){
            for(int j=0; j<nSize&&(i+j)<size; j++){
                cout << haystack[i+j] << "=" << needle[j] << endl;
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==nSize-1){
                    result = i;
                }
            }
            if(result != -1){
                break;
            }
        }
        return result;
    }
};