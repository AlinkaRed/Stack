#include "../LStack/Stack.h"
#include "gtest.h"
TEST(TStack, can_create_stack_with_positive_size)
{
    ASSERT_NO_THROW(TStack<int> bf);
}
TEST(TCalc, can_create_calculator)
{
    ASSERT_NO_THROW(TCalc calc);
}
