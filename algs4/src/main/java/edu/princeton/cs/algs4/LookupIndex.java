package edu.princeton.cs.algs4;

public class LookupIndex {
  private LookupIndex() {}

  public static void main(String[] args) {
    String filename = args[0];
    String separator = args[1];
    In in = new In(filename);

    ST<String, Queue<String>> st = new ST<String, Queue<String>>();
    ST<String, Queue<String>> ts = new ST<String, Queue<String>>();

    while (in.hasNextLine()) {
      String line = in.readLine();
      String[] fields = line.split(separator);
      String key = fields[0];
      for (int i = 1; i < fields.length; i++) {
        String val = fields[i];
        if (!st.contains(key)) {
          st.put(key, new Queue<String>());
        }
        if (!ts.contains(val)) {
          ts.put(val, new Queue<String>());
        }
        st.get(key).enqueue(val);
        ts.get(val).enqueue(key);
      }
    }

    StdOut.println("Done indexing");

    while (!StdIn.isEmpty()) {
      String query = StdIn.readLine();
      if (st.contains(query)) {
        for (String vals : st.get(query)) {
          StdOut.println("  " + vals);
        }
      }
      if (ts.contains(query)) {
        for (String keys : ts.get(query)) {
          StdOut.println("  " + keys);
        }
      }
    }
  }
}
