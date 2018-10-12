package edu.princeton.cs.algs4;

public class AssignmentProblem {
  private static final double FLOATING_POINT_EPSILON = 1E-14;
  private static final int UNMATCHED = -1;

  private int n;
  private double[][] weight;
  private double minWeight;
  private double[] px;
  private double[] py;
  private int[] xy;
  private int[] yx;

  public AssignmentProblem(double[][] weight) {
    if (weight == null) {
      throw new IllegalArgumentException("constructor argument is null");
    }
    n = weight.length;
    this.weight = new double[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Double.isNaN(weight[i][j])) {
          throw new IllegalArgumentException(
              "weight " + i + "-" + j + " is NaN");
        }
        if (weight[i][j] < minWeight) {
          minWeight = weight[i][j];
        }
        this.weight[i][j] = weight[i][j];
      }
    }

    px = new double[n];
    py = new double[n];

    xy = new int[n];
    yx = new int[n];
    for (int i = 0; i < n; i++) {
      xy[i] = UNMATCHED;
    }
    for (int j = 0; j < n; j++) {
      yx[j] = UNMATCHED;
    }

    for (int k = 0; k < n; k++) {
      assert isDualFeasible();
      assert isComplementarySlack();
      augment();
    }
    assert certifySolution();
  }

  private void augment() {
    EdgeWeightedDigraph G = new EdgeWeightedDigraph(2 * n + 2);
    int s = 2 * n;
    int t = 2 * n + 1;
    for (int i = 0; i < n; i++) {
      if (xy[i] == UNMATCHED) {
        G.addEdge(new DirectedEdge(s, i, 0.0));
      }
    }
    for (int j = 0; j < n; j++) {
      if (yx[j] == UNMATCHED) {
        G.addEdge(new DirectedEdge(n + j, t, py[j]));
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (xy[i] == j) {
          G.addEdge(new DirectedEdge(n + j, i, 0.0));
        } else {
          G.addEdge(new DirectedEdge(i, n + j, reducedCost(i, j)));
        }
      }
    }

    DijkstraSP spt = new DijkstraSP(G, s);

    for (DirectedEdge e : spt.pathTo(t)) {
      int i = e.from();
      int j = e.to() - n;
      if (i < n) {
        xy[i] = j;
        yx[j] = i;
      }
    }

    for (int i = 0; i < n; i++) {
      px[i] += spt.distTo(i);
    }
    for (int j = 0; j < n; j++) {
      py[j] += spt.distTo(n + j);
    }
  }

  private double reducedCost(int i, int j) {
    double reducedCost = (weight[i][j] - minWeight) + px[i] - py[j];

    double magnitube = Math.abs(weight[i][j])
        + Math.abs(px[i]) + Math.abs(py[j]);
    if (Math.abs(reducedCost) <= FLOATING_POINT_EPSILON * magnitube) {
      return 0.0;
    }
    assert reducedCost >= 0.0;
    return reducedCost;
  }

  public double dualRow(int i) {
    validate(i);
    return px[i];
  }

  public double dualCol(int j) {
    validate(j);
    return py[j];
  }

  public int sol(int i) {
    validate(i);
    return xy[i];
  }

  public double weight() {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
      if (xy[i] != UNMATCHED) {
        total += weight[i][xy[i]];
      }
    }
    return total;
  }

  private void validate(int i) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException(
          "index is not between 0 and " + (n - 1) + ": " + i);
    }
  }

  private boolean isDualFeasible() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (reducedCost(i, j) < 0) {
          StdOut.println("Dual variables are not feasible");
          return false;
        }
      }
    }
    return true;
  }

  private boolean isComplementarySlack() {
    for (int i = 0; i < n; i++) {
      if ((xy[i] != UNMATCHED) && (reducedCost(i, xy[i]) != 0)) {
        StdOut.println("Primal and dual variables are not complementary slack");
        return false;
      }
    }
    return true;
  }

  private boolean isPerfectMatching() {
    boolean[] perm = new boolean[n];
    for (int i = 0; i < n; i++) {
      if (perm[xy[i]]) {
        StdOut.println("Not a perfect matching");
        return false;
      }
      perm[xy[i]] = true;
    }

    for (int j = 0; j < n; j++) {
      if (xy[yx[j]] != j) {
        StdOut.println("xy[] and yx[] are not inverses");
        return false;
      }
    }
    for (int i = 0; i < n; i++) {
      if (yx[xy[i]] != i) {
        StdOut.println("xy[] and yx[] are not inverses");
        return false;
      }
    }
    return true;
  }

  private boolean certifySolution() {
    return isPerfectMatching() && isDualFeasible() && isComplementarySlack();
  }

  public static void main(String[] args) {
    int n = Integer.parseInt(args[0]);
    double[][] weight = new double[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        weight[i][j] = StdRandom.uniform(900) + 100;
      }
    }

    AssignmentProblem assignment = new AssignmentProblem(weight);
    StdOut.printf("weight = %.0f\n", assignment.weight());
    StdOut.println();

    if (n >= 20) {
      return;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == assignment.sol(i)) {
          StdOut.printf("*%.0f", weight[i][j]);
        } else {
          StdOut.printf(" %.0f ", weight[i][j]);
        }
      }
      StdOut.println();
    }
  }
}
