/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:02:29 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/09 09:02:27 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !(f))
		return ;
	while (lst != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}

// void ft_voidtoupper(void *p)
// {
// 	char *str = (char *)p;
//     while (*str)
//     {
//         *str = toupper(*str);
//         str++;
//     }
// }

// void	ft_test(t_list *lst, void (*f)(void *))
// {
// 	printf("\nTEST START!\n");
// 	ft_lstiter(lst, (f));
// 	while (lst)
// 	{
// 		printf("test lst = %s\n",(char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return ;
// }

// int main (){
// 	char test1[] = "tkodai";
// 	char test2[] = "kakawamo";
// 	t_list *lst;
// 	lst = ft_lstnew(test1);
// 	ft_test(lst,ft_voidtoupper);
// 	ft_lstadd_back(&lst, ft_lstnew(test2));
// 	ft_test(lst,ft_voidtoupper);
// 	return(0);
// }
