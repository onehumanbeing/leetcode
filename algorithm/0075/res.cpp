#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0, 1, 2 messy list given
        // 你能想出一个仅使用常数空间的一趟扫描算法吗
        // 使用非常暴力的平移插入法
        int zero, one, two;
        zero = one = two = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[++two] = 2;
                nums[++one] = 1;
                nums[++zero] = 0;
            }
            if(nums[i]==1){
                nums[++two] = 2;
                nums[++one] = 1;
            }
            if(nums[i]==2){
                nums[++two] = 2;
            }
        }
        cout << integerVectorToString(nums) << endl;
    }

    string integerVectorToString(vector<int> list, int length = -1) {
        if (length == -1) {
            length = list.size();
        }

        if (length == 0) {
            return "[]";
        }

        string result;
        for(int index = 0; index < length; index++) {
            int number = list[index];
            result += to_string(number) + ", ";
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
    }
};

int main(){
    return 0;
}