class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if( n==0 )
            return 0;     
        int i=0,j=0;
        while(j < n){
            if(nums[i] == nums[j]){
                j++;
                continue;
            }
            
            nums[i+1] = nums[j];
            i++;j++;
        }
        
        return i+1;
    }
    
};
