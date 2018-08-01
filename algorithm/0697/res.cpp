#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        map<int, int> counter;
        map<int, int> first;
        map<int, int> last;
        int degree = 1;
        int temp;
        string s;
        int minlength = n;

        for(int i=0;i<n;i++){
            if(counter.find(nums[i])==counter.end()){
                // 没找到这个元素
                counter.insert(map<int, int>::value_type (nums[i], 1));
                first.insert(map<int, int>::value_type (nums[i], i));
                last.insert(map<int, int>::value_type (nums[i], i));
            } else {
                temp = counter[nums[i]] + 1;
                if(temp > degree){
                    degree = temp;
                }
                counter[nums[i]] = temp;
                last[nums[i]] = i;
            }
        } // 第一遍，确定度，记录每个值出现次数，第一次出现和最后一次出现
        // 第二次遍历map， 确定最小数组长
        map<int, int>::iterator it;
        it = counter.begin();
        while(it != counter.end())
        {
            if(it->second==degree){
                temp = last[it->first] - first[it->first] + 1;
                if(temp < minlength){
                    // cout << last[it->first] << " " << first[it->first] << endl;
                    minlength = temp;
                }
            }
            it ++;         
        }
        return minlength;    
    }
};

int main(){
    int t[7] = {1,2,2,3,1,4,2};
    vector<int> a(t, t+1);
    cout << Solution().findShortestSubArray(a) << endl;
    return 0;
}