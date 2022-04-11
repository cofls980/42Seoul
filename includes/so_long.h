#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../minilibx-linux/mlx.h"//need to modify
#include <string.h> //delete
//system("leaks so_long > leaks_result; cat leaks_result; rm -rf leaks_result");

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define IMG_WIDTH 200
# define IMG_HEIGHT 400

# define IMG_SIZE 64

# define KEY_ESC		65307//53 need to modify
# define KEY_W			119//13 need to modify
# define KEY_A			97//0 need to modify
# define KEY_S			115//1 need to modify
# define KEY_D			100//2 need to modify

# define KeyPress_X_EVENT 02
# define KeyRelease_X_EVENT 03
# define ButtonPress_X_EVENT 04
# define ButtonRelease_X_EVENT 05
# define KeyExit_X_EVENT 17

# define KeyPress_X_MASK 1L<<0
# define LeaveWindowMask 1L<<5

typedef struct s_texture {
    void *wall_ptr;
    void *space_ptr;
    void *player_ptr;
    void *collection_ptr;
    void *exit_ptr;
} t_texture;

typedef struct s_player {
    int x;
    int y;
} t_player;

typedef struct s_mlx {
    t_texture txt;
    t_player ply;
    void *mlx_ptr; //mlx를 사용하기 위한 변수
    void *win_ptr; //윈도우를 띄우도록 하는 함수를 받는 변수
    int win_width;
    int win_height;
    int map_width;
    int map_height;
    int count;
    int collect_cnt;
    char **map;
} t_mlx;

int main(int argc, char **argv);
int				key_press(int keycode, t_mlx *param);
void mapSize(int *width, int *height, int fd);
char **makeMap(int width, int height);
void fillMap(char **map, int fd);
void texture_init(t_mlx *mlx);
void map_draw(t_mlx *mlx);
int mapValidWall(t_mlx *mlx, int fd);
int mapValidShape(t_mlx *mlx, int fd);

#endif