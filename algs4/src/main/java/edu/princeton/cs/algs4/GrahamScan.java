package edu.princeton.cs.algs4;

import java.util.Arrays;

public class GrahamScan {
  private Stack<Point2D> hull = new Stack<Point2D>();

  public GrahamScan(Point2D[] points) {
    if (points == null) {
      throw new IllegalArgumentException("argument is null");
    }
    if (points.length == 0) {
      throw new IllegalArgumentException("array is of length 0");
    }

    int n = points.length;
    Point2D[] a = new Point2D[n];
    for (int i = 0; i < n; i++) {
      if (points[i] == null) {
        throw new IllegalArgumentException("points[" + i + "] is null");
      }
      a[i] = points[i];
    }

    Arrays.sort(a);

    Arrays.sort(a, 1, n, a[0].polarOrder());

    hull.push(a[0]);

    int k1;
    for (k1 = 0; k1 < n; k1++) {
      if (!a[0].equals(a[k1])) {
        break;
      }
    }
    if (k1 == n) {
      return;
    }

    int k2;
    for (k2 = k1 + 1; k2 < n; k2++) {
      if (Point2D.ccw(a[0], a[k1], a[k2]) != 0) {
        break;
      }
    }
    hull.push(a[k2 - 1]);

    for (int i = k2; i < n; i++) {
      Point2D top = hull.pop();
      while (Point2D.ccw(hull.peek(), top, a[i]) <= 0) {
        top = hull.pop();
      }
      hull.push(top);
      hull.push(a[i]);
    }
    assert isConvex();
  }

  public Iterable<Point2D> hull() {
    Stack<Point2D> s = new Stack<Point2D>();
    for (Point2D p : hull) {
      s.push(p);
    }
    return s;
  }

  private boolean isConvex() {
    int n = hull.size();
    if (n <= 2) {
      return true;
    }

    Point2D[] points = new Point2D[n];
    int k = 0;
    for (Point2D p : hull()) {
      points[k++] = p;
    }

    for (int i = 0; i < n; i++) {
      if (Point2D.ccw(
          points[i], points[(i + 1) % n], points[(i + 2) % n]) <= 0) {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    int n = StdIn.readInt();
    Point2D[] points = new Point2D[n];
    for (int i = 0; i < n; i++) {
      int x = StdIn.readInt();
      int y = StdIn.readInt();
      points[i] = new Point2D(x, y);
    }
    GrahamScan graham = new GrahamScan(points);
    for (Point2D p : graham.hull()) {
      StdOut.println(p);
    }
  }
}
