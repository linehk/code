package edu.princeton.cs.algs4;

public class MergeBU {
  private MergeBU() {}

  private static void merge(Comparable[] a, Comparable[] aux, int lo, int mid,
      int hi) {
    for (int k = lo; k <= hi; k++) {
      aux[k] = a[k];
    }

    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++) {
      if (i > mid) {
        a[k] = aux[j++];
      } else if (j > hi) {
        a[k] = aux[i++];
      } else if (less(aux[j], aux[i])) {
        a[k] = aux[j++];
      } else {
        a[k] = aux[i++];
      }
    }
  }

  public static void sort(Comparable[] a) {
    int n = a.length;
    Comparable[] aux = new Comparable[n];
    for (int len = 1; len < n; len *= 2) {
      for (int lo = 0; lo < n - len; lo += len + len) {
        int mid = lo + len - 1;
        int hi = Math.min(lo + len + len - 1, n - 1);
        merge(a, aux, lo, mid, hi);
      }
    }
    assert isSorted(a);
  }

  private static boolean less(Comparable v, Comparable w) {
    return v.compareTo(w) < 0;
  }

  private static boolean isSorted(Comparable[] a) {
    for (int i = 1; i < a.length; i++) {
      if (less(a[i], a[i - 1])) {
        return false;
      }
    }
    return true;
  }

  private static void show(Comparable[] a) {
    for (int i = 0; i < a.length; i++) {
      StdOut.println(a[i]);
    }
  }

  public static void main(String[] args) {
    String[] a = StdIn.readAllStrings();
    MergeBU.sort(a);  
    show(a);
  }
}