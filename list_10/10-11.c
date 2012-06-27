#include <stdio.h>
#include <math.h>

struct rectangle{
  double x1, y1;
  double x2, y2;
};

int main(void);
double distance(double a, double b);
double calc_area(struct rectangle r);

int main(void)
{
  struct rectangle rect;
  double area;

  rect.x1 = 3.1;
  rect.y1 = 4.1;
  rect.x2 = 5.9;
  rect.y2 = 2.6;
  area = calc_area(rect);
  printf("長方形 (%g,%g)-(%g-%g) の面積は %g です。\n", rect.x1, rect.y1, rect.x2, rect.y2, area);
}

double distance(double a, double b)
{
  if(a > b){
    return (a - b);
  }else{
    return (b - a);
  }
}

double calc_area(struct rectangle r)
{
  double x, y;
  x = distance(r.x1, r.x2);
  y = distance(r.y1, r.y2);

  return (x * y);
}
