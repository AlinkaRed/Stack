#include "../LStack/Stack.h"
#include "gtest.h"
TEST(TStack, can_create_stack_with_positive_size)
{
	// ��������, ��� ����� ������� ���� � ������������� ��������

	ASSERT_NO_THROW(TStack<int> stack(5));
}
TEST(TStack, can_create_stack_with_positive_length)
{
	// ��������, ��� ����� ������� ���� � ������������� ������

	ASSERT_NO_THROW(TStack<int> stack(10));
}
TEST(TStack, cant_create_too_large_stack)
{
	// ��������, ��� ���� � �������� ������ MAXS ����������� ����������

	ASSERT_ANY_THROW(TStack<int> stack(MAXS + 1));
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	// ��������, ��� ���� � ������������� �������� ����������� ����������

	ASSERT_ANY_THROW(TStack<int> stack(-5));
}
TEST(TStack, can_create_copied_stack)
{
	// ��������, ��� ����� ������� ����� �����

	TStack<int> stack(5);
	ASSERT_NO_THROW(TStack<int> stack_copy(stack));
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	// ��������, ��� ������������� ���� ����� ���������

	TStack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	TStack<int> stack_copy(stack);
	EXPECT_EQ(stack, stack_copy); // �������� �� ���������

}
TEST(TStack, copied_stack_has_its_own_memory)
{
	// ��������, ��� ������������� ���� ����� ����������� ������

	TStack<int> stack(5);
	stack.Push(1);
	TStack<int> stack_copy(stack);
	stack_copy.Push(2);
	EXPECT_NE(stack.Top(), stack_copy.Top()); // ��������, ��� ����� ����������� �� ������� ���������

}
TEST(TStack, can_push_and_pop_elements_in_lifo_order)
{
	// ��������, ��� �������� ����������� � ��������� � ������� LIFO (Last In First Out)
	TStack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	EXPECT_EQ(stack.Pop(), 3); // ��������� ����������� �������

	EXPECT_EQ(stack.Pop(), 2); // ��������� �� �������

	EXPECT_EQ(stack.Pop(), 1); // ������ ����������� �������

}
TEST(TStack, throws_when_popping_from_empty_stack)
{
	// ��������, ��� ��� ������� ������� ������� �� ������� ����� ������������� ����������

	TStack<int> stack(5);
	ASSERT_ANY_THROW(stack.Pop());
}
TEST(TStack, can_check_if_stack_is_empty)
{
	// ��������, ��� ����� ���������, ���� �� ����

	TStack<int> stack(5);
	EXPECT_TRUE(stack.Empty()); // ������ ����

	stack.Push(1);
	EXPECT_FALSE(stack.Empty()); // ���� �� ���� ����� ���������� ��������

}
TEST(TStack, throws_when_pushing_into_full_stack)
{
	// ��������, ��� ��� ������� �������� ������� � ������ ���� ������������� ����������

	TStack<int> stack(2);
	stack.Push(1);
	stack.Push(2);
	ASSERT_ANY_THROW(stack.Push(3));
}
TEST(TStack, can_clear_stack)
{
	// ��������, ��� ����� �������� ����

	TStack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	stack.Clear(); // ������� �����

	EXPECT_TRUE(stack.Empty()); // ���� ������ ���� ����

}
TEST(TStack, stacks_with_different_sizes_are_not_equal)
{
	// ��������, ��� ����� � ������� ��������� �� �����

	TStack<int> stack1(5);
	TStack<int> stack2(3);
	EXPECT_FALSE(stack1 == stack2); // ���� � �������� 5 � ���� � �������� 3 �� �����

}
TEST(TStack, can_assign_stack_to_itself)
{
	// ��������, ��� ����� ��������� ���� ������ ����

	TStack<int> stack(5);
	stack.Push(1);
	ASSERT_NO_THROW(stack = stack); // ������������ ������ ���� ������ ���� ����������

}
TEST(TStack, can_assign_stacks_of_equal_size)
{
	// ��������, ��� ����� ����������� ������� ����� �����������

	TStack<int> stack1(5);
	stack1.Push(1);
	TStack<int> stack2(5);
	ASSERT_NO_THROW(stack2 = stack1); // ������������ ����� ������ ���� ����������

	EXPECT_EQ(stack2.Pop(), 1); // ��������, ��� �������� ����������� ���������

}
TEST(TStack, can_assign_stacks_of_different_size)
{
	// ��������, ��� ����� ����������� ����� ������ �������� (��� ������� ��� ������ ������������ ����� ������ ��� �����)
	TStack<int> stack1(5);
	stack1.Push(1);
	TStack<int> stack2(3);
	ASSERT_NO_THROW(stack2 = stack1); // ������������ ����� � ������� �������� � �������
	EXPECT_EQ(stack2.Pop(), 1); // ��������, ��� �������� ����������� ���������

}
TEST(TStack, compare_equal_stacks_return_true)
{
	// ��������, ��� ��� ���������� ����� �����

	TStack<int> stack1(5);
	TStack<int> stack2(5);
	stack1.Push(1);
	stack2.Push(1);
	EXPECT_TRUE(stack1 == stack2); // ��������, ��� ����� �����

}
