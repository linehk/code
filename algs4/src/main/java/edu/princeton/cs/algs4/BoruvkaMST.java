package edu.princeton.cs.algs4;

public class BoruvkaMST {
  private static final double FLOATING_POINT_EPSILON = 1E-12;

  private Bag<Edge> mst = new Bag<Edge>();
  private double weight;

  public BoruvkaMST(EdgeWeightedGraph G) {
    UF uf = new UF(G.V());

    for (int t = 1; t < G.V() && mst.size() < G.V() - 1; t = t + t) {
      Edge[] closest = new Edge[G.V()];
      for (Edge e : G.edges()) {
        int v = e.either();
        int w = e.other(v);
        int i = uf.find(v);
        int j = uf.find(w);
        if (i == j) {
          continue;
        }
        if (closest[i] == null || less(e, closest[i])) {
          closest[i] = e;
        }
        if (closest[j] == null || less(e, closest[j])) {
          closest[j] = e;
        }
      }

      for (int i = 0; i < G.V(); i++) {
        Edge e = closest[i];
        if (e != null) {
          int v = e.either();
          int w = e.other(v);
          if (!uf.connected(v, w)) {
            mst.add(e);
            weight += e.weight();
            uf.union(v, w);
          }
        }
      }
    }
    assert check(G);
  }

  public Iterable<Edge> edges() {
    return mst;
  }

  public double weight() {
    return weight;
  }

  private static boolean less(Edge e, Edge f) {
    return e.weight() < f.weight();
  }

  private boolean check(EdgeWeightedGraph G) {
    double totalWeight = 0.0;
    for (Edge e : edges()) {
      totalWeight += e.weight();
    }
    if (Math.abs(totalWeight - weight()) > FLOATING_POINT_EPSILON) {
      System.err.printf(
          "Weight of edges does not equal weight(): %f vs. %f\n",
          totalWeight, weight());
      return false;
    }

    UF uf = new UF(G.V());
    for (Edge e : edges()) {
      int v = e.either(), w = e.other(v);
      if (uf.connected(v, w)) {
        System.err.println("Not a forest");
        return false;
      }
      uf.union(v, w);
    }

    for (Edge e : G.edges()) {
      int v = e.either(), w = e.other(v);
      if (!uf.connected(v, w)) {
        System.err.println("Not a spanning forest");
        return false;
      }
    }

    for (Edge e : edges()) {
      uf = new UF(G.V());
      for (Edge f : mst) {
        int x = f.either(), y = f.other(x);
        if (f != e) uf.union(x, y);
      }

      for (Edge f : G.edges()) {
        int x = f.either(), y = f.other(x);
        if (!uf.connected(x, y)) {
          if (f.weight() < e.weight()) {
            System.err.println(
                "Edge " + f + " violates cut optimality conditions");
            return false;
          }
        }
      }
    }
    return true;
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    EdgeWeightedGraph G = new EdgeWeightedGraph(in);
    BoruvkaMST mst = new BoruvkaMST(G);
    for (Edge e : mst.edges()) {
      StdOut.println(e);
    }
    StdOut.printf("%.5f\n", mst.weight());
  }
}
