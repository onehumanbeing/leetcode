#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> fail(2, -1);
        vector<int> res(2, 0);
        if(n==0){
            return fail;
        }
        int beg=0, end=n-1;
        int mid=1, t=-1;
        
        if(n==1){
            if(nums[0]==target){
                return res;
            } else {
                return fail;
            }
        }
        if(n==2){
            if(nums[0]==target && nums[1]==target){
                res[1] = 1;
                return res;
            }
            if(nums[0]==target){
                return res;
            }
            if(nums[1]==target){
                res[1] = 1;
                res[0] = 1;
                return res;
            }
            return fail;
        }
        if(nums[beg]==target){
            for(int i=1;i<n;i++)
            {
                if(nums[i]!=target)
                    break;
                res[1] += 1;
            }
            return res;
        }
        if(nums[end]==target){
            res[0] = n-1;
            res[1] = n-1;
            for(int i=n-2;i>=0;i--)
            {
                if(nums[i]!=target)
                    break;
                res[0] -= 1;
            }
            return res;
        }
        while(beg<=end){
            if(beg==end){
                if(nums[beg]==target){
                    vector<int> res(2, beg);
                    return res;
                } else {
                    return fail;
                }
            }
            mid = (beg+end)/2;
            if(t==mid) return fail;
            t = mid;
            if(nums[mid]<target){
                beg = mid;
            }
            else if(nums[mid]>target){
                end = mid;
            } else {
                // 查到了这个数
                bool b=false,e=false;
                while(beg<=end){
                    if(b && e) break;
                    if(nums[beg]==target && !b){
                        res[0] = beg;
                        b = true;
                    }
                    if(nums[end]==target && !e){
                        res[1] = end;
                        e = true;
                    }
                    if(!b)beg++;
                    if(!e)end--;
                }
                return res;
            }
        }
        return fail;
    }
};

int main(){
    return 0;
}