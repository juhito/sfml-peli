EXE = timber
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FILES = timber.cc game.cc assets.cc window.cc player.cc text.cc
all: run

run : $(FILES)
	g++ -o $(EXE) $(FILES) $(LDFLAGS) && ./$(EXE)
