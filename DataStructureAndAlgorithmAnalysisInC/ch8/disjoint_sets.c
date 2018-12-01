#include <stdio.h>
#define NumSets 128

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);

void Initialize(DisjSet S)
{
        int i;

        for (i = NumSets; i > 0; i--)
                S[i] = 0;
}

/* slow algorithms
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
        S[Root2] = Root1;
}

SetType Find(ElementType X, DisjSet S)
{
        if (S[X] <= 0)
                return X;
        else
                return Find(S[X], S);
}
*/

void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
        if (S[Root2] < S[Root1])
                S[Root1] = Root2;
        else
        {
                if (S[Root1] == S[Root2])
                        S[Root1]--;
                S[Root2] = Root1;
        }
}

SetType Find(ElementType X, DisjSet S)
{
        if (S[X] <= 0)
                return X;
        else
                return S[X] = Find(S[X], S);
}

main()
{
        DisjSet S;
        int i, j, k, Set1, Set2;

        Initialize(S);
        j = k = 1;
        while (k <= 8)
        {
                j = 1;
                while (j < NumSets)
                {
                        Set1 = Find(j, S);
                        Set2 = Find(j + k, S);
                        SetUnion(S, Set1, Set2);
                        j += 2 * k;
                }
                k *= 2;
        }
        i = 1;
        for (i = 1; i <= NumSets; i++)
        {
                Set1 = Find(i, S);
                printf("%d**", Set1);
        }
        printf("\n");
        return 0;
}