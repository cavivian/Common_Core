#ifndef FT_LIST_H
# define  FT_LIST_H
typedef struct s_list
{
    struct s_list *next;
    void *data;
}   t_list;

// typedef struct  s_point
//   {
//     int           x;
//     int           y;
//   }               t_point;

// typedef struct s_list
// {
// 	struct s_list *next;
// 	void		  *data;
// }				 t_list;

#endif
