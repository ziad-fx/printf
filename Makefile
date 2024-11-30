CC = cc 
NAME =  libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_num.c functions.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rc
RM = rm -f
%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o  ${<:.c=.o}
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
all: ${NAME}
bonus : all
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME} 

re: fclean all