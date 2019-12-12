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

int main(){
    vector<int> vals;
    string line;
    getline(cin, line);
    int x;
    stringstream ss(line);
    while(ss >> x)
        vals.push_back(x);
    vector<int> num1(2, 0), num2(2, 0);
    int i = 0, j = 1;
    while(i < vals.size() && j < vals.size()){
        num1[0] += vals[i];
        num2[0] += vals[j];
        i += 2;
        j += 2;
    }
    if(i < vals.size())
        num1[0] += vals[i];
    i = vals.size() - 1;
    j = i - 1;
    while(i >= 0 && j >= 0){
        num1[1] += vals[i];
        num2[1] += vals[j];
        i -= 2;
        j -= 2;
    }
    if(i >= 0)
        num1[1] += vals[i];
    if(num1[0] >= num2[0] || num1[1] >= num2[1])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}