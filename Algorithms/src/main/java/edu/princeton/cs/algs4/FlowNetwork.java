package edu.princeton.cs.algs4;

public class FlowNetwork {
  private static final String NEWLINE = System.getProperty("line.separator");

  private final int V;
  private int E;
  private Bag<FlowEdge>[] adj;

  public FlowNetwork(int V) {
    if (V < 0) {
      throw new IllegalArgumentException(
          "Number of vertices in a Graph must be nonnegative");
    }
    this.V = V;
    this.E = 0;
    adj = (Bag<FlowEdge>[]) new Bag[V];
    for (int v = 0; v < V; v++) {
      adj[v] = new Bag<FlowEdge>();
    }
  }

  public FlowNetwork(int V, int E) {
    this(V);
    if (E < 0) {
      throw new IllegalArgumentException("Number of edges must be nonnegative");
    }
    for (int i = 0; i < E; i++) {
      int v = StdRandom.uniform(V);
      int w = StdRandom.uniform(V);
      double capcaity = StdRandom.uniform(100);
      addEdge(new FlowEdge(v, w, capcaity));
    }
  }

  public FlowNetwork(In in) {
    this(in.readInt());
    int E = in.readInt();
    if (E < 0) {
      throw new IllegalArgumentException("number of edges must be nonnegative");
    }
    for (int i = 0; i < E; i++) {
      int v = in.readInt();
      int w = in.readInt();
      validateVertex(v);
      validateVertex(w);
      double capacity = in.readDouble();
      addEdge(new FlowEdge(v, w, capacity));
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

  public void addEdge(FlowEdge e) {
    int v = e.from();
    int w = e.to();
    validateVertex(v);
    validateVertex(w);
    adj[v].add(e);
    adj[w].add(e);
    E++;
  }

  public Iterable<FlowEdge> adj(int v) {
    validateVertex(v);
    return adj[v];
  }

  public Iterable<FlowEdge> edges() {
    Bag<FlowEdge> list = new Bag<FlowEdge>();
    for (int v = 0; v < V; v++) {
      for (FlowEdge e : adj(v)) {
        if (e.to() != v) {
          list.add(e);
        }
      }
    }
    return list;
  }

  public String toString() {
    StringBuilder s = new StringBuilder();
    s.append(V + " " + E + NEWLINE);
    for (int v = 0; v < V; v++) {
      s.append(v + ":   ");
      for (FlowEdge e : adj[v]) {
        if (e.to() != v) {
          s.append(e + "  ");
        }
      }
      s.append(NEWLINE);
    }
    return s.toString();
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    FlowNetwork G = new FlowNetwork(in);
    StdOut.println(G);
  }
}
