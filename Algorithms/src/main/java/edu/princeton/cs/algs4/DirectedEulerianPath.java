package edu.princeton.cs.algs4;

import java.util.Iterator;

public class DirectedEulerianPath {
  private Stack<Integer> path = null;

  public DirectedEulerianPath(Digraph G) {
    int deficit = 0;
    int s = nonIsolatedVertex(G);
    for (int v = 0; v < G.V(); v++) {
      if (G.outdegree(v) > G.indegree(v)) {
        deficit += (G.outdegree(v) - G.indegree(v));
        s = v;
      }
    }

    if (deficit > 1) {
      return;
    }

    if (s == -1) {
      s = 0;
    }

    Iterator<Integer>[] adj = (Iterator<Integer>[]) new Iterator[G.V()];
    for (int v = 0; v < G.V(); v++) {
      adj[v] = G.adj(v).iterator();
    }

    Stack<Integer> stack = new Stack<Integer>();
    stack.push(s);
    path = new Stack<Integer>();
    while (!stack.isEmpty()) {
      int v = stack.pop();
      while (adj[v].hasNext()) {
        stack.push(v);
        v = adj[v].next();
      }
      path.push(v);
    }

    if (path.size() != G.E() + 1) {
      path = null;
    }
    assert check(G);
  }

  public Iterable<Integer> path() {
    return path;
  }

  public boolean hasEulerianPath() {
    return path != null;
  }

  private static int nonIsolatedVertex(Digraph G) {
    for (int v = 0; v < G.V(); v++) {
      if (G.outdegree(v) > 0) {
        return v;
      }
    }
    return -1;
  }

  private static boolean satisfiesNecessaryAndSufficientConditions(Digraph G) {
    if (G.E() == 0) {
      return true;
    }

    int deficit = 0;
    for (int v = 0; v < G.V(); v++) {
      if (G.outdegree(v) > G.indegree(v)) {
        deficit += (G.outdegree(v) - G.indegree(v));
      }
    }
    if (deficit > 1) {
      return false;
    }

    Graph H = new Graph(G.V());
    for (int v = 0; v < G.V(); v++) {
      for (int w : G.adj(v)) {
        H.addEdge(v, w);
      }
    }

    int s = nonIsolatedVertex(G);
    BreadthFirstPaths bfs = new BreadthFirstPaths(H, s);
    for (int v = 0; v < G.V(); v++) {
      if (H.degree(v) > 0 && !bfs.hasPathTo(v)) {
        return false;
      }
    }
    return true;
  }

  private boolean check(Digraph G) {
    if (hasEulerianPath() == (path() == null)) {
      return false;
    }

    if (hasEulerianPath() != satisfiesNecessaryAndSufficientConditions(G)) {
      return false;
    }

    if (path == null) {
      return true;
    }

    if (path.size() != G.E() + 1) {
      return false;
    }

    return true;
  }

  private static void unitTest(Digraph G, String description) {
    StdOut.println(description);
    StdOut.println("-------------------------------------");
    StdOut.print(G);

    DirectedEulerianPath euler = new DirectedEulerianPath(G);

    StdOut.print("Eulerian path: ");
    if (euler.hasEulerianPath()) {
      for (int v : euler.path()) {
        StdOut.print(v + " ");
      }
      StdOut.println();
    } else {
      StdOut.println("none");
    }
    StdOut.println();
  }

  public static void main(String[] args) {
    int V = Integer.parseInt(args[0]);
    int E = Integer.parseInt(args[1]);

    Digraph G1 = DigraphGenerator.eulerianCycle(V, E);
    unitTest(G1, "Eulerian cycle");

    Digraph G2 = DigraphGenerator.eulerianPath(V, E);
    unitTest(G2, "Eulerian path");

    Digraph G3 = new Digraph(G2);
    G3.addEdge(StdRandom.uniform(V), StdRandom.uniform(V));
    unitTest(G3, "one random edge added to Eulerian path");

    Digraph G4 = new Digraph(V);
    int v4 = StdRandom.uniform(V);
    G4.addEdge(v4, v4);
    unitTest(G4, "single self loop");

    Digraph G5 = new Digraph(V);
    G5.addEdge(StdRandom.uniform(V), StdRandom.uniform(V));
    unitTest(G5, "single edge");

    Digraph G6 = new Digraph(V);
    unitTest(G6, "empty digraph");

    Digraph G7 = DigraphGenerator.simple(V, E);
    unitTest(G7, "simple digraph");

    Digraph G8 = new Digraph(new In("eulerianD.txt"));
    unitTest(G8, "4-vertex Eulerian digraph");
  }
}
