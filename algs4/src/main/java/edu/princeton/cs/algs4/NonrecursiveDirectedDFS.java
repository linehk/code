package edu.princeton.cs.algs4;

import java.util.Iterator;

public class NonrecursiveDirectedDFS {
  private boolean[] marked;

  public NonrecursiveDirectedDFS(Digraph G, int s) {
    marked = new boolean[G.V()];
    validateVertex(s);

    Iterator<Integer>[] adj = (Iterator<Integer>[]) new Iterator[G.V()];
    for (int v = 0; v < G.V(); v++) {
      adj[v] = G.adj(v).iterator();
    }

    Stack<Integer> stack = new Stack<Integer>();
    marked[s] = true;
    stack.push(s);
    while (!stack.isEmpty()) {
      int v = stack.peek();
      if (adj[v].hasNext()) {
        int w = adj[v].next();
        if (!marked[w]) {
          marked[w] = true;
          stack.push(w);
        }
      } else {
        stack.pop();
      }
    }
  }

  public boolean marked(int v) {
    validateVertex(v);
    return marked[v];
  }

  private void validateVertex(int v) {
    int V = marked.length;
    if (v < 0 || v >= V)
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    Digraph G = new Digraph(in);
    int s = Integer.parseInt(args[1]);
    NonrecursiveDirectedDFS dfs = new NonrecursiveDirectedDFS(G, s);
    for (int v = 0; v < G.V(); v++) {
      if (dfs.marked(v)) {
        StdOut.print(v + " ");
      }
    }
    StdOut.println();
  }
}
