package edu.princeton.cs.algs4;

public class DegreesOfSeparation {
  private DegreesOfSeparation() {}

  public static void main(String[] args) {
    String filename = args[0];
    String delimiter = args[1];
    String source = args[2];

    SymbolGraph sg = new SymbolGraph(filename, delimiter);
    Graph G = sg.graph();
    if (!sg.contains(source)) {
      StdOut.println(source + " not in database.");
      return;
    }

    int s = sg.indexOf(source);
    BreadthFirstPaths bfs = new BreadthFirstPaths(G, s);

    while (!StdIn.isEmpty()) {
      String sink = StdIn.readLine();
      if (sg.contains(sink)) {
        int t = sg.indexOf(sink);
        if (bfs.hasPathTo(t)) {
          for (int v : bfs.pathTo(t)) {
            StdOut.println("    " + sg.nameOf(v));
          }
        } else {
          StdOut.println("Not connected");
        }
      } else {
        StdOut.println("  Not in database.");
      }
    }
  }
}
