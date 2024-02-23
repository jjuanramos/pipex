/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:11:10 by juramos           #+#    #+#             */
/*   Updated: 2023/10/02 13:32:21 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}
/*
int	main(void)
{
	char		*val;
	char		*val2;
	t_list	*t;
	t_list	*t2;

	val = "Goodbye";
	t = ft_lstnew(val);
	val2 = "Hello";
	t2 = ft_lstnew(val2);
	printf("value of t before: %s for content, %s for next.\n",
		(char *)(t->content), (char *)(t->next));
	printf("value of t2 before: %s for content, %s for next.\n",
		(char *)(t2->content), (char *)(t2->next));
	printf("Length of t: %i. Length of t2: %i.\n", ft_lstsize(t), ft_lstsize(t2));
	ft_lstadd_front(&t, t2);
	printf("value of t after: %s for content, %s for next.\n",
		(char *)(t->content), (char *)((t->next)->content));
	printf("value of t2 after: %s for content, %s for next.\n",
		(char *)(t2->content), (char *)((t2->next)->content));
	printf("Length of t: %i. Length of t2: %i.\n", ft_lstsize(t), ft_lstsize(t2));
}
*/