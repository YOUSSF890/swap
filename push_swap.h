/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:25:27 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/21 16:55:28 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}				t_list;

void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **rra);
void	reverse_rotate_b(t_list **rrb);
void	rotate_a(t_list **ra);
void	rotate_b(t_list **rb);
void	swap_a(t_list **sa);
void	swap_b(t_list **sb);

int		is_list_sorted(t_list *stati);
void	sort_three_numbers(t_list **stack_a);
void	sort_four_numbers(t_list **stack_a, t_list **stack_b);
void	sort_five_numbers(t_list **stack_a, t_list **stack_b);
void	sort_large_stack(t_list **stack_a, t_list **stack_b);

t_list	*create_new_node(int number);
void	append_node_to_list(t_list **lst, t_list *new);
void	assign_index_to_nodes(t_list *stack);
void	free_stack(t_list **list);

int		count_input_words(char **str);
void	validate_input(char **str);
void	check_duplicate_numbers(t_list **stack_a);
void	convert_to_stack(char **str, t_list **a);

long	ft_atoi(const char *str);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);

char	**ft_split(char const *str, char c);
char	**allocate_result_array(int word_count);
char	**split_and_store(char *input, char **t, int *a);
char	**split_input(char **str);

void	print_error(char **str);
void	free_string_array(char **str);
void	ft_freeup(char **strs, int i);
char	*ft_strdup1(const char *s1);

void	sa_bonus(t_list **sa);
void	sb_bonus(t_list **sb);
void	pb_bonus(t_list **stack_a, t_list **stack_b);
void	pa_bonus(t_list **stack_b, t_list **stack_a);
void	ra_bonus(t_list **ra);
void	rb_bonus(t_list **rb);
void	rra_bonus(t_list **rra);
void	rrb_bonus(t_list **rrb);
void	ss_bonus(t_list **sa, t_list **sb);
void	rrr_bonus(t_list **rra, t_list **rrb);
void	rr_bonus(t_list **ra, t_list **rb);

char	*chock_read(int fd, char *handel);
char	*get_file_rest(char *buffer);
char	*get_line(char *buffer);
char	*get_next_line(int fd);

void	ft_print_ko(t_list *copy);
void	ft_print_ko2(t_list **stack_a, t_list **stack_b);
void	ft_print_ok(t_list *copy);
void	ft_free_get_and_stack(char *line, t_list *stack_a);
int		ft_sizeff(t_list *stack);

#endif
