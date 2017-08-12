#include <boost/graph/visitors.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace boost;
using namespace std;
typedef boost::adjacency_list< vecS, vecS, directedS >  graph1 ;
typedef boost::graph_traits < graph1 >::in_edge_iterator in_edge_iterator;

void get_graph(graph1 &g, int nodes) ;
void display_graph (graph1 &g );
//void insert_head (graph1 &g, int nodes);

int main() {
    graph1 g ;
    int nodes ;
    cout << "Enter number of nodes :  " ;
    cin >> nodes ;
    get_graph( g, nodes ) ;
//    insert_head(g, nodes) ;
    display_graph (g) ;
    int deg = degree(2, g);
    cout << "\n degree of 2 is " << deg ;
    cout << "\n Calling BFS " ;
     boost::array<int, 6> distances{{0}};
   boost::breadth_first_search(g, 0,
    boost::visitor(
      boost::make_bfs_visitor(
        boost::record_distances(distances.begin(), on_examine_edge() ))));

  std::copy(distances.begin(), distances.end(),
    std::ostream_iterator<int>{std::cout, "\n"});
    return 0 ;
}
