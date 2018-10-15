package edu.princeton.cs.algs4;

import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class IndexBinomialMinPQ<Key> implements Iterable<Integer> {
  private Node<Key> head;
  private Node<Key>[] nodes;
  private int n;
  private final Comparator<Key> comparator;

  private class Node<Key> {
    Key key;
    int order;
    int index;
    Node<Key> parent;
    Node<Key> child;
    Node<Key> sibling;
  }

  public IndexBinomialMinPQ(int N) {
    if (N < 0) {
      throw new IllegalArgumentException(
          "Cannot create a priority queue of negative size");
    }
    comparator = new MyComparator();
    nodes = (Node<Key>[]) new Node[N];
    this.n = N;
  }

  public IndexBinomialMinPQ(int N, Comparator<Key> comparator) {
    if (N < 0) {
      throw new IllegalArgumentException(
          "Cannot create a priority queue of negative size");
    }
    this.comparator = comparator;
    nodes = (Node<Key>[]) new Node[N];
    this.n = N;
  }

  public boolean isEmpty() {
    return head == null;
  }

  public boolean contains(int i) {
    if (i < 0 || i > n) {
      throw new IllegalArgumentException();
    } else {
      return nodes[i] != null;
    }
  }

  public int size() {
    int result = 0;
    int tmp;
    for (Node<Key> node = head; node != null; node = node.sibling) {
      if (node.order > 30) {
        throw new ArithmeticException(
            "The number of elements cannot be evaluated, but the priority queue is still valid.");
      }
      tmp = 1 << node.order;
      result |= tmp;
    }
    return result;
  }

  public void insert(int i, Key key) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException();
    }
    if (contains(i)) {
      throw new IllegalArgumentException(
          "Specified index is already in the queue");
    }
    Node<Key> x = new Node<Key>();
    x.key = key;
    x.index = i;
    x.order = 0;
    nodes[i] = x;
    IndexBinomialMinPQ<Key> H = new IndexBinomialMinPQ<Key>();
    H.head = x;
    head = union(H).head;
  }

  public int minIndex() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    Node<Key> min = head;
    Node<Key> current = head;
    while (current.sibling != null) {
      min = (greater(min.key, current.sibling.key)) ? current.sibling : min;
      current = current.sibling;
    }
    return min.index;
  }

  public Key minKey() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    Node<Key> min = head;
    Node<Key> current = head;
    while (current.sibling != null) {
      min = (greater(min.key, current.sibling.key)) ? current.sibling : min;
      current = current.sibling;
    }
    return min.key;
  }

  public int delMin() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    Node<Key> min = eraseMin();
    Node<Key> x = (min.child == null) ? min : min.child;
    if (min.child != null) {
      min.child = null;
      Node<Key> prevx = null;
      Node<Key> nextx = x.sibling;
      while (nextx != null) {
        x.parent = null;
        x.sibling = prevx;
        prevx = x;
        x = nextx;
        nextx = nextx.sibling;
      }
      x.parent = null;
      x.sibling = prevx;
      IndexBinomialMinPQ<Key> H = new IndexBinomialMinPQ<Key>();
      H.head = x;
      head = union(H).head;
    }
    return min.index;
  }

  public Key keyOf(int i) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new IllegalArgumentException(
          "Specified index is not in the queue");
    }
    return nodes[i].key;
  }

  public void changeKey(int i, Key key) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new IllegalArgumentException("Specified index is not in the queue");
    }
    if (greater(nodes[i].key, key)) {
      decreaseKey(i, key);
    } else {
      increaseKey(i, key);
    }
  }

  public void decreaseKey(int i, Key key) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    if (greater(key, nodes[i].key)) {
      throw new IllegalArgumentException(
          "Calling with this argument would not decrease the key");
    }
    Node<Key> x = nodes[i];
    x.key = key;
    swim(i);
  }

  public void increaseKey(int i, Key key) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    if (greater(nodes[i].key, key)) {
      throw new IllegalArgumentException(
          "Calling with this argument would not increase the key");
    }
    delete(i);
    insert(i, key);
  }

  /**
   * Deletes the key associated the given index
   * Worst case is O(log(n))
   * @param i an index
   * @throws java.lang.IllegalArgumentException if the specified index is invalid
   * @throws java.util.NoSuchElementException if the given index has no key associated with
   */

  public void delete(int i) {
    if (i < 0 || i >= n) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    toTheRoot(i);
    Node<Key> x = erase(i);
    if (x.child != null) {
      Node<Key> y = x;
      x = x.child;
      y.child = null;
      Node<Key> prevx = null;
      Node<Key> nextx = x.sibling;
      while (nextx != null) {
        x.parent = null;
        x.sibling = prevx;
        prevx = x;
        x = nextx;
        nextx = nextx.sibling;
      }
      x.parent = null;
      x.sibling = prevx;
      IndexBinomialMinPQ<Key> H = new IndexBinomialMinPQ<Key>();
      H.head = x;
      head = union(H).head;
    }
  }

  private boolean greater(Key n, Key m) {
    if (n == null) {
      return false;
    }
    if (m == null) {
      return true;
    }
    return comparator.compare(n, m) > 0;
  }

  private void exchange(Node<Key> x, Node<Key> y) {
    Key tempKey = x.key;
    x.key = y.key;
    y.key = tempKey;
    int tempInt = x.index;
    x.index = y.index;
    y.index = tempInt;
    nodes[x.index] = x;
    nodes[y.index] = y;
  }

  private void link(Node<Key> root1, Node<Key> root2) {
    root1.sibling = root2.child;
    root1.parent = root2;
    root2.child = root1;
    root2.order++;
  }

  private void swim(int i) {
    Node<Key> x = nodes[i];
    Node<Key> parent = x.parent;
    if (parent != null && greater(parent.key, x.key)) {
      exchange(x, parent);
      swim(i);
    }
  }

  private void toTheRoot(int i) {
    Node<Key> x = nodes[i];
    Node<Key> parent = x.parent;
    if (parent != null) {
      exchange(x, parent);
      toTheRoot(i);
    }
  }

  private Node<Key> erase(int i) {
    Node<Key> reference = nodes[i];
    Node<Key> x = head;
    Node<Key> previous = null;
    while (x != reference) {
      previous = x;
      x = x.sibling;
    }
    previous.sibling = x.sibling;
    if (x == head) {
      head = head.sibling;
    }
    nodes[i] = null;
    return x;
  }

  private Node<Key> eraseMin() {
    Node<Key> min = head;
    Node<Key> previous = null;
    Node<Key> current = head;
    while (current.sibling != null) {
      if (greater(min.key, current.sibling.key)) {
        previous = current;
        min = current.sibling;
      }
      current = current.sibling;
    }
    previous.sibling = min.sibling;
    if (min == head) {
      head = min.sibling;
    }
    nodes[min.index] = null;
    return min;
  }

  private Node<Key> merge(Node<Key> h, Node<Key> x, Node<Key> y) {
    if (x == null && y == null) {
      return h;
    } else if (x == null) {
      h.sibling = merge(y, null, y.sibling);
    } else if (y == null) {
      h.sibling = merge(x, x.sibling, null);
    } else if (x.order < y.order) {
      h.sibling = merge(x, x.sibling, y);
    } else {
      h.sibling = merge(y, x, y.sibling);
    }
    return h;
  }

  private IndexBinomialMinPQ<Key> union(IndexBinomialMinPQ<Key> heap) {
    this.head = merge(new Node<Key>(), this.head, heap.head).sibling;
    Node<Key> x = this.head;
    Node<Key> prevx = null;
    Node<Key> nextx = x.sibling;
    while (nextx != null) {
      if (x.order < nextx.order
          || (nextx.sibling != null && nextx.sibling.order == x.order)) {
        prevx = x;
        x = nextx;
      } else if (greater(nextx.key, x.key)) {
        x.sibling = nextx.sibling;
        link(nextx, x);
      } else {
        if (prevx == null) {
          this.head = nextx;
        } else {
          prevx.sibling = nextx;
        }
        link(x, nextx);
        x = nextx;
      }
      nextx = x.sibling;
    }
    return this;
  }

  private IndexBinomialMinPQ() {
    comparator = null;
  }

  public Iterator<Integer> iterator() {
    return new MyIterator();
  }

  private class MyIterator implements Iterator<Integer> {
    IndexBinomialMinPQ<Key> data;

    public MyIterator() {
      data = new IndexBinomialMinPQ<Key>(n, comparator);
      data.head = clone(head, null);
    }

    private Node<Key> clone(Node<Key> x, Node<Key> parent) {
      if (x == null) {
        return null;
      }
      Node<Key> node = new Node<Key>();
      node.index = x.index;
      node.key = x.key;
      data.nodes[node.index] = node;
      node.parent = parent;
      node.sibling = clone(x.sibling, parent);
      node.child = clone(x.child, node);
      return node;
    }

    public boolean hasNext() {
      return !data.isEmpty();
    }

    public Integer next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      return data.delMin();
    }

    public void remove() {
      throw new UnsupportedOperationException();
    }
  }

  private class MyComparator implements Comparator<Key> {
    @Override
    public int compare(Key key1, Key key2) {
      return ((Comparable<Key>) key1).compareTo(key2);
    }
  }
}
