


/*
FLOYDWARSHALL IMPLEMENTA O ALGORITIMO PARA ENCONTRAR AS DINSTÂNCIAS MÍNIMAS ENTRE OS PARES
DE VÈRTIES EM UM GRAFO DIRECIONADO OU PONDERADO .
A FUNÇÃO RECEBE UMA MATRIZ DE ADJACÊNCIA "GRAPH" EM QUE GRAPH[i][j]
REPRESENTA O CUSTO DA ARESTA DO VÉRTICE i PARA O VÉRTICE j
OS VALORES 0 representam aresta de custo zero 
e INT_MAX É USADO PARA REPRESENTAR A FALTA DE UMA ARESTA ENTRE VÉRTICES.

O ALGORITIMO COMEÇA INICIALIZANDO UMA MATRIZ dist COM TODAS AS DINSTÂNCIAS DESCONHECIDAS COMO INT_MAX 
E AS DISTÂNCIAS CONHECIDAS COMO OS VALORES DO GRAGPS .
EM SEGUIDA , ELE ITERA POR TODOS OS VÉRTICES INTERMEDIÁRIOS E ATUAIZA AS DISTÂNCIAS MÍNIMAS ENTRE
OS PARE DE VÉRTICES USANDO A FÓRMULA dit[i][j] = min

*/

#include <iostream>
#include <vector>
#include <climits>


void floyWarshall(std::vector<std::vector<int>>& graph){
    
    int V = graph.size();

    std::vector<std::vector<int>> dist(V, std::vector<int>(V, INT_MAX));

    for(int i = 0 ;  i < V ; i++){
        dist[i][i] = 0 ;
    }


        /* PREENCHIMENTO DAS DISTANCIAS CONHECIDAS*/
    for(int i = 0 ;  i < V ; i++){
        for(int j = 0 ; j < V ; j++){

            if(graph[i][j] != 0){

                dist[i][j] = graph[i][j];
            }
        }
    }

    /* EXECUTANDO O ALGORITIMO*/
    for(int k = 0 ; k < V ; k++){

        for(int i = 0 ; i< V; i++){
            
            for(int j = 0 ; j < V ; j++){

                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    std::cout << "MATRIZ DE DISTANCIAS MINIMAS " << std::endl;

    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){

            if(dist[i][j] == INT_MAX){
                std::cout << "INF ";
            }else{
                std::cout << dist[i][j] << " ";
            }
        }

        std::cout<< std::endl ;
    }

}


int main(){

    std::cout << "MUNIZ SOARES ENGENHARIA DE SOFTWARE\n"<<std::endl;

    int V =4 ;
    std::vector<std::vector<int>> graph = {
        {0,5,INT_MAX ,10},
        {INT_MAX , 0,3 ,INT_MAX},
        {INT_MAX , INT_MAX , 0 ,1},
        {INT_MAX , INT_MAX, INT_MAX, 0}
    };

    floyWarshall(graph);

    return 0 ;
}