package edu.princeton.cs.algs4;

import java.util.NoSuchElementException;

public class Digraph {
  private static final String NEWLINE = System.getProperty("line.separator");

  private final int V;
  private int E;
  private Bag<Integer>[] adj;
  private int[] indegree;

  public Digraph(int V) {
    if (V < 0) {
      throw new IllegalArgumentException(
          "Number of vertices in a Digraph must be nonnegative");
    }
    this.V = V;
    this.E = 0;
    indegree = new int[V];
    adj = (Bag<Integer>[]) new Bag[V];
    for (int v = 0; v < V; v++) {
      adj[v] = new Bag<Integer>();
    }
  }

  public Digraph(In in) {
    try {
      this.V = in.readInt();
      if (V < 0) {
        throw new IllegalArgumentException(
            "Number of vertices in a Digraph must be nonnegative");
      }
      indegree = new int[V];
      adj = (Bag<Integer>[]) new Bag[V];
      for (int v = 0; v < V; v++) {
        adj[v] = new Bag<Integer>();
      }
      int E = in.readInt();
      if (E < 0) {
        throw new IllegalArgumentException(
            "Number of edges in a Digraph must be nonnegative");
      }
      for (int i = 0; i < E; i++) {
        int v = in.readInt();
        int w = in.readInt();
        addEdge(v, w);
      }
    } catch (NoSuchElementException e) {
      throw new IllegalArgumentException(
          "invalid input format in Digraph constructor", e);
    }
  }

  public Digraph(Digraph G) {
    this(G.V());
    this.E = G.E();
    for (int v = 0; v < V; v++) {
      this.indegree[v] = G.indegree(v);
    }
    for (int v = 0; v < G.V(); v++) {
      Stack<Integer> reverse = new Stack<Integer>();
      for (int w : G.adj[v]) {
        reverse.push(w);
      }
      for (int w : reverse) {
        adj[v].add(w);
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
    if (v < 0 || v >= V)
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
  }

  public void addEdge(int v, int w) {
    validateVertex(v);
    validateVertex(w);
    adj[v].add(w);
    indegree[w]++;
    E++;
  }

  public Iterable<Integer> adj(int v) {
    validateVertex(v);
    return adj[v];
  }

  public int outdegree(int v) {
    validateVertex(v);
    return adj[v].size();
  }

  public int indegree(int v) {
    validateVertex(v);
    return indegree[v];
  }

  public Digraph reverse() {
    Digraph reverse = new Digraph(V);
    for (int v = 0; v < V; v++) {
      for (int w : adj[v]) {
        reverse.addEdge(w, v);
      }
    }
    return reverse;
  }

  public String toString() {
    StringBuilder s = new StringBuilder();
    s.append(V + " vertices, " + E + " edges " + NEWLINE);
    for (int v = 0; v < V; v++) {
      s.append(String.format("%d: ", v));
      for (int w : adj[v]) {
        s.append(String.format("%d ", w));
      }
      s.append(NEWLINE);
    }
    return s.toString();
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    Digraph G = new Digraph(in);
    StdOut.println();
  }
}
