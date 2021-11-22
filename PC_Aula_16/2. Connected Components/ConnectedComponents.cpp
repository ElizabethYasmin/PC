#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};

void Graph::connectedComponents(){
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
    int cont = 0;
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            cont++;
            DFSUtil(v, visited);
            cout << "\n";
        }
    }
    cout << cont << " Components connect\n";
    delete[] visited;
}
 
void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    char _node = 'a' + v;
    cout << _node << ",";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main(){  
    int N, V, E;
    char a, b;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V >> E;
        Graph* graph = new Graph(V);
        for(int j=0; j<E; j++){
            cin >> a >> b;
            int x = a-97,y = b-97;;
            graph->addEdge(x,y);
        }
        cout << "Case #" << i+1 << ":\n";
        graph->connectedComponents(); cout << "\n";
        delete graph;
    }
    return 0;
}