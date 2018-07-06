#include <iostream>
using namespace std;

#define MIN -2147483648
#define MAX 2147483647
#define MMIN 2147483648

class Solution {
public:
    int myAtoi(string str) {
        long int result = 0;
        int i;
        int index = 1;
        int temp;
        bool start = true;
        bool is_negative = false;

        //i = is_negative ? 1 : 0;
        for(i=0;i<str.length();i++){
            if(start & (str[i] == ' ')){
                continue;
            }
            if(start & (str[i] == '-')){
                is_negative = true;
                start = false;
                continue;
            }
            if(start & (str[i] == '+')){
                start = false;
                continue;
            }
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            if(start){
                start = false;
            }
            temp = str[i] - '0';
            result = (result * 10) + temp;
            if(is_negative & (result > MMIN)){
                return MIN;
            } else if(!is_negative & (result > MAX)){
                return MAX;
            }
        }
        return is_negative ? result * (-1) : result;
    }
};

int main(){
    string a;
    Solution res = Solution();
    cin >> a;
    cout << res.myAtoi(a) << endl;
    return 0;
}
