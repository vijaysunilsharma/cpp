#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;

int main(int,char*[])
{
  // Create a graph object
  Graph g(3);

  boost::add_edge(0,1,g);
  boost::add_edge(1,2,g);


  int numberOfOutEdges = boost::out_degree(1,g);
  std::cout << "numberOfOutEdges: " << numberOfOutEdges << std::endl;



  return 0;
}
