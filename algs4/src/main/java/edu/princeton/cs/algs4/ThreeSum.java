package edu.princeton.cs.algs4;

public class ThreeSum {
  private ThreeSum() {}

  public static void printAll(int[] a) {
    int n = a.length;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (a[i] + a[j] + a[k] == 0) {
            StdOut.println(a[i] + " " + a[j] + " " + a[k]);
          }
        }
      }
    }
  }

  public static int count(int[] a) {
    int n = a.length;
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (a[i] + a[j] + a[k] == 0) {
            count++;
          }
        }
      }
    }
    return count;
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    int[] a = in.readAllInts();

    Stopwatch timer = new Stopwatch();
    int count = count(a);
    StdOut.println("elapsed time = " + timer.elapsedTime());
    StdOut.println(count);
  }
}