#include <gtest/gtest.h>

#include <zx/defer.h>

// Demonstrate some basic assertions.
TEST(DeferTest, SetOnDestruct) 
{
  bool flag = false;
  
  {
    ASSERT_FALSE(flag);
    auto d = zx::defer([&](){flag = true;});
  }

  ASSERT_TRUE(flag);
}

TEST(DeferTest, Cancel) 
{
  bool flag = false;
  
  {
    ASSERT_FALSE(flag);
    auto d = zx::defer([&](){flag = true;});
    d.cancel();
  }

  ASSERT_FALSE(flag);
}

TEST(DeferTest, MoveConstructor) 
{
  int count = 0;;
  
  {
    ASSERT_EQ(count, 0);
    auto d = zx::defer([&](){++count;});
    auto moved = std::move(d);
  }

  ASSERT_EQ(count, 1);
}

TEST(DeferTest, ExplicitExecute) 
{
  int count = 0;;
  
  {
    ASSERT_EQ(count, 0);
    auto d = zx::defer([&](){++count;});
    ASSERT_TRUE(d.execute());
    ASSERT_TRUE(d.has_executed());
  }

  ASSERT_EQ(count, 1);
}