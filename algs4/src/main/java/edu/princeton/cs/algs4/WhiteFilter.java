package edu.princeton.cs.algs4;

public class WhiteFilter {
  private WhiteFilter() {}

  public static void main(String[] args) {
    SET<String> set = new SET<String>();

    In in = new In(args[0]);
    while (!in.isEmpty()) {
      String word = in.readString();
      set.add(word);
    }

    while (!StdIn.isEmpty()) {
      String word = StdIn.readString();
      if (set.contains(word)) {
        StdOut.println(word);
      }
    }
  }
}
