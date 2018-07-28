// 索引一个文本字符串示例

#define null(A) (eq(key(A), key(NULLitem)))

static char text[maxN];

main(int argc, char *argv[])
{
        int i, t, N = 0;
        char query[maxQ];
        char *v;
        FILE *corpus = fopen(*++argv, "r");
        while ((t = getc(corpus)) != EOF) {
                if (N < maxN-1) {
                        text[N++] = t;
                } else {
                        break;
                }
        }
        text[N] = '\0';
        STinit(maxN);
        for (i = 0; i < N; i++) {
                STinsert(&text[i]);
        }
        while (gets(query) != NULL) {
                if (!null(v = STsearch(query))) {
                        printf("%11d %s\n", v-text, query);
                } else {
                        printf("(not found) %s\n", query);
                }
        }
}