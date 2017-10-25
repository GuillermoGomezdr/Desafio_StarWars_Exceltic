C = g++
IDIR = ../include
DDIR = ../dist
TARGET = desafioSW

CFLAGS = -g -I$(IDIR)

DEPS = $(wildcard $(IDIR)/*.h)
OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean dist

clean: 
	$(RM) *.o

dist: $(TARGET) clean
	mv $(TARGET) $(DDIR)
