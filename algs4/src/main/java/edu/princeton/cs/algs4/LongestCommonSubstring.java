package edu.princeton.cs.algs4;

public class LongestCommonSubstring {
  private LongestCommonSubstring() {}

  private static String lcp(String s, int p, String t, int q) {
    int n = Math.min(s.length() - p, t.length() - q);
    for (int i = 0; i < n; i++) {
      if (s.charAt(p + i) != t.charAt(q + i)) {
        return s.substring(p, p + i);
      }
    }
    return s.substring(p, p + n);
  }

  private static int compare(String s, int p, String t, int q) {
    int n = Math.min(s.length() - p, t.length() - q);
    for (int i = 0; i < n; i++) {
      if (s.charAt(p + i) != t.charAt(q + i)) {
        return s.charAt(p + i) - t.charAt(q + i);
      }
    }
    if (s.length() - p < t.length() - q) {
      return -1;
    } else if (s.length() - p > t.length() - q) {
      return +1;
    } else {
      return 0;
    }
  }

  public static String lcs(String s, String t) {
    SuffixArray suffix1 = new SuffixArray(s);
    SuffixArray suffix2 = new SuffixArray(t);

    String lcs = "";
    int i = 0;
    int j = 0;
    while (i < s.length() && j < t.length()) {
      int p = suffix1.index(i);
      int q = suffix2.index(j);
      String x = lcp(s, p, t, q);
      if (x.length() > lcs.length()) {
        lcs = x;
      }
      if (compare(s, p, t, q) < 0) {
        i++;
      } else {
        j++;
      }
    }
    return lcs;
  }

  public static void main(String[] args) {
    In in1 = new In(args[0]);
    In in2 = new In(args[1]);
    String s = in1.readAll().trim().replaceAll("\\s+", " ");
    String t = in2.readAll().trim().replaceAll("\\s+", " ");
    StdOut.println("'" + lcs(s, t) + "'");
  }
}
