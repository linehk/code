package edu.princeton.cs.algs4;

public class Stopwatch {
  private final long start;

  public Stopwatch() {
    start = System.currentTimeMillis();
  }

  public double elapsedTime() {
    long now = System.currentTimeMillis();
    return (now - start) / 1000.0;
  }

  public static void main(String[] args) {
    int n = Integer.parseInt(args[0]);

    Stopwatch timer1 = new Stopwatch();
    double sum1 = 0.0;
    for (int i = 1; i <= n; i++) {
      sum1 += Math.sqrt(i);
    }
    double time1 = timer1.elapsedTime();
    StdOut.printf("%e (%.2f seconds)\n", sum1, time1);

    Stopwatch timer2 = new Stopwatch();
    double sum2 = 0.0;
    for (int i = 1; i <= n; i++) {
      sum2 += Math.pow(i, 0.5);
    }
    double time2 = timer2.elapsedTime();
    StdOut.printf("%e (%.2f seconds)\n", sum2, time2);
  }
}