package edu.princeton.cs.algs4;

public class Accumulator {
  private int n = 0;
  private double sum = 0.0;
  private double mu = 0.0;

  public Accumulator() {}

  public void addDataValue(double x) {
    n++;
    double delta = x - mu;
    mu += delta / n;
    sum += (double) (n - 1) / n * delta * delta;
  }

  public double mean() {
    return mu;
  }

  public double var() {
    if (n <= 1) {
      return Double.NaN;
    }
    return sum / (n - 1);
  }

  public double stddev() {
    return Math.sqrt(this.var());
  }

  public int count() {
    return n;
  }

  public String toString() {
    return "n = " + n + ", mean = " + mean() + ", stddev = " + stddev();
  }

  public static void main(String[] args) {
    Accumulator stats = new Accumulator();
    while (!StdIn.isEmpty()) {
      double x = StdIn.readDouble();
      stats.addDataValue(x);
    }

    StdOut.printf("n      = %d\n", stats.count());
    StdOut.printf("mean   = %.5f\n", stats.mean());
    StdOut.printf("stddev = %.5f\n", stats.stddev());
    StdOut.printf("var    = %.5f\n", stats.var());
    StdOut.println(stats);
  }
}