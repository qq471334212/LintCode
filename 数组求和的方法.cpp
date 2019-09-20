class Solution {
    /*
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    public:
    int findTargetSumWays(vector<int> &nums, int s){
        // Write your code here
        if(nums.size()==0)
            return 0;
        //递归思路
        int m = 0;
        func(nums,s,m,0,0);
        return m;
    }
    void func(vector<int> &nums,int s,int &m,int n,int sum){
        if(n == nums.size() && sum ==s){
            m++;
            return;
        }
        if(n < nums.size()){
            func(nums,s,m,n+1,sum+nums[n]);
            func(nums,s,m,n+1,sum-nums[n]);
        }
    }
};

class Solution{
    public:
        int findTargetSumWays(vector<int> & sums,int s){
            int n = sums.size();
            if(n==0) return 0;
            unordered_map<int,int> mp;
            mp[0] = 1;
            for(int i = 0;i<n;i++){
                unordered_map<int,int> mpTmp;
                for(auto&& kv:mp){
                    mpTmp[kv.first + nums[i]] += kv.second;
                    mpTmp[kv.first - nums[i]] -= kv.second;
                }
                mp = mpTmp;
            }
            return mp[s];
        }
}