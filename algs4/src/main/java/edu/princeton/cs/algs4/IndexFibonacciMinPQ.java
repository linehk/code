package edu.princeton.cs.algs4;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class IndexFibonacciMinPQ<Key> implements Iterable<Integer> {
	private Node<Key>[] nodes;
	private Node<Key> head;
	private Node<Key> min;
	private int size;
	private int n;
	private final Comparator<Key> comp;
	private HashMap<Integer, Node<Key>> table = new HashMap<Integer, Node<Key>>();
	
	private class Node<Key> {
		Key key;
		int order;
		int index;
		Node<Key> prev;
		Node<Key> next;
		Node<Key> parent;
		Node<Key> child;
		boolean mark;
	}
	
	public IndexFibonacciMinPQ(int N) {
		if (N < 0) {
		  throw new IllegalArgumentException(
		      "Cannot create a priority queue of negative size");
    }
		n = N;
		nodes = (Node<Key>[]) new Node[n];
		comp = new MyComparator();
	}

	public IndexFibonacciMinPQ(Comparator<Key> C, int N) {
		if (N < 0) {
		  throw new IllegalArgumentException(
		      "Cannot create a priority queue of negative size");
    }
		n = N;
		nodes = (Node<Key>[]) new Node[n];
		comp = C;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public boolean contains(int i) {
		if (i < 0 || i >= n) {
		  throw new IllegalArgumentException();
    } else {
		  return nodes[i] != null;
    }
	}

	public int size() {
		return size;
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
		nodes[i] = x;
		size++;
		head = insert(x, head);
		if (min == null) {
		  min = head;
    } else {
		  min = (greater(min.key, key)) ? head : min;
    }
	}

	public int minIndex() {
		if (isEmpty()) {
		  throw new NoSuchElementException("Priority queue is empty");
    }
		return min.index;
	}

	public Key minKey() {
		if (isEmpty()) {
		  throw new NoSuchElementException("Priority queue is empty");
    }
		return min.key;
	}

	public int delMin() {
		if (isEmpty()) {
		  throw new NoSuchElementException("Priority queue is empty");
    }
		head = cut(min, head);
		Node<Key> x = min.child;
		int index = min.index;
		min.key = null;
		if (x != null) {
			do {
				x.parent = null;
				x = x.next;
			} while (x != min.child);
			head = meld(head, x);
			min.child = null;
		}
		size--;
		if (!isEmpty()) {
		  consolidate();
    } else {
		  min = null;
    }
		nodes[index] = null;
		return index;
	}

	public Key keyOf(int i) {
		if (i < 0 || i >= n) {
		  throw new IllegalArgumentException();
    }
		if (!contains(i)) {
		  throw new NoSuchElementException(
		      "Specified index is not in the queue");
    }
		return nodes[i].key;
	}

	public void changeKey(int i, Key key) {
		if (i < 0 || i >= n) {
		  throw new IllegalArgumentException();
    }
		if (!contains(i)) {
		  throw new NoSuchElementException(
		      "Specified index is not in the queue");
    }
		if (greater(key, nodes[i].key)) {
		  increaseKey(i, key);
    } else {
		  decreaseKey(i, key);
    }
	}

	public void decreaseKey(int i, Key key) {
		if (i < 0 || i >= n) {
		  throw new IllegalArgumentException();
    }
		if (!contains(i)) {
		  throw new NoSuchElementException(
		      "Specified index is not in the queue");
    }
		if (greater(key, nodes[i].key)) {
		  throw new IllegalArgumentException(
		      "Calling with this argument would not decrease the key");
    }
		Node<Key> x = nodes[i];
		x.key = key;
		if (greater(min.key, key)) {
		  min = x;
    }
		if (x.parent != null && greater(x.parent.key, key)) {
			cut(i);
		}
	}

	public void increaseKey(int i, Key key) {
		if (i < 0 || i >= n) {
		  throw new IllegalArgumentException();
    }
		if (!contains(i)) {
		  throw new NoSuchElementException(
		      "Specified index is not in the queue");
    }
		if (greater(nodes[i].key, key)) {
		  throw new IllegalArgumentException(
		      "Calling with this argument would not increase the key");
    }
		delete(i);
		insert(i, key);
	}

	public void delete(int i) {
		if (i < 0 || i >= n) {
		  throw new IllegalArgumentException();
    }
		if (!contains(i)) {
		  throw new NoSuchElementException(
		      "Specified index is not in the queue");
    }
		Node<Key> x = nodes[i];
		x.key = null;
		if (x.parent != null) {
			cut(i);
		}
		head = cut(x, head);
		if (x.child != null) {
			Node<Key> child = x.child;
			x.child = null;
			x = child;
			do {
				child.parent = null;
				child = child.next;
			} while (child != x);
			head = meld(head, child);
		}
		if (!isEmpty()) {
		  consolidate();
    } else {
		  min = null;
    }
		nodes[i] = null;
		size--;
	}
	
	private boolean greater(Key n, Key m) {
		if (n == null) {
		  return false;
    }
		if (m == null) {
		  return true;
    }
		return comp.compare(n,  m) > 0;
	}
	
	private void link(Node<Key> root1, Node<Key> root2) {
		root1.parent = root2;
		root2.child = insert(root1, root2.child);
		root2.order++;
	}
	
	private void cut(int i) {
		Node<Key> x = nodes[i];
		Node<Key> parent = x.parent;
		parent.child = cut(x, parent.child);
		x.parent = null;
		parent.order--;
		head = insert(x, head);
		parent.mark = !parent.mark;
		if (!parent.mark && parent.parent != null) {
			cut(parent.index);
		}
	}
	
	private void consolidate() {
		table.clear();
		Node<Key> x = head;
		int maxOrder = 0;
		min = head;
		Node<Key> y = null, z = null;
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
		for (Node<Key> n : table.values()) {
			min = greater(min.key, n.key) ? n : min;
			head = insert(n, head);
		}
	}
	
	private Node<Key> insert(Node<Key> x, Node<Key> head) {
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
	
	private Node<Key> cut(Node<Key> x, Node<Key> head) {
		if (x.next == x) {
			x.next = null;
			x.prev = null;
			return null;
		} else {
			x.next.prev = x.prev;
			x.prev.next = x.next;
			Node<Key> res = x.next;
			x.next = null;
			x.prev = null;
			if (head == x) {
			  return res;
      } else {
			  return head;
      }
		}
	}
	
	private Node<Key> meld(Node<Key> x, Node<Key> y) {
		if (x == null) {
		  return y;
    }
		if (y == null) {
		  return x;
    }
		x.prev.next = y.next;
		y.next.prev = x.prev;
		x.prev = y;
		y.next = x;
		return x;
	}
	
	public Iterator<Integer> iterator() {
		return new MyIterator();
	}
	
	private class MyIterator implements Iterator<Integer> {
		private IndexFibonacciMinPQ<Key> copy;
		
		public MyIterator() {
			copy = new IndexFibonacciMinPQ<Key>(comp, n);
			for (Node<Key> x : nodes) {
				if (x != null) {
				  copy.insert(x.index, x.key);
        }
			}
		}
		
		public void remove() {
			throw new UnsupportedOperationException();
		}
		
		public boolean hasNext() {
			return !copy.isEmpty();
		}
		
		public Integer next() {
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

