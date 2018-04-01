// 求运算符的优先级
int priority(char op)
{
        switch (op) {
        case '#':
                return -1;
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
        default:
                return -1;
        }
}