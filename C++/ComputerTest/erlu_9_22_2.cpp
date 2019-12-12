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

vector<int> solution(vector<int> nums){
    int N = nums[0], M = nums[1];
    vector<bool> people(N + 1, true);
    vector<int> ans;
    int count = 1;
    while(ans.size() != N){
        for(int i=1; i < people.size(); i++){
            if(people[i]){
                if(count == M){
                    people[i] = false;
                    ans.push_back(i);
                    count = 1;
                    continue;
                }
                count++;
            }
        }
    }
    return ans;
}


int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    vector<int> input;
    while(ss >> x)
        input.push_back(x);
    vector<int> nums = solution(input);
    for(auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}