int main(int ac, char **av)
{
    if (ac != 5 || ac != 6)
        return (ft_error("Error: wrong numbers of arguments \n"));
    if (init(ac, av))
        return (ft_error("Error: wrong arguments \n"));
}