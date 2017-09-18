CC=g++
CFLAGS=-Wall
EXEC_NAME=shmup.app
INCLUDES=-I/usr/include/SFML -I.
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES=Main.o Enemy.o Entity.o Freekazoid.o Polaroid.o Projectile.o Spatialship.o Vehicle.o Explosion.o Game.o
INSTALL_DIR=/usr/bin

all: $(EXEC_NAME)

clean:
	rm -rf $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME): $(OBJ_FILES)
	@echo "** Building the game"
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install:
	cp $(EXEC_NAME) $(INSTALL_DIR)
