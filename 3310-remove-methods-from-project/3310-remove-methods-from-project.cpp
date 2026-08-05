class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // create indegree for each node
        // from K-node start traversal(DFS or BFS)
        // mark suspicious nodes and updatre Indrgree of nodes
        // now check for suspicious nodes and indegree == -0 and return the safe node
        // else return the complete graph
        vector<vector<int>>adj(n);
        vector<int>Indegree(n,0);
        vector<bool>suspicious(n,false);
        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            Indegree[v]++;
        }
        queue<int>que;
        que.push(k);
        suspicious[k] = true;
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(int &ngbr: adj[curr]){
                Indegree[ngbr]--;
                if(!suspicious[ngbr]){
                    que.push(ngbr);
                    suspicious[ngbr]=true;

                }
            }
        }
        vector<int>res;
        bool cannotremove = false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && Indegree[i]>0){
                cannotremove = true;
                break;
            }
            if(!suspicious[i]){
                res.push_back(i);
            }
        }
        if(cannotremove){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return res;
    }
};