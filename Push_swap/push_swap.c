#include "push_swap.h"

void	calc_atob(t_list **a, t_list **b, t_info *info, int *cnt)
{
	if ((*info).pivot1 <= (*a)->value)
	{
		rotate(a, 'a', cnt);
		(*info).ra++;
	}
	else
	{
		push_ab(a, b, 'b', cnt);
		(*info).pb++;
		if ((*info).pivot2 <= (*b)->value)
		{
			rotate(b, 'b', cnt);
			(*info).rb++;
		}
	}
}

void	atob(t_list **a, t_list **b, int n, int *cnt)
{
	t_info	info;

	if (check_atob(a, b, n, cnt))
		return ;
	info.pivot1 = find_pivot(find_min(a, n), find_max(a, n), (double)2 / 3);
	info.pivot2 = find_pivot(find_min(a, n), info.pivot1, (double)1 / 2);
	info.ra = 0;
	info.rb = 0;
	info.pb = 0;
	while (n--)
	{
		calc_atob(a, b, &info, cnt);
	}
	rrr(a, b, info, cnt);
	atob(a, b, info.ra, cnt);
	btoa(b, a, info.rb, cnt);
	btoa(b, a, info.pb - info.rb, cnt);
}

void	calc_btoa(t_list **b, t_list **a, t_info *info, int *cnt)
{
	if ((*info).pivot2 > (*b)->value)
	{
		rotate(b, 'b', cnt);
		(*info).rb++;
	}
	else
	{
		push_ab(b, a, 'a', cnt);
		(*info).pa++;
		if ((*info).pivot1 > (*a)->value)
		{
			rotate(a, 'a', cnt);
			(*info).ra++;
		}
	}
}

void	btoa(t_list **b, t_list **a, int n, int *cnt)
{
	t_info	info;

	if (check_btoa(b, a, n, cnt))
		return ;
	info.pivot1 = find_pivot(find_min(b, n), find_max(b, n), (double)2 / 3);
	info.pivot2 = find_pivot(find_min(b, n), info.pivot1, (double)1 / 2);
	info.ra = 0;
	info.rb = 0;
	info.pa = 0;
	while (n--)
	{
		calc_btoa(b, a, &info, cnt);
	}
	atob(a, b, info.pa - info.ra, cnt);
	rrr(a, b, info, cnt);
	atob(a, b, info.ra, cnt);
	btoa(b, a, info.rb, cnt);
}
