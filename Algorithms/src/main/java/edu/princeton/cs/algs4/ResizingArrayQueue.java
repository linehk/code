package edu.princeton.cs.algs4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ResizingArrayQueue<Item> implements Iterable<Item> {
  private Item[] q;
  private int n;
  private int first;
  private int last;

  public ResizingArrayQueue() {
    q = (Item[]) new Object[2];
    n = 0;
    first = 0;
    last = 0;
  }

  public boolean isEmpty() {
    return n == 0;
  }

  public int size() {
    return n;
  }

  private void resize(int capacity) {
    assert capacity >= n;
    Item[] temp = (Item[]) new Object[capacity];
    for (int i = 0; i < n; i++) {
      temp[i] = q[(first + i) % q.length];
    }
    q = temp;
    first = 0;
    last = n;
  }

  public void enqueue(Item item) {
    if (n == q.length) {
      resize(2 * q.length);
    }
    q[last++] = item;
    if (last == q.length) {
      last = 0;
    }
    n++;
  }

  public Item dequeue() {
    if (isEmpty()) {
      throw new NoSuchElementException("Queue underflow");
    }
    Item item = q[first];
    q[first] = null;
    n--;
    first++;
    if (first == q.length) {
      first = 0;
    }
    if (n > 0 && n == q.length / 4) {
      resize(q.length / 2);
    }
    return item;
  }

  public Item peek() {
    if (isEmpty()) {
      throw new NoSuchElementException("Queue underflow");
    }
    return q[first];
  }

  public Iterator<Item> iterator() {
    return new ArrayIterator();
  }

  private class ArrayIterator implements Iterator<Item> {
    private int i = 0;

    public boolean hasNext() {
      return i < n;
    }

    public void remove() {
      throw new UnsupportedOperationException();
    }

    public Item next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      Item item = q[(i + first) % q.length];
      i++;
      return item;
    }
  }

  public static void main(String[] args) {
    ResizingArrayQueue<String> queue = new ResizingArrayQueue<String>();
    while (!StdIn.isEmpty()) {
      String item = StdIn.readString();
      if (!item.equals("-")) {
        queue.enqueue(item);
      } else if (!queue.isEmpty()) {
        StdOut.print(queue.dequeue() + " ");
      }
    }
    StdOut.println("(" + queue.size() + " left on queue");
  }
}