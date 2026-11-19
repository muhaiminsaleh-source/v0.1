all:
	g++ -O2 main.cpp Person.cpp FileHandler.cpp -o app

clean:
	rm -f app students_*.txt passed_*.txt failed_*.txt
