package edu.princeton.cs.algs4;

public class Cat {
  private Cat() {}

  public static void main(String[] args) {
    Out out = new Out(args[args.length - 1]);
    for (int i = 0; i < args.length - 1; i++) {
      In in = new In(args[i]);
      String s = in.readAll();
      out.println(s);
      in.close();
    }
    out.close();
  }
}