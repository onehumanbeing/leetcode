动态规划

sum[i]表示从i开始的最大子串和，

则有递推公式：sum[i] = max{nums[i], nums[i] + sum[i+1]}