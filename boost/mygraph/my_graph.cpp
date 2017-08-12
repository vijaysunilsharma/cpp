#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/named_function_params.hpp>
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

void get_graph(graph1 &g, int nodes) ;
void display_graph (graph1 &g );
int my_in_degree (graph1 &g, int node);
graph1::vertex_descriptor insert_head (graph1 &g, int nodes);

int main() {
    graph1 g ;
    int nodes ;
    cout << "Enter number of nodes :  " ;
    cin >> nodes ;
    get_graph( g, nodes ) ;
    graph1::vertex_descriptor head = insert_head(g, nodes) ;
    display_graph (g) ;

    cout << "\n Calling BFS " ;
    boost::array<int, 7> distances{{0}};
    boost::breadth_first_search(g, head,
    boost::visitor(
      boost::make_bfs_visitor(
        boost::record_distances(distances.begin(), on_examine_edge() ))));

  std::copy(distances.begin(), distances.end(),
    std::ostream_iterator<int>{std::cout, "\n"});
    return 0 ;
}

void get_graph(graph1 &g, int nodes) {
    for (int iter = 0 ; iter < nodes ; iter++) {
        int input = 0 ;
        while (input >= 0){
            cout << "\n Enter output edge from " << iter << "(-1 if no edge ) : " ;
            cin >> input ;
            if (input >=  0){
                add_edge(iter, input, g) ;
                }

        }

    }

}

void display_graph (graph1 &g ){
    graph1::vertex_iterator vstart, vfinish ;
    graph1::out_edge_iterator estart, efinish ;
    for(tie(vstart, vfinish) = vertices(g); vstart != vfinish; ++vstart){
        cout << *vstart << "--->" ;
        for(tie(estart, efinish) = out_edges(*vstart, g); estart != efinish; ++estart){
            cout << target(*estart, g )  << "--->" ;;
        }
        cout << "XXX" << endl ;
    }
}

graph1::vertex_descriptor insert_head (graph1 &g, int nodes){
    graph1::vertex_descriptor head = add_vertex(g) ;
    for(int iter = 0; iter < nodes ; iter++ ){
        int deg = my_in_degree(g, iter);
        if (deg == 0){
            add_edge(head, iter, g);
        }

    }
    return head ;

}

int my_in_degree (graph1 &g, int node){
    graph1::edge_iterator first, last ;
    int degree = 0 ;
    for(tie(first, last) = edges(g); first!= last; ++first){
        if (target(*first, g) == node){
        degree++ ;
        }

    }
    cout << "\n degree of "<< node << "is : " << degree ;
    return degree ;
}
