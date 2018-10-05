package edu.princeton.cs.algs4;

public class GabowSCC {
  private boolean[] marked;
  private int[] id;
  private int[] preorder;
  private int pre;
  private int count;
  private Stack<Integer> stack1;
  private Stack<Integer> stack2;

  public GabowSCC(Digraph G) {
    marked = new boolean[G.V()];
    stack1 = new Stack<Integer>();
    stack2 = new Stack<Integer>();
    id = new int[G.V()];
    preorder = new int[G.V()];
    for (int v = 0; v < G.V(); v++) {
      id[v] = -1;
    }

    for (int v = 0; v < G.V(); v++) {
      if (!marked[v]) {
        dfs(G, v);
      }
    }

    assert check(G);
  }

  private void dfs(Digraph G, int v) {
    marked[v] = true;
    preorder[v] = pre++;
    stack1.push(v);
    stack2.push(v);
    for (int w : G.adj(v)) {
      if (!marked[w]) {
        dfs(G, w);
      } else if (id[w] == -1) {
        while (preorder[stack2.peek()] > preorder[w]) {
          stack2.pop();
        }
      }
    }

    if (stack2.peek() == v) {
      stack2.pop();
      int w;
      do {
        w = stack1.pop();
        id[w] = count;
      } while (w != v);
      count++;
    }
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
        if (stronglyConnected(v, w)
            != (tc.reachable(v, w) && tc.reachable(w, v))) {
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
    GabowSCC scc = new GabowSCC(G);

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
