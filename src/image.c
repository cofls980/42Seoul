#include "../includes/so_long.h"

void texture_init(t_mlx *mlx)
{
    int img_width;
    int img_height;

    mlx->txt.wall_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "texture/tree.xpm", &img_width, &img_height);
    mlx->txt.space_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "texture/tile1.xpm", &img_width, &img_height);
    mlx->txt.player_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "texture/player.xpm", &img_width, &img_height);
    mlx->txt.exit_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "texture/exit.xpm", &img_width, &img_height);
    mlx->txt.collection_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "texture/collection.xpm", &img_width, &img_height);
}

void put_image(t_mlx *mlx, int mh, int mw)
{
    if (mlx->map[mh][mw] == '1')
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->txt.wall_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    }
    else if (mlx->map[mh][mw] == '0')
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->txt.space_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    }
    else if (mlx->map[mh][mw] == 'C')
    {
        mlx->collect_cnt++;
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->txt.collection_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    }
    else if (mlx->map[mh][mw] == 'E')
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->txt.exit_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    }
    else if (mlx->map[mh][mw] == 'P')
    {
        mlx->ply.x = mw;
        mlx->ply.y = mh;
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->txt.player_ptr, mw * IMG_SIZE, mh * IMG_SIZE);
    }
}

void map_draw(t_mlx *mlx)
{
    int mh;
    int mw;

    mlx->collect_cnt = 0;
    mh = -1;
    while (++mh < mlx->map_height)
    {
        mw = -1;
        while (++mw < mlx->map_width)
            put_image(mlx, mh, mw);
    }
}