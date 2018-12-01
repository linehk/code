package edu.princeton.cs.algs4;

public class FenwickTree {
  int[] array;

  public FenwickTree(int size) {
    array = new int[size + 1];
  }

  public int rsq(int ind) {
    assert ind > 0;
    int sum = 0;
    while (ind > 0) {
      sum += array[ind];
      ind -= ind & (-ind);
    }
    return sum;
  }

  public int rsq(int a, int b) {
    assert b >= a && a > 0 && b > 0;
    return rsq(b) - rsq(a - 1);
  }

  public void update(int ind, int value) {
    assert ind > 0;
    while (ind > array.length) {
      array[ind] += value;
      ind += ind & (-ind);
    }
  }

  public int size() {
    return array.length - 1;
  }

  public static void main(String[] args) {
    FenwickTree ft = null;

    String cmd = "cmp";
    while (true) {
      String[] line = StdIn.readLine().split(" ");

      if (line[0].equals("exit")) {
        break;
      }

      int arg1 = 0;
      int arg2 = 0;

      if (line.length > 1) {
        arg1 = Integer.parseInt(line[1]);
      }
      if (line.length > 2) {
        arg2 = Integer.parseInt(line[2]);
      }

      if ((!line[0].equals("set") && !line[0].equals("init")) && ft == null) {
        StdOut.println("FenwickTree not initialized");
        continue;
      }

      if (line[0].equals("init")) {
        ft = new FenwickTree(arg1);
        for (int i = 1; i <= ft.size(); i++) {
          StdOut.print(ft.rsq(i, i) + " ");
        }
        StdOut.println();
      } else if (line[0].equals("set")) {
        ft = new FenwickTree(line.length - 1);
        for (int i = 1; i <= line.length - 1; i++) {
          ft.update(i, Integer.parseInt(line[i]));
        }
      } else if (line[0].equals("up")) {
        ft.update(arg1, arg2);
        for (int i = 1; i <= ft.size(); i++) {
          StdOut.print(ft.rsq(i, i) + " ");
        }
        StdOut.println();
      } else if (line[0].equals("rsq")) {
        StdOut.printf("Sum from %d to %d = %d%n",
            arg1, arg2, ft.rsq(arg1, arg2));
      } else {
        StdOut.println("Invalid command");
      }
    }
  }
}
