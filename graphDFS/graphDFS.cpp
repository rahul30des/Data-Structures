#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;


class Graph {
  int V;
  unordered_map<int,list<int>> adj_mat;
  unordered_map<int,bool> visited;
  public:
  
  Graph(int v){
    V = v;
    for(int i = 0; i < V; i++) {
      visited[i] = false;
    }
  }
  
  void AddEdge(int v, int w) {
    adj_mat[v].push_back(w);
  }
  
  void DFS(int v) {
      cout<<" "<<v<<" ";
      visited[v] = true;
      for(auto it = adj_mat[v].begin(); it != adj_mat[v].end(); it++) {
        if(visited[*it] == false) {
          DFS(*it);
        }
      }
    }
};

int main() {
  Graph *g = new Graph(4);

  g->AddEdge(0, 1);
  g->AddEdge(0, 2);
  g->AddEdge(1, 2);
  g->AddEdge(2, 0);
  g->AddEdge(2, 3);
  g->AddEdge(3, 3);
  
  g->DFS(2);
  
  return 0;
}
