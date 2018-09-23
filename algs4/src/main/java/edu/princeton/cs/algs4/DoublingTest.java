package edu.princeton.cs.algs4;

public class DoublingTest {
  private static final int MAXIMUM_INTEGER = 1000000;

  private DoublingTest() {}

  public static double timeTrial(int n) {
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = StdRandom.uniform(-MAXIMUM_INTEGER, MAXIMUM_INTEGER);
    }
    Stopwatch timer = new Stopwatch();
    ThreeSum.count(a);
    return timer.elapsedTime();
  }

  public static void main(String[] args) {
    for (int n = 250; true; n += n) {
      double time = timeTrial(n);
      StdOut.printf("%7d %7.1f\n", n, time);
    }
  }
}