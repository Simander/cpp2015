Orig:
Dette var en vanskelig oppgave, var verre å finne god lettlest info/hjelp om c++ enn med java.
Kodeknekkinga gikk til slutt, men tok mye tid.
Blackjack oppgaven tok lengre tid, ble ikke helt fornøyd, men ble knapt med tid. 
shuffle metoden min funker bare når programmet starter på nytt. Ved ny runde blir det samme shuffle.
Er det mulig å få nye randoms med srand(time(0)) i realtime uten å starte programmet på nytt? 
eller må man bruke en annen funksjon?
Burde være mulig da det funker i java.

Update:
innså at jeg hadde glemt å laste opp deck.cpp og deck.hpp filene, og jeg hadde limt inn feil kode i player.cpp. Jeg har også oppdaget at random variabelen min og shuffle metoden funker. Hadde bare glemt å poppe cards fra hand vectorene til dealer og player i reset metoden min, slik at de fikk de fortsatt hadde de gamle kortene på samme plass i vektoren. nå er dette fikset og jeg er glad for å kunne si at spillet mitt nå funker :)
