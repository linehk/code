// 坐标点数据类型的实现

#include <math.h>
#include "Point.h"

float distance(point a, point b)
{
        float dx = a.x - b.x, dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);
}