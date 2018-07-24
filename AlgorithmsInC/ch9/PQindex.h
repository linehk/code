// 11.c 索引数据项的优先队列的 ADT 接口

int less(int, int);
void PQinit();
int PQempty();
void PQinsert(int);
int PQdelmax();
void PQchange(int);
void PQdelete(int);