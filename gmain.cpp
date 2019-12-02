#include <iostream>
#include <fstream>
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

int main()
{

    std::string fileName;
    bool isDirected, isWeighted;
    int  n, m, u, v;
    
    std::cout << "Please Enter file name :" << std::endl;
    std::cin >> fileName;

    std::ifstream file( fileName );

   file >> isDirected >> isWeighted >> n >> m;

   if (isDirected && !isWeighted)
   {
       DirectedGraph dgraph( n );
       while(file >> u >> v)
       {
           dgraph.addEdge( u, v);
       }
       file.close();
       dgraph.DFS();
       dgraph.BFS();
       dgraph.popularity();
    }else if ( !isDirected && isWeighted )
    {
        UndirectedGraph ugraph( n );
        int w;
        while(file >> u >> v >> w)
        {
           ugraph.addEdge( u, v, w);
        }
        file.close();
        ugraph.DFS();
        ugraph.BFS();
        ugraph.FoFs();
        ugraph.print();
    }else
        std::cout << " File not suitable for precessing... " << std::endl;

    return 0;
}
