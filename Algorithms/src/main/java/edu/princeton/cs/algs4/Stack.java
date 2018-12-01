package edu.princeton.cs.algs4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<Item> implements Iterable<Item> {
  private Node<Item> first;
  private int n;

  private static class Node<Item> {
    private Item item;
    private Node<Item> next;
  }

  public Stack() {
    first = null;
    n = 0;
  }

  public boolean isEmpty() {
    return first == null;
  }

  public int size() {
    return n;
  }

  public void push(Item item) {
    Node<Item> oldfirst = first;
    first = new Node<Item>();
    first.item = item;
    first.next = oldfirst;
    n++;
  }

  public Item pop() {
    if (isEmpty()) {
      throw new NoSuchElementException("Stack underflow");
    }
    Item item = first.item;
    first = first.next;
    n--;
    return item;
  }

  public Item peek() {
    if (isEmpty()) {
      throw new NoSuchElementException("Stack underflow");
    }
    return first.item;
  }

  public String toString() {
    StringBuilder s = new StringBuilder();
    for (Item item : this) {
      s.append(item);
      s.append(' ');
    }
    return s.toString();
  }

  public Iterator<Item> iterator() {
    return new ListIterator<Item>(first);
  }

  private class ListIterator<Item> implements Iterator<Item> {
    private Node<Item> current;

    public ListIterator(Node<Item> first) {
      current = first;
    }

    public boolean hasNext() {
      return current != null;
    }

    public void remove() {
      throw new UnsupportedOperationException();
    }

    public Item next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      Item item = current.item;
      current = current.next;
      return item;
    }
  }
}