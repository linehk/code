package edu.princeton.cs.algs4;

public class DijkstraUndirectedSP {
  private double[] distTo;
  private Edge[] edgeTo;
  private IndexMinPQ<Double> pq;

  public DijkstraUndirectedSP(EdgeWeightedGraph G, int s) {
    for (Edge e : G.edges()) {
      if (e.weight() < 0) {
        throw new IllegalArgumentException(
            "edge " + e + " has negative weight");
      }
    }

    distTo = new double[G.V()];
    edgeTo = new Edge[G.V()];

    validateVertex(s);

    for (int v = 0; v < G.V(); v++) {
      distTo[v] = Double.POSITIVE_INFINITY;
    }
    distTo[s] = 0.0;

    pq = new IndexMinPQ<Double>(G.V());
    pq.insert(s, distTo[s]);
    while (!pq.isEmpty()) {
      int v = pq.delMin();
      for (Edge e : G.adj(v)) {
        relax(e, v);
      }
    }

    assert check(G, s);
  }

  private void relax(Edge e, int v) {
    int w = e.other(v);
    if (distTo[w] > distTo[v] + e.weight()) {
      distTo[w] = distTo[v] + e.weight();
      edgeTo[w] = e;
      if (pq.contains(w)) {
        pq.decreaseKey(w, distTo[w]);
      } else {
        pq.insert(w, distTo[w]);
      }
    }
  }

  public double distTo(int v) {
    validateVertex(v);
    return distTo[v];
  }

  public boolean hasPathTo(int v) {
    validateVertex(v);
    return distTo[v] < Double.POSITIVE_INFINITY;
  }

  public Iterable<Edge> pathTo(int v) {
    validateVertex(v);
    if (!hasPathTo(v)) {
      return null;
    }
    Stack<Edge> path = new Stack<Edge>();
    int x = v;
    for (Edge e = edgeTo[v]; e != null; e = edgeTo[x]) {
      path.push(e);
      x = e.other(x);
    }
    return path;
  }

  private boolean check(EdgeWeightedGraph G, int s) {
    for (Edge e : G.edges()) {
      if (e.weight() < 0) {
        System.err.println("negative edge weight detected");
        return false;
      }
    }

    if (distTo[s] != 0.0 || edgeTo[s] != null) {
      System.err.println("distTo[s] and edgeTo[s] inconsistent");
      return false;
    }
    for (int v = 0; v < G.V(); v++) {
      if (v == s) {
        continue;
      }
      if (edgeTo[v] == null && distTo[v] != Double.POSITIVE_INFINITY) {
        System.err.println("distTo[] and edgeTo[] inconsistent");
        return false;
      }
    }

    for (int v = 0; v < G.V(); v++) {
      for (Edge e : G.adj(v)) {
        int w = e.other(v);
        if (distTo[v] + e.weight() < distTo[w]) {
          System.err.println("edge " + e + " not relaxed");
          return false;
        }
      }
    }

    for (int w = 0; w < G.V(); w++) {
      if (edgeTo[w] == null) {
        continue;
      }
      Edge e = edgeTo[w];
      if (w != e.either() && w != e.other(e.either())) {
        return false;
      }
      int v = e.other(w);
      if (distTo[v] + e.weight() != distTo[w]) {
        System.err.println("edge " + e + " on shortest path not tight");
        return false;
      }
    }
    return true;
  }

  private void validateVertex(int v) {
    int V = distTo.length;
    if (v < 0 || v >= V) {
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
    }
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    EdgeWeightedGraph G = new EdgeWeightedGraph(in);
    int s = Integer.parseInt(args[1]);

    DijkstraUndirectedSP sp = new DijkstraUndirectedSP(G, s);

    for (int t = 0; t < G.V(); t++) {
      if (sp.hasPathTo(t)) {
        StdOut.printf("%d to %d (%.2f)  ", s, t, sp.distTo(t));
        for (Edge e : sp.pathTo(t)) {
          StdOut.print(e + "    ");
        }
        StdOut.println();
      } else {
        StdOut.printf("%d to %d         no path\n", s, t);
      }
    }
  }
}
