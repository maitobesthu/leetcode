class Solution
{
    public:
        int characterReplacement(string s, int k)
        {
            vector<int> cnt(26, 0);
            int left = 0, maxFreq = 0, ans = 0;

            for (int right = 0; right < s.size(); right++)
            {
                cnt[s[right] - 'A']++;
                maxFreq = max(maxFreq, cnt[s[right] - 'A']);

               	// invalid window -> shrink
                while ((right - left + 1) - maxFreq > k)
                {
                    cnt[s[left] - 'A']--;
                    left++;
                }

                ans = max(ans, right - left + 1);
            }
            return ans;
        }
};