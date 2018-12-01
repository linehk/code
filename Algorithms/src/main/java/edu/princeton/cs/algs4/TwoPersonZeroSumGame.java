package edu.princeton.cs.algs4;

public class TwoPersonZeroSumGame {
  private static final double EPSILON = 1E-8;

  private final int m;
  private final int n;
  private LinearProgramming lp;
  private double constant;

  public TwoPersonZeroSumGame(double[][] payoff) {
    m = payoff.length;
    n = payoff[0].length;

    double[] c = new double[n];
    double[] b = new double[m];
    double[][] A = new double[m][n];
    for (int i = 0; i < m; i++) {
      b[i] = 1.0;
    }
    for (int j = 0; j < n; j++) {
      c[j] = 1.0;
    }

    constant = Double.POSITIVE_INFINITY;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (payoff[i][j] < constant) {
          constant = payoff[i][j];
        }
      }
    }

    if (constant <= 0) {
      constant = -constant + 1;
    } else {
      constant = 0;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        A[i][j] = payoff[i][j] + constant;
      }
    }

    lp = new LinearProgramming(A, b, c);
    assert certifySolution(payoff);
  }

  public double value() {
    return 1.0 / scale() - constant;
  }

  private double scale() {
    double[] x = lp.primal();
    double sum = 0.0;
    for (int j = 0; j < n; j++) {
      sum += x[j];
    }
    return sum;
  }

  public double[] row() {
    double scale = scale();
    double[] x = lp.primal();
    for (int j = 0; j < n; j++) {
      x[j] /= scale;
    }
    return x;
  }

  public double[] column() {
    double scale = scale();
    double[] y = lp.dual();
    for (int i = 0; i < m; i++) {
      y[i] /= scale;
    }
    return y;
  }

  private boolean isPrimalFeasible() {
    double[] x = row();
    double sum = 0.0;
    for (int j = 0; j < n; j++) {
      if (x[j] < 0) {
        StdOut.println("row vector not a probability distribution");
        StdOut.printf("   x[%d] = %f\n", j, x[j]);
        return false;
      }
      sum += x[j];
    }
    if (Math.abs(sum - 1.0) > EPSILON) {
      StdOut.println("row vector x[] is not a probability distribution");
      StdOut.println("    sum = " + sum);
      return false;
    }
    return true;
  }

  private boolean isDualFeasible() {
    double[] y = column();
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
      if (y[i] < 0) {
        StdOut.println("column vector y[] is not a probability distribution");
        StdOut.printf("    y[%d] = %f\n", i, y[i]);
        return false;
      }
      sum += y[i];
    }
    if (Math.abs(sum - 1.0) > EPSILON) {
      StdOut.println("column vector not a probability distribution");
      StdOut.println("    sum = " + sum);
      return false;
    }
    return true;
  }

  private boolean isNashEquilibrium(double[][] payoff) {
    double[] x = row();
    double[] y = column();
    double value = value();

    double opt1 = Double.NEGATIVE_INFINITY;
    for (int i = 0; i < m; i++) {
      double sum = 0.0;
      for (int j = 0; j < n; j++) {
        sum += payoff[i][j] * x[j];
      }
      if (sum > opt1) {
        opt1 = sum;
      }
    }
    if (Math.abs(opt1 - value) > EPSILON) {
      StdOut.println("Optimal value = " + value);
      StdOut.println("Optimal best response for column player = " + opt1);
      return false;
    }

    double opt2 = Double.POSITIVE_INFINITY;
    for (int j = 0; j < n; j++) {
      double sum = 0.0;
      for (int i = 0; i < m; i++) {
        sum += payoff[i][j] * y[i];
      }
      if (sum < opt2) {
        opt2 = sum;
      }
    }
    if (Math.abs(opt2 - value) > EPSILON) {
      StdOut.println("Optimal value = " + value);
      StdOut.println("Optimal best response for row player = " + opt2);
      return false;
    }
    return true;
  }

  private boolean certifySolution(double[][] payoff) {
    return isPrimalFeasible() && isDualFeasible() && isNashEquilibrium(payoff);
  }

  private static void test(String description, double[][] payoff) {
    StdOut.println();
    StdOut.println(description);
    StdOut.println("------------------------------------");
    int m = payoff.length;
    int n = payoff[0].length;
    TwoPersonZeroSumGame zerosum = new TwoPersonZeroSumGame(payoff);
    double[] x = zerosum.row();
    double[] y = zerosum.column();

    StdOut.print("x[] = [");
    for (int j = 0; j < n - 1; j++) {
      StdOut.printf("%8.4f, ", x[j]);
    }
    StdOut.printf("%8.4f]\n", x[n - 1]);

    StdOut.print("y[] = [");
    for (int i = 0; i < m - 1; i++) {
      StdOut.printf("%8.4f, ", y[i]);
    }
    StdOut.printf("%8.4f]\n", y[m - 1]);
    StdOut.println("value =  " + zerosum.value());

  }

  private static void test1() {
    double[][] payoff = {
        {30, -10, 20},
        {10, 20, -20}
    };
    test("wikipedia", payoff);
  }

  private static void test2() {
    double[][] payoff = {
        { 0, 2, -3, 0},
        {-2, 0, 0, 3},
        {3, 0, 0, -4},
        {0, -3, 4, 0}
    };
    test("Chvatal, p. 230", payoff);
  }

  private static void test3() {
    double[][] payoff = {
        {0, 2, -3, 0},
        {-2, 0, 0, 3},
        {3, 0, 0, -4},
        {0, -3, 4, 0},
        {0, 0, -3, 3},
        {-2, 2, 0, 0},
        {3, -3, 0, 0},
        {0, 0, 4, -4}
    };
    test("Chvatal, p. 234", payoff);
  }

  private static void test4() {
    double[][] payoff = {
        {0, 2, -1, -1},
        {0, 1, -2, -1},
        {-1, -1, 1, 1},
        {-1, 0, 0, 1},
        {1, -2, 0, -3},
        {1, -1, -1, -3},
        {0, -3, 2, -1},
        {0, -2, 1, -1},
    };
    test("Chvatal p. 236", payoff);
  }

  private static void test5() {
    double[][] payoff = {
        {0, -1, 1},
        {1, 0, -1},
        {-1, 1, 0}
    };
    test("rock, paper, scisssors", payoff);
  }

  public static void main(String[] args) {
    test1();
    test2();
    test3();
    test4();
    test5();

    int m = Integer.parseInt(args[0]);
    int n = Integer.parseInt(args[1]);
    double[][] payoff = new double[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        payoff[i][j] = StdRandom.uniform(-0.5, 0.5);
      }
    }
    test("random " + m + "-by-" + n, payoff);
  }
}
