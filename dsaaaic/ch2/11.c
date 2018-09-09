// 估计两个随机数互素的概率

Rel = 0;
Tot = 0;
for (i = 1; i <= N; i++)
{
        for (j = i + 1; j <= N; j++)
        {
                Tot++;
                if (Gcd(i, j) == 1)
                        Rel++;
        }
        printf("Percentage of relatively prime pairs is %f\n",
                (double)Rel / Tot);
}