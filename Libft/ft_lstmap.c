/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:55:33 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/10 02:44:13 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(f) || !(del))
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&tmp, ft_lstnew((f)(lst->content)));
		if (tmp == NULL)
			ft_lstclear(&tmp, (del));
		lst = lst->next;
	}
	return (tmp);
}

// void *ft_voidtoupper(void *p)
// {
// 	char *str = (char *)p;
//     while (*str)
//     {
//         *str = toupper(*str);
//         str++;
//     }
// 	return (p);
// }

// void	ft_test(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	printf("\nTEST START!\n");
// 	ft_lstmap(lst,(f),(del));
// 	while (lst)
// 	{
// 		printf("test lst = %s\n",(char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return ;
// }

// int main(){
// 	char test1[] = "tkodai";
// 	char test2[] = "destroys the programs";
// 	char test3[] = "with a smile";
// 	t_list *lst;
// 	lst = ft_lstnew(test1);
// 	ft_lstadd_back(&lst, ft_lstnew(test2));
// 	ft_lstadd_back(&lst, ft_lstnew(test3));
// 	ft_test(lst,ft_voidtoupper,free);
// 	return(0);
// }
