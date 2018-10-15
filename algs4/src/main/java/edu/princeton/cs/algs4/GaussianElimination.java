package edu.princeton.cs.algs4;

public class GaussianElimination {
  private static final double EPSILON = 1E-8;

  private final int m;
  private final int n;
  private double[][] a;

  public GaussianElimination(double[][] A, double[] b) {
    m = A.length;
    n = A[0].length;

    if (b.length != m) {
      throw new IllegalArgumentException("Dimensions disagree");
    }

    a = new double[m][n + 1];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = A[i][j];
      }
    }

    for (int i = 0; i < m; i++) {
      a[i][n] = b[i];
    }

    forwardElimination();

    assert certifySolution(A, b);
  }

  private void forwardElimination() {
    for (int p = 0; p < Math.min(m, n); p++) {
      int max = p;
      for (int i = p + 1; i < m; i++) {
        if (Math.abs(a[i][p]) > Math.abs(a[max][p])) {
          max = i;
        }
      }

      swap(p, max);

      if (Math.abs(a[p][p]) <= EPSILON) {
        continue;
      }

      pivot(p);
    }
  }

  private void swap(int row1, int row2) {
    double[] temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
  }

  private void pivot(int p) {
    for (int i = p + 1; i < m; i++) {
      double alpha = a[i][p] / a[p][p];
      for (int j = p; j <= n; j++) {
        a[i][j] -= alpha * a[p][j];
      }
    }
  }

  public double[] primal() {
    double[] x = new double[n];
    for (int i = Math.min(n - 1, m - 1); i >= 0; i--) {
      double sum = 0.0;
      for (int j = i + 1; j < n; j++) {
        sum += a[i][j] * x[j];
      }

      if (Math.abs(a[i][i]) > EPSILON) {
        x[i] = (a[i][n] - sum) / a[i][i];
      } else if (Math.abs(a[i][n] - sum) > EPSILON) {
        return null;
      }
    }

    for (int i = n; i < m; i++) {
      double sum = 0.0;
      for (int j = 0; j < n; j++) {
        sum += a[i][j] * x[j];
      }
      if (Math.abs(a[i][n] - sum) > EPSILON) {
        return null;
      }
    }
    return x;
  }

  public boolean isFeasible() {
    return primal() != null;
  }

  private boolean certifySolution(double[][] A, double[] b) {
    if (!isFeasible()) {
      return true;
    }
    double[] x = primal();
    for (int i = 0; i < m; i++) {
      double sum = 0.0;
      for (int j = 0; j < n; j++) {
        sum += A[i][j] * x[j];
      }
      if (Math.abs(sum - b[i]) > EPSILON) {
        StdOut.println("not feasible");
        StdOut.println("b[" + i + "] = " + b[i] + ", sum = " + sum);
        return false;
      }
    }
    return true;
  }

  private static void test(String name, double[][] A, double[] b) {
    StdOut.println("----------------------------------------------------");
    StdOut.println(name);
    StdOut.println("----------------------------------------------------");
    GaussianElimination gaussian = new GaussianElimination(A, b);
    double[] x = gaussian.primal();
    if (gaussian.isFeasible()) {
      for (int i = 0; i < x.length; i++) {
        StdOut.printf("%.6f\n", x[i]);
      }
    } else {
      StdOut.println("System is infeasible");
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
    test("test 1 (3-by-3 system, nonsingular)", A, b);
  }

  private static void test2() {
    double[][] A = {
        {1, -3, 1},
        {2, -8, 8},
        {-6, 3, -15}
    };
    double[] b = {4, -2, 9};
    test("test 2 (3-by-3 system, nonsingular)", A, b);
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
    test("test 3 (5-by-5 system, no solutions)", A, b);
  }

  private static void test4() {
    double[][] A = {
        {2, -3, -1, 2, 3},
        {4, -4, -1, 4, 11},
        {2, -5, -2, 2, -1},
        {0, 2, 1, 0, 4},
        {-4, 6, 0, 0, 7},
    };
    double[] b = {4, 4, 9, -5, 5};
    test("test 4 (5-by-5 system, infinitely many solutions)", A, b);
  }

  private static void test5() {
    double[][] A = {
        {2, -1, 1},
        {3, 2, -4},
        {-6, 3, -3},
    };
    double[] b = {1, 4, 2};
    test("test 5 (3-by-3 system, no solutions)", A, b);
  }

  private static void test6() {
    double[][] A = {
        {1, -1, 2},
        {4, 4, -2},
        {-2, 2, -4},
    };
    double[] b = {-3, 1, 6};
    test("test 6 (3-by-3 system, infinitely many solutions)", A, b);
  }

  private static void test7() {
    double[][] A = {
        {0, 1, 1},
        {2, 4, -2},
        {0, 3, 15},
        {2, 8, 14}
    };
    double[] b = {4, 2, 36, 42};
    test("test 7 (4-by-3 system, full rank)", A, b);
  }

  private static void test8() {
    double[][] A = {
        {0, 1, 1},
        {2, 4, -2},
        {0, 3, 15},
        {2, 8, 14}
    };
    double[] b = {4, 2, 36, 40};
    test("test 8 (4-by-3 system, no solution)", A, b);
  }

  private static void test9() {
    double[][] A = {
        {1, -3, 1, 1},
        {2, -8, 8, 2},
        {-6, 3, -15, 3}
    };
    double[] b = {4, -2, 9};
    test("test 9 (3-by-4 system, full rank)", A, b);
  }

  public static void main(String[] args) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

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

    test(n + "-by-" + n + " (probably nonsingular)", A, b);
  }
}
