package edu.princeton.cs.algs4;

public class Whitelist {
  private Whitelist() {}

  public static void main(String[] args) {
    In in = new In(args[0]);
    int[] white = in.readAllInts();
    StaticSETofInts set = new StaticSETofInts(white);

    while (!StdIn.isEmpty()) {
      int key = StdIn.readInt();
      if (!set.contains(key)) {
        StdOut.println(key);
      }
    }
  }
}