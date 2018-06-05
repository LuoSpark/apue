
CC = g++
PROM = test
SOURCE = $(shell find ./ -name "*.cpp")
INCLUDES = $(shell find ./ -name "*.h")
LIBS = pthread
OBJS = $(SOURCE:%.cpp=%.o)
CFLAGS = -g -Wall 

$(PROM):$(OBJS)
	$(CC) -o $(PROM) $(OBJS) $(addprefix -l,$(LIBS))

%.o:%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm  -f $(OBJS) $(PROM)
