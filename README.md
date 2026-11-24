
---
# Wstęp
W matematyce jest taki dział nazywający się "Teorią gier" (z ang. "Game theory"). Zajmuje się on badaniem optymalnego zachowana w ramach różnych sytuacji. Sytuacje nazywa się "Grami", i bierze w nich udział pewna ilość "Uczestników". W moim projekcie chciałbym się skupić na prostej "grze", która była już wykorzystywana w czasach Zimnej Wojny, aby znaleźć najlepszą strategię reakcji w razie eskalacji konfliktu. Używano do tego tzw. "Dylematu więźnia".

---
# "Dylemat Więźnia"
1. Zasady
	Gra polega na prostym założeniu. Jest dwóch więźniów który nie mogą się ze sobą komunikować oraz nie znają strategii drugiego z "uczestników". Wiedzą oni jedynie informację ile punków otrzymali w poprzedniej rundzie. Z tej informacji mogą wywnioskować jaki ruch wykonał przeciwnik, poprzez porównanie jej do "Tabeli wypłat". "Uczestnicy" mają tylko 2 możliwe ruchy: Współpracę lub Zdradę (z ang. Cooperate or Defect)
2. Przykładowa tabela wypłat
	Zawiera ona ile punktów otrzymuje "Więzień" w zależności od wykonanej akcji obu graczy:
	- Jeśli obaj gracze współpracują otrzymują 3 punkty
	- Jeśli jeden współpracuje, a drugi zdradza wtedy tylko zdradzający otrzymuje 5 punktów
	- Jeżeli oboje zdradzają każdy otrzymuje po 1 punkt
3. Celem gry jest otrzymanie maksymalnej liczby punktów

---
# Pomysł na rozwiązanie
1. Celem mojego projektu jest funkcjonalne wykorzystanie mechanizmów komunikacji międzyprocesowej i miedzy wątkowej w aplikacji. Celem aplikacji wygenerowanie jak najlepszej strategii przy pomocy metody opisanej poniżej.
2. Parametry programu (podstawowe wartości w nawiasach):
	1. Liczba generacji (10)
	2. Maksymalna Ilość gier na raz (50)
	3. ilość modeli na generację (100)
	4. Wagi początkowe (OPCJONALNE - 1 generacja może być z pliku lub generowana od zera)
	5. Wartości tabeli wypłat ( { \[3,3] , \[5,0] , \[0,5] , \[1,1] } )
3. Mistrz gry (później nazywany MG)
	Podstawowym procesem byłby tzw. "Game Master". Mistrz gry odpowiadał by za tworzenie kolejnych generacji, ewaluację ich wydajności, uruchamianie procesów "Sędziów", oraz kontrole parametrów gry tj.:
	- wartości tabeli wypłat
	- Ilości procesów
	- Ilości równoległych gier
	- Ilość rund
4. **Sędziowie** 
	to podrzędne procesy Mistrza Gry (MG). Otrzymują one parametry każdej gry oraz wagi dla sieci neuronowych reprezentujących Graczy przy pomocy kolejki komunikatów. Sędziowie uruchamiają procesy więźniów i kierują postępem gry. Na koniec zapisują do obszaru pamięci współdzielonej ilość otrzymanych punktów. Zapis ten jest synchronizowany przy pomocy semaforów.
5. Gracze
	Graczami są proste sieci neuronalne która deklarują jaki ruch wykonują na podstawie ruchów przeciwnika w poprzednich rundach(te otrzymują od sędziego przy pomocy pipe-ów). Składa się ona z kilku wejść, gdzie każde z nich przypada na wyniki poprzednich rund, 1 warstwy utajonej i 1 wyjścia. Wagi są generowane przez MG i przekazywane przez Sędziego. Po zakończonej grze proces się kończy, a wynik gry determinuje czy jego wagi przejdą do następnej generacji.
6. Interface
	1. Minimalistyczny
	2. Wyświetla aktualnie najlepszy model w wizualnej formie ASCII-Art ( OPCJONALNE )
	3. Po rozpoczęciu zadania nie pozwala zmienić jego parametrów, a jedynie zakończyć całość

---
# Dokładny szkic
## Struktura
Mistrz Gry jest procesem głównym i nadzoruje parametry pracy.  
Przy pomocy `exec()` i `fork()` uruchamia on sędziów z odpowiednimi parametrami, a następnie przy pomocy `waitpid()` oczekuje na zakończenie wszystkich rozgrywek.
W razie przekroczenia maksymalnego czasu wykonywania się rozgrywki zostanie przekazany do procesu `SIGKILL`. Parametry rozgrywek są przekazywane do sędziów `przy pomocy kolejek komunikatów` 

Sędziowie również z użyciem `fork()` i  `exec()` rozpoczynają procesy więźniów. Jeżeli któryś z uczestników nie odpowie w zadanym czasie rozgrywka jest przerywana i obie strony dostają po 0 punktów lub gra zostaje uruchomiona ponownie (w zależności od ustawień)

## Komunikacja
MG otwiera przestrzeń `pamięci współdzielonej` gdzie są przetrzymywane wyniki dla danych modeli. W razie `błędów lub sygnałów` przerwania zostaną one prawidłowo przekazane dalej do procesów potomnych aby te mogły je przetworzyć.

Sędziowie synchronizują oraz dyktują tępo gry przy pomocy `semaforów`. Komunikacja wyników otrzymanych punktów wykorzystuje mechanizm `pipe`.

## Limity
MG uruchamia tylko tyle pod procesów ile jest wątków procesora. 
Każdy sędzia nakłada limity zużycia CPU i RAM-u na Graczy.

---
# Planowany przebieg
1. MG tworzy segment `pamięci dzielonej`
2. MG losuje wagi
3. MG uruchamia kolejnych sędziów
4. MG przesyła im przy pomocy `kolejki komunikatów` wszystkie parametry
5. MG rozpoczyna oczekiwanie na zakończenie się generacji
6. Sędziowie rozpakowują parametry i tworzą `pipe`-y wraz z `semaforami`
7. Zgodnie z parametrami uruchamiają oni Graczy
8. Przy pomocy `semaforów` synchronizują rozgrywki
9. Każdy Gracz przy pomocy `pipe` przesyła swój ruch a następnie oczekuje na odpowiedź z wynikiem
10. Po zakończeniu zadanej ilości gier, sędzia wysyła `sygnał` aby gracze zakończyli swoje działanie
11. Następuje dodanie wyników do pamięci współdzielonej synchronizowane semaforem
12. Po zakończeniu się procesów graczy, a następnie sędziów, MG ewaluuje wygranego
13. MG czyści tablicę wyników, a następnie oczekuje na zatwierdzenie kolejnej generacji (o ile taka opcja zostanie wybrana)
14. **Powrót po pkt. 2**
15. W razie zakończenia pracy, wyniki są zapisywane do plików. Jeśli proces zakończy pracę zgodnie z planem wygrany model  zostaje zapisany do pliku który można załadować w kolejnych uruchomieniach


---
# Rozwiązanie
Rozwiązanie jest dostępne [here](https://github.com/SimpleProgrammr/dylemat_wieznia)