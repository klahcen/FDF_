Green = \033[0;32m
Red = \033[0;31m

src		=	main.c get_next_line.c get_next_line_utils.c ft_split.c ft_atoi.c\
			ft_read_map.c draw_maps.c ft_key.c ft_zoom.c song.c

b_src	=	main_bonus.c get_next_line.c get_next_line_utils.c ft_split.c ft_atoi.c\
			ft_read_map.c draw_maps.c ft_key.c ft_zoom.c song.c
			
OBJ		=	${src:.c=.o}
B_OBJ	=	${b_src:.c=.o}
CFLAG	= 	-Wall -Wextra -Werror
NAME	=	fdf
BONUS 	= 	fdf_bonus

 all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAG) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "🤝🏿 🛠 $(Green)Mandatory part"

bonus: $(BONUS)

$(BONUS): $(B_OBJ)
	@$(CC) $(B_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)
	@echo "🤝🏿 🛠 $(Green)Bonus part"

clean:
	@rm -rf $(OBJ) $(B_OBJ)
	@echo "🗑   $(Red)remove"
fclean: clean
	@rm -rf $(NAME) $(BONUS)
	
re: fclean all

.PHONY: all re fclean clean bonus