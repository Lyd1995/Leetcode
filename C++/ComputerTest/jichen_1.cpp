#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
#include<queue>
using namespace std;

int max_node(vector<int>& student);

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> student(2 * n, 0);
    vector<vector<int>> out(2 * n);
    for(int i=0; i < m; i++){
        int a, b;
        cin>>a>>b;
        student[a - 1]++;
        student[b - 1]++;
        out[a - 1].push_back(b - 1);
        out[b - 1].push_back(a - 1);
    }
    queue<int> q;
    int max = 0;
    q.push(max_node(student));
    vector<int> ans;
    while(!q.empty()){
        int temp = q.front();
        ans.push_back(temp + 1);
        student[temp] = 0;
        q.pop();
        for(auto i=out[temp].begin(); i != out[temp].end(); i++){
            int v = *i;
            student[v]--;
            m--;
        }
        q.push(max_node(student));
        if(m == 0)
            break;
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}

int max_node(vector<int>& student){
    int max = 0;
    int ans;
    for(int i=0; i < student.size(); i++){
        if(student[i] > max){
            ans = i;
            max = student[i];
        }
    }
    return ans;
}
