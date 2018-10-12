package edu.princeton.cs.algs4;

import java.util.Iterator;

public class HopcroftKarp {
  private static final int UNMATCHED = -1;

  private final int V;
  private BipartiteX bipartition;
  private int cardinality;
  private int[] mate;

  private boolean[] inMinVertexCover;
  private boolean[] marked;
  private int[] distTo;

  public HopcroftKarp(Graph G) {
    bipartition = new BipartiteX(G);
    if (!bipartition.isBipartite()) {
      throw new IllegalArgumentException("graph is not bipartite");
    }

    this.V = G.V();
    mate = new int[V];
    for (int v = 0; v < V; v++) {
      mate[v] = UNMATCHED;
    }

    while (hasAugmentingPath(G)) {
      Iterator<Integer>[] adj = (Iterator<Integer>[]) new Iterator[G.V()];
      for (int v = 0; v < G.V(); v++) {
        adj[v] = G.adj(v).iterator();
      }

      for (int s = 0; s < V; s++) {
        if (isMatched(s) || !bipartition.color(s)) {
          continue;
        }
        Stack<Integer> path = new Stack<Integer>();
        path.push(s);
        while (!path.isEmpty()) {
          int v = path.peek();

          if (!adj[v].hasNext()) {
            path.pop();
          } else {
            int w = adj[v].next();
            if (!isLevelGraphEdge(v, w)) {
              continue;
            }
            path.push(w);
            if (!isMatched(w)) {
              while (!path.isEmpty()) {
                int x = path.pop();
                int y = path.pop();
                mate[x] = y;
                mate[y] = x;
              }
              cardinality++;
            }
          }
        }
      }
    }

    inMinVertexCover = new boolean[V];
    for (int v = 0; v < V; v++) {
      if (bipartition.color(v) && !marked[v]) {
        inMinVertexCover[v] = true;
      }
      if (!bipartition.color(v) && marked[v]) {
        inMinVertexCover[v] = true;
      }
    }
    assert certifySolution(G);
  }

  private static String toString(Iterable<Integer> path) {
    StringBuilder sb = new StringBuilder();
    for (int v : path) {
      sb.append(v + "-");
    }
    String s = sb.toString();
    s = s.substring(0, s.lastIndexOf('-'));
    return s;
  }

  private boolean isLevelGraphEdge(int v, int w) {
    return (distTo[w] == distTo[v] + 1) && isResidualGraphEdge(v, w);
  }

  private boolean isResidualGraphEdge(int v, int w) {
    if ((mate[v] != w) && bipartition.color(v)) {
      return true;
    }
    if ((mate[v] == w) && !bipartition.color(v)) {
      return true;
    }
    return false;
  }

  private boolean hasAugmentingPath(Graph G) {
    marked = new boolean[V];
    distTo = new int[V];
    for (int v = 0; v < V; v++) {
      distTo[v] = Integer.MAX_VALUE;
    }

    Queue<Integer> queue = new Queue<Integer>();
    for (int v = 0; v < V; v++) {
      if (bipartition.color(v) && !isMatched(v)) {
        queue.enqueue(v);
        marked[v] = true;
        distTo[v] = 0;
      }
    }

    boolean hasAugmentingPath = false;
    while (!queue.isEmpty()) {
      int v = queue.dequeue();
      for (int w : G.adj(v)) {
        if (isResidualGraphEdge(v, w)) {
          if (!marked[w]) {
            distTo[w] = distTo[v] + 1;
            marked[w] = true;
            if (!isMatched(w)) {
              hasAugmentingPath = true;
            }
            if (!hasAugmentingPath) {
              queue.enqueue(w);
            }
          }
        }
      }
    }
    return hasAugmentingPath;
  }

  public int mate(int v) {
    validate(v);
    return mate[v];
  }

  public boolean isMatched(int v) {
    validate(v);
    return mate[v] != UNMATCHED;
  }

  public int size() {
    return cardinality;
  }

  public boolean isPerfect() {
    return cardinality * 2 == V;
  }

  public boolean inMinVertexCover(int v) {
    validate(v);
    return inMinVertexCover[v];
  }

  private void validate(int v) {
    if (v < 0 || v >= V) {
      throw new IllegalArgumentException(
          "vertex " + v + " is not between 0 and " + (V - 1));
    }
  }

  private boolean certifySolution(Graph G) {
    for (int v = 0; v < V; v++) {
      if (mate(v) == -1) {
        continue;
      }
      if (mate(mate(v)) != v) {
        return false;
      }
    }

    int matchedVertices = 0;
    for (int v = 0; v < V; v++) {
      if (mate(v) != -1) {
        matchedVertices++;
      }
    }
    if (2 * size() != matchedVertices) {
      return false;
    }

    int sizeOfMinVertexCover = 0;
    for (int v = 0; v < V; v++) {
      if (inMinVertexCover(v)) {
        sizeOfMinVertexCover++;
      }
    }
    if (size() != sizeOfMinVertexCover) {
      return false;
    }

    boolean[] isMatched = new boolean[V];
    for (int v = 0; v < V; v++) {
      int w = mate[v];
      if (w == -1) {
        continue;
      }
      if (v == w) {
        return false;
      }
      if (v >= w) {
        continue;
      }
      if (isMatched[v] || isMatched[w]) {
        return false;
      }
      isMatched[v] = true;
      isMatched[w] = true;
    }

    for (int v = 0; v < V; v++) {
      if (mate(v) == -1) {
        continue;
      }
      boolean isEdge = false;
      for (int w : G.adj(v)) {
        if (mate(v) == w) {
          isEdge = true;
        }
      }
      if (!isEdge) {
        return false;
      }
    }

    for (int v = 0; v < V; v++) {
      for (int w : G.adj(v)) {
        if (!inMinVertexCover(v) && !inMinVertexCover(w)) {
          return false;
        }
      }
    }
    return true;
  }

  public static void main(String[] args) {
    int V1 = Integer.parseInt(args[0]);
    int V2 = Integer.parseInt(args[1]);
    int E  = Integer.parseInt(args[2]);
    Graph G = GraphGenerator.bipartite(V1, V2, E);
    if (G.V() < 1000) {
      StdOut.println(G);
    }

    HopcroftKarp matching = new HopcroftKarp(G);

    // print maximum matching
    StdOut.printf("Number of edges in max matching        = %d\n",
        matching.size());
    StdOut.printf("Number of vertices in min vertex cover = %d\n",
        matching.size());
    StdOut.printf("Graph has a perfect matching           = %b\n",
        matching.isPerfect());
    StdOut.println();

    if (G.V() >= 1000) {
      return;
    }

    StdOut.print("Max matching: ");
    for (int v = 0; v < G.V(); v++) {
      int w = matching.mate(v);
      if (matching.isMatched(v) && v < w) {
        StdOut.print(v + "-" + w + " ");
      }
    }
    StdOut.println();

    StdOut.print("Min vertex cover: ");
    for (int v = 0; v < G.V(); v++) {
      if (matching.inMinVertexCover(v)) {
        StdOut.print(v + " ");
      }
    }
    StdOut.println();
  }
}
