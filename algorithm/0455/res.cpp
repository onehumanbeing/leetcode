#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0;
        int child = g.size();
        for(int j=0;j<s.size();j++){
            if(i>=child){
                return i;
            }
            if(g[i] <= s[j]){
                i++;
            }
        }
        return i>=child ? child : i;
    }
};

int main(){

}