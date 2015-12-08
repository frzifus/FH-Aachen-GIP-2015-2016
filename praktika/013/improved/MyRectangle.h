// Copyright [2016] <none>
#ifndef PRAKTIKA_013_BENNE_MYRECTANGLE_H_
#define PRAKTIKA_013_BENNE_MYRECTANGLE_H_

class MyRectangle {
 private:
  int x1_ = 0;
  int y1_ = 0;
  int x2_ = 0;
  int y2_ = 0;

 public:
  MyRectangle();
  MyRectangle(int x1, int y1, int x2, int y2);

  MyRectangle operator*(double) const;

  int x1() const { return x1_; }
  void set_x1(int x1) { x1_ = x1; }
  int y1() const { return y1_; }
  void set_y1(int y1) { y1_ = y1; }
  int x2() const { return x2_; }
  void set_x2(int x2) { x2_ = x2; }
  int y2() const { return y2_; }
  void set_y2(int y2) { y2_ = y2; }

  void set(int, int, int, int);
  bool does_not_collide_with(const MyRectangle&);
  void draw(const unsigned char[]);
  void draw_red();
};

#endif  // PRAKTIKA_013_BENNE_MYRECTANGLE_H_c
