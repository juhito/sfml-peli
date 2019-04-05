EXE = timber
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FILES = timber.cc engine.cc assets.cc
all: run

run : $(FILES)
	g++ -o $(EXE) $(FILES) $(LDFLAGS) && ./$(EXE)
