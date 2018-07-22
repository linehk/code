// QUEUE.c 队列的一级 ADT 接口

typedef struct queue *Q;
void QUEUEdump(Q);
Q QUEUEinit(int maxN);
int QUEUEempty(Q);
void QUEUEput(Q, Item);
Item QUEUEget(Q);