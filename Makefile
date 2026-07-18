CC = g++
CFLAGS = -g -std=c++20 -Iinclude -Wall -Wextra # -Werror
# LFLAGS = 

BINDIR = bin
SRCDIR = src
INCDIR = include
LIBDIR = lib

# Locate files
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRC))

TARGET = $(BINDIR)/app

all: $(TARGET)

# Build Rules
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBDIR) -lmingw32 -lSDL3 -lSDL3_mixer -lSDL3_image -lSDL3_ttf

$(BINDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	rm $(BINDIR)/*.o -rf

run: $(BINDIR)/app.exe
	./$(BINDIR)/app.exe

