#ifndef DGRAPH_H
#define DGRAPH_H

#include <vector>
#include <iostream>

class DirectedGraph
{
    public:
        DirectedGraph(int  m );
        void addEdge(int u, int v);  
        void DFS();
        void BFS();
        void popularity();
    private:
        void DFSUtil( std::vector<char> &colors, int u );
        std::vector<std::vector<int>> edges;
        int n;  // no. of vertices
};


#endif