#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

int main(){
    int p;
    cin>>p;
    int ans = 0;
    for(int i=1; i < p / 3; i++){
        double l = p;
        double j = l - l * l / (2 * l - 2 * i);
        if(i < j && j - (int)j < 1e-5)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}