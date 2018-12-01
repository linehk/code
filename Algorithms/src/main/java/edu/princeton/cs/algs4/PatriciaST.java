package edu.princeton.cs.algs4;

public class PatriciaST<Value> {
  private Node head;
  private int count;

  private class Node {
    private Node left;
    private Node right;
    private String key;
    private Value val;
    private int b;

    public Node(String key, Value val, int b) {
      this.key = key;
      this.val = val;
      this.b = b;
    }
  }

  public PatriciaST() {
    head = new Node("", null, 0);
    head.left = head;
    head.right = head;
    count = 0;
  }

  public void put(String key, Value val) {
    if (key == null) {
      throw new IllegalArgumentException("called put(null)");
    }
    if (key.length() == 0) {
      throw new IllegalArgumentException("invalid key");
    }
    if (val == null) {
      delete(key);
    }
    Node p;
    Node x = head;
    do {
      p = x;
      if (safeBitTest(key, x.b)) {
        x = x.right;
      } else {
        x = x.left;
      }
    } while (p.b < x.b);
    if (!x.key.equals(key)) {
      int b = firstDifferingBit(x.key, key);
      x = head;
      do {
        p = x;
        if (safeBitTest(key, x.b)) {
          x = x.right;
        } else {
          x = x.left;
        }
      } while (p.b < x.b && x.b < b);
      Node t = new Node(key, val, b);
      if (safeBitTest(key, b)) {
        t.left = x;
        t.right = t;
      } else {
        t.left = t;
        t.right = x;
      }
      if (safeBitTest(key, p.b)) {
        p.right = t;
      } else {
        p.left = t;
      }
      count++;
    } else {
      x.val = val;
    }
  }

  public Value get(String key) {
    if (key == null) {
      throw new IllegalArgumentException("called get(null)");
    }
    if (key.length() == 0) {
      throw new IllegalArgumentException("invalid key");
    }
    Node p;
    Node x = head;
    do {
      p = x;
      if (safeBitTest(key, x.b)) {
        x = x.right;
      } else {
        x = x.left;
      }
    } while (p.b < x.b);
    if (x.key.equals(key)) {
      return x.val;
    } else {
      return null;
    }
  }

  public void delete(String key) {
    if (key == null) {
      throw new IllegalArgumentException("called delete(null)");
    }
    if (key.length() == 0) {
      throw new IllegalArgumentException("invalid key");
    }
    Node g;
    Node p = head;
    Node x = head;
    do {
      g = p;
      p = x;
      if (safeBitTest(key, x.b)) {
        x = x.right;
      } else {
        x = x.left;
      }
    } while (p.b < x.b);
    if (x.key.equals(key)) {
      Node z;
      Node y = head;
      do {
        z = y;
        if (safeBitTest(key, y.b)) {
          y = y.right;
        } else {
          y = y.left;
        }
      } while (y != x);
      if (x == p) {
        Node c;
        if (safeBitTest(key, x.b)) {
          c = x.left;
        } else {
          c = x.right;
        }
        if (safeBitTest(key, z.b)) {
          z.right = c;
        } else {
          z.left = c;
        }
      } else {
        Node c;
        if (safeBitTest(key, p.b)) {
          c = p.left;
        } else {
          c = p.right;
        }
        if (safeBitTest(key, g.b)) {
          g.right = c;
        } else {
          g.left = c;
        }
        if (safeBitTest(key, z.b)) {
          z.right = p;
        } else {
          z.left = p;
        }
        p.left = x.left;
        p.right = x.right;
        p.b = x.b;
      }
      count--;
    }
  }

  public boolean contains(String key) {
    return get(key) != null;
  }

  public boolean isEmpty() {
    return count == 0;
  }

  public int size() {
    return count;
  }

  public Iterable<String> keys() {
    Queue<String> queue = new Queue<String>();
    if (head.left != head) {
      keys(head.left, 0, queue);
    }
    if (head.right != head) {
      keys(head.right, 0, queue);
    }
    return queue;
  }

  private void keys(Node x, int b, Queue<String> queue) {
    if (x.b > b) {
      keys(x.left, x.b, queue);
      queue.enqueue(x.key);
      keys(x.right, x.b, queue);
    }
  }

  private static boolean safeBitTest(String key, int b) {
    if (b < key.length() * 16) {
      return bitTest(key, b) != 0;
    }
    if (b > key.length() * 16 + 15) {
      return false;
    }
    return true;
  }

  private static int bitTest(String key, int b) {
    return (key.charAt(b >>> 4) >>> (b & 0xf)) & 1;
  }

  private static int safeCharAt(String key, int i) {
    if (i < key.length()) {
      return key.charAt(i);
    }
    if (i > key.length()) {
      return 0x0000;
    } else {
      return 0xffff;
    }
  }

  private static int firstDifferingBit(String k1, String k2) {
    int i = 0;
    int c1 = safeCharAt(k1, 0) & ~1;
    int c2 = safeCharAt(k2, 0) & ~1;
    if (c1 == c2) {
      i = 1;
      while (safeCharAt(k1, i) == safeCharAt(k2, i)) {
        i++;
      }
      c1 = safeCharAt(k1, i);
      c2 = safeCharAt(k2, i);
    }
    int b = 0;
    while (((c1 >>> b) & 1) == ((c2 >>> b) & 1)) {
      b++;
    }
    return i * 16 + b;
  }

  public static void main(String[] args) {
    PatriciaST<Integer> st = new PatriciaST<Integer>();
    int limitItem = 1000000;
    int limitPass = 1;
    int countPass = 0;
    boolean ok = true;

    if (args.length > 0) {
      limitItem = Integer.parseInt(args[0]);
    }
    if (args.length > 1) {
      limitPass = Integer.parseInt(args[1]);
    }

    do {
      String[] a = new String[limitItem];
      int[] v = new int[limitItem];

      StdOut.printf("Creating dataset (%d items)...\n", limitItem);
      for (int i = 0; i < limitItem; i++) {
        a[i] = Integer.toString(i, 16);
        v[i] = i;
      }

      StdOut.printf("Shuffling...\n");
      StdRandom.shuffle(v);

      StdOut.printf("Adding (%d items)...\n", limitItem);
      for (int i = 0; i < limitItem; i++) {
        st.put(a[v[i]], v[i]);
      }

      int countKeys = 0;
      StdOut.printf("Iterating...\n");
      for (String key : st.keys()) {
        countKeys++;
      }
      StdOut.printf("%d items iterated\n", countKeys);
      if (countKeys != limitItem) {
        ok = false;
      }
      if (countKeys != st.size()) {
        ok = false;
      }

      StdOut.printf("Shuffling...\n");
      StdRandom.shuffle(v);

      int limitDelete = limitItem / 2;
      StdOut.printf("Deleting (%d items)...\n", limitDelete);
      for (int i = 0; i < limitDelete; i++) {
        st.delete(a[v[i]]);
      }

      countKeys = 0;
      StdOut.printf("Iterating...\n");
      for (String key : st.keys()) {
        countKeys++;
      }
      StdOut.printf("%d items iterated\n", countKeys);
      if (countKeys != limitItem - limitDelete) {
        ok = false;
      }
      if (countKeys != st.size()) {
        ok = false;
      }

      int countDelete = 0;
      int countRemain = 0;
      StdOut.printf("Checking...\n");
      for (int i = 0; i < limitItem; i++) {
        if (i < limitDelete) {
          if (!st.contains(a[v[i]])) {
            countDelete++;
          }
        } else {
          int val = st.get(a[v[i]]);
          if (val == v[i]) {
            countRemain++;
          }
        }
      }
      StdOut.printf("%d items found and %d (deleted) items missing\n",
          countRemain, countDelete);
      if (countRemain + countDelete != limitItem) {
        ok = false;
      }
      if (countRemain != st.size()) {
        ok = false;
      }
      if (st.isEmpty()) {
        ok = false;
      }

      StdOut.printf("Deleting the rest (%d items)...\n",
          limitItem - countDelete);
      for (int i = countDelete; i < limitItem; i++) {
        st.delete(a[v[i]]);
      }
      if (!st.isEmpty()) {
        ok = false;
      }

      countPass++;
      if (ok) {
        StdOut.printf("PASS %d TESTS SUCCEEDED\n", countPass);
      } else {
        StdOut.printf("PASS %d TESTS FAILED\n",    countPass);
      }
    } while (ok && countPass < limitPass);

    if (!ok) {
      throw new java.lang.RuntimeException("TESTS FAILED");
    }
  }
}
