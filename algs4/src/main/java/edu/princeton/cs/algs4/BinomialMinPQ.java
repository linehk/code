package edu.princeton.cs.algs4;

import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class BinomialMinPQ<Key> implements Iterable<Key> {
  private Node head;
  private final Comparator<Key> comp;

  private class Node {
    Key key;
    int order;
    Node child;
    Node sibling;
  }

  public BinomialMinPQ() {
    comp = new MyComparator();
  }

  public BinomialMinPQ(Comparator<Key> C) {
    comp = C;
  }

  public BinomialMinPQ(Key[] a) {
    comp = new MyComparator();
    for (Key k : a) {
      insert(k);
    }
  }

  public BinomialMinPQ(Comparator<Key> C, Key[] a) {
    comp = C;
    for (Key k : a) {
      insert(k);
    }
  }

  public boolean isEmpty() {
    return head == null;
  }

  public int size() {
    int result = 0;
    int tmp;
    for (Node node = head; node != null; node = node.sibling) {
      if (node.order > 30) {
        throw new ArithmeticException(
            "The number of elements cannot be evaluated, but the priority queue is still valid.");
      }
      tmp = 1 << node.order;
      result |= tmp;
    }
    return result;
  }

  public void insert(Key key) {
    Node x = new Node();
    x.key = key;
    x.order = 0;
    BinomialMinPQ<Key> H = new BinomialMinPQ<Key>();
    H.head = x;
    this.head = this.union(H).head;
  }

  public Key minKey() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    Node min = head;
    Node current = head;
    while (current.sibling != null) {
      min = (greater(min.key, current.sibling.key)) ? current : min;
      current = current.sibling;
    }
    return min.key;
  }

  public Key delMin() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    Node min = eraseMin();
    Node x = (min.child == null) ? min : min.child;
    if (min.child != null) {
      min.child = null;
      Node prevx = null;
      Node nextx = x.sibling;
      while (nextx != null) {
        x.sibling = prevx;
        prevx = x;
        x = nextx;
        nextx = nextx.sibling;
      }
      x.sibling = prevx;
      BinomialMinPQ<Key> H = new BinomialMinPQ<Key>();
      H.head = x;
      head = union(H).head;
    }
    return min.key;
  }

  public BinomialMinPQ<Key> union(BinomialMinPQ<Key> heap) {
    if (heap == null) {
      throw new IllegalArgumentException(
          "Cannot merge a Binomial Heap with null");
    }
    this.head = merge(new Node(), this.head, heap.head).sibling;
    Node x = this.head;
    Node prevx = null;
    Node nextx = x.sibling;
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

  private boolean greater(Key n, Key m) {
    if (n == null) {
      return false;
    }
    if (m == null) {
      return true;
    }
    return comp.compare(n, m) > 0;
  }

  private void link(Node root1, Node root2) {
    root1.sibling = root2.child;
    root2.child = root1;
    root2.order++;
  }

  private Node eraseMin() {
    Node min = head;
    Node previous = null;
    Node current = head;
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
    return min;
  }

  private Node merge(Node h, Node x, Node y) {
    if (x == null && y == null) {
      return h;
    } else if (x == null) {
      h.sibling = merge(x, null, y.sibling);
    } else if (y == null) {
      h.sibling = merge(x, x.sibling, null);
    } else if (x.order < y.order) {
      h.sibling = merge(x, x.sibling, y);
    } else {
      h.sibling = merge(y, x, y.sibling);
    }
    return h;
  }

  public Iterator<Key> iterator() {
    return new MyIterator();
  }

  private class MyIterator implements Iterator<Key> {
    BinomialMinPQ<Key> data;

    public MyIterator() {
      data = new BinomialMinPQ<Key>(comp);
      data.head = clone(head, null);
    }

    private Node clone(Node x, Node parent) {
      if (x == null) {
        return null;
      }
      Node node = new Node();
      node.key = x.key;
      node.sibling = clone(x.sibling, parent);
      node.child = clone(x.child, node);
      return node;
    }

    public boolean hasNext() {
      return !data.isEmpty();
    }

    public Key next() {
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
