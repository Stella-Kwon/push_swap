/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:24:49 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/28 18:59:25 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	long long		data;
	struct stack	*next;
	long long		index;
}			t_stack;

int			error_check(int arg, char **args, t_stack **a, long long *arg_i);
int			write_error(void);
long long	ft_atoi_m(const char *str);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(long long data);
void		ft_sa(t_stack **a);
void		ft_sb(t_stack **b);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
void		ft_ra(t_stack **a);
void		ft_rb(t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_rra(t_stack **a);
void		ft_rrb(t_stack **b);
void		ft_rrr(t_stack **a, t_stack **b);
void		ft_free(t_stack **lst);
int			insert_args(long long atoi_i, t_stack **a, long long *arg_i);
int			is_sorted(t_stack *a);
int			find_index(t_stack *a_b, long long data);
long long	find_max(t_stack *a_b);
long long	find_min(t_stack *a_b);
void		small_sort(t_stack **a, int arg);
void		up_to_three(t_stack **a);
void		up_to_four(t_stack **a, t_stack **b);
void		up_to_five(t_stack **a, t_stack **b);
t_stack		*find_middle_node(t_stack *copy);
t_stack		*copy_stack(t_stack *a);
t_stack		*divide_merge_sort(t_stack *copy);
void		put_index(t_stack **copy);
int			pre_sort(t_stack **a);
void		pass_index_(t_stack **sort, t_stack **a);
t_stack		*to_binary_sort(t_stack **a);
void		move_to_b_stack(t_stack **a, t_stack **b, int *j);
int			big_sort(t_stack **a);
int			first_one_bit(t_stack *a);
t_stack		*find_max_pointer(t_stack *a_b);
char		**ft_split(char const *s, char c);
int			check_integer(int arg, char **args, t_stack **a, long long *arg_i);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
int			arg_is_two(int arg, char **args, t_stack **a, long long *arg_i);
char		**all_free(char **res);
t_stack		*free_both(t_stack **head, t_stack **a);
#endif
