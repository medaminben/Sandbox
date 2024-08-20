#include <Sandbox/Geo/Geo.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>
#include <array>
#include <concepts>
// Test case names must start with the name of the executable they are
// contained in, in this case, "test_core"
TEST (test_Geo_factorial, result) {
    // no use of Result<..> class cause it never fails
    auto result = Sg::factorial<5>::is;
    EXPECT_EQ(result,120);
}

TEST (test_Geo_bino_coef, error) {
    auto result = Sg::bino_coef<>(2,6);
    EXPECT_EQ(result.isError(),true);
}

TEST (test_Geo_bino_coef, result) {
    auto result = Sg::bino_coef<>(6,2);
    EXPECT_EQ(result(),15);
}

TEST (test_Geo_reduce_Point, result) {
    float pt[2] = { 45 , 15};
    auto my_point = Sp::Point2D(pt);
    auto result = Sg::reducePoint(my_point);
    std:: cout <<" result: - x: " << Sp::get<0>(result()) 
    << " | y: " << Sp::get<1>(result()) << " \n";
    EXPECT_EQ(Sp::get<0>(result()),3);
}
TEST (test_Geo_distance_Point, result_zero) {
    float a_pt[2] = { 45 , 15};
    float b_pt[2] = { 45 , 15};
    auto a_point = Sp::Point2D(a_pt);
    auto b_point = Sp::Point2D(b_pt);
    auto result  = Sg::distance(a_point, b_point);
    std:: cout <<" distance between a and b : " << result
    << " \n";
    EXPECT_EQ(result,0);
}
TEST (test_Geo_distance_Point, result) {
    float a_pt[2] = { 45 , 15};
    float b_pt[2] = { 0 , 0};
    auto a_point = Sp::Point2D(a_pt);
    auto b_point = Sp::Point2D(b_pt);
    auto result  = Sg::distance(a_point, b_point);
    std:: cout <<" distance between a and b : " << result
    << " \n";
    EXPECT_LE(result - 47.434164, 0.00001);
}