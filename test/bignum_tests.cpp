#include "bignum.hpp"
#include <gtest/gtest.h>

TEST(Unsigned_Big_Numbers, construct_unsigned_big_number_from_int) {
  lw_big::UBignum a{123};
  const std::string ans{"123"};

  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, construct_unsigned_big_number_from_string) {
  lw_big::UBignum a{"123"};
  const std::string ans{"123"};

  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, construct_unsigned_big_number_from_int_to_bin) {
  lw_big::UBignum a{123};
  const std::string ans{"1111011"};

  EXPECT_EQ(ans, a.repr(lw_big::base::bin));
}

TEST(Unsigned_Big_Numbers, construct_unsigned_big_number_from_string_to_bin) {
  lw_big::UBignum a{"123"};
  const std::string ans{"1111011"};

  EXPECT_EQ(ans, a.repr(lw_big::base::bin));
}

TEST(Unsigned_Big_Numbers, assignment_with_addition_test) {
  lw_big::UBignum a{"123"};
  lw_big::UBignum b{"321"};
  const std::string ans{"444"};

  a += b;

  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_addition_test2) {
  lw_big::UBignum a{9223372036854775807};
  lw_big::UBignum b{"9223372036852678655"};
  const std::string ans{"18446744073707454462"};

  a += b;

  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_addition_test3) {
  lw_big::UBignum a{"1000000000000"};
  lw_big::UBignum b{1};
  const std::string ans{"1000000000001"};

  a += b;

  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, addition_operator_test) {
  const lw_big::UBignum a{9223372036854775807};
  const lw_big::UBignum b{"9223372036852678655"};
  const std::string ans{"18446744073707454462"};
  const auto c = a + b;

  EXPECT_EQ(ans, c.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, addition_operator_num_plus_zero) {
  constexpr auto z = 0UL;
  const lw_big::UBignum zero{z};
  
  for (size_t i = 0; i < std::numeric_limits<unsigned short>::max(); ++i) {
    ASSERT_EQ(std::to_string(z + i), (lw_big::UBignum (i) + zero).repr(lw_big::base::dec));
  }
}

TEST(Unsigned_Big_Numbers, addition_operator_num_plus_num) {
  for (size_t i = 0; i < std::numeric_limits<unsigned short>::max(); ++i) {
    ASSERT_EQ(std::to_string(i + i), (lw_big::UBignum (i) + lw_big::UBignum (i)).repr(lw_big::base::dec));
  }
}

TEST(Unsigned_Big_Numbers, assignment_with_substraction_test) {
  lw_big::UBignum a{256};
  const lw_big::UBignum b{1};
  const std::string ans{"255"};

  a -= b;
  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_substraction_test2) {
  lw_big::UBignum a{"1"};
  const lw_big::UBignum b{1};
  const std::string ans{"0"};

  a -= b;
  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_substraction_test3_zero_plus_zero) {
  lw_big::UBignum a{0};
  const lw_big::UBignum b{"0"};
  const std::string ans{"0"};

  a -= b;
  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_substraction_test4_num_plus_zero) {
  lw_big::UBignum a{"255"};
  const lw_big::UBignum b{"0"};
  const std::string ans{"255"};

  a -= b;
  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_substraction_test5_num_plus_zero) {
  lw_big::UBignum a{"256"};
  const lw_big::UBignum b{"0"};
  const std::string ans{"256"};

  a -= b;
  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, assignment_with_substraction_test6_small_minus_big) {
  lw_big::UBignum a{"1"};
  const lw_big::UBignum b{"100000"};
  const std::string ans{"16677217"};

  a -= b;
  EXPECT_EQ(ans, a.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, substraction_operator_num_minus_zero) {
  constexpr auto z = 0UL;
  const lw_big::UBignum zero{z};
  
  for (size_t i = 0; i < std::numeric_limits<unsigned short>::max(); ++i) {
    ASSERT_EQ(std::to_string(z + i), (lw_big::UBignum (i) - zero).repr(lw_big::base::dec));
  }
}

TEST(Unsigned_Big_Numbers, addition_operator_num_minus_num) {
  const std::string ans{"0"};
  
  for (size_t i = 0; i < std::numeric_limits<unsigned short>::max(); ++i) {
    ASSERT_EQ(ans, (lw_big::UBignum (i) - lw_big::UBignum (i)).repr(lw_big::base::dec));
  }
}

TEST(Unsigned_Big_Numbers, addition_and_substraction_test1) {
  const lw_big::UBignum a{255};
  const lw_big::UBignum b{256};
  const lw_big::UBignum c{1};
  const auto res = a - b + c;
  const std::string ans{"65536"};
  EXPECT_EQ(ans, res.repr(lw_big::base::dec));
}

TEST(Unsigned_Big_Numbers, addition_and_substraction_test2_long) {
  for (size_t i = 0; i < std::numeric_limits<unsigned short>::max(); ++i) {
    const lw_big::UBignum a{i + 3};
    const lw_big::UBignum b{i + 2};
    const lw_big::UBignum c{i + 1};
    const lw_big::UBignum res = a + c - b;
    std::string ans{std::to_string(i + 2)};
    
    ASSERT_EQ(ans, res.repr(lw_big::base::dec));
  }
}