package edu.princeton.cs.algs4;

public class GaussJordanElimination {
  private static final double EPSILON = 1E-8;

  private final int n;
  private double[][] a;

  public GaussJordanElimination(double[][] A, double[] b) {
    n = b.length;

    a = new double[n][n + n + 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = A[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      a[i][n + i] = 1.0;
    }

    for (int i = 0; i < n; i++) {
      a[i][n + n] = b[i];
    }

    solve();

    assert certifySolution(A, b);
  }

  private void solve() {
    for (int p = 0; p < n; p++) {
      int max = p;
      for (int i = p + 1; i < n; i++) {
        if (Math.abs(a[i][p]) > Math.abs(a[max][p])) {
          max = i;
        }
      }

      swap(p, max);

      if (Math.abs(a[p][p]) <= EPSILON) {
        continue;
      }

      pivot(p, p);
    }
  }

  private void swap(int row1, int row2) {
    double[] temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
  }

  private void pivot(int p, int q) {
    for (int i = 0; i < n; i++) {
      double alpha = a[i][q] / a[p][q];
      for (int j = 0; j <= n + n; j++) {
        if (i != p && j != q) {
          a[i][j] -= alpha * a[p][j];
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (i != p) {
        a[i][q] = 0.0;
      }
    }

    for (int j = 0; j <= n + n; j++) {
      if (j != q) {
        a[p][j] /= a[p][q];
      }
    }
    a[p][q] = 1.0;
  }

  public double[] primal() {
    double[] x = new double[n];
    for (int i = 0; i < n; i++) {
      if (Math.abs(a[i][i]) > EPSILON) {
        x[i] = a[i][n + n] / a[i][i];
      } else if (Math.abs(a[i][n + n]) > EPSILON) {
        return null;
      }
    }
    return x;
  }

  public double[] dual() {
    double[] y = new double[n];
    for (int i = 0; i < n; i++) {
      if ((Math.abs(a[i][i]) <= EPSILON)
          && (Math.abs(a[i][n + n]) > EPSILON)) {
        for (int j = 0; j < n; j++) {
          y[j] = a[i][n + j];
        }
        return y;
      }
    }
    return null;
  }

  public boolean isFeasible() {
    return primal() != null;
  }

  private void show() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        StdOut.printf("%8.3f ", a[i][j]);
      }
      StdOut.printf("| ");
      for (int j = n; j < n + n; j++) {
        StdOut.printf("%8.3f ", a[i][j]);
      }
      StdOut.printf("| %8.3f\n", a[i][n + n]);
    }
    StdOut.println();
  }

  private boolean certifySolution(double[][] A, double[] b) {
    if (isFeasible()) {
      double[] x = primal();
      for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
          sum += A[i][j] * x[j];
        }
        if (Math.abs(sum - b[i]) > EPSILON) {
          StdOut.println("not feasible");
          StdOut.printf("b[%d] = %8.3f, sum = %8.3f\n", i, b[i], sum);
          return false;
        }
      }
      return true;
    } else {
      double[] y = dual();
      for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
          sum += A[i][j] * y[i];
        }
        if (Math.abs(sum) > EPSILON) {
          StdOut.println("invalid certificate of infeasibility");
          StdOut.printf("sum = %8.3f\n", sum);
          return false;
        }
      }
      double sum = 0.0;
      for (int i = 0; i < n; i++) {
        sum += y[i] * b[i];
      }
      if (Math.abs(sum) < EPSILON) {
        StdOut.println("invalid certificate of infeasibility");
        StdOut.printf("yb  = %8.3f\n", sum);
        return false;
      }
      return true;
    }
  }

  private static void test(String name, double[][] A, double[] b) {
    StdOut.println("----------------------------------------------------");
    StdOut.println(name);
    StdOut.println("----------------------------------------------------");
    GaussJordanElimination gaussian = new GaussJordanElimination(A, b);
    if (gaussian.isFeasible()) {
      StdOut.println("Solution to Ax = b");
      double[] x = gaussian.primal();
      for (int i = 0; i < x.length; i++) {
        StdOut.printf("%10.6f\n", x[i]);
      }
    } else {
      StdOut.println("Certificate of infeasibility");
      double[] y = gaussian.dual();
      for (int j = 0; j < y.length; j++) {
        StdOut.printf("%10.6f\n", y[j]);
      }
    }
    StdOut.println();
    StdOut.println();
  }

  private static void test1() {
    double[][] A = {
        {0, 1, 1},
        {2, 4, -2},
        {0, 3, 15}
    };
    double[] b = {4, 2, 36};
    test("test 1", A, b);
  }

  private static void test2() {
    double[][] A = {
        {1, -3, 1},
        {2, -8, 8},
        {-6,  3, -15}
    };
    double[] b = {4, -2, 9};
    test("test 2", A, b);
  }

  private static void test3() {
    double[][] A = {
        {2, -3, -1, 2, 3},
        {4, -4, -1, 4, 11},
        {2, -5, -2, 2, -1},
        {0, 2, 1, 0, 4},
        {-4, 6, 0, 0, 7},
    };
    double[] b = {4, 4, 9, -6, 5};
    test("test 3", A, b);
  }

  private static void test4() {
    double[][] A = {
        {2, -3, -1, 2, 3},
        {4, -4, -1, 4, 11},
        {2, -5, -2, 2, -1},
        {0, 2, 1, 0, 4},
        {-4, 6, 0, 0, 7},
    };
    double[] b = {4, 4, 9, -5, 5 };
    test("test 4", A, b);
  }

  private static void test5() {
    double[][] A = {
        {2, -1, 1},
        {3, 2, -4},
        {-6, 3, -3},
    };
    double[] b = {1, 4, 2};
    test("test 5", A, b);
  }

  private static void test6() {
    double[][] A = {
        {1, -1, 2},
        {4, 4, -2},
        {-2, 2, -4},
    };
    double[] b = {-3, 1, 6};
    test("test 6 (infinitely many solutions)", A, b);
  }

  public static void main(String[] args) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    int n = Integer.parseInt(args[0]);
    double[][] A = new double[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        A[i][j] = StdRandom.uniform(1000);
      }
    }
    double[] b = new double[n];
    for (int i = 0; i < n; i++) {
      b[i] = StdRandom.uniform(1000);
    }
    test("random " + n + "-by-" + n + " (likely full rank)", A, b);


    A = new double[n][n];
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n; j++) {
        A[i][j] = StdRandom.uniform(1000);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      double alpha = StdRandom.uniform(11) - 5.0;
      for (int j = 0; j < n; j++) {
        A[n - 1][j] += alpha * A[i][j];
      }
    }
    b = new double[n];
    for (int i = 0; i < n; i++) {
      b[i] = StdRandom.uniform(1000);
    }
    test("random " + n + "-by-" + n + " (likely infeasible)", A, b);
  }
}
