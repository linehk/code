package edu.princeton.cs.algs4;

import java.util.Iterator;

public class NonrecursiveDFS {
  private boolean[] marked;

  public NonrecursiveDFS(Graph G, int s) {
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
        // StdOut.printf("check %d\n", w);
        if (!marked[w]) {
          marked[w] = true;
          // edgeTo[w] = v;
          stack.push(w);
          // StdOut.printf("dfs(%d)\n", w);
        }
      } else {
        StdOut.printf("%d done\n", v);
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
    if (v < 0 || v >= V) {
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
    }
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    Graph G = new Graph(in);
    int s = Integer.parseInt(args[1]);
    NonrecursiveDFS dfs = new NonrecursiveDFS(G, s);
    for (int v = 0; v < G.V(); v++) {
      if (dfs.marked(v)) {
        StdOut.print(v + " ");
      }
    }
    StdOut.println();
  }
}
