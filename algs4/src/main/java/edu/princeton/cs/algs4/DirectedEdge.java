package edu.princeton.cs.algs4;

public class DirectedEdge {
  private final int v;
  private final int w;
  private final double weight;

  public DirectedEdge(int v, int w, double weight) {
    if (v < 0) {
      throw new IllegalArgumentException("Vertex names must be nonnegative integers");
    }
    if (w < 0) {
      throw new IllegalArgumentException("Vertex names must be nonnegative integers");
    }
    if (Double.isNaN(weight)) {
      throw new IllegalArgumentException("Weight is NaN");
    }
    this.v = v;
    this.w = w;
    this.weight = weight;
  }

  public int from() {
    return v;
  }

  public int to() {
    return w;
  }

  public double weight() {
    return weight;
  }

  public String toString() {
    return v + "->" + w + " " + String.format("%5.2f", weight);
  }

  public static void main(String[] args) {
    DirectedEdge e = new DirectedEdge(12, 34, 5.67);
    StdOut.println(e);
  }
}
