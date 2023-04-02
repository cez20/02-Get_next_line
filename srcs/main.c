#include "get_next_line.h"

int main()
{
    char *str = NULL;
    int fd;

    fd = open("./docs/example.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        write(1, str, ft_strlen(str));
        str = get_next_line(fd);
    }

    return (0);
}