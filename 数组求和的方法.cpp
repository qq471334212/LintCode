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
