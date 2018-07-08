#include <iostream>
#include <map>
#include <vector>

using namespace std;


// 313 过了 312个时 没有排序 优化 注意审题
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> temp, t;
        map<int, map<int, int>> record;

        vector<vector<int>> res(0);
        vector<int> item(0);
        int i, j, c;
        int len = nums.size();
        if(len<3){
            return res;
        }
        sort(nums.begin(),nums.end());// 
        for(i=0;i<=len-1;i++){
            // reference binding to null pointer of type 'value_type'
           if(temp.find(nums[i])!=temp.end()){
               temp[-nums[i]] = temp[-nums[i]] + 1;
               record[-nums[i]][i] = 1;
           }
           else{
               t[i] = 1;
               temp[-nums[i]] = 1;
               record[-nums[i]] = t;
               t.clear();
           }
        }
        for(i=0;i<=len-2;i++){
            if(i != 0 && nums[i] == nums[i - 1])//i重复出现时不重复处理
                continue;
            for(j=i+1;j<len-1;j++){
                c = 0;
                if(temp.find(nums[i] + nums[j])!=temp.end()){
                    t = record[nums[i] + nums[j]];
                    if(t.find(i)!=t.end()){
                        c += 1;
                    }
                    if(t.find(j)!=t.end()){
                        c += 1;
                    }
                    if(c<temp[nums[i] + nums[j]]){
                        item.push_back(nums[i]);
                        item.push_back(nums[j]);
                        item.push_back(-nums[i]-nums[j]);
                        sort(item.begin(),item.end());//从小到大
                        res.push_back(item);
                        item.clear();
                    }
                }
                while(j + 1 < len && nums[j] == nums[j + 1])//j重复出现时不重复处理
                    j++;
            }
        }
        sort(res.begin(), res.end());
        res.erase( unique( res.begin(), res.end() ), res.end());// 消除相同的数值 
        return res;
    }
};

int main(){
    return 0;
}