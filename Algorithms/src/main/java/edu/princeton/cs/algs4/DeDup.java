package edu.princeton.cs.algs4;

public class DeDup {
  private DeDup() {}

  public static void main(String[] args) {
    SET<String> set = new SET<String>();
    while (!StdIn.isEmpty()) {
      String key = StdIn.readString();
      if (!set.contains(key)) {
        set.add(key);
        StdOut.println(key);
      }
    }
  }
}
