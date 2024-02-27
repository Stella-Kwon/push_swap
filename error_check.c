/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:22:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/27 15:28:51 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int write_error(void)
{
	int length;

	length = write(2, "ERROR\n", 6);
	if (length == -1)
		write(2, "ERROR\n", 6); // this you need to consider it really needs or not
	return (-1);
}

int check_integer(int arg, char **args, t_stack **a, long long i, long long *arg_i)
{
	long long j;
	long long atoi_i;
	long long atoi_j;

	atoi_i = ft_atoi_m(args[i]);
	printf("\n\n\n>>>>>new_arg<<<<<\n\n\n");
	printf("args[%lld} : %s\n", i, args[i]);
	printf("atoi_i : %lld\n\n", atoi_i);
	if (!args[i][0] || atoi_i == -1 || sizeof(atoi_i) > sizeof(long long))
	{
		printf("empty("") | atoi_i == -1 |overbits : \n");
		return (write_error());
	}
	j = i + 1;
	// printf("\n\n\n<<<<<test: j < arg >>>>>\n\n\n");
	while (j < arg && args[j])
	{
		atoi_j = ft_atoi_m(args[j]);
		if (atoi_j != -1 && atoi_i == atoi_j)
		{
			printf("duplicate \n");
			return (write_error());
		}
		j++;
	}
	if (insert_args(atoi_i, a, arg_i) == -1)
		return (write_error());
		
	printf("finish\n");
	return (1);
}

int error_check(int arg, char **args, t_stack **a, long long *arg_i)
{
	long long i;
	// long long j;
	// long long integer;
	// char	*emp;
	// long long atoi_j;
	char **str_arg;
	// integer = 0;
	i = 1;
	str_arg = NULL;
	// emp = "";
	// if (args[1] == emp) ->  will only compare the addresses of it, not the contents.
	// printf("<<<<<test: arg < 2 >>>>>\n\n\n");
	printf("\narg : %d\n", arg);
	if (arg < 2)
	{
		printf("arg <2 \n");
		return (write_error()); // this is woring because write_error is void func.
	}
	if (arg == 2)
	{
		i = 0;
		str_arg = ft_split(args[1], ' ');
		while (str_arg[i])
		{
			printf("std_arg :  %s\n", str_arg[i]);
			if(check_integer(arg, str_arg, a, i, arg_i) == -1)
				return (-1);
			i++;
		}
		
		return (1);
	}
	// printf("\n\n\n<<<<<test: i < arg >>>>>\n\n\n");
	while (i < arg)
	{
		if (check_integer(arg, args, a, i, arg_i) == -1)
			return (-1);
		i++;
	}
	if (!a)
		return (write_error());
	return (1);
}



/*

메모리 풀은 반복적으로 메모리를 할당하고 해제하는 작업을 최소화하기 위해 사용됩니다. 이는 메모리 할당 및 해제 작업이 상대적으로 느리고 비용이 많이 들기 때문에 중요합니다. 메모리 풀은 미리 할당된 메모리 블록을 사용하여 객체를 생성하고, 필요 없어지면 메모리 블록을 해제하지 않고 재사용하는 방식으로 동작합니다.

간단한 메모리 풀의 예시를 보여드리겠습니다. 아래 코드는 C 언어로 작성되었으며, 미리 할당된 메모리 블록을 사용하여 정수를 저장하는 간단한 메모리 풀을 구현한 것입니다.

c
Copy code
#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 100

// 메모리 풀 구조체
typedef struct {
	int data;
	int in_use;
} MemoryBlock;

MemoryBlock memory_pool[POOL_SIZE]; // 메모리 풀

// 메모리 풀 초기화 함수
void initialize_memory_pool() {
	for (int i = 0; i < POOL_SIZE; ++i) {
		memory_pool[i].in_use = 0; // 초기화: 사용 중이 아님
	}
}

// 메모리 풀에서 사용 가능한 메모리 블록을 찾아서 반환하는 함수
MemoryBlock* allocate_memory_block() {
	for (int i = 0; i < POOL_SIZE; ++i) {
		if (!memory_pool[i].in_use) { // 사용 중이 아닌 블록을 찾음
			memory_pool[i].in_use = 1; // 사용 중으로 설정
			return &memory_pool[i]; // 해당 블록 반환
		}
	}
	return NULL; // 사용 가능한 블록이 없는 경우
}

// 사용한 메모리 블록을 다시 메모리 풀에 반환하는 함수
void free_memory_block(MemoryBlock* block) {
	block->in_use = 0; // 사용 중이 아니라고 표시
}

int main() {
	initialize_memory_pool(); // 메모리 풀 초기화

	// 메모리 풀에서 블록 할당
	MemoryBlock* block1 = allocate_memory_block();
	block1->data = 10;

	// 메모리 풀에서 또 다른 블록 할당
	MemoryBlock* block2 = allocate_memory_block();
	block2->data = 20;

	// 블록 해제
	free_memory_block(block1);
	free_memory_block(block2);

	return 0;
}
위의 예시에서는 MemoryBlock 구조체를 사용하여 메모리 풀을 구현하였습니다. MemoryBlock 구조체에는 실제 데이터를 저장하는 data 필드와 해당 블록이 현재 사용 중인지를 나타내는 in_use 필드가 포함되어 있습니다.

initialize_memory_pool 함수는 메모리 풀을 초기화하는데 사용되며, allocate_memory_block 함수는 사용 가능한 메모리 블록을 찾아서 반환합니다. free_memory_block 함수는 사용한 메모리 블록을 다시 메모리 풀에 반환합니다.

이러한 메모리 풀을 사용하면 반복적으로 메모리를 할당하고 해제하는 작업을 최소화하여 성능을 향상시킬 수 있습니다.
*/