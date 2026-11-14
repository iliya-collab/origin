#include <gtest/gtest.h>
#include "ExpectExactThrow.hpp"
#include "../extended_array.h"

namespace NativeUnitTest 
{

TEST(ExtendedArrayTest, Mean) {
    ExtArray<int> v{ 4, 2, 7, 3, -5, 0, -3, 1 };
    EXPECT_DOUBLE_EQ(v.mean(), 1.125);
}

TEST(ExtendedArrayTest, Median) {
    ExtArray<double> v{ 4.5, 0.7, 10.8, -3.5 };
    EXPECT_DOUBLE_EQ(v.median(), 2.6);
}

TEST(ExtendedArrayTest, Mode) {
    ExtArray<int> v{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
    EXPECT_DOUBLE_EQ(v.mode().first, 5);
}


// -----------------------------------------------------------------------


TEST(ExtendedArrayEmptyTest, MeanSizeIsZero) {
    ExtArray<int> v(0);
    EXPECT_DOUBLE_EQ(v.mean(), 0.0);
}

TEST(ExtendedArrayEmptyTest, MedianSizeIsZero) {
    ExtArray<int> v(0);
    EXPECT_DOUBLE_EQ(v.median(), 0.0);
}

TEST(ExtendedArrayEmptyTest, ModeSizeIsZero) {
    ExtArray<int> v(0);
    auto m = v.mode();
    EXPECT_EQ(m.first, 0);
    EXPECT_EQ(m.second, 0);
}


// -----------------------------------------------------------------------


TEST(ExtendedArrayTestWithRange, MeanInRange) {
    ExtArray<double> v{ 4.1, 2.6, 7.0, 3.3, -5.1, 0.0, -3.7, 1.8 };
    EXPECT_NEAR(v.mean(1, 4), 4.3, 1e-9);
}

TEST(ExtendedArrayTestWithRange, MeanWithInvalidRange) {
    ExtArray<double> v{ 4.1, 2.6, 7.0, 3.3, -5.1, 0.0, -3.7, 1.8 };
    EXPECT_THROW(v.mean(-1, 4), std::invalid_argument);
    EXPECT_THROW(v.mean(1, -4), std::invalid_argument);
    EXPECT_THROW(v.mean(-1, -4), std::invalid_argument);
    EXPECT_THROW(v.mean(4, 1), std::invalid_argument);
    EXPECT_THROW(v.mean(4, 4), std::invalid_argument);
}


// -----------------------------------------------------------------------


TEST(ExtendedArrayTestWithCheckSum, CheckSumWithInvalidType) {
    ExtArray<double> v{ 4.1, 2.6, 7.0, 3.3, -5.1, 0.0, -3.7, 1.8 };
    ExpectExactThrow<std::bad_typeid>(
        [&]() { v.checkSum(); });
}

TEST(ExtendedArrayTestWithCheckSum, CheckSumWithInvalidValue) {
    ExtArray<int> v{ 1, 0, 2, 1, 0 };
    ExpectExactThrow<std::logic_error>(
        [&]() { v.checkSum(); },
        "The array must contain only 1 or 0");
}

TEST(ExtendedArrayTestWithCheckSum, CheckSum) {
    ExtArray<int> v{ 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0 };
    EXPECT_EQ(v.checkSum(), 8);
}

} // NativeUnitTest
