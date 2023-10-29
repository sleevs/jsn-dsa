#include <iostream>
#include <vector>
#include <queue>

/*

ALGORITIMO DE ORDENAÇÃO TOPOLÓGICA  
ELE RECEBE UM GRAFO COMO ARGUMENTO QUE REPRESENTA O GRAFO 
DIRECIONADO ONDE AS ARESTA SÃO DEPENDÊNCIAS ENTRE OS NÓS

A FUNÇÃO UTILIZA UMA ABORDAGEM DE BUSCA EM PROFUNDIDADE dfs PARA O GRAFO.
PARA CADA NÓ NÃO VISITADO dfs É CHAMADA RECURSIVAMENTE PARA EPLORAR OS NÓS ADJACENTES.

QUANDO NÃO HÁ MAIS NÓS NÃO VISITADOS ADJACENTES , O NÓ É A ADICIONADO AO INÍCIO DA PILHA stack.
NO FIM A FUNÇÃO RETORNA A PILHA stack CONTENDOOS NÓS ORDENADOS TOPOLOGICAMENTE
*/

class Graph {

    private: std::vector<std::vector<int>> adjacentyList ;

    public:
        Graph(int numVertices) : adjacentyList(numVertices) {}


    void addEdge( int source , int destination){
        adjacentyList[source].push_back(destination);
    }

    std::vector<int> totpologicalSort(){

        std::vector<int> inDegree(adjacentyList.size() , 0);

        for(const auto& neighbors : adjacentyList){

            for(int vertex : neighbors){
                inDegree[vertex]++;
            }
        }

        std::queue<int> zeroInDegreeVertices ;
        for(int i = 0 ; i < inDegree.size() ; i++){

            if(inDegree[i] == 0){
                zeroInDegreeVertices.push(i);
            }
        }

        std::vector<int> sortedOrder;

        while(!zeroInDegreeVertices.empty()){

            int vertex = zeroInDegreeVertices.front();
            zeroInDegreeVertices.pop();
            sortedOrder.push_back(vertex);

            for(int neighbor : adjacentyList[vertex]){
                inDegree[neighbor]-- ;
                if(inDegree[neighbor] == 0){
                    zeroInDegreeVertices.push(neighbor);
                }
            }
        }

        if(sortedOrder.size() != adjacentyList.size()){

            return std::vector<int>();
        }

        return sortedOrder;
    }

};

int main(){

    std::cout << "MUNIZ SOARES ENGENHARIA DE SOFTWARE \n" ;


    Graph graph(6);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);

    std::vector<int> sort = graph.totpologicalSort();

    if(sort.empty()){

        std::cout << "o grafo contem um ciclo" << std::endl ;
    }else{

        std::cout << "ordem topological do grafo " << std::endl ;
        for(int vertex : sort){
            std::cout << " "<< vertex;
        }
        std::cout << std::endl ;
    }

    return 0 ;
}