package edu.princeton.cs.algs4;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class FibonacciMinPQ<Key> implements Iterable<Key> {
  private Node head;
  private Node min;
  private int size;
  private final Comparator<Key> comp;
  private HashMap<Integer, Node> table = new HashMap<Integer, Node>();

  private class Node {
    Key key;
    int order;
    Node prev;
    Node next;
    Node child;
  }

  public FibonacciMinPQ(Comparator<Key> C) {
    comp = C;
  }

  public FibonacciMinPQ() {
    comp = new MyComparator();
  }

  public FibonacciMinPQ(Comparator<Key> C, Key[] a) {
    comp = C;
    for (Key k : a) {
      insert(k);
    }
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public int size() {
    return size;
  }

  public void insert(Key key) {
    Node x = new Node();
    x.key = key;
    size++;
    head = insert(x, head);
    if (min == null) {
      min = head;
    } else {
      min = (greater(min.key, key)) ? head : min;
    }
  }

  public Key minKey() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    return min.key;
  }

  public Key delMin() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    head = cut(min, head);
    Node x = min.child;
    Key key = min.key;
    min.key = null;
    if (x != null) {
      head = meld(head, x);
      min.child = null;
    }
    size--;
    if (!isEmpty()) {
      consolidate();
    } else {
      min = null;
    }
    return key;
  }

  public FibonacciMinPQ<Key> union(FibonacciMinPQ<Key> that) {
    this.head = meld(head, that.head);
    this.min = (greater(this.min.key, that.min.key)) ? that.min : this.min;
    this.size = this.size + that.size;
    return that;
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
    root2.child = insert(root1, root2.child);
    root2.order++;
  }

  private void consolidate() {
    table.clear();
    Node x = head;
    int maxOrder = 0;
    min = head;
    Node y = null;
    Node z = null;
    do {
      y = x;
      x = x.next;
      z = table.get(y.order);
      while (z != null) {
        table.remove(y.order);
        if (greater(y.key, z.key)) {
          link(y, z);
          y = z;
        } else {
          link(z, y);
        }
        z = table.get(y.order);
      }
      table.put(y.order, y);
      if (y.order > maxOrder) {
        maxOrder = y.order;
      }
    } while (x != head);
    head = null;
    for (Node n : table.values()) {
      if (n != null) {
        min = greater(min.key, n.key) ? n : min;
        head = insert(n, head);
      }
    }
  }

  private Node insert(Node x, Node head) {
    if (head == null) {
      x.prev = x;
      x.next = x;
    } else {
      head.prev.next = x;
      x.next = head;
      x.prev = head.prev;
      head.prev = x;
    }
    return x;
  }

  private Node cut(Node x, Node head) {
    if (x.next == x) {
      x.next = null;
      x.prev = null;
      return null;
    } else {
      x.next.prev = x.prev;
      x.prev.next = x.next;
      Node res = x.next;
      x.next = null;
      x.prev = null;
      if (head == x) {
        return res;
      } else {
        return head;
      }
    }
  }

  private Node meld(Node x, Node y) {
    if (x == null) {
      return y;
    }
    if (y == null) {
      return x;
    }
    x.prev.next = y.next;
    y.next.prev = x.prev;
    x.prev = x;
    y.next = x;
    return x;
  }

  public Iterator<Key> iterator() {
    return new MyIterator();
  }

  private class MyIterator implements Iterator<Key> {
    private FibonacciMinPQ<Key> copy;

    public MyIterator() {
      copy = new FibonacciMinPQ<Key>(comp);
      insertAll(head);
    }

    private void insertAll(Node head) {
      if (head == null) {
        return;
      }
      Node x = head;
      do {
        copy.insert(x.key);
        insertAll(x.child);
        x = x.next;
      } while (x != head);
    }

    public void remove() {
      throw new UnsupportedOperationException();
    }

    public boolean hasNext() {
      return !copy.isEmpty();
    }

    public Key next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      return copy.delMin();
    }
  }

  private class MyComparator implements Comparator<Key> {
    @Override
    public int compare(Key key1, Key key2) {
      return ((Comparable<Key>) key1).compareTo(key2);
    }
  }
}
