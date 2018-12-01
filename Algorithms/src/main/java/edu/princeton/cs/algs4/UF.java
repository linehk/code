package edu.princeton.cs.algs4;

public class UF {
  private int[] parent;
  private byte[] rank;
  private int count;

  public UF(int n) {
    if (n < 0) {
      throw new IllegalArgumentException();
    }
    count = n;
    parent = new int[n];
    rank = new byte[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  public int find(int p) {
    validate(p);
    while (p != parent[p]) {
      parent[p] = parent[parent[p]];
      p = parent[p];
    }
    return p;
  }

  public int count() {
    return count;
  }

  public boolean connected(int p, int q) {
    return find(p) == find(q);
  }

  public void union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) {
      return;
    }

    if (rank[rootP] < rank[rootQ]) {
      parent[rootP] = rootQ;
    } else if (rank[rootP] > rank[rootQ]) {
      parent[rootQ] = rootP;
    } else {
      parent[rootQ] = rootP;
      rank[rootP]++;
    }
    count--;
  }

  private void validate(int p) {
    int n = parent.length;
    if (p < 0 || p >= n) {
      throw new IllegalArgumentException("index " + p +
          " is not between 0 and " + (n - 1));
    }
  }

  public static void main(String[] args) {
    int n = StdIn.readInt();
    UF uf = new UF(n);
    while (!StdIn.isEmpty()) {
      int p = StdIn.readInt();
      int q = StdIn.readInt();
      if (uf.connected(p, q)) {
        continue;
      }
      uf.union(p, q);
      StdOut.println(p + " " + q);
    }
    StdOut.println(uf.count() + " components");
  }
}