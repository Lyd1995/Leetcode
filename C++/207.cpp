#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1、构建邻接表
        vector<set<int>> adj(numCourses);
        vector<bool> check(numCourses, false);
        for(auto courses : prerequisites){
            adj[courses[0]].insert(courses[1]);  // courses[1]  ----->  courses[0]
        }
        set<int> del;
        int nums=0;
        while(true){
            bool flag=true;
            for(int i=0; i < adj.size(); i++){
                // 不存在依赖
                if(!check[i] && adj[i].empty()){
                    del.insert(i);
                    flag = false;
                    nums++;
                    check[i] = true;
                }
            }
            for(int i=0; i < adj.size(); i++){
                for(auto j : del){
                    if(adj[i].count(j))
                        adj[i].erase(j);
                }
            }
            del.clear();
            if(nums == numCourses)
                return true;
            if(flag)
                break;
        }
        return false;
    }
};

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int num = 0;
        // 统计每个顶点的入度
		vector<int> inDegree(numCourses, 0);
        // 统计每个顶点的出边所指向的顶点
		vector<vector<int>> out(numCourses);
        // 使用队列来存放入度为0的顶点
		queue<int> q;
        // 统计
        for(int i=0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            out[prerequisites[i][1]].push_back(prerequisites[i][0]);        // 1  ---->  0
        }
        // 将入度为0的顶点放入队列
        int nums = 0;
        for(int i=0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
                nums++;
            }
        }
        // 拓扑排序
        while(!q.empty()){
            int v = q.front();
            q.pop();
            // 减小各个顶点的入度
            // out：（起始顶点， 终止顶点）
            // 第一维度与顶点编号恰好重合
            // 第二维度分为indices与val(顶点编号)
            for(int i=0; i < out[v].size(); i++){
                // 得终止顶点u
                int u = out[v][i];
                if(--inDegree[u] == 0){
                    q.push(u);
                    nums++;
                }
            }
        }
        
		return (nums == numCourses);
	}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> course(numCourses);
        for(int i=0;i<numCourses;i++)
            course[i]=i;//课程序号
        vector<vector<int>> ad(numCourses);//邻接表 先修课程到后修课程
        vector<int> inLines(numCourses,0);//每个课程的入度
        
        for(auto p:prerequisites){
            ad[p[1]].push_back(p[0]);//a b代表b->a的边
            inLines[p[0]]++;//a的入度+1
        }
        
        queue<int> q;//辅助队列
        int res=0;
        for(int i=0;i<numCourses;i++)
            if(inLines[i]==0)
                q.push(i);//入度为0的课程入队列
        
        while(!q.empty()){
            int cur=q.front();//当前课程
            q.pop();
            res++;
            auto p=ad[cur];//后修课程
            //遍历每个后修课程
            for(auto pp:p){ 
                inLines[pp]--;//删除该边 即后修课程的入度-1 因为当前节点唯一访问 所以不需要删除邻接表
                if(inLines[pp]==0)//删除边后 该节点的入度为0且未在拓扑排序中
                    q.push(pp);//入队列
            }
        }
        return res==numCourses?true:false;
    }
};




class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int num = 0;
		vector<int> inDegree(numCourses, 0);
		vector<vector<int> > out(numCourses);
		queue<int> q;
		for (int i = 0; i < prerequisites.size(); i++) {
			inDegree[prerequisites[i][1]]++;
			out[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		for (int i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0) 
                q.push(i);
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < out[u].size(); i++) {
				int v = out[u][i];
				inDegree[v]--;
				if (inDegree[v] == 0) {
					q.push(v);
				}
			}
			num++;
		}
		if (num == numCourses)return true;
		return false;
	}
};

int main(){
    vector<vector<int>> prerequisites = {{1, 0}};

}