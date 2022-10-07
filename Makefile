NAME = libftprintf.a
SRCS = 	ft_printf.c \
		ft_putnbr.c \
		ft_putstr.c 

BONUS = ft_printf.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_bonus.c \
		ft_atoi.c

GCC = gcc -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

BNOBJ = $(BONUS:.c=.o)

LIB = ar -crs

DEL = rm -rf

%o: %c 
	$(GCC) -c $< -o $@ 

all: $(NAME)
	
$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

bonus: $(OBJS) $(BNOBJ) 
	$(LIB) $(NAME) $(OBJS) $(BNOBJ)

clean:
	$(DEL) $(OBJS) $(BNOBJ)

fclean: clean
	$(DEL) $(NAME) 

re: fclean all

.PHONY: bonus clean fclean all re