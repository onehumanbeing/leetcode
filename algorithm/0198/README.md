dp[i]表示从0-i户可以打劫到的最大钱数。

则有dp[i] = max(dp[i-1],dp[i-2]+nums[i])。