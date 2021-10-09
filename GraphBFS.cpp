#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// BFS (level-order traversal for a graph)

class Graph {
  int V;
  list<int> *adj;
  public:
  Graph(int size) {
    V = size;
    adj = new list<int>[V];
  }
  
  void AddEdge(int v, int w) {
    adj[v].push_back(w);
  }
  
  void BFS(int v) {
    vector<bool> visited(V, false);
    
    queue<int> q;
    visited[v] = true;
    q.push(v);
    
    while(!q.empty()) {
      v = q.front();
      q.pop();
      cout<<" "<<v<<" "<<endl;
      for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if(visited[*it] == false) {
          visited[*it] = true;
          q.push(*it);
        }
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
 
  cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
  g->BFS(2);
  return 0;
}

