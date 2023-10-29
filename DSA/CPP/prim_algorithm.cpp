

#include <iostream>
#include <vector>
#include <queue>




/*

o método primMST implementa o algoritimo de Prim para encontrar a ARVORE DE ABRANGÊNCIA MÍNIMA
 MST(Minimum Spanning Tree) .
Ele utilizauma fila de prioridade (priority_queue) para selecionar a aresta(edge) de menor peso
em cada iteração . 
O algoritimo mantém informações sobre vértices visitados , os Pais de cada vértice e 
as chaves (peso/weight) dos vértices .

*/
using namespace std ;


typedef pair <int , int> pii ;


class Graph{


    private: 
        int numVertices;
        vector<vector<pii>> adjacencyList ;


    public:
        Graph(int numVertices) : numVertices(numVertices){
            adjacencyList.resize(numVertices);
        }


    void addEdge(int source , int destination , int weight){

        adjacencyList[source].push_back(make_pair(destination, weight));
        adjacencyList[destination].push_back(make_pair(source , weight));
    }


    void primMST(){

        vector<bool> visited(numVertices , false);
        vector<int> parent(numVertices , -1);
        vector<int> key(numVertices , __INT_MAX__);

        auto compare = [] (const pii& lhs , const pii& rhs){
            return lhs.second > rhs.second ;
        };

        priority_queue<pii , vector<pii> , decltype(compare)> pq(compare);

        int starVertex = 0 ;
        pq.push(make_pair(starVertex , 0));
        key[starVertex] = 0 ;


        while(!pq.empty()){

            int u = pq.top().first;

            pq.pop();

            visited[u] = true ;

            for(const auto& neighbor : adjacencyList[u]){

                int v = neighbor.first ;
                int weight = neighbor.second ;

                if(!visited[v] && weight < key[v]){

                    parent[v] = u ;
                    key[v] =weight;
                    pq.push(make_pair(v , weight));
                }
            }
        }

        cout << "MINIMUM SPANNING TREE" << endl;
        for(int i = 1 ; i < numVertices ; i++){
            cout << parent[i] << " --- "<< i << endl ;
        }
    }
};


int main(){

    std::cout << "MUNIZ SOARES ENGENHARIA DE SOFTWARE \n";
    int vertices = 6 ;
    Graph graph(vertices);

    graph.addEdge(0,1 ,4);
    graph.addEdge( 0,2,3);
    graph.addEdge( 1,2,1);
    graph.addEdge( 1,3,2);
    graph.addEdge( 2,3,4);
    graph.addEdge( 2,4,3);
    graph.addEdge( 3,4,2);
    graph.addEdge( 3,5,1);
    graph.addEdge( 4,5,6);

    graph.primMST();
    return 0 ;
}