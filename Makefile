NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SOURCES = pipex.c pipex_utils.c main.c

OBJECTS = $(SOURCES:.c=.o)

GREEN = \033[0;32m
NC = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m
TOTAL_OBJ = $(words $(OBJECTS))

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) --no-print-directory

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@$(MAKE) -s progress
	@echo ""
	@echo "$(GREEN)¡Compilación del pipex completada!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(MAKE) -s progress

clean:
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@$(RM) $(OBJECTS)
	@echo "$(YELLOW)¡Dejamos todo preparado para el pipex!$(NC)"

fclean:
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@$(RM) $(OBJECTS) $(NAME)
	@echo "$(RED)¡Todo limpio del pipex!$(NC)"

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