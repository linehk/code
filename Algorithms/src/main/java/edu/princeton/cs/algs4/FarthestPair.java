package edu.princeton.cs.algs4;

public class FarthestPair {
  private Point2D best1;
  private Point2D best2;
  private double bestDistanceSquared = Double.NEGATIVE_INFINITY;

  public FarthestPair(Point2D[] points) {
    if (points == null) {
      throw new IllegalArgumentException("constructor argument is null");
    }
    for (int i = 0; i < points.length; i++) {
      if (points[i] == null) {
        throw new IllegalArgumentException("array element " + i + " is null");
      }
    }

    GrahamScan graham = new GrahamScan(points);

    if (points.length <= 1) {
      return;
    }

    int m = 0;
    for (Point2D p : graham.hull()) {
      m++;
    }

    Point2D[] hull = new Point2D[m + 1];
    m = 1;
    for (Point2D p : graham.hull()) {
      hull[m++] = p;
    }
    m--;

    if (m == 1) {
      return;
    }

    if (m == 2) {
      best1 = hull[1];
      best2 = hull[2];
      bestDistanceSquared = best1.distanceSquaredTo(best2);
      return;
    }

    int k = 2;
    while (Point2D.area2(hull[m], hull[1], hull[k + 1])
        > Point2D.area2(hull[m], hull[1], hull[k])) {
      k++;
    }

    int j = k;
    for (int i = 1; i <= k && j <= m; i++) {
      if (hull[i].distanceSquaredTo(hull[j]) > bestDistanceSquared) {
        best1 = hull[i];
        best2 = hull[j];
        bestDistanceSquared = hull[i].distanceSquaredTo(hull[j]);
      }
      while ((j < m) && Point2D.area2(hull[i], hull[i + 1], hull[j + 1])
          > Point2D.area2(hull[i], hull[i + 1], hull[j])) {
        j++;
        double distanceSquared = hull[i].distanceSquaredTo(hull[j]);
        if (distanceSquared > bestDistanceSquared) {
          best1 = hull[i];
          best2 = hull[j];
          bestDistanceSquared = hull[i].distanceSquaredTo(hull[j]);
        }
      }
    }
  }

  public Point2D either() {
    return best1;
  }

  public Point2D other() {
    return best2;
  }

  public double distance() {
    return Math.sqrt(bestDistanceSquared);
  }

  public static void main(String[] args) {
    int n = StdIn.readInt();
    Point2D[] points = new Point2D[n];
    for (int i = 0; i < n; i++) {
      int x = StdIn.readInt();
      int y = StdIn.readInt();
      points[i] = new Point2D(x, y);
    }
    FarthestPair farthest = new FarthestPair(points);
    StdOut.println(farthest.distance() + " from "
        + farthest.either() + " to " + farthest.other());
  }
}
