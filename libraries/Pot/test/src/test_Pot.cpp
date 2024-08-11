#include <Sandbox/Pot/Pot.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>
// control board ! undefine the test that you don't need to check by block
// useful to reduce compile time by discarding the archived tests
#define TEST_POT   true
#if TEST_POT 
#define TEST_POT_POINT   true 
#define TEST_POT_CONCEPT true
#endif  

#ifdef TEST_POT_CONCEPT
struct test_pot_concept : public ::testing::Test {
   public:
      Sp::Point2D<float>       a_point;
      Sp::basic_point<float,2> b_point = Sp::basic_point<float,2>(1.5f);
   void SetUp(){
      a_point = Sp::Point2D<float>(1.5f);
   }
   void TearDown(){
      
   }
};
TEST_F (test_pot_concept, get_1st_coord_from_point ) {
   auto x = Sp::get<0>(a_point);
   EXPECT_EQ(x, 1.5);
}

TEST_F (test_pot_concept, get_2nd_coord_from_point ) {
   const auto o = Sp::get<1>(b_point);
   EXPECT_EQ(1.5, o);
}

#endif

#if TEST_POT_POINT 
TEST_F (test_pot_concept, add_points ) {
   Sp::Point2D<float> result = a_point + b_point;
   const auto x = Sp::get<0>(result);
   EXPECT_EQ(x, 3);
}
TEST_F (test_pot_concept, copy_constructor ) {
   Sp::Point2D<float> result(a_point);
   const auto x = Sp::get<0>(result);
   const auto a = Sp::get<0>(a_point);
   EXPECT_EQ(x, a);
}
#endif

