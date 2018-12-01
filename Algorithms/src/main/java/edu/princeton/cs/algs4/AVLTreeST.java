package edu.princeton.cs.algs4;

import java.util.NoSuchElementException;

public class AVLTreeST<Key extends Comparable<Key>, Value> {
  private Node root;

  private class Node {
    private final Key key;
    private Value val;
    private int height;
    private int size;
    private Node left;
    private Node right;

    public Node(Key key, Value val, int height, int size) {
      this.key = key;
      this.val = val;
      this.size = size;
      this.height = height;
    }
  }

  public AVLTreeST() {}

  public boolean isEmpty() {
    return root == null;
  }

  public int size() {
    return size(root);
  }

  private int size(Node x) {
    if (x == null) {
      return 0;
    }
    return x.size;
  }

  public int height() {
    return height(root);
  }

  private int height(Node x) {
    if (x == null) {
      return -1;
    }
    return x.height;
  }

  public Value get(Key key) {
    if (key == null) {
      throw new IllegalArgumentException("argument to get() is null");
    }
    Node x = get(root, key);
    if (x == null) {
      return null;
    }
    return x.val;
  }

  private Node get(Node x, Key key) {
    if (x == null) {
      return null;
    }
    int cmp = key.compareTo(x.key);
    if (cmp < 0) {
      return get(x.left, key);
    } else if (cmp > 0) {
      return get(x.right, key);
    } else {
      return x;
    }
  }

  public boolean contains(Key key) {
    return get(key) != null;
  }

  public void put(Key key, Value val) {
    if (key == null) {
      throw new IllegalArgumentException("first argument to put() is null");
    }
    if (val == null) {
      delete(key);
      return;
    }
    root = put(root, key, val);
    assert check();
  }

  private Node put(Node x, Key key, Value val) {
    if (x == null) {
      return new Node(key, val, 0, 1);
    }
    int cmp = key.compareTo(x.key);
    if (cmp < 0) {
      x.left = put(x.left, key, val);
    } else if (cmp > 0) {
      x.right = put(x.right, key, val);
    } else {
      x.val = val;
      return x;
    }
    x.size = 1 + size(x.left) + size(x.right);
    x.height = 1 + Math.max(height(x.left), height(x.right));
    return balance(x);
  }

  private Node balance(Node x) {
    if (balanceFactor(x) < -1) {
      if (balanceFactor(x.right) > 0) {
        x.right = rotateRight(x.right);
      }
      x = rotateLeft(x);
    } else if (balanceFactor(x) > 1) {
      if (balanceFactor(x.left) < 0) {
        x.left = rotateLeft(x.left);
      }
      x = rotateRight(x);
    }
    return x;
  }

  private int balanceFactor(Node x) {
    return height(x.left) - height(x.right);
  }

  private Node rotateRight(Node x) {
    Node y = x.left;
    x.left = y.right;
    y.right = x;
    y.size = x.size;
    x.size = 1 + size(x.left) + size(x.right);
    x.height = 1 + Math.max(height(x.left), height(x.right));
    y.height = 1 + Math.max(height(y.left), height(y.right));
    return y;
  }

  private Node rotateLeft(Node x) {
    Node y = x.right;
    x.right = y.left;
    y.left = x;
    y.size = x.size;
    x.size = 1 + size(x.left) + size(x.right);
    x.height = 1 + Math.max(height(x.left), height(x.right));
    y.height = 1 + Math.max(height(y.left), height(y.right));
    return y;
  }

  public void delete(Key key) {
    if (key == null) {
      throw new IllegalArgumentException("argument to delete() is null");
    }
    if (!contains(key)) {
      return;
    }
    root = delete(root, key);
    assert check();
  }

  private Node delete(Node x, Key key) {
    int cmp = key.compareTo(x.key);
    if (cmp < 0) {
      x.left = delete(x.left, key);
    } else if (cmp > 0) {
      x.right = delete(x.right, key);
    } else {
      if (x.left == null) {
        return x.right;
      } else if (x.right == null) {
        return x.left;
      } else {
        Node y = x;
        x = min(y.right);
        x.right = deleteMin(y.right);
        x.left = y.left;
      }
    }
    x.size = 1 + size(x.left) + size(x.right);
    x.height = 1 + Math.max(height(x.left), height(x.right));
    return balance(x);
  }

  public void deleteMin() {
    if (isEmpty()) {
      throw new NoSuchElementException(
          "called deleteMin() with empty symbol table");
    }
    root = deleteMin(root);
    assert check();
  }

  private Node deleteMin(Node x) {
    if (x.left == null) {
      return x.right;
    }
    x.left = deleteMin(x.left);
    x.size = 1 + size(x.left) + size(x.right);
    x.height = 1 + Math.max(height(x.left), height(x.right));
    return balance(x);
  }

  public void deleteMax() {
    if (isEmpty()) {
      throw new NoSuchElementException(
          "called deleteMax() with empty symbol table");
    }
    root = deleteMax(root);
    assert check();
  }

  private Node deleteMax(Node x) {
    if (x.right == null) {
      return x.left;
    }
    x.right = deleteMax(x.right);
    x.size = 1 + size(x.left) + size(x.right);
    x.height = 1 + Math.max(height(x.left), height(x.right));
    return balance(x);
  }

  public Key min() {
    if (isEmpty()) {
      throw new NoSuchElementException(
          "called min() with empty symbol table");
    }
    return min(root).key;
  }

  private Node min(Node x) {
    if (x.left == null) {
      return x;
    }
    return min(x.left);
  }

  public Key max() {
    if (isEmpty()) {
      throw new NoSuchElementException(
          "called max() with empty symbol table");
    }
    return max(root).key;
  }

  private Node max(Node x) {
    if (x.right == null) {
      return x;
    }
    return max(x.right);
  }

  public Key floor(Key key) {
    if (key == null) {
      throw new IllegalArgumentException("argument to floor() is null");
    }
    if (isEmpty()) {
      throw new NoSuchElementException(
          "called floor() with empty symbol table");
    }
    Node x = floor(root, key);
    if (x == null) {
      return null;
    } else {
      return x.key;
    }
  }

  private Node floor(Node x, Key key) {
    if (x == null) {
      return null;
    }
    int cmp = key.compareTo(x.key);
    if (cmp == 0) {
      return x;
    }
    if (cmp < 0) {
      return floor(x.left, key);
    }
    Node y = floor(x.right, key);
    if (y != null) {
      return y;
    } else {
      return x;
    }
  }

  public Key ceiling(Key key) {
    if (key == null) {
      throw new IllegalArgumentException("argument to ceiling() is null");
    }
    if (isEmpty()) {
      throw new NoSuchElementException(
          "called ceiling() with empty symbol table");
    }
    Node x = ceiling(root, key);
    if (x == null) {
      return null;
    } else {
      return x.key;
    }
  }

  private Node ceiling(Node x, Key key) {
    if (x == null) {
      return null;
    }
    int cmp = key.compareTo(x.key);
    if (cmp == 0) {
      return x;
    }
    if (cmp > 0) {
      return ceiling(x.right, key);
    }
    Node y = ceiling(x.left, key);
    if (y != null) {
      return y;
    } else {
      return x;
    }
  }

  public Key select(int k) {
    if (k < 0 || k >= size()) {
      throw new IllegalArgumentException(
          "k is not in range 0-" + (size() - 1));
    }
    Node x = select(root, k);
    return x.key;
  }

  private Node select(Node x, int k) {
    if (x == null) {
      return null;
    }
    int t = size(x.left);
    if (t > k) {
      return select(x.left, k);
    } else if (t < k) {
      return select(x.right, k - t - 1);
    } else {
      return x;
    }
  }

  public int rank(Key key) {
    if (key == null) {
      throw new IllegalArgumentException("argument to rank() is null");
    }
    return rank(key, root);
  }

  private int rank(Key key, Node x) {
    if (x == null) {
      return 0;
    }
    int cmp = key.compareTo(x.key);
    if (cmp < 0) {
      return rank(key, x.left);
    } else if (cmp > 0) {
      return 1 + size(x.left) + rank(key, x.right);
    } else {
      return size(x.left);
    }
  }

  public Iterable<Key> keys() {
    return keysInOrder();
  }

  public Iterable<Key> keysInOrder() {
    Queue<Key> queue = new Queue<Key>();
    keysInOrder(root, queue);
    return queue;
  }

  private void keysInOrder(Node x, Queue<Key> queue) {
    if (x == null) {
      return;
    }
    keysInOrder(x.left, queue);
    queue.enqueue(x.key);
    keysInOrder(x.right, queue);
  }

  public Iterable<Key> keysLevelOrder() {
    Queue<Key> queue = new Queue<Key>();
    if (!isEmpty()) {
      Queue<Node> queue2 = new Queue<Node>();
      queue2.enqueue(root);
      while (!queue2.isEmpty()) {
        Node x = queue2.dequeue();
        queue.enqueue(x.key);
        if (x.left != null) {
          queue2.enqueue(x.left);
        }
        if (x.right != null) {
          queue2.enqueue(x.right);
        }
      }
    }
    return queue;
  }

  public Iterable<Key> keys(Key lo, Key hi) {
    if (lo == null) {
      throw new IllegalArgumentException(
          "first argument to keys() is null");
    }
    if (hi == null) {
      throw new IllegalArgumentException(
          "second argument to keys() is null");
    }
    Queue<Key> queue = new Queue<Key>();
    keys(root, queue, lo, hi);
    return queue;
  }

  private void keys(Node x, Queue<Key> queue, Key lo, Key hi) {
    if (x == null) {
      return;
    }
    int cmplo = lo.compareTo(x.key);
    int cmphi = hi.compareTo(x.key);
    if (cmplo < 0) {
      keys(x.left, queue, lo, hi);
    }
    if (cmplo <= 0 && cmphi >= 0) {
      queue.enqueue(x.key);
    }
    if (cmphi > 0) {
      keys(x.right, queue, lo, hi);
    }
  }

  public int size(Key lo, Key hi) {
    if (lo == null) {
      throw new IllegalArgumentException(
          "first argument to size() is null");
    }
    if (hi == null) {
      throw new IllegalArgumentException(
          "second argument to size() is null");
    }
    if (lo.compareTo(hi) > 0) {
      return 0;
    }
    if (contains(hi)) {
      return rank(hi) - rank(lo) + 1;
    } else {
      return rank(hi) - rank(lo);
    }
  }

  private boolean check() {
    if (!isBST()) {
      StdOut.println("Symmetric order not consistent");
    }
    if (!isAVL()) {
      StdOut.println("AVL property not consistent");
    }
    if (!isSizeConsistent()) {
      StdOut.println("Subtree counts not consistent");
    }
    if (!isRankConsistent()) {
      StdOut.println("Ranks not consistent");
    }
    return isBST() && isAVL() && isSizeConsistent() && isRankConsistent();
  }

  private boolean isAVL() {
    return isAVL(root);
  }

  private boolean isAVL(Node x) {
    if (x == null) {
      return true;
    }
    int bf = balanceFactor(x);
    if (bf > 1 || bf < -1) {
      return false;
    }
    return isAVL(x.left) && isAVL(x.right);
  }

  private boolean isBST() {
    return isBST(root, null, null);
  }

  private boolean isBST(Node x, Key min, Key max) {
    if (x == null) {
      return true;
    }
    if (min != null && x.key.compareTo(min) <= 0) {
      return false;
    }
    if (max != null && x.key.compareTo(max) >= 0) {
      return false;
    }
    return isBST(x.left, min, x.key) && isBST(x.right, x.key, max);
  }

  private boolean isSizeConsistent() {
    return isSizeConsistent(root);
  }

  private boolean isSizeConsistent(Node x) {
    if (x == null) {
      return true;
    }
    if (x.size != size(x.left) + size(x.right) + 1) {
      return false;
    }
    return isSizeConsistent(x.left) && isSizeConsistent(x.right);
  }

  private boolean isRankConsistent() {
    for (int i = 0; i < size(); i++) {
      if (i != rank(select(i))) {
        return false;
      }
    }
    for (Key key : keys()) {
      if (key.compareTo(select(rank(key))) != 0) {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    AVLTreeST<String, Integer> st = new AVLTreeST<String, Integer>();
    for (int i = 0; !StdIn.isEmpty(); i++) {
      String key = StdIn.readString();
      st.put(key, i);
    }
    for (String s : st.keys()) {
      StdOut.println(s + " " + st.get(s));
    }
    StdOut.println();
  }
}
