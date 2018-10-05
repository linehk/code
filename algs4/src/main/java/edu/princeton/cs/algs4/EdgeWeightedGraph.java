package edu.princeton.cs.algs4;

public class EdgeWeightedGraph {
  private static final String NEWLINE = System.getProperty("line.separator");

  private final int V;
  private int E;
  private Bag<Edge>[] adj;

  public EdgeWeightedGraph(int V) {
    if (V < 0) {
      throw new IllegalArgumentException(
          "Number of vertices must be nonnegative");
    }
    this.V = V;
    this.E = 0;
    adj = (Bag<Edge>[]) new Bag[V];
    for (int v = 0; v < V; v++) {
      adj[v] = new Bag<Edge>();
    }
  }

  public EdgeWeightedGraph(int V, int E) {
    this(V);
    if (E < 0) {
      throw new IllegalArgumentException("Number of edges must be nonnegative");
    }
    for (int i = 0; i < E; i++) {
      int v = StdRandom.uniform(V);
      int w = StdRandom.uniform(V);
      double weight = Math.round(100 * StdRandom.uniform()) / 100.0;
      Edge e = new Edge(v, w, weight);
      addEdge(e);
    }
  }

  public EdgeWeightedGraph(In in) {
    this(in.readInt());
    int E = in.readInt();
    if (E < 0) {
      throw new IllegalArgumentException("Number of edges must be nonnegative");
    }
    for (int i = 0; i < E; i++) {
      int v = in.readInt();
      int w = in.readInt();
      validateVertex(v);
      validateVertex(w);
      double weight = in.readDouble();
      Edge e = new Edge(v, w, weight);
      addEdge(e);
    }
  }

  public EdgeWeightedGraph(EdgeWeightedGraph G) {
    this(G.V());
    this.E = G.E();
    for (int v = 0; v < G.V(); v++) {
      Stack<Edge> reverse = new Stack<Edge>();
      for (Edge e : G.adj[v]) {
        reverse.push(e);
      }
      for (Edge e : reverse) {
        adj[v].add(e);
      }
    }
  }

  public int V() {
    return V;
  }

  public int E() {
    return E;
  }

  private void validateVertex(int v) {
    if (v < 0 || v >= V) {
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
    }
  }

  public void addEdge(Edge e) {
    int v = e.either();
    int w = e.other(v);
    validateVertex(v);
    validateVertex(w);
    adj[v].add(e);
    adj[w].add(e);
    E++;
  }

  public Iterable<Edge> adj(int v) {
    validateVertex(v);
    return adj[v];
  }

  public int degree(int v) {
    validateVertex(v);
    return adj[v].size();
  }

  public Iterable<Edge> edges() {
    Bag<Edge> list = new Bag<Edge>();
    for (int v = 0; v < V; v++) {
      int selfLoops = 0;
      for (Edge e : adj(v)) {
        if (e.other(v) > v) {
          list.add(e);
        } else if (e.other(v) == v) {
          if (selfLoops % 2 == 0) {
            list.add(e);
          }
          selfLoops++;
        }
      }
    }
    return list;
  }

  public String toString() {
    StringBuilder s = new StringBuilder();
    s.append(V + " " + E + NEWLINE);
    for (int v = 0; v < V; v++) {
      s.append(v + ": ");
      for (Edge e : adj[v]) {
        s.append(e + "  ");
      }
      s.append(NEWLINE);
    }
    return s.toString();
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    EdgeWeightedGraph G = new EdgeWeightedGraph(in);
    StdOut.println(G);
  }
}
