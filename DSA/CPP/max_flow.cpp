

#include <iostream>
#include <vector>
#include <queue>
#include <limits>


constexpr int INF = std::numeric_limits<int>::max();

class Graph{

    private:
        int numVertices ;
        std::vector<std::vector<int>> adjMatrix ;

    public: 
            Graph (int numVertices ) : numVertices(numVertices)
        , adjMatrix(numVertices , std::vector<int>(numVertices, 0)){}

        void add(int source , int destination , int capacity){
            adjMatrix[source][destination]=  capacity ;
        }

        
        bool breadthFirstSearch(const std::vector<std::vector<int>>& graph , int source , int destination , std::vector<int>& parent ){

            std::vector<bool> visited(numVertices, false);
            std::queue<int> queue ;

            visited[source] = true ;
            parent[source] = -1;
            queue.push(source);

            while(!queue.empty()){

                int u = queue.front() ;
                queue.pop();

                for(int i = 0 ; i < numVertices ; i++){

                    if(!visited[i] && graph[u][i] > 0){
                        visited[i] = true;
                        parent[i] = u ;
                        queue.push(i);
                    }
                }
            }
            return visited[destination];
        }

        int maxFlow(int source , int destination){

            std::vector<std::vector<int>> residualGraph = adjMatrix ;
            std::vector<int> parent(numVertices, -1 );
            int max_flow = 0 ;

            while ( breadthFirstSearch(residualGraph , source , destination , parent) ){

                int path_flow = INF ;

                for(int i = destination ; i != source ; i = parent[i]){
                    int u = parent[i];
                    path_flow = std::min(path_flow , residualGraph[u][i]);
                }

                for(int i = destination ; i != source ; i = parent[i]){
                    int u = parent[i];
                    residualGraph[u][i] -= path_flow ;
                    residualGraph[i][u] += path_flow ;
                }
                max_flow += path_flow ;
            }
            return max_flow ;
        }
};




int main(){

    Graph graph(6);
    graph.add(0,1,16);
    graph.add(0,2,13);
    graph.add(1,2,10);
    graph.add(1,3,12);
    graph.add(2,1,4);
    graph.add(3,2,9);
    graph.add(3,5,20);
    graph.add(4,3,7);
    graph.add(4,5,4);
    
    int source = 0 ;
    int destination = 5 ;

    int maxFlowValue = graph.maxFlow(source , destination);

    std::cout<< " MAX FLOW IS : " << maxFlowValue <<std::endl;

    return 0 ;
}
