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

/*
”删除”序列中所有相邻的重复元素(只保留一个)。此处的删除，并不是真的删除，而是指重复元素的位置被不重复的元素给占领了(详细情况，下面会讲)。
由于它”删除”的是相邻的重复元素，所以在使用unique函数之前，一般都会将目标序列进行排序。
 */


int main() {
    vector<int> arr(10);
    for(int i=0; i < arr.size(); i++){
        arr[i] = rand() % 10;
    }
    // 元素排序
    sort(arr.begin(), arr.end());

    // 去重，但是并没有正真删除
    //unique(arr.begin(), arr.end());

    // unique：返回最后一个不重复的元素之后的一个元素的迭代器
    // 这整条语句连起来，直接对数组去重
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    return 0;
}