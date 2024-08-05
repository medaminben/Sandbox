#include <Sandbox/Pot/Pot.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>

// Test case names must start with the name of the executable they are
// contained in, in this case, "test_core"
TEST (test_Pot_Point, add_points ) {
   const int a[2] = { 1 , 3 };
   const int b[2] = { 1 , 3 }; 
   const auto point_a = Sp::Point2D(a); 
   const auto point_b = Sp::Point2D(b);
   const auto result = point_a + point_b;
   EXPECT_EQ(result.x,2);
}