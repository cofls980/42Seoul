#include "../includes/so_long.h"

//추가: 맵 유효한지, 유효하다면 makeMap & fillMap
char **makeMap(int width, int height)
{
    char **map;
    int mh;

    mh = -1;
    map = (char **)malloc(sizeof(char *) * (height + 1));
    while (++mh < width)
        map[mh] = (char *)malloc(sizeof(char) * (width + 1));
    return (map);
}

void fillMap(char **map, int fd)
{
    char c;
    int tmp_w;
    int mw;
    int mh;

    mw = 0;
    mh = 0;
    while (read(fd, &c, 1) > 0)
    {
        if (c == '\n')
        {
            mh++;
            mw = 0;
        }
        else
        {
            map[mh][mw] = c;
            mw++;
        }
    }
}

//1. 벽으로 둘러싸여있는지
//2. 최소 하나의 출구와 콜렉션과 플레이어가 있어야한다.
int mapValidWall(t_mlx *mlx, int fd) // 정상이면 map이 정상적으로 만들어짐.
{
    int P; //1이어야함
    int E; //1이상이어야함
    int C; //1이상이어야함
    int mh;
    int mw;

    mlx->map = makeMap(mlx->map_width, mlx->map_height);
    fillMap(mlx->map, fd);
    P = 0;
    E = 0;
    C = 0;
    mh = -1;
    while (++mh < mlx->map_height)
    {
        mw = -1;
        while (++mw < mlx->map_width)
        {
            if (mh == 0 || mh == mlx->map_height - 1)
            {
                if (mlx->map[mh][mw] != '1')
                    return (0);
            }
            else if (mw == 0 || mw == mlx->map_width - 1)
            {
                if (mlx->map[mh][mw] != '1')
                    return (0);
            }
            if (mlx->map[mh][mw] == 'P')
                P++;
            else if (mlx->map[mh][mw] == 'C')
                C++;
            else if (mlx->map[mh][mw] == 'E')
                E++;
            printf("%c ", mlx->map[mh][mw]);
        }
        printf("\n");
    }
    printf("%d, %d, %d\n", P, E, C);
    if (!(P == 1 && E > 0 && C > 0)) //free 필요
        return (0);
    return (1);
}

//3. 맵이 사각형인지 -> 높이가 최소 3이어야함.
int mapValidShape(t_mlx *mlx, int fd) // 정상이면 맵 사이즈 구해짐.
{
    int mw;
    int mh;
    int comp_width;
    char c;

    mw = 0;
    mh = 0;
    while (read(fd, &c, 1) > 0)
    {
        if (c == '\n')
        {
            if (mh == 0)
                comp_width = mw;
            else if (comp_width != mw)
                return (0);
            mh++;
            mw = 0;
        }
        else
            mw++;
    }
    if (++mh < 3 || comp_width != mw)
        return (0);
    mlx->map_width = comp_width;
    mlx->map_height = mh;
    return (1);
}