package edu.princeton.cs.algs4;

public class FloydWarshall {
  private boolean hasNegativeCycle;
  private double[][] distTo;
  private DirectedEdge[][] edgeTo;

  public FloydWarshall(AdjMatrixEdgeWeightedDigraph G) {
    int V = G.V();
    distTo = new double[V][V];
    edgeTo = new DirectedEdge[V][V];

    for (int v = 0; v < V; v++) {
      for (int w = 0; w < V; w++) {
        distTo[v][w] = Double.POSITIVE_INFINITY;
      }
    }

    for (int v = 0; v < G.V(); v++) {
      for (DirectedEdge e : G.adj(v)) {
        distTo[e.from()][e.to()] = e.weight();
        edgeTo[e.from()][e.to()] = e;
      }
      if (distTo[v][v] > 0.0) {
        distTo[v][v] = 0.0;
        edgeTo[v][v] = null;
      }
    }

    for (int i = 0; i < V; i++) {
      for (int v = 0; v < V; v++) {
        if (edgeTo[v][i] == null) {
          continue;
        }
        for (int w = 0; w < V; w++) {
          if (distTo[v][w] > distTo[v][i] + distTo[i][w]) {
            distTo[v][w] = distTo[v][i] + distTo[i][w];
            edgeTo[v][w] = edgeTo[i][w];
          }
        }
        if (distTo[v][v] < 0.0) {
          hasNegativeCycle = true;
          return;
        }
      }
    }
    assert check(G);
  }

  public boolean hasNegativeCycle() {
    return hasNegativeCycle;
  }

  public Iterable<DirectedEdge> negativeCycle() {
    for (int v = 0; v < distTo.length; v++) {
      if (distTo[v][v] < 0.0) {
        int V = edgeTo.length;
        EdgeWeightedDigraph spt = new EdgeWeightedDigraph(V);
        for (int w = 0; w < V; w++) {
          if (edgeTo[v][w] != null) {
            spt.addEdge(edgeTo[v][w]);
          }
        }
        EdgeWeightedDirectedCycle finder = new EdgeWeightedDirectedCycle(spt);
        assert finder.hasCycle();
        return finder.cycle();
      }
    }
    return null;
  }

  public boolean hasPath(int s, int t) {
    validateVertex(s);
    validateVertex(t);
    return distTo[s][t] < Double.POSITIVE_INFINITY;
  }

  public double dist(int s, int t) {
    validateVertex(s);
    validateVertex(t);
    if (hasNegativeCycle()) {
      throw new UnsupportedOperationException("Negative cost cycle exists");
    }
    return distTo[s][t];
  }

  public Iterable<DirectedEdge> path(int s, int t) {
    validateVertex(s);
    validateVertex(t);
    if (hasNegativeCycle()) {
      throw new UnsupportedOperationException("Negative cost cycle exists");
    }
    if (!hasPath(s, t)) {
      return null;
    }
    Stack<DirectedEdge> path = new Stack<DirectedEdge>();
    for (DirectedEdge e = edgeTo[s][t]; e != null; e = edgeTo[s][e.from()]) {
      path.push(e);
    }
    return path;
  }

  private boolean check(AdjMatrixEdgeWeightedDigraph G) {
    if (!hasNegativeCycle()) {
      for (int v = 0; v < G.V(); v++) {
        for (DirectedEdge e : G.adj(v)) {
          int w = e.to();
          for (int i = 0; i < G.V(); i++) {
            if (distTo[i][w] > distTo[i][v] + e.weight()) {
              System.err.println("edge " + e + " is eligible");
              return false;
            }
          }
        }
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
    int V = Integer.parseInt(args[0]);
    int E = Integer.parseInt(args[1]);
    AdjMatrixEdgeWeightedDigraph G = new AdjMatrixEdgeWeightedDigraph(V);
    for (int i = 0; i < E; i++) {
      int v = StdRandom.uniform(V);
      int w = StdRandom.uniform(V);
      double weight = Math.round(100 * (StdRandom.uniform() - 0.15)) / 100.0;
      if (v == w) {
        G.addEdge(new DirectedEdge(v, w, Math.abs(weight)));
      } else {
        G.addEdge(new DirectedEdge(v, w, weight));
      }
    }

    StdOut.println(G);

    FloydWarshall spt = new FloydWarshall(G);

    StdOut.printf("  ");
    for (int v = 0; v < G.V(); v++) {
      StdOut.printf("%6d ", v);
    }
    StdOut.println();
    for (int v = 0; v < G.V(); v++) {
      StdOut.printf("%3d: ", v);
      for (int w = 0; w < G.V(); w++) {
        if (spt.hasPath(v, w)) {
          StdOut.printf("%6.2f ", spt.dist(v, w));
        } else {
          StdOut.printf("  Inf ");
        }
      }
      StdOut.println();
    }

    if (spt.hasNegativeCycle()) {
      StdOut.println("Negative cost cycle:");
      for (DirectedEdge e : spt.negativeCycle()) {
        StdOut.println(e);
      }
      StdOut.println();
    } else {
      for (int v = 0; v < G.V(); v++) {
        for (int w = 0; w < G.V(); w++) {
          if (spt.hasPath(v, w)) {
            StdOut.printf("%d to %d (%5.2f)  ", v, w, spt.dist(v, w));
            for (DirectedEdge e : spt.path(v, w)) {
              StdOut.print(e + "  ");
            }
            StdOut.println();
          } else {
            StdOut.printf("%d to %d no path\n", v, w);
          }
        }
      }
    }
  }
}

