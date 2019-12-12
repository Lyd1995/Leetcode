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
    bool canMeasureWater(int x, int y, int z) {
        int maxv = max(x, y), minv = min(x, y);
        if(z == 0)
            return true;
        if(maxv == 0)
            return false;
        if(minv == 0){
            if(maxv == z)
                return true;
            return false;
        }
        // 以上是合法性判断
        if(minv >= z)
            return lessV();
        if(maxv >= z)
            return largeV(maxv - z, maxv, minv);
        else{
            if(z > maxv + minv)
                return false;
            int target = z - maxv;
            // 现在要想办法让小容器装target升的水
            if(target == minv)
                return true;
            if(maxv % minv == target)
                return true;
            return false;
        }
        
    }

    bool largeV(int d, int maxv, int minv){
        if(d < 0)
            return false;
        // 现在的想法是怎么样把这d升水从大容器里面排出去
        d = d % minv;
        // 通过这个办法，可以尽可能的将水送出去
        if(d == 0)
            return true;
        // 想办法让小容器里面装target升的水
        int target = minv - d;
        if(maxv % minv == target)
            return true;
        return false;
    }

    bool lessV(){

    }
};


class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0)
            return true;
        if(z > x + y)
            return false;
        if(x == 0){
            if(z == y)
                return true;
            return false;
        }
        if(y == 0){
            if(z == x)
                return true;
            return false;
        }
        int d = gcd(x, y);
        if(z % d == 0)
            return true;
        return false;
    }

    int gcd(int x, int y){
        int maxv = max(x, y), minv = min(x, y), ans;
        while(true){
            int temp = maxv % minv;
            if(temp == 0)
                break;
            maxv = minv;
            minv = temp;
        }
        return minv;
    }
};