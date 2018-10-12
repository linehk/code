package edu.princeton.cs.algs4;

public class GlobalMincut {
  private static final double FLOATING_POINT_EPSILON = 1E-11;

  private double weight = Double.POSITIVE_INFINITY;

  private boolean[] cut;

  private int V;

  private class CutPhase {
    private double weight;
    private int s;
    private int t;

    public CutPhase(double weight, int s, int t) {
      this.weight = weight;
      this.s = s;
      this.t = t;
    }
  }

  public GlobalMincut(EdgeWeightedGraph G) {
    V = G.V();
    validate(G);
    minCut(G, 0);
    assert check(G);
  }

  private void validate(EdgeWeightedGraph G) {
    if (G.V() < 2) {
      throw new IllegalArgumentException(
          "number of vertices of G is less than 2");
    }
    for (Edge e : G.edges()) {
      if (e.weight() < 0) {
        throw new IllegalArgumentException(
            "edge " + e + " has negative weight");
      }
    }
  }

  public double weight() {
    return weight;
  }

  public boolean cut(int v) {
    validateVertex(v);
    return cut[v];
  }

  private void makeCut(int t, UF uf) {
    for (int v = 0; v < cut.length; v++) {
      cut[v] = uf.connected(v, t);
    }
  }

  private void minCut(EdgeWeightedGraph G, int a) {
    UF uf = new UF(G.V());
    boolean[] marked = new boolean[G.V()];
    cut = new boolean[G.V()];
    CutPhase cp = new CutPhase(0.0, a, a);
    for (int v = G.V(); v > 1; v--) {
      cp = minCutPhase(G, marked, cp);
      if (cp.weight < weight) {
        weight = cp.weight;
        makeCut(cp.t, uf);
      }
      G = contractEdge(G, cp.s, cp.t);
      marked[cp.t] = true;
      uf.union(cp.s, cp.t);
    }
  }

  private CutPhase minCutPhase(
      EdgeWeightedGraph G, boolean[] marked, CutPhase cp) {
    IndexMaxPQ<Double> pq = new IndexMaxPQ<Double>(G.V());
    for (int v = 0; v < G.V(); v++) {
      if (v != cp.s && !marked[v]) {
        pq.insert(v, 0.0);
      }
    }
    pq.insert(cp.s, Double.POSITIVE_INFINITY);
    while (!pq.isEmpty()) {
      int v = pq.delMax();
      cp.s = cp.t;
      cp.t = v;
      for (Edge e : G.adj(v)) {
        int w = e.other(v);
        if (pq.contains(w)) {
          pq.increaseKey(w, pq.keyOf(w) + e.weight());
        }
      }
    }
    cp.weight = 0.0;
    for (Edge e : G.adj(cp.t)) {
      cp.weight += e.weight();
    }
    return cp;
  }

  private EdgeWeightedGraph contractEdge(EdgeWeightedGraph G, int s, int t) {
    EdgeWeightedGraph H = new EdgeWeightedGraph(G.V());
    for (int v = 0; v < G.V(); v++) {
      for (Edge e : G.adj(v)) {
        int w = e.other(v);
        if (v == s && w == t || v == t && w == s) {
          continue;
        }
        if (v < w) {
          if (w == t) {
            H.addEdge(new Edge(v, s, e.weight()));
          } else if (v == t) {
            H.addEdge(new Edge(w, s, e.weight()));
          } else {
            H.addEdge(new Edge(v, w, e.weight()));
          }
        }
      }
    }
    return H;
  }

  private boolean check(EdgeWeightedGraph G) {
    double value = Double.POSITIVE_INFINITY;
    for (int s = 0, t = 1; t < G.V(); t++) {
      FlowNetwork F = new FlowNetwork(G.V());
      for (Edge e : G.edges()) {
        int v = e.either();
        int w = e.other(v);
        F.addEdge(new FlowEdge(v, w, e.weight()));
        F.addEdge(new FlowEdge(w, v, e.weight()));
      }
      FordFulkerson maxflow = new FordFulkerson(F, s, t);
      value = Math.min(value, maxflow.value());
    }
    if (Math.abs(weight - value) > FLOATING_POINT_EPSILON) {
      System.err.println("Min cut weight = " + weight + " , max flow value = " + value);
      return false;
    }
    return true;
  }

  private void validateVertex(int v) {
    if (v < 0 || v >= V) {
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
    }
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    EdgeWeightedGraph G = new EdgeWeightedGraph(in);
    GlobalMincut mc = new GlobalMincut(G);
    StdOut.print("Min Cut: ");
    for (int v = 0; v < G.V(); v++) {
      if (mc.cut(v)) {
        StdOut.print(v + " ");
      }
    }
    StdOut.println();
    StdOut.println("Min cut weight = " + mc.weight());
  }
}
