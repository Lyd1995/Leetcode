#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> temp;
        map<int, int> hash;
        // 统计出现次数
        for(auto n : arr)
            hash[n]++;
        // 计算次数是否有重复
        for(auto t : hash){
            if(temp.count(t.second))
                return false;
            temp.insert(t.second);
        }

        return true;
    }
};

int main() {
    vector<int> a = {1,2,2,1,1,3};
    Solution b;
    b.uniqueOccurrences(a);
}