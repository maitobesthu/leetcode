class Solution
{
    public:
        int solveMemo(int i, int amt, vector<int> &coins,
            vector<vector < int>> &dp)
        {
            if (amt == 0) return 1;
            if (i == 0)
            {
                if (amt % coins[0] == 0) return 1;
                else return 0;
            }

            if (dp[i][amt] != -1)
                return dp[i][amt];
            int notTake = solveMemo(i - 1, amt, coins, dp);
            int take = 0;
            if (coins[i] <= amt)
            {
                take = solveMemo(i, amt - coins[i], coins, dp);
            }

            return dp[i][amt] = take + notTake;
        }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector < int>> dp(n, vector<int> (amount + 1, -1));
        return solveMemo(n - 1, amount, coins, dp);
    }
};