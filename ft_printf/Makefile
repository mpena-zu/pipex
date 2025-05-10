NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SOURCES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf_u.c ft_hexa.c ft_hexa_upper.c \
			ft_printf_p.c

OBJECTS = $(SOURCES:.c=.o)

GREEN = \033[0;32m
NC = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m
TOTAL_OBJ = $(words $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@$(MAKE) -s progress
	@echo ""
	@echo "$(GREEN)¡Compilación ft_printf completada!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(MAKE) -s progress

clean:
	@$(RM) $(OBJECTS)
	@echo "$(YELLOW)¡Dejamos todo preparado para el ft_printf!$(NC)"

fclean:
	@$(RM) $(OBJECTS) $(NAME)
	@echo "$(RED)¡Todo limpio del ft_printf!$(NC)"

re: fclean all

progress:
	@$(eval COMPLETED = $(shell ls -1 $(OBJECTS) 2>/dev/null | wc -l))
	@$(eval PERCENTAGE = $(shell echo "scale=2; 100 * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval BAR_LENGTH = 50)
	@$(eval FILLED_LENGTH = $(shell echo "$(BAR_LENGTH) * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval EMPTY_LENGTH = $(shell echo "$(BAR_LENGTH) - $(FILLED_LENGTH)" | bc))
	@echo -n "$(GREEN)["
	@$(eval BAR = $(shell yes "=" | head -n $(FILLED_LENGTH) | tr -d '\n'))
	@$(eval EMPTY = $(shell yes " " | head -n $(EMPTY_LENGTH) | tr -d '\n'))
	@echo -n "$(BAR)$(EMPTY)"
	@echo -n "] $(PERCENTAGE)%"
	@echo -n "\r"
	@sleep 0.05

.PHONY: all clean fclean re progress
