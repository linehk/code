package edu.princeton.cs.algs4;

public class CPM {
  private CPM() {}

  public static void main(String[] args) {
    int n = StdIn.readInt();

    int source = 2 * n;
    int sink = 2 * n + 1;

    EdgeWeightedDigraph G = new EdgeWeightedDigraph(2 * n + 2);
    for (int i = 0; i < n; i++) {
      double duration = StdIn.readDouble();
      G.addEdge(new DirectedEdge(source, i, 0.0));
      G.addEdge(new DirectedEdge(i + n, sink, 0.0));
      G.addEdge(new DirectedEdge(i, i + n, duration));

      int m = StdIn.readInt();
      for (int j = 0; j < m; j++) {
        int precedent = StdIn.readInt();
        G.addEdge(new DirectedEdge(n + i, precedent, 0.0));
      }
    }

    AcyclicLP lp = new AcyclicLP(G, source);

    StdOut.println(" job   start  finish");
    StdOut.println("--------------------");
    for (int i = 0; i < n; i++) {
      StdOut.printf("%4d %7.1f %7.1f\n", i, lp.distTo(i), lp.distTo(i + n));
    }
    StdOut.printf("Finish time: %7.1f\n", lp.distTo(sink));
  }
}
