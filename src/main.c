#include "../includes/so_long.h"

int button_press(t_mlx *mlx)
{
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    exit(0);
    return (0);
}

int valid(t_mlx *mlx, char *file)
{
    int fd[2];

    fd[0] = open(file, O_RDONLY);
    fd[1] = open(file, O_RDONLY);
    if (!mapValidShape(mlx, fd[0]))
    {
        close(fd[0]);
        return (0);
    }
    close(fd[0]);
    if (!mapValidWall(mlx, fd[1]))
    {
        close(fd[1]);
        return (0);
    }
    close(fd[1]);
    return (1);
}

int init(t_mlx *mlx, char *file)
{
    if (!valid(mlx, file))
        return (0);
    mlx->win_width = mlx->map_width * IMG_SIZE;
    mlx->win_height = mlx->map_height * IMG_SIZE;
    printf("[map] width: %d, height: %d\n", mlx->map_width, mlx->map_height);
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width, mlx->win_height, "so_long");
    texture_init(mlx);
    mlx->count = 0;
    return (1);
}

int main(int argc, char **argv)
{
    t_mlx mlx;

    if (argc != 2 || !init(&mlx, argv[1]))
    {
        printf("ERROR!\n");
        return (0);
    }
    map_draw(&mlx);
    mlx_hook(mlx.win_ptr, KeyPress_X_EVENT, KeyPress_X_MASK, &key_press, &mlx);
    mlx_hook(mlx.win_ptr, KeyExit_X_EVENT, LeaveWindowMask, &button_press, &mlx);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}