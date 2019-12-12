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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long i = 1, j = n, mid;
        while(i < j){
            mid = (i + j) / 2;
            if(isBadVersion(mid))
                j = mid;
            else
                i = mid + 1;
        }
        return j;
    }
};

int main() {

    cout << "hello world!!" << endl;

    return 0;
}