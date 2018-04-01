// 判断一个字符是否为运算符
int is_operation(char op)
{
        switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
                return 1;
        default:
                return 0;
        }
}