#include<iostream>
#include<queue>
#include<list>


using namespace std;

class Graph{

    int vertices;
    list<int>* adjacencyList ;

    public : Graph(int vertices){

        this->vertices = vertices ;
        adjacencyList = new list<int>[vertices];
    }

    public : void addEdge(int source , int destination){
        adjacencyList[source].push_back(destination);
    }

    public : void breadthFirstSearch(int startVertex){

        bool* visited = new bool[vertices] ;

        for(int i = 0 ; i < vertices ; i++){
            visited[i] = false ;
        }

        queue<int> queue;
        visited[startVertex] = true ;
        queue.push(startVertex) ;

        while(!queue.empty()){

            int currentVertex = queue.front();
            cout << currentVertex << " " ;
            queue.pop();

            for(int neighbor : adjacencyList[currentVertex]){

                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        delete[] visited ;
    }

};

int main (){

    std::cout << "MUNIZ SOARES ENGENHARIA DE SOFTWARE ";

    Graph g(6) ;

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(5,4);

    g.breadthFirstSearch(0);

    return 0 ;
}
