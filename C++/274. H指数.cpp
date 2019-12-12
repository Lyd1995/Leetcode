#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<sstream>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = citations.size();
        for(int i=0; i < citations.size(); i++){
            if(citations[i] >= ans)
                break;
            ans--;
        }
        return ans;
    }
};
