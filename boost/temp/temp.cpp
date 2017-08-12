 const int V = 2;
  typedef ... UndirectedGraph;
  UndirectedGraph undigraph(V);

  std::cout << "the edges incident to v: ";
  boost::graph_traits<UndirectedGraph>::out_edge_iterator e, e_end;
  boost::graph_traits<UndirectedGraph>::vertex_descriptor
    s = vertex(0, undigraph);
  for (boost::tie(e, e_end) = out_edges(s, undigraph); e != e_end; ++e)
    std::cout << "(" << source(*e, undigraph)
              << "," << target(*e, undigraph) << ")" << endl;
