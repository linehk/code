// TST 中部分匹配搜索

char word[maxW];
void matchR(link h, char *v, int i)
{
        if (h == z) {
                return;
        }
        if ((*v == '\0') && (h->d == '\0')) {
                word[i] = h->d;
                printf("%s ", word);
        }
        if ((*v == '*') || (*v == h->d)) {
                word[i] = h->d;
                matchR(h->m, v+1, i+1);
        }
        if ((*v == '*') || (*v < h->d)) {
                matchR(h->l, v, i);
        }
        if ((*v == '*') || (*v > h->d)) {
                matchR(h->r, v, i);
        }
}

void STmatch(char *v)
{
        matchR(head, v, 0);
}