package edu.princeton.cs.algs4;

public class Interval2D {
  private final Interval1D x;
  private final Interval1D y;

  public Interval2D(Interval1D x, Interval1D y) {
    this.x = x;
    this.y = y;
  }

  public boolean intersects(Interval2D that) {
    if (!this.x.intersects(that.x)) {
      return false;
    }
    if (!this.y.intersects(that.y)) {
      return false;
    }
    return true;
  }

  public boolean contains(Point2D p) {
    return x.contains(p.x()) && y.contains(p.y());
  }

  public double area() {
    return x.length() * y.length();
  }

  public String tosString() {
    return x + " x " + y;
  }

  public boolean equals(Object other) {
    if (other == this) {
      return true;
    }
    if (other == null) {
      return false;
    }
    if (other.getClass() != this.getClass()) {
      return false;
    }
    Interval2D that = (Interval2D)other;
    return this.x.equals(that.x) && this.y.equals(that.y);
  }

  public int hashCode() {
    int hash1 = x.hashCode();
    int hash2 = y.hashCode();
    return 31 * hash1 + hash2;
  }

  public void draw() {
    double xc = (x.min() + x.max()) / 2.0;
    double yc = (y.min() + y.max()) / 2.0;
    StdDraw.rectangle(xc, yc, x.length() / 2.0, y.length() / 2.0);
  }

  public static void main(String[] args) {
    double xmin = Double.parseDouble(args[0]);
    double xmax = Double.parseDouble(args[1]);
    double ymin = Double.parseDouble(args[2]);
    double ymax = Double.parseDouble(args[3]);
    int trials = Integer.parseInt(args[4]);

    Interval1D xInterval = new Interval1D(xmin, xmax);
    Interval1D yInterval = new Interval1D(ymin, ymax);
    Interval2D box = new Interval2D(xInterval, yInterval);
    box.draw();

    Counter counter = new Counter("hits");
    for (int t = 0; t < trials; t++) {
      double x = StdRandom.uniform(0.0, 1.0);
      double y = StdRandom.uniform(0.0, 1.0);
      Point2D point = new Point2D(x, y);

      if (box.contains(point)) {
        counter.increment();
      } else {
        point.draw();
      }
    }

    StdOut.println(counter);
    StdOut.printf("box area = %.2f\n", box.area());
  }
}