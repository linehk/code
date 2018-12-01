package edu.princeton.cs.algs4;

public class InplaceMSD {
  private static final int R = 256;
  private static final int CUTOFF = 15;

  private InplaceMSD() {}

  public static void sort(String[] a) {
    int n = a.length;
    sort(a, 0, n - 1, 0);
  }

  private static int charAt(String s, int d) {
    assert d >= 0 && d <= s.length();
    if (d == s.length()) {
      return -1;
    }
    return s.charAt(d);
  }

  private static void sort(String[] a, int lo, int hi, int d) {
    if (hi <= lo + CUTOFF) {
      insertion(a, lo, hi, d);
      return;
    }

    int[] heads = new int[R + 2];
    int[] tails = new int[R + 1];
    for (int i = lo; i <= hi; i++) {
      int c = charAt(a[i], d);
      heads[c + 2]++;
    }

    heads[0] = lo;
    for (int r = 0; r < R + 1; r++) {
      heads[r + 1] += heads[r];
      tails[r] = heads[r + 1];
    }

    for (int r = 0; r < R + 1; r++) {
      while (heads[r] < tails[r]) {
        int c = charAt(a[heads[r]], d);
        while (c + 1 != r) {
          exch(a, heads[c], heads[c + 1]++);
          c = charAt(a[heads[r]], d);
        }
        heads[r]++;
      }
    }

    for (int r = 0; r < R; r++) {
      sort(a, tails[r], tails[r + 1] - 1, d + 1);
    }
  }

  private static void insertion(String[] a, int lo, int hi, int d) {
    for (int i = lo; i <= hi; i++) {
      for (int j = i; j > lo && less(a[j], a[j - 1], d); j--) {
        exch(a, j, j - 1);
      }
    }
  }

  private static void exch(String[] a, int i, int j) {
    String temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  private static boolean less(String v, String w, int d) {
    for (int i = d; i < Math.min(v.length(), w.length()); i++) {
      if (v.charAt(i) < w.charAt(i)) {
        return true;
      }
      if (v.charAt(i) > w.charAt(i)) {
        return false;
      }
    }
    return v.length() < w.length();
  }

  public static void main(String[] args) {
    String[] a = StdIn.readAllStrings();
    int n = a.length;
    sort(a);
    for (int i = 0; i < n; i++) {
      StdOut.println(a[i]);
    }
  }
}
