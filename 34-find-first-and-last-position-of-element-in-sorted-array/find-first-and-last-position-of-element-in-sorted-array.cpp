class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int first = -1, last = -1;
            int x = target;
            int n=nums.size();
            first = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            if(first==n || nums[first]!=x){
                return {-1,-1};
            }
            last = upper_bound(nums.begin(), nums.end(), x) - nums.begin()-1;
            return {first,last};
        }
};