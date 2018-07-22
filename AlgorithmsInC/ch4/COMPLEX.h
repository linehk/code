// 14.h 复数的一级数据类型

typedef struct {
        float Re;
        float Im;
} Complex;

Complex COMPLEXinit(float, float);
float Re(Complex);
float Im(Complex);
Complex COMPLEXmult(Complex, Complex);