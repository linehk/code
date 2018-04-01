#include "readnumb.c"

// 求一个后缀表达式的值
double evalpost(char f[])
{
        double obst[100]; // 操作数栈
        int top = 0;
        int i = 0;
        double x1, x2;
        while (f[i] != '#') {
                if (f[i] >= '0' && f[i] <= '9') {
                        obst[top] = readnumber(f, &i);
                        top++;
                }
                else if (f[i] == ' ') {
                        i++;
                }
                else if (f[i] == '+') {
                        x2 = obst[--top];
                        x1 = obst[--top];
                        obst[top] = x1 + x2;
                        top++;
                        i++;
                }
                else if (f[i] == '-') {
                        x2 = obst[--top];
                        x1 = obst[--top];
                        obst[top] = x1 - x2;
                        top++;
                        i++;
                }
                else if (f[i] == '*') {
                        x2 = obst[--top];
                        x1 = obst[--top];
                        obst[top] = x1 * x2;
                        top++;
                        i++;
                }
                else if (f[i] == '/') {
                        x2 = obst[--top];
                        x1 = obst[--top];
                        obst[top] = x1 / x2;
                        top++;
                        i++;
                }
        }
        return obst[0];
}