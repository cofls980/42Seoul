#include "../includes/so_long.h"

void imageBack(t_mlx *param, int mw, int mh)
{
    if (param->map[mh][mw] == '0' || param->map[mh][mw] == 'P')
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.space_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    else if (param->map[mh][mw] == 'E')
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.exit_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    else if (param->map[mh][mw] == 'C')
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.space_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
}

void key_W(t_mlx *param)
{
    int mh;
    int mw;

    mh = param->ply.y;
    mw = param->ply.x;
    if (mh - 1 > 0 && param->map[mh - 1][mw] != '1')
    {
        if (param->map[mh - 1][mw] == 'E' && param->collect_cnt == 0)
            exit(0);
        else if (param->map[mh - 1][mw] == 'C')
        {
            param->map[mh - 1][mw] == '0';
            param->collect_cnt--;
        }
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.player_ptr, mw * IMG_SIZE, (mh - 1) * IMG_SIZE);
        imageBack(param, mw, mh);
        param->ply.y--;
        param->count++;
        printf("COUNT: %d\n", param->count);
    }
}

void key_S(t_mlx *param)
{
    int mh;
    int mw;

    mh = param->ply.y;
    mw = param->ply.x;
    if (mh + 1 < param->map_height - 1 && param->map[mh + 1][mw] != '1')
    {
        if (param->map[mh + 1][mw] == 'E' && param->collect_cnt == 0)
            exit(0);
        else if (param->map[mh + 1][mw] == 'C')
        {
            param->map[mh + 1][mw] = '0';
            param->collect_cnt--;
        }
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.player_ptr, mw * IMG_SIZE, (mh + 1) * IMG_SIZE);
        imageBack(param, mw, mh);
        param->ply.y++;
        param->count++;
        printf("COUNT: %d\n", param->count);
    }
}

void key_A(t_mlx *param)
{
    int mh;
    int mw;

    mh = param->ply.y;
    mw = param->ply.x;
    if (mw - 1 > 0 && param->map[mh][mw - 1] != '1')
    {
        if (param->map[mh][mw - 1] == 'E' && param->collect_cnt == 0)
            exit(0);
        else if (param->map[mh][mw - 1] == 'C')
        {
            param->map[mh][mw - 1] = '0';
            param->collect_cnt--;
        }
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.player_ptr, (mw - 1) * IMG_SIZE, mh * IMG_SIZE);
        imageBack(param, mw, mh);
        param->ply.x--;
        param->count++;
        printf("COUNT: %d\n", param->count);
    }
}

void key_D(t_mlx *param)
{
    int mh;
    int mw;

    mh = param->ply.y;
    mw = param->ply.x;
    if (mw + 1 < param->map_width - 1 && param->map[mh][mw + 1] != '1')
    {
        if (param->map[mh][mw + 1] == 'E' && param->collect_cnt == 0)
            exit(0);
        else if (param->map[mh][mw + 1] == 'C')
        {
            param->map[mh][mw + 1] = '0';
            param->collect_cnt--;
        }
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->txt.player_ptr, (mw + 1) * IMG_SIZE, mh * IMG_SIZE);
        imageBack(param, mw, mh);
        param->ply.x++;
        param->count++;
        printf("COUNT: %d\n", param->count);
    }
}

int		key_press(int keycode, t_mlx *param)// player W, A, S, D keys
{
    //printf("key: %d\n", keycode);
	if (keycode == KEY_W)
        key_W(param);
	else if (keycode == KEY_S)
        key_S(param);
	else if (keycode == KEY_A)
        key_A(param);
	else if (keycode == KEY_D)
        key_D(param);
	else if (keycode == KEY_ESC)
	{
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        exit(0);
    }
	//printf("x: %d, y: %d\n", param->ply.x, param->ply.y);
	return (0);
}