echo "---10---"
gcc -g3 -fsanitize=address push_swap.c checker.c ./srcs/libft_list.c ./srcs/operations.c ./srcs/numbers.c && ./a.out 19 20 22 21 54