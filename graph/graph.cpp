#include<iostream>
#include<list>
#include<set>
#include<queue>
using namespace std;

enum Status {Unvisited, InProgress, Visited};

class Vertex ;

class Edge {
    public:
    Vertex *to;
    int weight;

    Edge(Vertex *to, int weight) {
        this->to = to;
        this->weight = weight;
    }
};

class Vertex {
    public:
    string data;
    list<Edge*> edges;
    Status visited;

    Vertex(string s) {
        this->data = s;
        this->visited = Unvisited;
    }
};


class Graph {
    public:
    set<Vertex*> vertices;

    // DFS
    bool dfs(Vertex *start, string search) {
        cout<<"Visiting Node : "<<start->data<<endl;
        start->visited = InProgress;
        if(start->data == search) {
             return true;
        }
        for(auto it = start->edges.begin(); it != start->edges.end(); it++) {
            if((*it)->to->visited == Unvisited) {
                if(this->dfs((*it)->to,search) == true) {
                    return true;
                }
            }
        }
        start->visited = Visited;
        return false;
    }

    // BFS
    bool bfs(Vertex *start, string search) {
        queue<Vertex *> vq;
        vq.push(start);
        start->visited = Visited;
        while(!vq.empty()) {
           Vertex *v = vq.front();
           vq.pop();
           cout<<"Visiting Node : "<<v->data<<endl;
           if(v->data == search) {
                return true;
           }
           for(auto it = v->edges.begin(); it != v->edges.end(); it++) {
                if((*it)->to->visited == Unvisited) {
                    cout<<"Pushing Node : "<<(*it)->to->data<<endl;
                    vq.push((*it)->to);
                    (*it)->to->visited = Visited;
                }
           }
        }
        return false;
    }
};

int main() {
    Graph *g = new Graph();

    Vertex *s = new Vertex("s");
    Vertex *a = new Vertex("a");
    Vertex *b = new Vertex("b");
    Vertex *c = new Vertex("c");
    Vertex *d = new Vertex("d");

    g->vertices.insert(s);
    g->vertices.insert(a);
    g->vertices.insert(b);
    g->vertices.insert(c);
    g->vertices.insert(d);

    s->edges.push_back(new Edge(a,8));
    s->edges.push_back(new Edge(b,7));

    a->edges.push_back(new Edge(b,10));
    b->edges.push_back(new Edge(c,5));
    d->edges.push_back(new Edge(c,2));
    //cout<<g->dfs(s,"d");
    cout<<g->bfs(s,"d");
    return 0;
}
