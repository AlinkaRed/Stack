#include "../LStack/Stack.h"
#include "gtest.h"
TEST(TStack, can_create_stack_with_positive_size)
{
	// Проверка, что можно создать стек с положительным размером

	ASSERT_NO_THROW(TStack<int> stack(5));
}
TEST(TStack, can_create_stack_with_positive_length)
{
	// Проверка, что можно создать стек с положительной длиной

	ASSERT_NO_THROW(TStack<int> stack(10));
}
TEST(TStack, cant_create_too_large_stack)
{
	// Проверка, что стек с размером больше MAXS выбрасывает исключение

	ASSERT_ANY_THROW(TStack<int> stack(MAXS + 1));
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	// Проверка, что стек с отрицательным размером выбрасывает исключение

	ASSERT_ANY_THROW(TStack<int> stack(-5));
}
TEST(TStack, can_create_copied_stack)
{
	// Проверка, что можно создать копию стека

	TStack<int> stack(5);
	ASSERT_NO_THROW(TStack<int> stack_copy(stack));
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	// Проверка, что скопированный стек равен исходному

	TStack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	TStack<int> stack_copy(stack);
	EXPECT_EQ(stack, stack_copy); // Проверка на равенство

}
TEST(TStack, copied_stack_has_its_own_memory)
{
	// Проверка, что скопированный стек имеет собственную память

	TStack<int> stack(5);
	stack.Push(1);
	TStack<int> stack_copy(stack);
	stack_copy.Push(2);
	EXPECT_NE(stack.Top(), stack_copy.Top()); // Проверка, что стеки различаются по верхним элементам

}
TEST(TStack, can_push_and_pop_elements_in_lifo_order)
{
	// Проверка, что элементы добавляются и удаляются в порядке LIFO (Last In First Out)
	TStack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	EXPECT_EQ(stack.Pop(), 3); // Последний добавленный элемент

	EXPECT_EQ(stack.Pop(), 2); // Следующий по порядку

	EXPECT_EQ(stack.Pop(), 1); // Первый добавленный элемент

}
TEST(TStack, throws_when_popping_from_empty_stack)
{
	// Проверка, что при попытке извлечь элемент из пустого стека выбрасывается исключение

	TStack<int> stack(5);
	ASSERT_ANY_THROW(stack.Pop());
}
TEST(TStack, can_check_if_stack_is_empty)
{
	// Проверка, что можно проверить, пуст ли стек

	TStack<int> stack(5);
	EXPECT_TRUE(stack.Empty()); // Пустой стек

	stack.Push(1);
	EXPECT_FALSE(stack.Empty()); // Стек не пуст после добавления элемента

}
TEST(TStack, throws_when_pushing_into_full_stack)
{
	// Проверка, что при попытке добавить элемент в полный стек выбрасывается исключение

	TStack<int> stack(2);
	stack.Push(1);
	stack.Push(2);
	ASSERT_ANY_THROW(stack.Push(3));
}
TEST(TStack, can_clear_stack)
{
	// Проверка, что можно очистить стек

	TStack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	stack.Clear(); // Очистка стека

	EXPECT_TRUE(stack.Empty()); // Стек должен быть пуст

}
TEST(TStack, stacks_with_different_sizes_are_not_equal)
{
	// Проверка, что стеки с разными размерами не равны

	TStack<int> stack1(5);
	TStack<int> stack2(3);
	EXPECT_FALSE(stack1 == stack2); // Стек с размером 5 и стек с размером 3 не равны

}
TEST(TStack, can_assign_stack_to_itself)
{
	// Проверка, что можно присвоить стек самому себе

	TStack<int> stack(5);
	stack.Push(1);
	ASSERT_NO_THROW(stack = stack); // Присваивание самого себя должно быть безопасным

}
TEST(TStack, can_assign_stacks_of_equal_size)
{
	// Проверка, что стеки одинакового размера можно присваивать

	TStack<int> stack1(5);
	stack1.Push(1);
	TStack<int> stack2(5);
	ASSERT_NO_THROW(stack2 = stack1); // Присваивание стека должно быть безопасным

	EXPECT_EQ(stack2.Pop(), 1); // Проверка, что элементы скопированы правильно

}
TEST(TStack, can_assign_stacks_of_different_size)
{
	// Проверка, что можно присваивать стеки разных размеров (при условии что размер принимающего стека больше или равен)
	TStack<int> stack1(5);
	stack1.Push(1);
	TStack<int> stack2(3);
	ASSERT_NO_THROW(stack2 = stack1); // Присваивание стека с большим размером в меньший
	EXPECT_EQ(stack2.Pop(), 1); // Проверка, что элементы скопированы правильно

}
TEST(TStack, compare_equal_stacks_return_true)
{
	// Проверка, что два одинаковых стека равны

	TStack<int> stack1(5);
	TStack<int> stack2(5);
	stack1.Push(1);
	stack2.Push(1);
	EXPECT_TRUE(stack1 == stack2); // Проверка, что стеки равны

}
