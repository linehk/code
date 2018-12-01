package edu.princeton.cs.algs4;

public class DepthFirstDirectedPaths {
  private boolean[] marked;
  private int[] edgeTo;
  private final int s;

  public DepthFirstDirectedPaths(Digraph G, int s) {
    marked = new boolean[G.V()];
    edgeTo = new int[G.V()];
    this.s = s;
    validateVertex(s);
    dfs(G, s);
  }

  private void dfs(Digraph G, int v) {
    marked[v] = true;
    for (int w : G.adj(v)) {
      if (!marked[w]) {
        edgeTo[w] = v;
        dfs(G, w);
      }
    }
  }

  public boolean hasPathTo(int v) {
    validateVertex(v);
    return marked[v];
  }

  public Iterable<Integer> pathTo(int v) {
    validateVertex(v);
    if (!hasPathTo(v)) {
      return null;
    }
    Stack<Integer> path = new Stack<Integer>();
    for (int x = v; x != s; x = edgeTo[x]) {
      path.push(x);
    }
    path.push(s);
    return path;
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
    DepthFirstDirectedPaths dfs = new DepthFirstDirectedPaths(G, s);

    for (int v = 0; v < G.V(); v++) {
      if (dfs.hasPathTo(v)) {
        StdOut.printf("%d to %d:  ", s, v);
        for (int x : dfs.pathTo(v)) {
          if (x == s) {
            StdOut.print(x);
          } else {
            StdOut.print("-" + x);
          }
        }
        StdOut.println();
      } else {
        StdOut.printf("%d to %d: connected\n", s, v);
      }
    }
  }
}
