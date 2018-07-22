// STACK.c 复数的一级 ADT

typedef struct complex *Complex;

Complex COMPLEXinit(float, float);
float Re(Complex);
float Im(Complex);
Complex COMPLEXmult(Complex, Complex);