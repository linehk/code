// 最大子序列3

static int
MaxSubSum(const int A[], int Left, int Right)
{
        int MaxLeftSum, MaxRightSum;
        int MaxLeftBorderSum, MaxRightBorderSum;
        int LeftBorderSum, RightBorderSum;
        int Center, i;

        if (Left == Right)
                if (A[Right] > 0)
                        return A[Left];
                else
                        return 0;

        Center = (Left + Right) / 2;
        MaxLeftSum = MaxSubSum(A, Left, Center);
        MaxRightSum = MaxSubSum(A, Center + 1, Right);

        MaxLeftBorderSum = 0;
        LeftBorderSum = 0;
        for (i = Center; i >= Left; i--)
        {
                LeftBorderSum += A[i];
                if (LeftBorderSum > MaxLeftBorderSum)
                        MaxLeftBorderSum = LeftBorderSum;
        }

        MaxRightBorderSum = 0;
        RightBorderSum = 0;
        for (i = Center + 1; i <= Right; i++)
        {
                RightBorderSum += A[i];
                if (RightBorderSum > MaxRightBorderSum)
                        MaxRightBorderSum = RightBorderSum;
        }

        return Max3(MaxLeftSum, MaxRightSum,
                MaxLeftBorderSum + MaxRightBorderSum);
}

int
MaxSubsequenceSum(const int A[], int N)
{
        return MaxSubSum(A, 0, N - 1);
}