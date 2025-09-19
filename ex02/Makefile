NAME := operator

### SRCS #######################################################################

PATH_SRCS := srcs

SRCS += main.cpp
SRCS += Fixed.cpp

vpath %.cpp $(PATH_SRCS)

### OBJS #######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.cpp, $(PATH_OBJS)%.o, $(SRCS))

### HEADER #####################################################################

PATH_INCLUDES += includes

### COMPILATION ################################################################

COMPILATION := c++
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Werror
CXXFLAGS += -std=c++98

## RULES #######################################################################

all: $(NAME)

$(OBJS): $(PATH_OBJS)%.o: %.cpp
		mkdir -p $(PATH_OBJS)
		$(COMPILATION) $(CXXFLAGS) -c $< -o $@ -I $(PATH_INCLUDES)

$(NAME): $(OBJS)
		$(COMPILATION) $(CXXFLAGS) $(OBJS) -o $(NAME) -I $(PATH_INCLUDES)

clean:
		$(RM) -r $(PATH_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
