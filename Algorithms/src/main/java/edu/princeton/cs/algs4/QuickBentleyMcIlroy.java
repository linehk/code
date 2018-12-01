package edu.princeton.cs.algs4;

public class QuickBentleyMcIlroy {
  private static final int INSERTION_SORT_CUTOFF = 8;

  private static final int MEDIAN_OF_3_CUTOFF = 40;

  private QuickBentleyMcIlroy() {}

  public static void sort(Comparable[] a) {
    sort(a, 0, a.length - 1);
  }

  private static void sort(Comparable[] a, int lo, int hi) {
    int n = hi - lo + 1;

    if (n <= INSERTION_SORT_CUTOFF) {
      insertionSort(a, lo, hi);
      return;
    } else if (n <= MEDIAN_OF_3_CUTOFF) {
      int m = median3(a, lo, lo + n / 2, hi);
      exch(a, m, lo);
    } else {
      int eps = n / 8;
      int mid = lo + n / 2;
      int m1 = median3(a, lo, lo + eps, lo + eps + eps);
      int m2 = median3(a, mid - eps, mid, mid + eps);
      int m3 = median3(a, hi - eps - eps, hi - eps, hi);
      int ninther = median3(a, m1, m2, m3);
      exch(a, ninther, lo);
    }

    int i = lo;
    int j = hi + 1;
    int p = lo;
    int q = hi + 1;
    Comparable v = a[lo];
    while (true) {
      while (less(a[++i], v)) {
        if (i == hi) {
          break;
        }
      }
      while (less(v, a[--j])) {
        if (j == lo) {
          break;
        }
      }

      if (i == j && eq(a[i], v)) {
        exch(a, ++p, i);
      }
      if (i >= j) {
        break;
      }

      exch(a, i, j);
      if (eq(a[i], v)) {
        exch(a, ++p, i);
      }
      if (eq(a[j], v)) {
        exch(a, --q, j);
      }
    }

    i = j + 1;
    for (int k = lo; k <= p; k++) {
      exch(a, k, j--);
    }
    for (int k = hi; k >= q; k--) {
      exch(a, k, i++);
    }

    sort(a, lo, j);
    sort(a, i, hi);
  }

  private static void insertionSort(Comparable[] a, int lo, int hi) {
    for (int i = lo; i <= hi; i++) {
      for (int j = i; j > lo && less(a[j], a[j - 1]); j--) {
        exch(a, j, j - 1);
      }
    }
  }

  private static int median3(Comparable[] a, int i, int j, int k) {
    return (less(a[i], a[j]) ?
        (less(a[j], a[k]) ? j : less(a[i], a[k]) ? k : i) :
        (less(a[k], a[j]) ? j : less(a[k], a[i]) ? k : i));
  }

  private static boolean less(Comparable v, Comparable w) {
    if (v == w) {
      return false;
    }
    return v.compareTo(w) < 0;
  }

  private static boolean eq(Comparable v, Comparable w) {
    if (v == w) {
      return true;
    }
    return v.compareTo(w) == 0;
  }

  private static void exch(Object[] a, int i, int j) {
    Object swap = a[i];
    a[i] = a[j];
    a[j] = swap;
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
    QuickBentleyMcIlroy.sort(a);  
    assert isSorted(a);
    show(a);
  }
}