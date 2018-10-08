package edu.princeton.cs.algs4;

public class AmericanFlag {
  private static final int BITS_PER_BYTE = 8;
  private static final int BITS_PER_INT = 32;
  private static final int R = 256;
  private static final int CUTOFF = 15;

  private AmericanFlag() {}

  private static int charAt(String s, int d) {
    assert d >= 0 && d <= s.length();
    if (d == s.length()) {
      return -1;
    }
    return s.charAt(d);
  }

  public static void sort(String[] a) {
    sort(a, 0, a.length - 1);
  }

  public static void sort(String[] a, int lo, int hi) {
    Stack<Integer> st = new Stack<Integer>();
    int[] first = new int[R + 2];
    int[] next = new int[R + 2];
    int d = 0;

    st.push(lo);
    st.push(hi);
    st.push(d);

    while (!st.isEmpty()) {
      d = st.pop();
      hi = st.pop();
      lo = st.pop();

      if (hi <= lo + CUTOFF) {
        insertion(a, lo, hi, d);
        continue;
      }

      for (int i = lo; i <= hi; i++) {
        int c = charAt(a[i], d) + 1;
        first[c + 1]++;
      }

      first[0] = lo;
      for (int c = 0; c <= R; c++) {
        first[c + 1] += first[c];

        if (c > 0 && first[c + 1] - 1 > first[c]) {
          st.push(first[c]);
          st.push(first[c + 1] - 1);
          st.push(d + 1);
        }
      }

      for (int c = 0; c < R + 2; c++) {
        next[c] = first[c];
      }

      for (int k = lo; k <= hi; k++) {
        int c = charAt(a[k], d) + 1;
        while (first[c] > k) {
          exch(a, k, next[c]++);
          c = charAt(a[k], d) + 1;
        }
        next[c]++;
      }

      for (int c = 0; c < R + 2; c++) {
        first[c] = 0;
        next[c] = 0;
      }
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

  public static void sort(int[] a) {
    sort(a, 0, a.length - 1);
  }

  private static void sort(int[] a, int lo, int hi) {
    Stack<Integer> st = new Stack<Integer>();
    int[] first = new int[R + 1];
    int[] next = new int[R + 1];
    int mask = R - 1;
    int d = 0;

    st.push(lo);
    st.push(hi);
    st.push(d);

    while (!st.isEmpty()) {
      d = st.pop();
      hi = st.pop();
      lo = st.pop();

      if (hi <= lo + CUTOFF) {
        insertion(a, lo, hi, d);
        continue;
      }

      int shift = BITS_PER_INT - BITS_PER_BYTE * d - BITS_PER_BYTE;
      for (int i = lo; i <= hi; i++) {
        int c = (a[i] >> shift) & mask;
        first[c + 1]++;
      }

      first[0] = lo;
      for (int c = 0; c < R; c++) {
        first[c + 1] += first[c];

        if (d < 3 && first[c + 1] - 1 > first[c]) {
          st.push(first[c]);
          st.push(first[c + 1] - 1);
          st.push(d + 1);
        }
      }

      for (int c = 0; c < R + 1; c++) {
        next[c] = first[c];
      }

      for (int k = lo; k <= hi; k++) {
        int c = (a[k] >> shift) & mask;
        while (first[c] > k) {
          exch(a, k, next[c]++);
          c = (a[k] >> shift) & mask;
        }
        next[c]++;
      }

      for (int c = 0; c < R + 1; c++) {
        first[c] = 0;
        next[c] = 0;
      }
    }
  }

  private static void insertion(int[] a, int lo, int hi, int d) {
    for (int i = lo; i <= hi; i++) {
      for (int j = i; j > lo && less(a[j], a[j - 1], d); j--) {
        exch(a, j, j - 1);
      }
    }
  }

  private static void exch(int[] a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  private static boolean less(int v, int w, int d) {
    int mask = R - 1;
    for (int i = d; i < 4; i++) {
      int shift = BITS_PER_INT - BITS_PER_BYTE * i - BITS_PER_BYTE;
      int a = (v >> shift) & mask;
      int b = (w >> shift) & mask;
      if (a < b) {
        return true;
      }
      if (a > b) {
        return false;
      }
    }
    return false;
  }

  public static void main(String[] args) {
    if (args.length > 0 && args[0].equals("int")) {
      int[] a = StdIn.readAllInts();
      sort(a);

      for (int i = 0; i < a.length; i++) {
        StdOut.println(a[i]);
      }
    } else {
      String[] a = StdIn.readAllStrings();
      sort(a);

      for (int i = 0; i < a.length; i++) {
        StdOut.println(a[i]);
      }
    }
  }
}
