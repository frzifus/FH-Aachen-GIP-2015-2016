// Copyright [2015] <none>
#include "catch.h"

#include "./../MyRectangle.h"

TEST_CASE("Pruefung der Methode MyRectangle::does_not_collide_with()") {
  MyRectangle rectangle(200, 200, 300, 300);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(100, 200, 150, 300)) ==
          true);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(400, 200, 500, 300)) ==
          true);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(200, 0, 300, 100)) ==
          true);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(200, 400, 300, 500)) ==
          true);

  REQUIRE(rectangle.does_not_collide_with(MyRectangle(100, 200, 200, 300)) ==
          false);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(100, 200, 250, 300)) ==
          false);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(300, 200, 400, 300)) ==
          false);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(250, 200, 500, 300)) ==
          false);

  REQUIRE(rectangle.does_not_collide_with(MyRectangle(200, 100, 300, 200)) ==
          false);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(200, 100, 300, 250)) ==
          false);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(200, 300, 300, 400)) ==
          false);
  REQUIRE(rectangle.does_not_collide_with(MyRectangle(200, 250, 300, 400)) ==
          false);
}
