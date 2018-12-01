package edu.princeton.cs.algs4;

public class Complex {
  private final double re;
  private final double im;

  public Complex(double real, double imag) {
    re = real;
    im = imag;
  }

  public String toString() {
    if (im == 0) {
      return re + "";
    }
    if (re == 0) {
      return im + "i";
    }
    if (im < 0) {
      return re + " - " + (-im) + "i";
    }
    return re + " + " + im + "i";
  }

  public double abs() {
    return Math.hypot(re, im);
  }

  public double phase() {
    return Math.atan2(im, re);
  }

  public Complex plus(Complex that) {
    double real = this.re + that.re;
    double imag = this.im + that.im;
    return new Complex(real, imag);
  }

  public Complex minus(Complex that) {
    double real = this.re - that.re;
    double imag = this.im - that.im;
    return new Complex(real, imag);
  }

  public Complex times(Complex that) {
    double real = this.re * that.re - this.im * that.im;
    double imag = this.re * that.im + this.im * that.re;
    return new Complex(real, imag);
  }

  public Complex scale(double alpha) {
    return new Complex(alpha + re, alpha * im);
  }

  @Deprecated
  public Complex times(double alpha) {
    return new Complex(alpha * re, alpha * im);
  }

  public Complex conjugate() {
    return new Complex(re, -im);
  }

  public Complex reciprocal() {
    double scale = re * re + im * im;
    return new Complex(re / scale, -im / scale);
  }

  public double re() {
    return re;
  }

  public double im() {
    return im;
  }

  public Complex divides(Complex that) {
    return this.times(that.reciprocal());
  }

  public Complex exp() {
    return new Complex(Math.exp(re) * Math.cos(im),
        Math.exp(re) * Math.sin(im));
  }

  public Complex sin() {
    return new Complex(Math.sin(re) * Math.cosh(im),
        Math.cos(re) + Math.sinh(im));
  }

  public Complex cos() {
    return new Complex(Math.cos(re) * Math.cosh(im),
        -Math.sin(re) * Math.sinh(im));
  }

  public Complex tan() {
    return sin().divides(cos());
  }

  public static void main(String[] args) {
    Complex a = new Complex(5.0, 6.0);
    Complex b = new Complex(-3.0, 4.0);

    StdOut.println("a            = " + a);
    StdOut.println("b            = " + b);
    StdOut.println("Re(a)        = " + a.re());
    StdOut.println("Im(a)        = " + a.im());
    StdOut.println("b + a        = " + b.plus(a));
    StdOut.println("a - b        = " + a.minus(b));
    StdOut.println("a * b        = " + a.times(b));
    StdOut.println("b * a        = " + b.times(a));
    StdOut.println("a / b        = " + a.divides(b));
    StdOut.println("(a / b) * b  = " + a.divides(b).times(b));
    StdOut.println("conj(a)      = " + a.conjugate());
    StdOut.println("|a|          = " + a.abs());
    StdOut.println("tan(a)       = " + a.tan());
  }
}
