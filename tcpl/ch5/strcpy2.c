/* strcpy: copy t to s; pointer version */
void strcpy(char *s, char *t)
{
        while ((*s = *t) != '\0') {
                s++;
                t++;
        }
}