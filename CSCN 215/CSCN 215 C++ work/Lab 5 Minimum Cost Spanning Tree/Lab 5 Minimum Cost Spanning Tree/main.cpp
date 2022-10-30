#include <iostream>
#include <memory>
#include "GraphAM.h"

int main()
{
    cout << "Andres Choque - Lab 5: Minimum Cost Spanning Tree" << endl;

    unique_ptr<GraphAM> graph = make_unique<GraphAM>("inputgraph.txt");
    graph->print(false);
    graph->write("outputgraph.txt");
    GraphAM* mcst1 = graph->MCST(0); // also implemented the smart pointers here
    GraphAM* mcst2 = graph->MCST(4);
    GraphAM* mcst3 = graph->MCST(2);

    mcst1->write("mcst1.txt");
    mcst2->write("mcst2.txt");
    mcst3->write("mcst3.txt");
}