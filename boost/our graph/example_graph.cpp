//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee,
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <boost/config.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/pending/indirect_cmp.hpp>
#include <boost/range/irange.hpp>

int main()
{
  using namespace boost;
  using namespace std;
  int N;
  const int name[] = { 1,2,3,4,5,6,7,8,9
  };

  cout <<"nu daal: ";
  cin >> N;
  adjacency_list <> g(N);
  while(1){
    int s,d;
    cout << "source aur desti daal: ";
    cin >> s >> d;

    if(s >= 0 && d >= 0 ){
      add_edge(s, d, g);
    }
    else{
       cout << "bass\n";
       break;
    }
  }

//  add_edge(Jeanie, Debbie, g);
//  add_edge(Jeanie, Rick, g);
//  add_edge(Jeanie, John, g);
//  add_edge(Debbie, Amanda, g);
//  add_edge(Rick, Margaret, g);
//  add_edge(John, Benjamin, g);
//  add_edge(Benjamin,Shashank ,g);
//  add_edge(Margaret,Shashank ,g);

  graph_traits < adjacency_list <> >::vertex_iterator i, end;
  graph_traits < adjacency_list <> >::adjacency_iterator ai, a_end;
  property_map < adjacency_list <>, vertex_index_t >::type
    index_map = get(vertex_index, g);

  for (boost::tie(i, end) = vertices(g); i != end; ++i) {
    std::cout << name[get(index_map, *i)];
    boost::tie(ai, a_end) = adjacent_vertices(*i, g);
    if (ai == a_end)
      std::cout << " has no children";
    else
      std::cout << " is the parent of ";
    for (; ai != a_end; ++ai) {
      std::cout << name[get(index_map, *ai)];
      if (boost::next(ai) != a_end)
        std::cout << ", ";
    }
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}
