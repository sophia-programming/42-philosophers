NAME = philo

srcs = ./dining_actions.c \
		init.c \
		 main.c \
		 monitor.c \
		 only_one_philosopher.c \
		 print_actions.c \
		 routine.c \
		 thread.c \
		 time.c \
		 utils.c \
		 error_handling.c

thread_flag = -g3 -fsanitize=thread

CFLAGS = -Wall -Werror -Wextra -pthread $(thread_flag)

objs = $(srcs:.c=.o)

all: $(NAME)

$(NAME): $(objs)
	cc $(CFLAGS) $(objs) -o $(NAME)
	
clean:
	$(RM) $(objs)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

## basic testcase
test: re
	echo 'should die'
	./philo 1 800 200 200 #die

test2: re
	echo 'should loop'
	./philo 5 800 200 200 #loop

test3: re
	echo 'should die about 3500'
	./philo 5 800 200 200 7 #die about 3500

test4: re
	echo 'should loop'
	./philo 4 410 200 200  #loop

test5: re
	echo 'should die about 310'
	./philo 4 310 200 100 #die about 310

## too many philosophers(over 200)
error: re
	echo 'should do nothing'
	./philo 200 310 200 100

## argv[x] <= 0
error2: re
	echo 'should do nothing'
	./philo -1 300 100 100

## invalid argc.
error3: re
	echo 'print usage'
	./philo 5 300 200 100 3 3

error4:	re
	echo 'print message'
	./philo 5 3h0 200 100
.PHONY: test test2 test3 test4 test5 error error2 error3 error4
