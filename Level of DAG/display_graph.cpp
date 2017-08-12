//Displays passed graph
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
