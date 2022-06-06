* 
    problem : 27. Remove Element
    url : https://leetcode.com/problems/remove-element/
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int realIndex=0;
        int len=nums.size();
        int valNum=0;
        for(int i=0; i<len; i++){
            if(nums[i]==val){
                valNum++;
            }else{
                nums[realIndex]=nums[i];
                //nums.insert(nums.begin() + realIndex, nums[i]);
                realIndex++;
            }
        }
       
        for (auto i: nums)
            std::cout << i << ' ';
        
        return len-valNum;
        
    }
};
