#include "Graph.h"
#include <iostream>
#include <sstream>

using namespace std;


Graph<int> createTestFlowGraph() {
    Graph<int> myGraph;

    for (int i = 1; i < 7; i++)
        myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 3);
    myGraph.addEdge(1, 3, 2);
    myGraph.addEdge(2, 5, 4);
    myGraph.addEdge(2, 4, 3);
    myGraph.addEdge(2, 3, 1);
    myGraph.addEdge(3, 5, 2);
    myGraph.addEdge(4, 6, 2);
    myGraph.addEdge(5, 6, 3);

    return myGraph;
}

void testFordFulkerson() {
    Graph<int> graph = createTestFlowGraph();
    graph.fordFulkerson(1, 6);

    stringstream ss;
    for (auto v : graph.getVertexSet()) {
        ss << v->getInfo() << "-> (";
        for (auto e : v->getAdj())
            ss << (e->getDest())->getInfo() << "[Flow: " << e->getFlow() << "] ";
        ss << ") || ";
    }

    string expected = "1-> (2[Flow: 3] 3[Flow: 2] ) || 2-> (5[Flow: 1] 4[Flow: 2] 3[Flow: 0] ) || 3-> (5[Flow: 2] ) || 4-> (6[Flow: 2] ) || 5-> (6[Flow: 3] ) || 6-> () || ";

    if (ss.str() == expected)
        cout << "Success!" << endl;
    else {
        cout << "Failed:" << endl;
        cout << "Expected: " << expected << endl;
        cout << "Actual : " << ss.str() << endl;
    }

}

int main(int argc, char const *argv[]) {
    testFordFulkerson();
    return 0;
}
