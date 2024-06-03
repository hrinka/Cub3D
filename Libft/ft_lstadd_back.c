/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:44:34 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/07 23:48:20 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast (*lst);
		last->next = new;
	}
}

// int main (){
// 	char test1[] = "tkodai";
// 	char test2[] = "kawamoto";
// 	char test3[] = "aosato";
// 	t_list *a;
// 	a = ft_lstnew(test1);
// 	ft_lstadd_back(&a, ft_lstnew(test2));
// 	ft_lstadd_back(&a, ft_lstnew(test3));
// 	while (a)
// 	{
// 		printf("test lstnew = %s\n",(char *)a->content);
// 		a = a->next;
// 	}
// 	return(0);
// }