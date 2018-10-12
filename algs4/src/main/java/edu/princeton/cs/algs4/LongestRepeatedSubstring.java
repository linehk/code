package edu.princeton.cs.algs4;

public class LongestRepeatedSubstring {
  private LongestRepeatedSubstring() {}

  public static String lrs(String text) {
    int n = text.length();
    SuffixArray sa = new SuffixArray(text);
    String lrs = "";
    for (int i = 1; i < n; i++) {
      int length = sa.lcp(i);
      if (length > lrs.length()) {
        lrs = text.substring(sa.index(i), sa.index(i) + length);
      }
    }
    return lrs;
  }

  public static void main(String[] args) {
    String text = StdIn.readAll().replaceAll("\\s+", " ");
    StdOut.println("'" + lrs(text) + "'");
  }
}
