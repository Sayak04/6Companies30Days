class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i < numCourses; i++) {
            for(auto it: adj[i])
                indegree[it]++;
        }
        
        vector<int> topoSort;
        queue<int> que;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            topoSort.push_back(node);
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    que.push(it);
            }
        }
        
        if(topoSort.size() == numCourses) return true;
        return false;
    }
};