package edu.princeton.cs.algs4;

public class AmericanFlagX {
  private static final int R = 256;
  private static final int CUTOFF = 15;

  private AmericanFlagX() {}

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
    int[] count = new int[R + 1];
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
        count[c]++;
      }

      count[0] += lo;
      for (int c = 0; c < R; c++) {
        count[c + 1] += count[c];

        if (c > 0 && count[c + 1] - 1 > count[c]) {
          st.push(count[c]);
          st.push(count[c + 1] - 1);
          st.push(d + 1);
        }
      }

      for (int r = hi; r >= lo; r--) {
        int c = charAt(a[r], d) + 1;
        while (r >= lo && count[c] - 1 <= r) {
          if (count[c] - 1 == r) {
            count[c]--;
          }
          r--;
          if (r >= lo) {
            c = charAt(a[r], d) + 1;
          }
        }

        if (r < lo) {
          break;
        }

        while (--count[c] != r) {
          exch(a, r, count[c]);
          c = charAt(a[r], d) + 1;
        }
      }

      for (int c = 0; c < R + 1; c++) {
        count[c] = 0;
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

  public static void main(String[] args) {
    String[] a = StdIn.readAllStrings();
    sort(a);

    for (int i = 0; i < a.length; i++) {
      StdOut.println(a[i]);
    }
  }
}
