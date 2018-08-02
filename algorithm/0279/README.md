所有的数都可以看做一个普通数加上一个完美平方数

dp[i + j * j] = Math.min(dp[i] + 1, dp[i + j * j])