package edu.princeton.cs.algs4;

public class TarjanSCC {
  private boolean[] marked;
  private int[] id;
  private int[] low;
  private int pre;
  private int count;
  private Stack<Integer> stack;

  public TarjanSCC(Digraph G) {
    marked = new boolean[G.V()];
    stack = new Stack<Integer>();
    id = new int[G.V()];
    low = new int[G.V()];
    for (int v = 0; v < G.V(); v++) {
      if (!marked[v]) {
        dfs(G, v);
      }
    }
    assert check(G);
  }

  private void dfs(Digraph G, int v) {
    marked[v] = true;
    low[v] = pre++;
    int min = low[v];
    stack.push(v);
    for (int w : G.adj(v)) {
      if (!marked[w]) {
        dfs(G, w);
      }
      if (low[w] < min) {
        min = low[w];
      }
    }
    if (min < low[v]) {
      low[v] = min;
      return;
    }
    int w;
    do {
      w = stack.pop();
      id[w] = count;
      low[w] = G.V();
    } while (w != v);
    count++;
  }

  public int count() {
    return count;
  }

  public boolean stronglyConnected(int v, int w) {
    validateVertex(v);
    validateVertex(w);
    return id[v] == id[w];
  }

  public int id(int v) {
    validateVertex(v);
    return id[v];
  }

  private boolean check(Digraph G) {
    TransitiveClosure tc = new TransitiveClosure(G);
    for (int v = 0; v < G.V(); v++) {
      for (int w = 0; w < G.V(); w++) {
        if (stronglyConnected(v, w) !=
            (tc.reachable(v, w) && tc.reachable(w, v))) {
          return false;
        }
      }
    }
    return true;
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
    Digraph G = new Digraph(in);
    TarjanSCC scc = new TarjanSCC(G);

    int m = scc.count();
    StdOut.println(m + " components");

    Queue<Integer>[] components = (Queue<Integer>[]) new Queue[m];
    for (int i = 0; i < m; i++) {
      components[i] = new Queue<Integer>();
    }
    for (int v = 0; v < G.V(); v++) {
      components[scc.id(v)].enqueue(v);
    }

    for (int i = 0; i < m; i++) {
      for (int v : components[i]) {
        StdOut.print(v + " ");
      }
      StdOut.println();
    }
  }
}
