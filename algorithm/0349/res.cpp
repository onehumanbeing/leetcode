#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 两个似乎都是无序数组
        map<int, int> b;
        vector<int> res;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 >= n2 ? n1 : n2;
        for(int i=0;i<n;i++){
            if(i<n1){
                if(b.find(nums1[i])==b.end()){
                    b.insert(map<int, int>::value_type (nums1[i], 1));
                } else {
                    if(b[nums1[i]]==2){
                        b[nums1[i]]=3;
                    }
                }
            }
            if(i<n2){
                if(b.find(nums2[i])==b.end()){
                    b.insert(map<int, int>::value_type (nums2[i], 2));
                } else {
                if(b[nums2[i]]==1){
                    b[nums2[i]]=3;
                }
            }
            }
        }
        map<int ,int>::iterator it;
        it = b.begin();
        while(it != b.end())
        {
            if(it->second==3){
                res.push_back(it->first);
            }
            it ++;
        }
        return res;
    }
};

int main(){
    return 0;
}