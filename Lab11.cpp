/* Assume an undirected graph having 4 vertices 0,1,2,3 . the vertices are connected in following manner 
 0->1,0->2, ,1->0, 1->2, 2->3, 3->2. 
Implement graph DS by using Adjacency list and Adjacency Matrix method.*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph_By_List{
    public:
    unordered_map<int,list<int>> adjList;

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void display(){
        for(auto i: adjList){
            cout<<i.first<<" -> ";
            for(int j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
class graph_By_Matrix{
    public:
    int vertices;
    vector<vector<int>> adjMat;

    graph_By_Matrix (int ver){
        vertices = ver;
        adjMat.resize(ver,vector<int>(ver,0));
    }
    void addEdge(int u, int v){
        if(isValid(u) && isValid(v)){
            adjMat[u][v] = 1;
            adjMat[v][u] = 1;
        }
    }
    void display(){
        for(auto i: adjMat){
            for(int j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    private:
    bool isValid(int vertex){
        return vertex>=0 && vertex<vertices;
    }
};

int main(){
    cout<<"Implementation through Adjacency List: "<<endl;
    graph_By_List g1;
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.display();
    cout<<endl<<"Implementation through Adjacency Matrix: "<<endl;
    graph_By_Matrix g2(4);
    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.display();
}
