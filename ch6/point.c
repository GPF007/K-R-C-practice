#include <stdio.h>

#define XMAX 300
#define YMAX 400

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
struct point
{
    int x;
    int y;
    /* data */
};
struct rect{
    struct point pt1;
    struct point pt2;
}

struct point makepoint(int x,int y);
struct addpoint(struct point p1,struct point p2);
int ptinrect(struct point p,struct rect r);
struct rect cannorect(struct rect r);

int main(int argc, char const *argv[])
{
    struct point maxpt={320,200};
    printf("%d,%d\n",maxpt.x,maxpt.y);

    struct rect screen;
    struct point middle;

    screen.pt1=makepoint(0,0);
    screen.pt2=makepoint(XMAX,YMAX);
    return 0;
}


struct point makepoint(int x,int y){
    struct point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
/* addpoints: add two points */
struct addpoint(struct point p1,struct point p2){
    p1.x+=p2.x;
    p1.y+=p2.y;
    return p1;
}
/*ptinrect: return 1 if p in r,else 0*/
int ptinrect(struct point p,struct rect r){
    return p.x>=r.pt1.x && p.x <r.pt2.x
        && p.y>=r.pt1.y && p.y<r.pt2.y;
}

/*cannonrect: canonicalize coordinates of rect*/
struct rect cannorect(struct rect r){
    struct rect temp;

    temp.pt1.x=min(r.pt1.x,r.pt2.x);
    temp.pt1.y=min(r.pt1.y,r.pt2.y);
    temp.pt2.x=max(r.pt1.x,r.pt2.x);
    temp.pt2.y=max(r.pt1.y,r.pt2.y);
}