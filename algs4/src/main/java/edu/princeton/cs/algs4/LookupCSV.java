package edu.princeton.cs.algs4;

public class LookupCSV {
  private LookupCSV() {}

  public static void main(String[] args) {
    int keyField = Integer.parseInt(args[1]);
    int valField = Integer.parseInt(args[2]);

    ST<String, String> st = new ST<String, String>();

    In in = new In(args[0]);
    while (in.hasNextLine()) {
      String line = in.readLine();
      String[] tokens = line.split(",");
      String key = tokens[keyField];
      String val = tokens[valField];
      st.put(key, val);
    }

    while (!StdIn.isEmpty()) {
      String s = StdIn.readString();
      if (st.contains(s)) {
        StdOut.println(st.get(s));
      } else {
        StdOut.println("Not found");
      }
    }
  }
}
