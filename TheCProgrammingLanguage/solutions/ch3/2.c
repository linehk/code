/* escape: expand newline and tab into visible sequences
        while copying the string t to s */
void escape(char s[], char t[])
{
        int i, j;

        for (i = j = 0; t[i] != '\0'; i++)
                switch (t[i]) {
                case '\n':      /* newline */
                        s[j++] = '\\';
                        s[j++] = 'n';
                        break;
                case '\t':      /* tab */
                        s[j++] = '\\';
                        s[j++] = 't';
                        break;
                default:        /* all other chars */
                        s[j++] = t[i];
                        break;
                }
        s[j] = '\0';
}

/* unescape: convert escape sequences into real characters
        while copying the string t to s */
void unescape(char s[], char t[])
{
        int i, j;

        for (i = j = 0; t[i] != '\0'; i++)
                if (t[i] != '\\')
                        s[j++] = t[i];
                else    /* it is a backslash */
                        switch(t[++i]) {
                        case 'n':       /* real newline */
                                s[j++] = '\n';
                                break;
                        case 't':       /* real tab */
                                s[j++] = '\t';
                                break;
                        default:        /* all other chars */
                                s[j++] = '\\';
                                s[j++] = t[i];
                                break;
                        }
        s[j] = '\0';
}

// void unescape(char s[], char t[])
// {
//         int i, j;

//         for (i = j = 0; t[i] != '\0'; i++)
//                 switch (t[i]) {
//                 case '\\':      /* backslash */
//                         switch(t[++i]) {
//                         case 'n':       /* real newline */
//                                 s[j++] = '\n';
//                                 break;
//                         case 't':       /* real tab */
//                                 s[j++] = '\t';
//                                 break;
//                         default:        /* all other chars */
//                                 s[j++] = '\\';
//                                 s[j++] = t[i];
//                                 break;
//                         }
//                         break;
//                 default:
//                         s[j++] = t[i];  /* not a backslash */
//                         break;
//                 }
//         s[j] = '\0';
// }