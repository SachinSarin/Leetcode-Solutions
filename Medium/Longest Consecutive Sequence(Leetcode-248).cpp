class Solution {
public:
    int ans = 0;
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto x: nums)
        {
            mp[x]++;
        }
        for(auto x: nums)
        {
            if(mp.find(x-1)!=mp.end())
            {
                continue;
            }
            else
            {
                int size = 1;
                int curr=x+1;
                while(mp.find(curr)!=mp.end())
                {
                    curr++;
                    size++;
                }
                   ans = max(ans , size);
            }
         
        }
        return ans;
    }
};
