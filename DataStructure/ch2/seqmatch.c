#include "seqstack.c"

// 判断表达式括号是否匹配
int match_kuohao(char c[])
{
        int i = 0;
        sequence_stack s;
        init(&s);
        while (c[i] != '#') {
                switch (c[i]) {
                case '{':
                case '[':
                case '(':
                        push(&s, c[i]);
                        break;
                case '}':
                        if (!empty(s) && read(s) == '{') {
                                pop(&s);
                                break;
                        }
                        else {
                                return 0;
                        }
                case ']':
                        if (!empty(s) && read(s) == '[') {
                                pop(&s);
                                break;
                        }
                        else {
                                return 0;
                        }
                case ')':
                        if (!empty(s) && read(s) == '(') {
                                pop(&s);
                                break;
                        }
                        else {
                                return 0;
                        }
                }
                i++;
        }
        return (empty(s)); // 栈为空则匹配，否则不匹配
}