CC = cc
FLAGS = -Wall -Wextra -Werror -g

PRNTDIR = ..
SRCDIR = srcs 
INCDIR = includes 
BINDIR = bin
TESTDIR = tests
LIBFT = ../libft.h

FT_EXE = $(addprefix $(BINDIR)/ft_,toupper tolower isdigit isascii isalnum isalpha isprint atoi strlen strdup)
SYS_EXE = $(addprefix $(BINDIR)/sys_,toupper tolower isdigit isascii isalnum isalpha isprint atoi strlen strdup)
RND_EXE = $(BINDIR)/gen_rand_int $(BINDIR)/gen_rand_str

all: $(BINDIR) $(FT_EXE) $(SYS_EXE) $(RND_EXE)

$(BINDIR):
	mkdir bin

# Rules for compiling libft functions

$(BINDIR)/ft_toupper: $(PRNTDIR)/ft_toupper.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_toupper $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_tolower: $(PRNTDIR)/ft_tolower.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_tolower $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_isdigit: $(PRNTDIR)/ft_isdigit.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_isdigit $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_isascii: $(PRNTDIR)/ft_isascii.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_isascii $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_isalnum: $(PRNTDIR)/ft_isalnum.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_isalnum $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_isalpha: $(PRNTDIR)/ft_isalpha.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_isalpha $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_isprint: $(PRNTDIR)/ft_isprint.c $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_isprint $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_atoi: $(PRNTDIR)/ft_atoi.c $(TESTDIR)/test2.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_atoi $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_strlen: $(PRNTDIR)/ft_strlen.c $(TESTDIR)/test2.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_strlen $^ $(LIBFT) -o $@ -I $(INCDIR)

$(BINDIR)/ft_strdup: $(PRNTDIR)/ft_strdup.c $(TESTDIR)/test3.c
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_strdup $^ $(PRNTDIR)/ft_strlen.c $(LIBFT) -o $@ -I $(INCDIR)

# Rules for compiling system functions

$(BINDIR)/sys_toupper: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=toupper $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_tolower: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=tolower $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_isdigit: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=isdigit $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_isascii: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=isascii $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_isalnum: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=isalnum $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_isalpha: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=isalpha $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_isprint: $(TESTDIR)/test1.c
	$(CC) $(FLAGS) -DFT=isprint $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_atoi: $(TESTDIR)/test2.c
	$(CC) $(FLAGS) -DFT=atoi $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_strlen: $(TESTDIR)/test2.c
	$(CC) $(FLAGS) -DFT=strlen $^ -o $@ -I $(INCDIR)

$(BINDIR)/sys_strdup: $(TESTDIR)/test3.c
	$(CC) $(FLAGS) -DFT=strdup $^ -o $@ -I $(INCDIR)

# Rules for compiling random string/int generator

$(BINDIR)/gen_rand_int: srcs/gen_rand_int.c
	$(CC) $(FLAGS) $< -o $@ -I $(INCDIR)

$(BINDIR)/gen_rand_str: srcs/gen_rand_str.c
	$(CC) $(FLAGS) $< -o $@ -I $(INCDIR)

.PHONY: tests clean

tests:
	bash ./tests/run_tests_1.sh
	bash ./tests/run_tests_1_1.sh
	bash ./tests/run_tests_2.sh
	bash ./tests/run_tests_2_1.sh

clean:
	rm -rf $(BINDIR)
