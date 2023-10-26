#include<iostream>
#include<vector>
#include<queue>
#include<limits>




/*

*/
#define INF std::numeric_limits<int>::max()

class Edge{

    public : int destination;
    public : int weight ;

    public : Edge(int d , int w) : destination(d) , weight(w){}

};

class Graph{

public : 
     int numVertices ;
     std::vector<std::vector<Edge> > adjacencyList ;

    Graph(int num ) : numVertices(num){
        adjacencyList.resize(num);

    }

     void addEdge(int source , int destination , int weight){

        adjacencyList[source].push_back(Edge(destination , weight));
        adjacencyList[destination].push_back(Edge(source , weight));
    }

    public : std::vector<int> dijkstra(int starVertice){

        std::vector<int> distances(numVertices, INF);
        std::vector<bool> visited(numVertices, false);
        std::priority_queue<std::pair<int , int> ,
        std::vector<std::pair<int , int > >, 
        std::greater<std::pair<int , int> > > pq ;

        distances[starVertice] = 0 ;

        pq.push(std::make_pair(0, starVertice));

        while (!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            if(visited[u]){
                continue;
            }
             visited[u] = true ;

             for(std::vector<Edge>::const_iterator it = adjacencyList[u].begin() ; it != adjacencyList[u].end(); ++it){

                int v = it->destination;
                int weight = it->weight;

                if(distances[u] + weight < distances[v]){
                    distances[v] = distances[u] + weight ;
                    pq.push(std::make_pair(distances[v], v));
                }
             }
        }
        return distances ;
       
        
    }

};



int main (){


    std::cout << "MUNIZ SOARES ENGENHARIA DE SOFTWARE ";

    int numVertices = 0 ;

    Graph g(numVertices);

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,3,1);
    g.addEdge(2,3,3);
    g.addEdge(3,4,2);

    int start = 0 ;
    std::vector<int> distances = g.dijkstra(start);

    for(int i = 0 ; i < numVertices ; i++){
        std::cout << " VERTEX " << i << " - " << distances[i] << std::endl ;
    }
    return 0 ;
}