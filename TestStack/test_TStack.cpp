#include "../LStack/Stack.h"
#include "gtest.h"
TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> a(10));
}
TEST(TStack, cant_create_too_large_size)
{
	ASSERT_ANY_THROW(TStack<int> a(1000000));
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> a(-2));
}
TEST(TStack, can_create_copied_stack)
{
	TStack<int> b(5);
	ASSERT_NO_THROW(TStack<int> a(b));
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> b(5);
	b.Push(1);
	b.Push(2);
	TStack<int> a(b);
	EXPECT_EQ(b, a);

}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> b(5);
	b.Push(1);
	TStack<int> a(b);
	a.Push(2);
	EXPECT_NE(b.Top(), a.Top());

}
TEST(TStack, can_push_and_pop_elements_in_lifo_order)
{
	TStack<int> a(5);
	a.Push(5);
	a.Push(20);
	a.Push(87);
	EXPECT_EQ(a.Pop(), 87);
	EXPECT_EQ(a.Pop(), 20);
	EXPECT_EQ(a.Pop(), 5);

}
TEST(TStack, throws_when_popping_from_empty_stack)
{
	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Pop());
}
TEST(TStack, can_check_if_stack_is_empty)
{
	TStack<int> s(5);
	EXPECT_TRUE(s.Empty());
	s.Push(4);
	EXPECT_FALSE(s.Empty());

}
TEST(TStack, throws_when_pushing_into_full_stack)
{
	TStack<int> s(2);
	s.Push(6);
	s.Push(3);
	ASSERT_ANY_THROW(s.Push(3));
}
TEST(TStack, can_clear_stack)
{
	TStack<int> s(5);
	s.Push(1);
	s.Push(2);
	s.Clear();
	EXPECT_TRUE(s.Empty());

}
TEST(TStack, stacks_with_different_sizes_are_not_equal1)
{
	TStack<int> s1(8);
	TStack<int> s2(2);
	EXPECT_FALSE(s1 == s2);

}
TEST(TStack, stacks_with_different_sizes_are_not_equal2)
{
	TStack<int> s1(8);
	TStack<int> s2(2);
	EXPECT_TRUE(s1 != s2);

}
TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s(5);
	s.Push(1);
	ASSERT_NO_THROW(s = s);
	EXPECT_TRUE(s == s);
}
TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s1(5);
	s1.Push(4);
	TStack<int> s2(5);
	ASSERT_NO_THROW(s2 = s1);
	EXPECT_EQ(s2, s1);

}
TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> s1(5);
	s1.Push(2);
	TStack<int> s2(3);
	ASSERT_NO_THROW(s2 = s1); 
	EXPECT_EQ(s2, s1);

}
TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> s1(5);
	TStack<int> s2(5);
	s1.Push(1);
	s2.Push(1);
	EXPECT_TRUE(s1 == s2);
}
TEST(TCalc, can_perform_arithmetic_expressions)
{
	TCalc c;
	c.SetInfix("2+4");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 6);
	c.SetInfix("2-9");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), -7);
	c.SetInfix("8+7-1-2");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 12);
	c.SetInfix("-2-1");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), -3);
	c.SetInfix("(9+8)*3-4");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 47);
	c.SetInfix("6^2*7+2-1");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 253);
	c.SetInfix("(8-1)*2-7^3");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), -329);
}
