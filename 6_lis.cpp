class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        for(int i=0; i<nums.size(); i++){
            if(sub.empty() || sub.back() < nums[i]){
                sub.push_back(nums[i]);
            } else{
                auto it = lower_bound(sub.begin(),sub.end(),nums[i]);

                int idx = it - sub.begin();

                sub[idx] = nums[i];
            }
        }

        return sub.size();
    }
};