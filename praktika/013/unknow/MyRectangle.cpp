// Copyright [2016] <none>
#include "./MyRectangle.h"

#ifndef UNITTEST
#include "CImgGIP03.h"
#endif

MyRectangle::MyRectangle() {}
MyRectangle::MyRectangle(int x1, int y1, int x2, int y2) {
  set(x1, y1, x2, y2);
}

MyRectangle MyRectangle::operator*(double multiplier) const {
  MyRectangle tmp(*this);
  tmp.set_x2(x1_ +
             static_cast<int>(static_cast<double>(x2_ - x1_) * multiplier));
  tmp.set_y2(y1_ +
             static_cast<int>(static_cast<double>(y2_ - y1_) * multiplier));
  return tmp;
}

void MyRectangle::set(int x1, int y1, int x2, int y2) {
  // Setters are usually used if we want to do some mutations or checks on
  // the data that is given so I'll call the setters here so that someone who
  // would build such checks into the setters would not have to update this
  // redundant multi-setter method.
  set_x1(x1);
  set_y1(y1);
  set_x2(x2);
  set_y2(y2);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other) {
  // Assuming that x1 <= x2 and y1 <= y2
  return x2_ < other.x1() || other.x2() < x1_ || other.y1() > y2_ ||
         y1_ > other.y2();
}

/*
 * We won't unit test these and therefore don't need CImgGIP03.h
 * This is not an ideal solution for this at all but the actual issue here is
 * the design flaw in CImgGIP03.h which does not exist in CImg.h
 * This design flaw is preprogrammed to cause further issues and therefore I'll
 * use this workaround for now because I currently don't want to fix the
 * CImgGIP03.h source.
 * Now if that design flaw would not exist I'd still use a tool such as FakeIt
 * to mock stuff if I need to.
 */
#ifndef UNITTEST
void MyRectangle::draw(const unsigned char color[]) {
  gip_draw_rectangle(x1_, y1_, x2_, y2_, color);
}

void MyRectangle::draw_red() {
  draw(red);
}
#endif
