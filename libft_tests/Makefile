CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCDIR = ..
AUXDIR = aux
INCDIR = includes
BINDIR = bin
TESTDIR = tests

# Extract function name from path
RAW_FUNC := $(shell echo $($(BINDIR)/%) | sed 's|bin/ft_||')
FT_FUNC := $(shell echo $($(BINDIR)/%) | sed 's|bin/||')
SYS_FUNC := $(shell echo $($(BINDIR)/%) | sed 's|bin/ft_|bin/sys_|')

# Source files
SRC1 = $(SRCDIR)/ft_toupper.c $(SRCDIR)/ft_tolower.c $(SRCDIR)/ft_isprint.c $(SRCDIR)/ft_isascii.c $(SRCDIR)/ft_isalnum.c $(SRCDIR)/ft_isdigit.c $(SRCDIR)/ft_isalpha.c
TEST1 = $(TESTDIR)/test1.c
RND_GEN = $(AUXDIR)/gen_rand_int.c $(AUXDIR)/gen_rand_str.c

# Executables
EXE1_FT = $(BINDIR)/ft_toupper $(BINDIR)/ft_tolower $(BINDIR)/ft_isprint $(BINDIR)/ft_isascii $(BINDIR)/ft_isalnum $(BINDIR)/ft_isdigit $(BINDIR)/ft_isalpha
EXE1_SYS = $(BINDIR)/sys_toupper $(BINDIR)/sys_tolower $(BINDIR)/sys_isprint $(BINDIR)/sys_isascii $(BINDIR)/sys_isalnum $(BINDIR)/sys_isdigit $(BINDIR)/sys_isalpha
RND_EXE = $(BINDIR)/gen_rand_int $(BINDIR)/gen_rand_str

all: $(EXE1_FT) $(EXE1_SYS) $(RND_EXE)

$(BINDIR)/%: $(AUXDIR)/%.c
	$(CC) $(FLAGS) $< -o $@ -I $(INCDIR)

$(BINDIR)/%: $(SRCDIR)/%.c 
	$(CC) $(FLAGS) -DUSE_FT -DFT=$(FT_FUNC) $< $(TEST1) -o $@ -I $(INCDIR)

$(EXE1_SYS):
	$(CC) $(FLAGS) -DFT=$(RAW_FUNC) $(TEST1) -o $@ -I $(INCDIR)

.PHONY: tests
tests:
	bash ./bash/run_tests_1.sh

clean:
	rm -f $(EXE1_FT) $(EXE1_SYS) $(RAND) $(RND_EXE)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(NAME)
