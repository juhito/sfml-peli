EXE = peli
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
FILES = main.cc
all: run

run : $(FILES)
	g++ -o $(EXE) $(FILES) $(LDFLAGS) && ./$(EXE)
