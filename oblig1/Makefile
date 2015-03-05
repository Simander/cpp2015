GCC=g++
CCOPT=-std=c++11

# Add more as you please
OBJECTS=blackjack.o dealer.o player.o card.o deck.o

# Name of the final binary
EXEC=blackjack

all: $(OBJECTS)
	$(GCC) $(CCOPT) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(GCC) $(CCOPT) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXEC)
