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
#include<<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> ans;
    map<string, int> hash;
    vector<string> list;
    int len1, len2;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto tic : tickets){
            list.push_back(tic[0]);
            list.push_back(tic[1]);
        }
        sort(list.begin(), list.end());
        int id = 0;
        for(int i=0; i < list.size(); i++){
            if(hash.count(list[i]) == 0){
                hash.insert(pair<string, int>(list[i], id));
                id++;
            }
            else{
                list.erase(list.begin() + i);
                i--;
            }
        }
        // 建立好了：机场名称-->数字的映射
        len1 = tickets.size();
        len2 = list.size();
        vector<int> out_degree(id, 0);
        vector<vector<int>> out(id);
        for(auto tic : tickets){
            out_degree[hash[tic[0]]]++;
            out[hash[tic[0]]].push_back(hash[tic[1]]);
        }
        for(int i=0; i < id; i++)
            sort(out[i].begin(), out[i].end());
        // 准备就绪
        int begin = hash["JFK"];
        dfs(out, begin, 0);
        return ans;
    }

    bool dfs(vector<vector<int>>& out, int begin, int num){
        ans.push_back(list[begin]);
        if(num == len1)
            return true;
        bool fl = false;;
        for(int i=0; i < out[begin].size(); i++){
            int temp = out[begin][i];
            out[begin].erase(out[begin].begin() + i);
            fl = dfs(out, temp, num + 1);
            if(fl)
                return true;
            else{
                ans.pop_back();
                out[begin].insert(out[begin].begin() + i, temp);
            }
        }
        return false;
    }
};


int main(){
    vector<vector<string>> tic = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution a;
    auto b = a.findItinerary(tic);

    return 0;
}

class Solution {
public:
    void visit(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& G, string src, vector<string>& ans, int& idx) { 
        stack<string> st;
        st.push(src);
        while(!st.empty()) {
            string cur = st.top();
            if (!G[cur].empty()) {
                string w = G[cur].top();
                G[cur].pop();
                st.push(w);
            } else {
                st.pop();
                ans[--idx] = cur;
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> G;
        vector<string> ans(tickets.size() + 1);
        for (int i = 0; i < tickets.size(); i++) {
            G[tickets[i][0]].push(tickets[i][1]);
        }
        int idx = tickets.size() + 1;
        visit(G, "JFK", ans, idx);
        return ans;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        map<string, multiset<string>> m;
        for(int i = 0;i < tickets.size();i++){
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs(ans, m, "JFK");
        return vector<string>(ans.rbegin(), ans.rend());
    }
    
    void dfs(vector<string>& ans, map<string, multiset<string>>& m, string start){
        //cout << start << endl;
        
        while(m[start].size() > 0){
            string temp = *m[start].begin();
            m[start].erase(m[start].begin());
            dfs(ans, m, temp);
            
        }
        ans.push_back(start);
    }
};