package edu.princeton.cs.algs4;

import java.util.Iterator;

public class DirectedEulerianCycle {
  private Stack<Integer> cycle = null;

  public DirectedEulerianCycle(Digraph G) {
    if (G.E() == 0) {
      return;
    }

    for (int v = 0; v < G.V(); v++) {
      if (G.outdegree(v) != G.indegree(v)) {
        return;
      }
    }

    Iterator<Integer>[] adj = (Iterator<Integer>[]) new Iterator[G.V()];
    for (int v = 0; v < G.V(); v++) {
      adj[v] = G.adj(v).iterator();
    }

    int s = nonIsolatedVertex(G);
    Stack<Integer> stack = new Stack<Integer>();
    stack.push(s);

    cycle = new Stack<Integer>();
    while (!stack.isEmpty()) {
      int v = stack.pop();
      while (adj[v].hasNext()) {
        stack.push(v);
        v = adj[v].next();
      }
      cycle.push(v);
    }

    if (cycle.size() != G.E() + 1) {
      cycle = null;
    }
    assert certifySolution(G);
  }

  public Iterable<Integer> cycle() {
    return cycle;
  }

  public boolean hasEulerianCycle() {
    return cycle != null;
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
      return false;
    }

    for (int v = 0; v < G.V(); v++) {
      if (G.outdegree(v) != G.indegree(v)) {
        return false;
      }
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

  private boolean certifySolution(Digraph G) {
    if (hasEulerianCycle() == (cycle() == null)) {
      return false;
    }

    if (hasEulerianCycle() != satisfiesNecessaryAndSufficientConditions(G)) {
      return false;
    }

    if (cycle == null) {
      return true;
    }

    if (cycle.size() != G.E() + 1) {
      return false;
    }
    return true;
  }

  private static void unitTest(Digraph G, String description) {
    StdOut.println(description);
    StdOut.println("-------------------------------------");
    StdOut.print(G);

    DirectedEulerianCycle euler = new DirectedEulerianCycle(G);

    StdOut.print("Eulerian cycle: ");
    if (euler.hasEulerianCycle()) {
      for (int v : euler.cycle()) {
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

    Digraph G3 = new Digraph(V);
    unitTest(G3, "empty digraph");

    Digraph G4 = new Digraph(V);
    int v4 = StdRandom.uniform(V);
    G4.addEdge(v4, v4);
    unitTest(G4, "single self loop");

    Digraph H1 = DigraphGenerator.eulerianCycle(V / 2, E / 2);
    Digraph H2 = DigraphGenerator.eulerianCycle(V - V / 2, E - E / 2);
    int[] perm = new int[V];
    for (int i = 0; i < V; i++) {
      perm[i] = i;
    }
    StdRandom.shuffle(perm);
    Digraph G5 = new Digraph(V);
    for (int v = 0; v < H1.V(); v++) {
      for (int w : H1.adj(v)) {
        G5.addEdge(perm[v], perm[w]);
      }
    }
    for (int v = 0; v < H2.V(); v++) {
      for (int w : H2.adj(v)) {
        G5.addEdge(perm[V / 2 + v], perm[V / 2 + w]);
      }
    }
    unitTest(G5, "Union of two disjoint cycles");

    Digraph G6 = DigraphGenerator.simple(V, E);
    unitTest(G6, "simple digraph");

    Digraph G7 = new Digraph(new In("eulerianD.txt"));
    unitTest(G7, "4-vertex Eulerian digraph");
  }
}
