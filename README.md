
# Research and demostration of some algorithms


-  [Depth first search Algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/DepthFirstSearch.cpp)

**Behavior**: Is a recursive algorithm for search all the vertices of graph or tree data structure.
 The algorithm starts at the root (top) node of a tree and goes as far as it can down a given branch (path), then backtracks until   
 it finds an unexplored path, and then explores it.

Develop by :  Charles Pierre Trémaux in in the 19th century.

-  [Breadth First Search algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/BreadthFirstSearch.cpp)

**Behavior**: this algorithm traverses a graph in a breadth motion to search a graph data structure for a node
that meets a set of criteria. It uses a queue to remember the next vertice to start a search when a dead end occurs in
any iteraction.

Develop by : Konrad Zuse in 1945.

-  [Dijkstra algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/Dijkstra.cpp)

**Behavior**: is a method for finding the shortest paths between a single
 source vertex and each of the other vertices in a weighted digraph. Give the algorithm a weighted graph, and it’ll return the shortest path between the selected node and all other nodes. It is similar to Dijkstra’s algorithm but slower. However, its versatility, which means it can handle both negative-weighted and positive-weighted edges, makes it a popular choice

Develop by : Edsger W. Dijkstra in 1956

-  [Bellman Ford algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/bellman_ford_algorithm.cpp)

**Behavior**: is a method for finding the shortest paths between a single
 source vertex and each of the other vertices in a weighted digraph.
 Give the algorithm a weighted graph, and it’ll return the shortest path between the selected
 node and all other nodes. It is similar to Dijkstra’s algorithm but slower. However, its versatility, 
 which means it can handle both negative-weighted and positive-weighted edges, makes it a popular choice.

Develop by :  Alfonso Shimbel (1955) ,Lester Ford Jr (1956) and Richard Bellman (1958) .

-  [Boyer more algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/boyer_more_algorithm.cpp)

**Behavior**: This algorithm recceive a array of char with as pattern to be search in a text. So the algorithm
return a array with position where was found in the text. The algorithm utilize a table with the last ocurrence
to determine which caracter can be jump in which iteraction. First it compare the caracter of pattern with text
from right to left . If not exist any ocurrence , the algorithm uses the table to find the last ocorrence to jump
the max character possible.

Develop by : in 1977, Robert S. Boyer and J Strother Moore .

- [Floyd Warshall algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/floyd_warshall.cpp)

**Behavior**: This algorithm find a minimum distances between two vertices in a graph structure
the algorithm initiate with a matrix with all distances unknow as INT_MAX and the knew distances as 
the graph values.
Next the algorithm iterate with all vertices intermediate and update the mimimum distances between 
the pair of vertices with the statement: dit[i][j] = min

Develop by : Robert Floyd and also by Stephen Warshall in 1962

-  [Greedy algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/greedy_algorithm.cpp)

**Behavior**: A greedy algorithm is an algorithm that always chooses the best possible option at 
each step without considering future steps. 
The algorithm typically starts with a  small solution and then improves it 
by making local changes that do not affect the global optimum.
   
-  [Kruskal algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/kruskal_algorithm.cpp)

**Behavior**: The Kruskal algorithm is a graph theory algorithm used to find the minimum spanning tree for a given graph.
The algorithm works by starting with all the vertices in the graph and connecting them to form a tree.
The tree is then trimmed by removing the edges that are not part of the minimum spanning tree.

Develop by : by Joseph Kruskal in 1956.

- [Max flow algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/max_flow.cpp)

**Behavior**: The maximum flow algorithm is a graph theory algorithm used to find the maximum possible flow between two nodes in a graph. It is a more sophisticated algorithm that considers each edge’s  capacity in the graph.

Develop by : In 1955, Lester R. Ford, Jr. and Delbert R. Fulkerson

- [Prim algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/prim_algorithm.cpp)

**Behavior**: This algorithm utilize a queue to select a edge with minimum weight in each itaraction.
The algorithm stay the information about the visited vertice with pair key/weight.

Develop by : by Vojtěch Jarník in 1930.

- [Topological Sort algorithm](https://github.com/sleevs/jsn-dsa/blob/main/DSA/CPP/topological_sort.cpp)

**Behavior**: This is a sort algorithm that receive a graph as parameter which represents a directed graph
where the edges are dependency of the vertices
The algorithm utilize a deph first search to each vertice when finish all vertices  the
the algorithm return a stack with all vertices sorted topologically.
 
