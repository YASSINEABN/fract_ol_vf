CC = cc
CFLAGS = -Wall -Werror -Wextra 
NAME = fractol
SRC = fract_ol.c render_Mandelbrot.c utils.c render_julia.c render_burning.c events.c check_julia.c
OBJS = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
  
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
