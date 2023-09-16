# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 23:33:44 by oaoba             #+#    #+#              #
#    Updated: 2023/09/11 00:05:41 by oaoba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

#thread_flag = -g3 -fsanitize=thread

#CFLAGS = -Wall -Werror -Wextra -pthread $(thread_flag)
CFLAGS = -Wall -Werror -Wextra -pthread

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
