FLAGS = -ansi -pedantic -Wall -std=c++11 -g

Projet: main.o Trajet.o CaseTrajet.o ListeTrajet.o TrajetSimple.o TrajetCompose.o Catalogue.o
	g++ $(FLAGS) $^ -o $@

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

Trajet.o: Trajet.cpp
	g++ $(FLAGS) -c Trajet.cpp
	
TrajetSimple.o: Trajet.cpp TrajetSimple.cpp
	g++ $(FLAGS) -c $^	

CaseTrajet.o: CaseTrajet.cpp
	g++ $(FLAGS) -c CaseTrajet.cpp

ListeTrajet.o: ListeTrajet.cpp
	g++ $(FLAGS) -c ListeTrajet.cpp

TrajetCompose.o:Trajet.cpp TrajetCompose.cpp
	g++ $(FLAGS) -c $^
	
Catalogue.o: Catalogue.cpp 
	g++ $(FLAGS) -c Catalogue.cpp	

clean:
	rm *.o Projet
