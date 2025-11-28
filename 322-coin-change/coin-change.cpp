class Solution
{
    public:
        int INF = 1e9;

    int solveRec(int i, int amt, vector<int> &coins,vector<vector<int>>& dp)
    {
        if (amt == 0) return 0;

        if (i == 0)
        {
            if (amt % coins[0] == 0)
            {
                return amt / coins[0];
            }
            else
            {
                return INF;
            }
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }

        int notTake = solveRec(i - 1, amt, coins,dp);

        int take = INF;
        if (coins[i] <= amt)
        {
            take = 1 + solveRec(i, amt - coins[i], coins,dp);
        }

        return dp[i][amt] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solveRec(n - 1, amount, coins,dp);
        if (ans >= INF) return -1;
        return ans;
    }
};