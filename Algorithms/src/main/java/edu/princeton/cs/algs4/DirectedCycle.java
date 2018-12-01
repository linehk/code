package edu.princeton.cs.algs4;

public class DirectedCycle {
  private boolean[] marked;
  private int[] edgeTo;
  private boolean[] onStack;
  private Stack<Integer> cycle;

  public DirectedCycle(Digraph G) {
    marked = new boolean[G.V()];
    onStack = new boolean[G.V()];
    edgeTo = new int[G.V()];
    for (int v = 0; v < G.V(); v++) {
      if (!marked[v] && cycle == null) {
        dfs(G, v);
      }
    }
  }

  private void dfs(Digraph G, int v) {
    onStack[v] = true;
    marked[v] = true;
    for (int w : G.adj(v)) {
      if (cycle != null) {
        return;
      } else if (!marked[w]) {
        edgeTo[w] = v;
        dfs(G, v);
      } else if (onStack[w]) {
        cycle = new Stack<Integer>();
        for (int x = v; x != w; x = edgeTo[x]) {
          cycle.push(x);
        }
        cycle.push(w);
        cycle.push(v);
        assert check();
      }
    }
    onStack[v] = false;
  }

  public boolean hasCycle() {
    return cycle != null;
  }

  public Iterable<Integer> cycle() {
    return cycle;
  }

  private boolean check() {
    if (hasCycle()) {
      int first = -1;
      int last = -1;
      for (int v : cycle()) {
        if (first == -1) {
          first = v;
        }
        last = v;
      }
      if (first != last) {
        System.err.printf(
            "cycle begins with %d and ends with %d\n", first, last);
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    Digraph G = new Digraph(in);

    DirectedCycle finder = new DirectedCycle(G);
    if (finder.hasCycle()) {
      StdOut.print("Directed cycle: ");
      for (int v : finder.cycle()) {
        StdOut.print(v + " ");
      }
      StdOut.println();
    } else {
      StdOut.println("No directed cycle");
    }
    StdOut.println();
  }
}
