# ******************* #
# VARIABLES
# ******************* #

NAME            := libasm.a

NASM            := nasm
NASMFLAGS       := -f elf64

AR              := ar
ARFLAGS         := rcs

RM              := rm -f

SRCS_DIR        := srcs
OBJS_DIR        := objs

SRCS            := \
    $(SRCS_DIR)/ft_strlen.s \
    $(SRCS_DIR)/ft_strcpy.s \
    $(SRCS_DIR)/ft_strcmp.s \
    $(SRCS_DIR)/ft_write.s  \
    $(SRCS_DIR)/ft_read.s   \
    $(SRCS_DIR)/ft_strdup.s

OBJS            := $(SRCS:$(SRCS_DIR)/%.s=$(OBJS_DIR)/%.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

# Construit la lib uniquement si un .o a changé
$(NAME): $(OBJS)
	$(RM) $@
	$(AR) $(ARFLAGS) $@ $^

# Compile uniquement le .s concerné en .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.s | $(OBJS_DIR)
	$(NASM) $(NASMFLAGS) -o $@ $<

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) test ./tmp.txt

re: fclean all

test: all
	gcc tests/main.c tests/ft_strlen.c tests/ft_strcpy.c tests/ft_strcmp.c tests/ft_strdup.c tests/ft_write.c tests/ft_read.c -L . -lasm -I . -o test
	./test