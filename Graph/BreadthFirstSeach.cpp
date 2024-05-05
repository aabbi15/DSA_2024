//question link: https://www.naukri.com/code360/problems/bfs-in-graph_973002

//Basic idea is in BFS is to travel level-wise

// level here can be seen as the distance from the starting node 
// OR
// level is the number of edges form the starting node

// the starting node is considered level 0 
// after that at distance of 1 edge --> we see level 1

// the data structures required are:
// a queue which will help in traveling level wise as preference will be given to FIRST level IN 
// a visited array to track the nodes we have already included in the answer




vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    
    
    vector<int> visited(n,0);
    queue<int> q;

  //initially we insert the first node in queue and mark it as visited
    vector<int> ans;
    q.push(0);
    visited[0] = 1;

  
  //an empty queue denotes that all levels have been traversed
    while(!q.empty()){

      //retrieve the the level that was FIRST IN and add to ANS
        int x = q.front();
        q.pop();
        ans.push_back(x);

        // traverse through each node connected to x which is the next level 
        // Thus adding the next level in the queue (if not visited yet)
      
        for(int node:adj[x]){

            if(visited[node]==0){
                visited[node]=1;
                q.push(node);
            }

        }

        
    }

    return ans;

}
