#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        int sum = 0, x;
        stringstream ss(line);
        while(ss >> x)
            sum += x;
        cout << sum << endl;
    }


    int *f;
    char c;
    int i=0;
    while(scanf("%d",&f[i++])!=EOF){
        c=cin.get();
        if(c!=' ') 
            break;
    }
}