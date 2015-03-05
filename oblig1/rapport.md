<h1>RAPPORT OBLIG 1 CPP</h1>

<h3>OPPVARMING</h3>
  Oppvarmingsoppgaven var litt vrien da det tok litt tid å finne ut hvordan man kunne oversette beskjedene til char-arrays, ved   å ta byte for byte til char, ved å først ta de første 8bitene og gjøre til char og så bitforskyve for å få neste char.
  Men det gikk til slutt.
  
<h3>BLACKJACK</h3>
Nå skal alle filene være her.

<h5>Klasser:</h5>
  - Card    (Card.cpp & Card.hpp)
  - Deck    (Deck.cpp & Deck.hpp)
  - Dealer  (Dealer.cpp & Dealer.hpp)
  - Player  (Player.cpp & Player.hpp)
  - Game    (Blackjack.cpp (Klassen Game er en viktig del av denne filen, i samarbeid med main metoden.))
  
<img src="https://scontent-ams.xx.fbcdn.net/hphotos-xpf1/v/t1.0-9/1623566_10153118851052464_3994729613835250899_n.jpg?oh=12bc7a16a9e596ce47f3e8d20088f650&oe=558E3604" width ="550" height ="650">
  
Jeg sleit litt med å #include av egne klasser,før jeg fant ut at jeg måtte dele de opp i en .cpp fil med konstruktør og klassemetoder og en .hpp fil som definerer klassen og dens metoder og variabler, dette viste seg å problematisk når jeg tok i bruk MakeFile og skulle compilere/linke flere filer. Hver for seg compilerte de greit, men som en helhet fikk jeg masse rare uforståelige feilmeldinger. Fant ut etter litt googling at Når man linker klasser hvor klasser har #include i starten av mange av de samme headerne blir det kluss, og at for å løse dette måtte man bruke safeguards i headerne. Når jeg gjorde dette funket make som en velsmurt motor. Problemet nå var å luke ut feil med tanke på hva som skjer når en ny runde startes, samt å implementere spilleregler. Jeg trodde først at random generatoren i shuffle metoden min ikke fungerte da man fikk samme sekvens av kort for hver ny runde av et spill. Jeg fant etterhvert ut at det ikke var noe gærent med shuffle metoden min, men at jeg rett og slett hadde glemt å tømme hand vectoren til player, slik at spilleren beholdt kortene fra forrige runde mens de nye ble lagt etter disse i vektoren. Da jeg hadde satt tilbake counteren som teller antall kort i hånden til 0 førte det til at spilleren bare så de samme kortene fra forrige runde. 

<h1>CPP</h1>
