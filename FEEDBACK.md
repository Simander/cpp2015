# Oblig 1

### Resultat: 
Ikke godkjent / Lever på nytt


### Checklist:
* [] Begge programmen bygger med `make`.
* [] Begge programmen starter og kjører under Linux.
* [x] **oppvarming** gir riktig output.
* [] **blackjack** har det viktigeste funksjonaliteten.
	* [] En spiller har et saldo og kan satse et beløp.
	* [] En spiller har valgen "HIT" og "STAND".
	* [] En spiller kan ikke fortsette når den har gått tom for penger.
	* [] Dealerns handlinger virker riktige.
	* [] Spillet følger reglene til BlackJack.
* [] Ingen alvorlige kjøretidsfeil (segfault etc.)
* [] Ingen minnelekasjer funnet med `valgrind`.
* [/] Repo innholder `RAPPORT.md`.


### Tilbakemelding:

Makefile fungerer ikke; `Makefile:11: *** missing separator (did you mean TAB instead of 8 spaces?).  Stop.`. Dette er grunnet at det er brukt space i stedet for TAB i filen. 

Fikk rettet opp i dette, men får fortsatt feil for `blackjack.cpp` inkluderer filer som ikke eksisterer: 
	
`In file included from blackjack.cpp:2:0:
dealer.hpp:5:20: fatal error: deck.hpp: No such file or directory
 #include "deck.hpp"`
 
Rapporten er også noe svak. Ellers er det bra at du brukt klasser - din kode ser ryddig og fin ut! Men for å få teste spillet må disse tingen rettes opp i.

#### Fix:
* Rette opp i Makefile.
* Fjern include av `deck.hpp`, eller last opp de filene som mangler.
* Skriv litt mer på rapporten :) 