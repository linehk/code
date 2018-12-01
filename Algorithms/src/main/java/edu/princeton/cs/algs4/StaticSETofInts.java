package edu.princeton.cs.algs4;

import java.util.Arrays;

public class StaticSETofInts {
  private int[] a;

  public StaticSETofInts(int[] keys) {
    a = new int[keys.length];
    for (int i = 0; i < keys.length; i++) {
      a[i] = keys[i];
    }

    Arrays.sort(a);

    for (int i = 1; i < a.length; i++) {
      if (a[i] == a[i - 1]) {
        throw new IllegalArgumentException(
            "Argument arrays contains duplicate keys.");
      }
    }
  }

  public boolean contains(int key) {
    return rank(key) != -1;
  }

  public int rank(int key) {
    int lo = 0;
    int hi = a.length - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (key < a[mid]) {
        hi = mid - 1;
      } else if (key > a[mid]) {
        lo = mid + 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
}