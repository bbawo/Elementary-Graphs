#ifndef UGRAPH_H
#define UGRAPH_H

#include <vector>
#include <utility>

class UndirectedGraph
{
    public:
        UndirectedGraph( int  m );
        void addEdge( int u, int v, int w);
        void DFS();
        void BFS(); 
        void FoFs();
        void print();
    private:
        int n;  //no. of vertices
        std::vector<std::vector<std::pair<int, int>>> edges;   
        std::pair<int, int> LongestFriendship( int v ); //return the index and no.of days v has longest friendship with
        std::vector<int> fof;                           //vector of number of friends of friends of each vertex
        void DFSUtil( std::vector<char> &colors, int u );   //DFS utility function

};

#endif