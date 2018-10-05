package edu.princeton.cs.algs4;

public class BreadthFirstDirectedPaths {
  private static final int INFINITY = Integer.MAX_VALUE;
  private boolean[] marked;
  private int[] edgeTo;
  private int[] distTo;

  public BreadthFirstDirectedPaths(Digraph G, int s) {
    marked = new boolean[G.V()];
    distTo = new int[G.V()];
    edgeTo = new int[G.V()];
    for (int v = 0; v < G.V(); v++) {
      distTo[v] = INFINITY;
    }
    validateVertex(s);
    bfs(G, s);
  }

  public BreadthFirstDirectedPaths(Digraph G, Iterable<Integer> sources) {
    marked = new boolean[G.V()];
    distTo = new int[G.V()];
    edgeTo = new int[G.V()];
    for (int v = 0; v < G.V(); v++) {
      distTo[v] = INFINITY;
    }
    validateVertices(sources);
    bfs(G, sources);
  }

  private void bfs(Digraph G, int s) {
    Queue<Integer> q = new Queue<Integer>();
    marked[s] = true;
    distTo[s] = 0;
    q.enqueue(s);
    while (!q.isEmpty()) {
      int v = q.dequeue();
      for (int w : G.adj(v)) {
        if (!marked[w]) {
          edgeTo[w] = v;
          distTo[w] = distTo[v] + 1;
          marked[w] = true;
          q.enqueue(w);
        }
      }
    }
  }

  private void bfs(Digraph G, Iterable<Integer> sources) {
    Queue<Integer> q = new Queue<Integer>();
    for (int s : sources) {
      marked[s] = true;
      distTo[s] = 0;
      q.enqueue(s);
    }
    while (!q.isEmpty()) {
      int v = q.dequeue();
      for (int w : G.adj(v)) {
        if (!marked[w]) {
          edgeTo[w] = v;
          distTo[w] = distTo[v] + 1;
          marked[w] = true;
          q.enqueue(w);
        }
      }
    }
  }

  public boolean hasPathTo(int v) {
    validateVertex(v);
    return marked[v];
  }

  public int distTo(int v) {
    validateVertex(v);
    return distTo[v];
  }

  public Iterable<Integer> pathTo(int v) {
    validateVertex(v);

    if (!hasPathTo(v)) {
      return null;
    }
    Stack<Integer> path = new Stack<Integer>();
    int x;
    for (x = v; distTo[x] != 0; x = edgeTo[x]) {
      path.push(x);
    }
    path.push(x);
    return path;
  }

  private void validateVertex(int v) {
    int V = marked.length;
    if (v < 0 || v >= V)
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
  }

  private void validateVertices(Iterable<Integer> vertices) {
    if (vertices == null) {
      throw new IllegalArgumentException("argument is null");
    }
    int V = marked.length;
    for (int v : vertices) {
      if (v < 0 || v >= V) {
        throw new IllegalArgumentException(
            "vertex " + v + " is not between 0 and " + (V - 1));
      }
    }
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    Digraph G = new Digraph(in);

    int s = Integer.parseInt(args[1]);
    BreadthFirstDirectedPaths bfs = new BreadthFirstDirectedPaths(G, s);

    for (int v = 0; v < G.V(); v++) {
      if (bfs.hasPathTo(v)) {
        StdOut.printf("%d to %d (%d): ", s, v, bfs.distTo(v));
        for (int x : bfs.pathTo(v)) {
          if (x == s) {
            StdOut.print(x);
          } else {
            StdOut.print("->" + x);
          }
        }
        StdOut.println();
      } else {
        StdOut.printf("%d to %d (-): not connected\n", s, v);
      }
    }
  }
}
