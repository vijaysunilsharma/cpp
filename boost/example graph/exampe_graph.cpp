#include <boost/graph/adjacency_list.hpp>
#include <iostream>
using namespace boost ;
using namespace std ;

int main()
{
   adjacency_list<> g;
   typedef adjacency_list<>::vertex_descriptor  vertex ;

   vertex v1 =  add_vertex(g);
   adjacency_list<>::vertex_descriptor v2 =  add_vertex(g);
   adjacency_list<>::vertex_descriptor v3 =  add_vertex(g);
   adjacency_list<>::vertex_descriptor v4 =  add_vertex(g);
   adjacency_list<>::vertex_descriptor v5 =  add_vertex(g);
   adjacency_list<>::vertex_descriptor v6 =  add_vertex(g);

   add_edge(0, 3, g ) ;
   add_edge(2, 3, g ) ;
   add_edge(v3, v4, g ) ;
   add_edge(v3, v5, g ) ;
   add_edge(v3, v6, g ) ;
   add_edge(v5, v6, g ) ;

  cout << v1 << ", " << v2 << ", " << v3 << ", " << v4 << v5  << v6 <<'\n';
}
