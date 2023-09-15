CCOPTIONS = -Wall -ggdb 
CC = g++ $(CCOPTIONS)
LDFLAGS  =
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = -Isrc

all: $(BIN_DIR)/mainTXT

$(OBJ_DIR)/winTXT.o: $(SRC_DIR)/winTXT.cpp $(SRC_DIR)/winTXT.h
	$(CC) -c $(SRC_DIR)/winTXT.cpp -o $(OBJ_DIR)/winTXT.o

$(BIN_DIR)/mainTXT: $(OBJ_DIR)/mainTXT.o $(OBJ_DIR)/Personnage.o  $(OBJ_DIR)/Terrain.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/winTXT.o
	$(CC) $(OBJ_DIR)/mainTXT.o $(OBJ_DIR)/Personnage.o  $(OBJ_DIR)/Terrain.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/winTXT.o  -o $(BIN_DIR)/mainTXT $(LDFLAGS)

$(OBJ_DIR)/Terrain.o: $(SRC_DIR)/Terrain.cpp $(SRC_DIR)/Terrain.h
	$(CC) -c $(SRC_DIR)/Terrain.cpp -o $(OBJ_DIR)/Terrain.o

$(OBJ_DIR)/Personnage.o: $(SRC_DIR)/Personnage.cpp $(SRC_DIR)/Personnage.h $(SRC_DIR) $(SRC_DIR)/Vecteur.h
	$(CC) -c $(SRC_DIR)/Personnage.cpp -o $(OBJ_DIR)/Personnage.o

$(OBJ_DIR)/Jeu.o: $(SRC_DIR)/Jeu.cpp $(SRC_DIR)/Jeu.h $(SRC_DIR)/Terrain.h $(SRC_DIR)/Personnage.h
	$(CC) -c $(SRC_DIR)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o

$(OBJ_DIR)/mainTXT.o: $(SRC_DIR)/mainTXT.cpp $(SRC_DIR)/Jeu.h $(SRC_DIR)/winTXT.h
	$(CC) -c $(SRC_DIR)/mainTXT.cpp -o $(OBJ_DIR)/mainTXT.o

clean:
	rm $(OBJ_DIR)/*.o

veryclean:
	rm $(BIN_DIR)/*