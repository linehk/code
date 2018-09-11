#define MaxDegree 10

// 多项式 ADT 数组实现类型声明
typedef struct
{
        int CorffArray[MaxDegree + 1];
        int HighPower;
} *Polynomial;


// 初始化为0
void
ZeroPolyNomial(Polynomial Poly)
{
        int i;
        for (i = 0; i <= MaxDegree; i++)
                Poly->CorffArray[i] = 0;
        Poly->HighPower = 0;
}

// 两个多项式相加
void
AddPolynomial(const Polynomial Poly1,
        const Polynomial Poly2, Polynomial PolySum)
{
        int i;
        ZeroPolyNomial(PolySum);
        PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

        for (i = PolySum->HighPower; i >= 0; i--)
                PolySum->CorffArray[i] = Poly1->CorffArray[i] + Poly2->CorffArray[i];
}

// 两个多项式相乘
void
MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
        int i, j;

        ZeroPolyNomial(PolyProd);
        PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

        if (PolyProd->HighPower > MaxDegree)
                Error("Exceeded array size");
        else
                for (i = 0; i <= Poly1->HighPower; i++)
                        for (j = 0; j <= Poly2->HighPower; j++)
                                PolyProd->CorffArray[i + j] += Poly1->CorffArray[i] * Poly2->CorffArray[j];
}

// 多项式 ADT 链表实现的类型说明
typedef struct Node *PtrToNode;

struct Node
{
        int Coefficient;
        int Exponent;
        PtrToNode Next;
};

typedef PtrToNode Polynomial;