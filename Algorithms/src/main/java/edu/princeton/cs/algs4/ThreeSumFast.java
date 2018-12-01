package edu.princeton.cs.algs4;

import java.util.Arrays;

public class ThreeSumFast {
  private ThreeSumFast() {}

  private static boolean containsDuplicates(int[] a) {
    for (int i = 1; i < a.length; i++) {
      if (a[i] == a[i - 1]) {
        return true;
      }
    }
    return false;
  }

  public static void printAll(int[] a) {
    int n = a.length;
    Arrays.sort(a);
    if (containsDuplicates(a)) {
      throw new IllegalArgumentException("array contains duplicate integers");
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int k = Arrays.binarySearch(a, -(a[i] + a[j]));
        if (k > j) {
          StdOut.println(a[i] + " " + a[j] + " " + a[k]);
        }
      }
    }
  }

  public static int count(int[] a) {
    int n = a.length;
    Arrays.sort(a);
    if (containsDuplicates(a)) {
      throw new IllegalArgumentException("array contains duplicate integers");
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int k = Arrays.binarySearch(a, -(a[i] + a[j]));
        if (k > j) {
          count++;
        }
      }
    }
    return count;
  }

  public static void main(String[] args) {
    In in = new In(args[0]);
    int[] a = in.readAllInts();
    int count = count(a);
    StdOut.println(count);
  }
}