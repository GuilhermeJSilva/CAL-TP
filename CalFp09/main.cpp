#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"

using namespace std;


bool testFlow(Graph<string> & graph, string orig, string dest, double expectedFlow) {
    double actualFlow = graph.getFlow(orig, dest);
    if ( actualFlow == expectedFlow)
        return true;
    cout << "Actual flow from " << orig << " to " << dest << " (" << actualFlow << ") different from expected (" << expectedFlow << ")" << endl;
    return false;
}

double testMinCostFlow2() {
    cout << "Running testMinCostFlow2 ... ";

    Graph<string> g;

    g.addVertex("s");
    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("t");

    g.addEdge("s", "a", 3, 0);
    g.addEdge("s", "b", 2, 0);
    g.addEdge("a", "b", 1, -2);
    g.addEdge("a", "c", 3, 1);
    g.addEdge("a", "d", 4, 2);
    g.addEdge("b", "d", 2, 2);
    g.addEdge("c", "t", 2, 1);
    g.addEdge("d", "t", 3, 1);

    double cost = g.minCostFlow("s", "t", 3);

    if (cost != 5) {
        cout << "Actual cost (" << cost << ") different from expected (" << 3 << ")" << endl;
        return 0.0;
    }

    if ( !testFlow(g, "s", "a", 3)
         || !testFlow(g, "s", "b", 0)
         || !testFlow(g, "a", "b", 1)
         || !testFlow(g, "a", "c", 2)
         || !testFlow(g, "a", "d", 0)
         || !testFlow(g, "b", "d", 1)
         || !testFlow(g, "c", "t", 2)
         || !testFlow(g, "d", "t", 1) ) {
        return 0.0;
    }
    cout << "succeeded!" << endl;

    return 1.0;
}

double testMinCostFlow1() {
    cout << "Running testMinCostFlow1 ... ";

    Graph<string> g;

    g.addVertex("s");
    g.addVertex("x");
    g.addVertex("t");

    g.addEdge("s", "t", 3, 1);
    g.addEdge("s", "x", 2, 2);
    g.addEdge("x", "t", 1, 2);

    double cost = g.minCostFlow("s", "t", INF);

    if (cost != 7) {
        cout << "Actual cost (" << cost << ") different from expected (" << 7 << ")" << endl;
        return 0.0;
    }

    if ( !testFlow(g, "s", "t", 3)
         || !testFlow(g, "s", "x", 1)
         || !testFlow(g, "x", "t", 1)) {
        return 0.0;
    }

    cout << "succeeded!" << endl;
    return 1.0;
}

int main(int argc, char const *argv[]) {
    double score1 = testMinCostFlow1();
    double score2 = testMinCostFlow2();
    //double score3 = testComparativePerformanceMinCostFlow();
    cout << "Total score = " << (score1 * 30 + score2 * 30 + 0 * 40) << "%" << endl;
    return 0;
}
