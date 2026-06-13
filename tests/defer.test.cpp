#include <gtest/gtest.h>

#include <zx/defer.h>

// Demonstrate some basic assertions.
TEST(DeferTest, SetOnDestruct) 
{
  bool b = false;
  
  {
    EXPECT_EQ(b, false);
    auto d = zx::defer([&](){b = true;});
  }

  EXPECT_EQ(b, true);
}