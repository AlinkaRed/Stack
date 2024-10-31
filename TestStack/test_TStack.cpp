#include "../LStack/Stack.h"
#include "gtest.h"
TEST(TStack, can_create_stack_with_positive_size)
{
    ASSERT_NO_THROW(TStack<int> bf);
}
