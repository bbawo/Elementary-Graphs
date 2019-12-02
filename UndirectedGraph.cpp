#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include "UndirectedGraph.h"


UndirectedGraph::UndirectedGraph( int n )
{
    this->n = n;
    edges.resize( n );
    fof.resize( n );
}

//add edge: second vertex and weight stred as pairs
void UndirectedGraph::addEdge( int u, int v, int w)
{
    edges[u].push_back( std::make_pair(v, w) );
    edges[v].push_back( std::make_pair(u, w) );
}

void UndirectedGraph::BFS()
{
    std::vector<char> colors( n, 'w');
    std::queue<int> q;
    std::cout << "BFS traversal: ";
    q.push( 0 );

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(  std::pair<int, int> v: edges[u] )
        {
            if ( colors[v.first] == 'w')
            {
                colors[v.first] = 'g';
                q.push( v.first );
            }
        }
        colors[u] = 'b';
        std::cout << u << ' ';
    }
    std::cout << std::endl;
}

void UndirectedGraph::DFS()
{
    std::vector< char > colors( n, 'w');
    std::cout << "DFS traversal: ";

    for( int i = 0; i < n; ++i)
        if(colors[i] == 'w' )
            DFSUtil(colors, i);
   
    std::cout << std::endl;
}

void UndirectedGraph::DFSUtil( std::vector< char > &colors, int u )
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
            if ( colors[edges[u][v].first] == 'w')
                mystack.push(edges[u][v].first);
    }
}

//Find unique friends of friends and push into  uniqueElements then store the size of uniqueElements in fof vector
void UndirectedGraph::FoFs()
{   
    std::list<int> templist;    //temporary storage

    for( int v = 0; v < n; v++ )
    {
        for( int i = 0; i < edges[v].size(); i++ )
        {   
            for( std::pair<int, int> &j : edges[edges[v][i].first])
                templist.push_back( j.first );
        }
        templist.sort();
        templist.unique();
        fof[v] = templist.size() - 1;
        templist.clear();
    }
}

//return the index and no.of days v has longest friendship with
std::pair<int, int> UndirectedGraph::LongestFriendship( int v )
{
    int longest = 0;
    int index = 0;
    for ( std::pair<int, int> i : edges[v])
    {
        if( i.second > longest )
        {
            longest = i.second;
            index = i.first;
        }    
    }
    return (std::make_pair(index, longest));
}

void UndirectedGraph::print()
{   
    for ( int i = 0; i < n; i++)
    {   
        std::cout << "Person " << i << " has " 
        << edges[i].size() << " friends  and " 
        << fof[i] << " FoFs, oldest friend is " 
        << LongestFriendship( i ).first << "("
        << LongestFriendship( i ).second << ")" << std::endl;
    }
}