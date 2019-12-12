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
        int i = 0, j = citations.size();
        int ans = 0, max = j;
        while(i < j){
            int mid = (i + j) / 2;
            if(citations[mid] >= max - mid){
                if(max - mid > ans)
                    ans = max - mid;
                else
                    break;
                j = mid;
            }
            else
                i = mid + 1;
        }
        return ans;
    }
};