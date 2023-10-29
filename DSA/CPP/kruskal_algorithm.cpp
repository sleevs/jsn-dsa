
/*
The Kruskal algorithm is a graph theory algorithm used to find the minimum spanning tree for a given graph.
 The algorithm works by starting with all the vertices in the graph and connecting them to form a tree.
 The tree is then trimmed by removing the edges that are not part of the minimum spanning tree.
 
 Applications of Kruskal

    Designing rail and road networks to connect several cities
    Placing microwave towers
    Designing irrigation channels
    Designing fiber-optic grids
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std ;




struct Edge {

    int source , destination , weight ;
};


struct DisjoinSet{

    vector<int> parent , rank ;

    DisjoinSet(int n){
        parent.resize(n);
        rank.resize(n , 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i ;
        }
    }

    int find(int x){

        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unioSet(int x , int y){

        int xRoot = find(x);
        int yRoot = find(y);


        if(rank[xRoot] < rank[yRoot]){
            parent[xRoot] = yRoot ;
        }else if(rank[xRoot] > rank[yRoot]){
            parent[xRoot] = xRoot ;
        }else {
            parent[yRoot] = xRoot ;
            rank[xRoot] ++ ;
        }
    }
};


bool compareEdge(const Edge& edge1 , const Edge& edge2){

    return edge1.weight < edge2.weight ;
}


void kruskal(vector<Edge>& edges , int numVerices){

    sort(edges.begin() , edges.end() , compareEdge);

    DisjoinSet disjoiSet(numVerices);
    vector<Edge> mst ;

    for(const Edge& edge : edges){

        int u = edge.source;
        int v = edge.destination ;

        int uRoot = disjoiSet.find(u);
        int vRoot = disjoiSet.find(v);

        if(uRoot != vRoot){
            disjoiSet.unioSet(uRoot , vRoot);
            mst.push_back(edge);
        }
    }

    cout << " " ;

    for(const Edge& edge : mst){
        cout << edge.source << " : " << edge.destination << " : " << edge.weight ;
    }
}


int main(){

    int numVertices = 6 ;

    vector<Edge> edges ={

        {0,1,4},
        {0,2,3},
        {1,2,1},
        {1,3,2},
        {2,3,4},
        {2,4,3},
        {3,4,2},
        {3,5,1},
        {4,5,6}

    };

    kruskal(edges, numVertices);

    return 0 ;
}