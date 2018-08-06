#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > res;
        vector<int> t;
        backtracking(0, n, k, res, t);
        return res;
    }

    void backtracking(int index, int n, int k, vector< vector<int> > & res, vector<int> t){
        if(t.size()==k){
            // 已经填装完毕，不需要继续
            res.push_back(t);
            return ;
        }
        if(t.size()>1 && t.back() < *(t.end()-2)){ // 不满足递增
            return ;
            // back() 代表vector最后一个元素的引用，end返回迭代器的尾部地址，最后一个元素地址+1
        }
        for(int i=index+1;i<n+1;i++){
            t.push_back(i);
            backtracking(i, n, k, res, t);
            t.pop_back(); // 因为下一次要更换temp内容，所以要把元素移开
        }
    }
};

int main(){
    vector< vector<int> > a = Solution().combine(4, 2);
    int m = a.size();
    if(m==0)return 0;
    int n = a[0].size();
    cout << "[" << endl;
    for(int i=0;i<m;i++)
    {
        cout << "\t[ ";
        for(int j=0;j<n;j++){
            cout << a[i][j];
            if(j!=n-1) cout  << ", ";
        }
        cout << " ]" << endl;
    }
    cout << " ]" << endl;
    return 0;
}