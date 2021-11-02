#include <limits.h>
#include "gtest/gtest.h"

int add(int a, int b) {
    return a + b;
}

namespace {


TEST(AddTest, some_test_name) {
    EXPECT_EQ(5, add(1, 4));
    EXPECT_EQ(100000, add(200000, -100000));
}


}
