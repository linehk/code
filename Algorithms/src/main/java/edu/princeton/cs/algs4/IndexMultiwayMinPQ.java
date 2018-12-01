package edu.princeton.cs.algs4;

import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class IndexMultiwayMinPQ<Key> implements Iterable<Integer> {
  private final int d;
  private int n;
  private int nmax;
  private int[] pq;
  private int[] qp;
  private Key[] keys;
  private final Comparator<Key> comp;

  public IndexMultiwayMinPQ(int N, int D) {
    if (N < 0) {
      throw new IllegalArgumentException(
          "Maximum number of elements cannot be negative");
    }
    if (D < 2) {
      throw new IllegalArgumentException("Dimension should be 2 or over");
    }
    this.d = D;
    pq = new int[nmax + D];
    qp = new int[nmax + D];
    keys = (Key[]) new Comparable[nmax + D];
    for (int i = 0; i < nmax + D; qp[i++] = -1) {}
    comp = new MyComparator();
  }

  public IndexMultiwayMinPQ(int N, Comparator<Key> C, int D) {
    if (N < 0) {
      throw new IllegalArgumentException(
          "Maximum number of elements cannot be negative");
    }
    if (D < 2) {
      throw new IllegalArgumentException("Dimension should be 2 or over");
    }
    this.d = D;
    nmax = N;
    pq = new int[nmax + D];
    qp = new int[nmax + D];
    keys = (Key[]) new Comparable[nmax + D];
    for (int i = 0; i < nmax + D; qp[i++] = -1) {}
    comp = C;
  }

  public boolean isEmpty() {
    return n == 0;
  }

  public boolean contains(int i) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    return qp[i + d] != -1;
  }

  public int size() {
    return n;
  }

  public void insert(int i, Key key) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    if (contains(i)) {
      throw new IllegalArgumentException("Index already there");
    }
    keys[i + d] = key;
    pq[n + d] = i;
    qp[i + d] = n;
    swim(n++);
  }

  public int minIndex() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    return pq[d];
  }

  public Key minKey() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    return keys[pq[d] + d];
  }

  public int delMin() {
    if (isEmpty()) {
      throw new NoSuchElementException("Priority queue is empty");
    }
    int min = pq[d];
    exch(0, --n);
    sink(0);
    qp[min + d] = -1;
    keys[pq[n + d] + d] = null;
    pq[n + d] = -1;
    return min;
  }

  public Key keyOf(int i) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    return keys[i + d];
  }

  public void changeKey(int i, Key key) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    Key tmp = keys[i + d];
    keys[i + d] = key;
    if (comp.compare(key, tmp) <= 0) {
      swim(qp[i + d]);
    } else {
      sink(qp[i + d]);
    }
  }

  public void decreaseKey(int i, Key key) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    if (comp.compare(keys[i + d], key) <= 0) {
      throw new IllegalArgumentException(
          "Calling with this argument would not decrease the Key");
    }
    keys[i + d] = key;
    swim(qp[i + d]);
  }

  public void increaseKey(int i, Key key) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    if (comp.compare(keys[i + d], key) >= 0) {
      throw new IllegalArgumentException(
          "Calling with this argument would not increase the Key");
    }
    keys[i + d] = key;
    sink(qp[i + d]);
  }

  public void delete(int i) {
    if (i < 0 || i >= nmax) {
      throw new IllegalArgumentException();
    }
    if (!contains(i)) {
      throw new NoSuchElementException("Specified index is not in the queue");
    }
    int idx = qp[i + d];
    exch(idx, --n);
    swim(idx);
    sink(idx);
    keys[i + d] = null;
    qp[i + d] = -1;
  }

  private boolean greater(int i, int j) {
    return comp.compare(keys[pq[i + d] + d], keys[pq[j + d] + d]) > 0;
  }

  private void exch(int x, int y) {
    int i = x + d;
    int j = y + d;
    int swap = pq[i];
    pq[i] = pq[j];
    pq[j] = swap;
    qp[pq[i] + d] = x;
    qp[pq[j] + d] = y;
  }

  private void swim(int i) {
    if (i > 0 && greater((i - 1) / d, i)) {
      exch(i, (i - 1) / d);
      swim((i - 1) / d);
    }
  }

  private void sink(int i) {
    if (d * i + 1 >= n) {
      return;
    }
    int min = minChild(i);
    while (min < n && greater(i, min)) {
      exch(i, min);
      i = min;
      min = minChild(i);
    }
  }

  private int minChild(int i) {
    int loBound = d * i + 1;
    int hiBound = d * i + d;
    int min = loBound;
    for (int cur = loBound; cur <= hiBound; cur++) {
      if (cur < n && greater(min, cur)) {
        min = cur;
      }
    }
    return min;
  }

  public Iterator<Integer> iterator() {
    return new MyIterator();
  }

  private class MyIterator implements Iterator<Integer> {
    IndexMultiwayMinPQ<Key> clone;

    public MyIterator() {
      clone = new IndexMultiwayMinPQ<Key>(nmax, comp, d);
      for (int i = 0; i < n; i++) {
        clone.insert(pq[i + d], keys[pq[i + d] + d]);
      }
    }

    public boolean hasNext() {
      return !clone.isEmpty();
    }

    public Integer next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      return clone.delMin();
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
