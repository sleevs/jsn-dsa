/*
The Bellman-Ford procedure is a method for finding the shortest paths between a single
 source vertex and each of the other vertices in a weighted digraph.
  Give the algorithm a weighted graph, and it’ll return the shortest path between the selected
   node and all other nodes. It is similar to Dijkstra’s algorithm but slower. However, its versatility, 
   which means it can handle both negative-weighted and positive-weighted edges, makes it a popular choice.

Applications of Bellman-Ford

    It is used in distance-vector routing protocols, e.g., in Routing Information Protocols (RIPs).
    It is used in the Maximum Weighted Matching problem, a problem in graph theory.
    It is used in the All-Pairs Shortest Paths problem.
    In chemical reactions computing the smallest possible heat loss/gain.
    Identifying the currency conversion method that’d be most efficient
*/


#include <iostream>
#include <vector>
#include <limits.h>


using namespace std;


struct Edge{

    int source , destination , weight ;
};



void bellmanFord(vector<Edge>& edges , int numVertices , int source ){

    vector<int> dist(numVertices , INT_MAX);
    dist[source] = 0 ;

    for(int i = 0 ; i < numVertices - 1 ; i ++){

        for(const auto& edge : edges){
            int u = edge.source ;
            int v = edge.destination ;
            int weight = edge.weight ;

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){

                dist[v] = dist[u] + weight ;
            }
        }
    }

        for(const auto& edge : edges){

            int u = edge.source ;
            int v = edge.destination;
            int weight = edge.weight ;

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){

                cout << "GRAPH CONTAINS NEGATIVE WEIGHT CYCLE" ;
                return ;
            }
        }

        cout << "SHORTEST DISTANCE FROM SOURCE NODE" << source ;
        for(int i = 0 ; i < numVertices ; i++){
            cout << " NODE " << i << " : " << dist[i] << endl;
        }
}


int main(){


    int numVertices = 5 ;
    vector<Edge> edges = {
        {0,1,6},
        {0,2,7},
        {1,2,8},
        {1,3,-4},
        {1,4,5},
        {2,3,9},
        {2,4,-3},
        {3,1,2},
        {4,0,3},
        {4,3,7},
    };

    int sourceNOde = 0 ;
    bellmanFord(edges , numVertices , sourceNOde);

    return 0 ;
}