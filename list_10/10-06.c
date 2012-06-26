struct point{
  double x;
  double y;
};

struct line1{
  double x1;
  double y1;
  double x2;
  double y2;
};

struct line2{
  struct point start;
  struct point end;
};

struct rectangle1{
  double x1;
  double y1;
  double x2;
  double y2;
};

struct rectangle2{
  struct point p1;
  struct point p2;
};
