// 用于字符串关键字的通用散列函数

int hashU(char *v, int M)
{
        int h, a = 31415, b = 27183;
        for (h = 0; *v != '\0'; v++, a = a*b % (M-1)) {
                h = (a*h + *v) % M;
        }
        return M;
}

// 介于 s 和 t 之间的浮点数
#define hash(v, M) (((v-s)/(t-s))*M)

// 整数关键字
#define hash(v, M) (v % M)

// M 不是素数
#define hash(v, M) ((int)(.616161 * (float)v) % M)
// 或者
#define hash(v, M) ((16161 * (unsigned)v) % M)