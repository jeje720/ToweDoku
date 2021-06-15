
#include <stdio.h>
#include <stdlib.h>
/*          0       1       2       3   4       5           6       7       8      9
/rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left
row3left row4left row1right row2right row3right row4right"

 4324122243211222
 4324122243211222
 4324122243211222
*/

//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
//col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right

#define LENGHT_HEADER 4

typedef struct s_position{
    int left;    //up
    int right;  //down
} t_position;

typedef struct s_header_tower{
    t_position row;
    t_position col;
} t_header_tower;


int value_from_id(char *arg, int id)
{
    int i;
    int index;
    char *current;
    
    i = 0;
    index = 0;
    current = arg;
    

    while(arg[i] != '\0')
    {
        if(arg[i] > 48 && arg[i] < 53)
        {
            if(index ==  id)
                return (arg[i] - 48);
            index++;
        }

        i++;
    }   
}

int ft_parse(t_header_tower **header, char *arg)
{
    int i;
    int current_value;
    t_header_tower *current_header;


    current_header = malloc(sizeof(t_header_tower)* LENGHT_HEADER );

    if(current_header == NULL)
        return 0;


    i = 0;

    while( i < (LENGHT_HEADER * LENGHT_HEADER) ) 
    {
        current_value = value_from_id(arg, i);
        printf("%d ", current_value);

        if(i > 9)
            current_header[i % LENGHT_HEADER].row.right = current_value;
        else if( i > 6)
            current_header[i % LENGHT_HEADER].row.left = current_value;
        else if(i > 3)
            current_header[i % LENGHT_HEADER].col.right = current_value;
        else
            current_header[i % LENGHT_HEADER].col.left = current_value;

        i++;
    }

    *header = current_header;

    return i;
}

void print_game_test(t_header_tower* header, int **game)
{
    int heap;

    heap = 0;

    while(heap < (LENGHT_HEADER + 2))
    {
        if(heap == 0 || heap == 5)
            puts("   ");
        else
        {
            putchar(' ');
            putchar(header[heap-1].col.left + 48 );
            putchar(' ');
        }
        heap++;
    }
    putchar('\n');

    heap = 0;

    while(heap < (LENGHT_HEADER +2) )
    {
        if(heap == 0)
            
        else if(heap == 5)

        else
        {
            
        }
    }


    heap = 0;
    while(heap < (LENGHT_HEADER + 2))
    {
        if(heap == 0 || heap == 5)
            puts("   ");
        else
        {
            printf("%d", header[heap-1].col.right);
            putchar(' ');
            //putchar(header[heap-1].col.right);
            putchar(' ');
        }
        heap++;
    }

}


int create_game(int ***game, int default_Value)
{
    int **current;
    int i;
    
    current = malloc(sizeof(int *) * LENGHT_HEADER);
    i = 0;

    while(i < LENGHT_HEADER)
    {
        int y;

        current[i] = malloc(sizeof(int) * LENGHT_HEADER);

        if(current[i] == NULL) 
            return 0;
        
        while(y < LENGHT_HEADER)
        {
            current[i][y] = default_Value;
            y++;
        }

        i++;
    }

    *game = current;

    return 1;
}

int main(int argc, char **argv)
{

    t_header_tower* header;
    int **game;


    if(argc < 2)
    {
        puts("Error\n");
        return 1;
    }

    if(create_game(&game, 0) == 0)
    {
        puts("Error\n");
        return 1;
    }

    if(ft_parse(&header, argv[1]) == 0)
    {
        puts("Error\n");
        return 1;
    }

    print_game_test(header, game);

/*
    if(ft_find_solution(header, game))
    {

    }
*/

    free(header);
    return 0;
}