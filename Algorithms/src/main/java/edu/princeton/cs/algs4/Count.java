package edu.princeton.cs.algs4;

public class Count {
  private Count() {}

  public static void main(String[] args) {
    Alphabet alphabet = new Alphabet(args[0]);
    final int R = alphabet.radix();
    int[] count = new int[R];
    while (StdIn.hasNextChar()) {
      char c = StdIn.readChar();
      if (alphabet.contains(c)) {
        count[alphabet.toIndex(c)]++;
      }
    }
    for (int c = 0; c < R; c++) {
      StdOut.println(alphabet.toChar(c) + " " + count[c]);
    }
  }
}