
#include <iostream>
#include <vector>
#include <unordered_set>


/*

A greedy algorithm is an algorithm that always chooses the best possible option at 
each step without considering future steps. 
The algorithm typically starts with a  small solution and then improves it 
by making local changes that do not affect the global optimum.
*/


using namespace std ;


class Graph{

    private: int numVertices ;
    private: vector<unordered_set<int>> adjacencyList ;


    public: Graph(int numVertices){
        this->numVertices = numVertices;
        this->adjacencyList.resize(numVertices);
    }


    void addEdge(int source , int destination){

        adjacencyList[source].insert(destination);
        adjacencyList[destination].insert(source);
    }

    private: int countDegree(int vertex , unordered_set<int>& visited){

        int degree = 0 ;

        for(int neighbor : adjacencyList[vertex]){

            if(visited.find(neighbor) == visited.end()){
                degree ++ ;
            }
        }
        return degree ;
    }


    public: vector<int> greedyAlgorithm(){

        unordered_set<int> visited ;
        vector<int> coveringSet ;

        while(visited.size() < numVertices){

            int maxDegreeVertex = -1 ;
            int maxDegree = -1 ;

            for(int vertex =0 ; vertex < numVertices ; vertex++){ 

                if(visited.find(vertex) == visited.end()){

                    int degree = countDegree(vertex, visited);

                    if(degree > maxDegree){
                        maxDegree = degree;
                        maxDegreeVertex = vertex ;
                    }
                }

            }

            visited.insert(maxDegreeVertex);
            coveringSet.push_back(maxDegreeVertex);
        }

        return coveringSet;
    }
};


int main (){

    int numberOfVertices = 7 ;

    Graph graph (numberOfVertices);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(4,6);


    vector<int> coveringSet = graph.greedyAlgorithm();

    for(int vertex : coveringSet){

        cout << vertex << " ";
    }

    return 0 ;

}