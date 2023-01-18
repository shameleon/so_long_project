# so_long
so_long project for 42 Paris : create a small 2D-game

## minilibx
### links :
![minilibx tutorial : 42 docs](https://harm-smits.github.io/42docs/libs/minilibx)

### small example as starter
Global in the .h file

```c
#define WIN_W 1800
#define WIN_H 800
#define WIN_TITLE "explore mlx"
#define ERR_MLX 1
```

Data is in a t_type datatype in the .h file     
```c
typedef struct s_data
{
    void    *mlx;
    void    *win;
}              t_data;

```
basic to create and open a window 
```c
int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    if (data.mlx == NULL)
        return (ERR_MLX);
    data.win = mlx_new_window(data.mlx, WIN_H, WIN_H, WIN_TITLE);
    if (data.win == NULL)
    {
        free (data.win);
        return (ERR_MLX);
    }
    mlx_loop(data.mlx);
    mlx_destroy_window(data.mlx, data.win);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
    return (0);
}
```
