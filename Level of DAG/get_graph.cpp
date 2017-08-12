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
