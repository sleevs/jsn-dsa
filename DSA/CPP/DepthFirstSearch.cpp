#include <iostream>
#include <list>

using namespace std ;

class Graph{


    int vertives ;
    list<int> *adj ;


    void dfsUtil(int vetices , bool visited[]);

    public : Graph(int verices);


    void addEdge(int vertices , int w);

    void dfs(int vertices);

};


Graph::Graph(int vertices){
    this->vertives = vertices ;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int vertices , int w){
    adj[vertices].push_back(w);
}

void Graph::dfsUtil(int vertices , bool visited[]){

    visited[vertices] = true ;
    cout << vertives << " ";


    for(auto i = adj[vertices].begin() ; i != adj[vertices].end() ; ++i)
        if(!visited[*i])
            dfsUtil(*i , visited);
        
}


void Graph::dfs(int vertices){

    bool *visited = new bool[vertices];
    for(int i = 0 ; i< vertices ; i++)
        visited[i] = false ;

        dfsUtil(vertices , visited) ;
}

int main(){
    
    std::cout << " MUNIZ SOARES ENGENHARIA DE SOFTWARE ";
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.dfs(0);

    return 0 ;
}