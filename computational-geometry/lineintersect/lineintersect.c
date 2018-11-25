#include <stdio.h>
#include<stdbool.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

struct Point {
    int x;
    int y;
};

//check if point q is on line pr

bool onSegment(struct Point p, struct Point q, struct Point r) {
    if(q.x <= max(p.x,r.x) && q.x >= min(p.x,r.x) && q.y<= max(p.y,r.y) && q.y >= min(p.y,r.y))
        return true;

    return false;
}

int orientation(struct Point p, struct Point q, struct Point r) {
    int orientation = (q.y-p.y) * (r.x-q.x) - (r.y-q.y) * (q.x-p.x);
    if(orientation == 0) 
        return orientation;
    return (orientation >0) ? 1: 2;
}

bool doIntersect(struct Point p1, struct Point q1, struct Point p2, struct Point q2) {
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);
    printf("%d %d %d %d", o1,o2,o3,o4);
    if(o1!=o2 && o3!=o4) 
        return true;

   // p1, q1 and p2 are colinear and p2 lies on segment p1q1
   if (o1 == 0 && onSegment(p1, p2, q1)) return true;

   // p1, q1 and q2 are colinear and q2 lies on segment p1q1
   if (o2 == 0 && onSegment(p1, q2, q1)) return true;

   // p2, q2 and p1 are colinear and p1 lies on segment p2q2
   if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
   if (o4 == 0 && onSegment(p2, q1, q2)) return true;

   return false;
}

void main() {
    struct Point p1 = {1, 1}, q1 = {10, 1};
   struct Point p2 = {1, 2}, q2 = {10, 2};

   doIntersect(p1, q1, p2, q2)? printf("Yes\n"): printf("No\n");

   struct Point point1 = {10, 0}, qcoord1 = {0, 10};
   struct Point point2 = {0, 0}, qcoord2 = {10, 10};
   doIntersect(point1, qcoord1, point2, qcoord2)? printf("Yes\n"): printf("NO\n");
}