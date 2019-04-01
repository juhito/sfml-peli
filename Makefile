EXE = peli
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
FILES =
all: run

run : $(FILES)
	g++ -o $(EXE) $(FILES) $(LDFLAGS) && ./$(EXE)
