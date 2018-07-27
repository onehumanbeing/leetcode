## 思路

我们可以想象：最后的剩下一个气球为i的时候，可以获得的分数为：

``` nums[-1]*nums[i]*nums[n] ```

那么介于i,j之间的x，有：

```
dp[i][j] = max(dp[i][j], dp[i][x – 1] + nums[i – 1] * nums[x] * nums[j + 1] + dp[x + 1][j]);
```

