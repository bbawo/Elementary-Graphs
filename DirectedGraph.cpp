#include <iostream>
#include <queue>
#include <stack>
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph( int n )
{
    edges.resize( n );
    this->n = n;
}

// add edge u--v to vector edges
void DirectedGraph::addEdge( int u, int v )
{
    edges[u].push_back( v );
}

void DirectedGraph::BFS()
{
    std::vector<char> colors( n, 'w' );  //colors: 'w'--> not discovered, 'g'-->discovered, 'b'--> done processing 
    std::queue<int> q;
    int u;
    std::cout << "BFS traversal: ";

    colors[0] = 'g';
    q.push( 0 );

    while (!q.empty())
    {
        u = q.front();   //first in 
        q.pop(); //first out implementation

        for( int &v: edges[u] ) 
        {
            if ( colors[v] == 'w')
            {
                colors[v] = 'g';    
                q.push( v );
            }
        }
        colors[u] = 'b';
        std::cout << u << ' ';
    }
    std::cout << std::endl;
}

void DirectedGraph::DFS()
{
    std::vector<char> colors( n, 'w');

    std::cout << "DFS traversal: ";
    for( int i = 0; i < n; i++ )
    {
        if ( colors[i] == 'w' ) 
            DFSUtil( colors, i );
    }
    std::cout << std::endl;
}

//DFS utility function -->> recursive function
void DirectedGraph::DFSUtil( std::vector<char> &colors, int u ) 
{
    std::stack< int > mystack;  // a deque would have been better but I opted for stack

    mystack.push(u);
    while (!mystack.empty())
    {
        u = mystack.top();
        mystack.pop();
        if ( colors[u] == 'w' ) 
        {   
            colors[u] = 'g';
            std::cout << u << ' ';
        }
            
        for( int v = edges[u].size()-1; v >= 0; --v )
            if ( colors[edges[u][v]] == 'w')
                mystack.push(edges[u][v]);
    }
}

//compute popularity and print out everything
void DirectedGraph::popularity()
{   
    std::vector<int> followers( n );
    double popscore;    //popularity score
    int adjListSize;
    int count = 0;

    while( count < n)
    {
        followers[count] = 0;
        count++;
    }

    //compute followers
    for (int i =0; i < n; i++)
        for(const int &j : edges[i])
            followers[j]++;

    //print
    for(int i = 0; i < n; i++)
    {
        adjListSize = edges[i].size();
        if(adjListSize == 0)
        {
            std::cout << "Person " << i << " is "
            << ((followers[i] >= 3) ? "" : "NOT ") 
            << "popular." << "  Followed by : "
            << followers[i] << "  Follows : " << 0 << std::endl; 
        }else
        { 
            popscore = followers[i]/double(adjListSize);
            std::cout << "Person " << i << " is "
            << ((popscore >= 2.0) ? "" : "NOT " ) 
            << "popular.  Popularity score : " 
            << popscore << "  Followed by : "
            <<  followers[i] << "  Follows : "
             << adjListSize << std::endl; 
        }
    }
}
