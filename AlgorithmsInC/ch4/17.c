// 复数 ADT 的实现

#include <stdlib.h>
#include "16.c"
// #include "STACK.h"

struct complex {
        float Re;
        float Im;
};

Complex COMPLEXinit(float Re, float Im)
{
        Complex t = malloc(sizeof *t);
        t->Re = Re;
        t->Im = Im;
        return t;
}

float Re(Complex z)
{
        return z->Re;
}

float Im(Complex z)
{
        return z->Im;
}

Complex COMPLEXmult(Complex a, Complex b)
{
        return COMPLEXinit(Re(a)*Re(b) - Im(a)*Im(b),
                        Re(a)*Im(b) + Im(a)*Re(b));
}