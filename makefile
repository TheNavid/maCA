CC := g++ -std=c++11

all: utunes.out

utunes.out: main.o ExceptionManager.o InputManager.o User.o Music.o Utunes.o Criteria.o ArtistCriteria.o LikeCriteria.o DateCriteria.o
	$(CC) main.o ExceptionManager.o InputManager.o User.o Music.o Utunes.o Criteria.o ArtistCriteria.o LikeCriteria.o DateCriteria.o -o utunes.out

main.o: main.cpp Utunes.hpp LibrariesAndDefines.hpp
	$(CC) -c main.cpp

ExceptionManager.o: ExceptionManager.cpp ExceptionManager.hpp LibrariesAndDefines.hpp
	$(CC) -c ExceptionManager.cpp

InputManager.o: InputManager.cpp InputManager.hpp Music.hpp LibrariesAndDefines.hpp
	$(CC) -c InputManager.cpp

Utunes.o: Utunes.cpp Utunes.hpp ExceptionManager.hpp InputManager.hpp User.hpp Music.hpp Criteria.hpp ArtistCriteria.hpp LikeCriteria.hpp DateCriteria.hpp LibrariesAndDefines.hpp
	$(CC) -c Utunes.cpp

User.o: User.cpp User.hpp Music.hpp Criteria.hpp ArtistCriteria.hpp LikeCriteria.hpp DateCriteria.hpp LibrariesAndDefines.hpp
	$(CC) -c User.cpp

Music.o: Music.cpp Music.hpp LibrariesAndDefines.hpp
	$(CC) -c Music.cpp

Criteria.o: Criteria.cpp Criteria.hpp Music.hpp LibrariesAndDefines.hpp
	$(CC) -c Criteria.cpp

ArtistCriteria.o: ArtistCriteria.cpp ArtistCriteria.hpp Criteria.hpp Music.hpp LibrariesAndDefines.hpp
	$(CC) -c ArtistCriteria.cpp

LikeCriteria.o: LikeCriteria.cpp LikeCriteria.hpp Criteria.hpp Music.hpp LibrariesAndDefines.hpp	
	$(CC) -c LikeCriteria.cpp

DateCriteria.o: DateCriteria.cpp DateCriteria.hpp Criteria.hpp Music.hpp LibrariesAndDefines.hpp
	$(CC) -c DateCriteria.cpp


.PHONY: clean
clean:
	rm -r *.o