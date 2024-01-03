// Q1) Give Implementation of depth & breadth first search algorithms on graph 
//0->1,0->2, ,1->0, 1->2, 2->3, 3->2. 

// <<--------------------------BFS Traversal------------------------------------>>
// #include<iostream>
// #include<vector>
// #include<list>
// #include<unordered_map>
// #include<queue>

// using namespace std;

// void makeAdjList(unordered_map<int,list<int>> &adjList,vector<vector<int>> &graph){
//     for(int i=0; i<graph.size(); i++){
//         int u = graph[i][0];
//         int v = graph[i][1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
// }
// void bfs(int node, unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans){
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while(!q.empty()){
//         int frontNode = q.front();
//         q.pop();

//         ans.push_back(frontNode);

//         for(auto i: adjList[frontNode]){
//             if(!visited[i]){
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }

// }

// vector<int> bfsTraversal(int Vertices, vector<vector<int>> &graph){
//     unordered_map<int,list<int>> adjList;
//     unordered_map<int,bool> visited;
//     vector<int> ans;

//     makeAdjList(adjList,graph);

//     for(int i=0; i<Vertices; i++){
//         if(!visited[i]){
//             bfs(i,adjList,visited,ans);
//         }
//     }   
//     return ans;
// }

// int main(){
//     int m, n;
//     cin>> m>>n;

//     vector<vector<int>> graph;
//     for(int i=0; i<m; i++){
//         int u,v;
//         cin>>u>>v;
//         graph.push_back({u,v});
//     }

//     vector<int> bfs = bfsTraversal(m,graph);
//     cout<<endl<<"BFS Traversal"<<endl;
//     for(int i:bfs){
//         cout<<i<<" ";
//     }
//     return 0;
// }

// <<--------------------------DFS Traversal------------------------------------>>
// #include<iostream>
// #include<unordered_map>
// #include<list>
// #include<vector>

// using namespace std;

// void dfs(int node,unordered_map<int, bool> &visited,unordered_map<int,list<int>> &adjList,vector<int> &component){
//     // push the answers in componenet vector
//     component.push_back(node);
//     // mark the ans (true)
//     visited[node] = true;

//     // Recursivelly Call Every Node Connected to Answer (Pushed) Node
//     for(auto i: adjList[node]){
//         if(!visited[i]){
//             dfs(i,visited,adjList,component);
//         }
//     }
// }

// vector<vector<int>> DFS(int m, int n,vector<vector<int>> &graph){
//     // Initialize Adjacecy list
//     unordered_map<int,list<int>> adjList;

//     // TO Make Adjacecny list
//     for(int i=0; i<graph.size(); i++){
//         int u = graph[i][0];
//         int v =graph[i][1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
//     unordered_map<int, bool> visited;
//     vector<vector<int>> ans;

//     // Iterate Through Every Node and Appplied DFS Traversal
//     for(int i=0; i<m; i++){
//         if(!visited[i]){
//             vector<int> component;
//             dfs(i,visited,adjList,component);
//             ans.push_back(component);
//         }
//     }
//     return ans;
// }

// int main(){
//     // Take Input about Vertices and Edges
//     int m,n;
//     cin>>m>>n;

//     vector<vector<int>> graph;
//     // Make The graph by taking values of connected Nodes
//     for(int i=0; i<n; i++){
//         int u,v;
//         cin>>u>>v;
//         graph.push_back({u,v});
//     }

//     vector<vector<int>> result = DFS(m,n,graph); 
//     cout<<endl<<"DFS Traversal: "<<endl;
    
//     // Print The answers
//     for (auto i : result) {
//         for (int node : i) {
//             cout<<node<< " ";
//         }
//     }
//     return 0;
// }

//Q#3) Determine whether an undirected graph is a tree (Acyclic Connected Graph).
//Also give implementation. Analyzes your algorithm and identify the worst time complexity.
#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>

using namespace std;

bool isCycleBFS(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList){
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;

    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbours:adjList[front]){
            if(visited[neighbours]== true && neighbours!=parent[front]){
                return true;
            }
            else if(!visited[neighbours]){
                q.push(neighbours);
                visited[neighbours] = 1;
                parent[neighbours] = front;
            }
        }
    }

    return false;
}
bool Graph_is_Tree(vector<vector<int>> &graph, int n, int m){
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = graph[i][0];
        int v = graph[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    bool cycle = false;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i,visited,adjList);
            if(ans==1){
                cycle = true;
            }
        }
    }
    // return "No";
    if(cycle == false && m == (n-1)){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Number of Vertices: ";
    cin>>n;

    int m;
    cout<<"Number of Edges: ";
    cin>>m;

    vector<vector<int>> graph;
    cout<<"Enter Connections: "<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph.push_back({u,v});
    }


    bool ans = Graph_is_Tree(graph,n,m);

    cout<<"Given Graph is" <<(ans == 1 ? "": " not")<<" a Tree"  <<endl;

    return 0;
}
