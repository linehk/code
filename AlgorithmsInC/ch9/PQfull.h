// 8.c 一级优先队列 ADT

typedef struct pq* PQ;
typedef struct PQnode* PQlink;

PQ PQinit();
int PQempty(PQ);
PQlink PQinsert(PQ, Item);
Item PQdelmax(PQ);
void PQchange(PQ, PQlink, Item);
void PQjoin(PQ, PQ);