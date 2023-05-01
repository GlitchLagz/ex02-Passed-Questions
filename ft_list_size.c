#include <stdlib.h>
typedef struct s_list
{
	struct s_list *next;
	void	*data;
}			t_list;

int	ft_list_size(t_list *begin_list)
{
	if(begin_list)
		return((1+ft_list_size(begin_list->next)));
}
