
CY-METEO: ./C/main.o
	gcc -o ./C/CY-METEO ./C/main.o

main.o: ./C/main.c ./C/shared.c ./C/shared.h ./C/abr.c ./C/avl.c ./C/tab.c ./C/tab.h ./C/abr.h ./C/avl.h
	gcc -o ./C/main.o -c ./C/main.c 

clean:
	rm -rf ./C/*.o
	rm -rf ./C/CY-METEO
	rm -rf ./C/data/tempplace.txt
	rm -rf ./C/data/temptimeandplace.txt
	rm -rf ./C/data/file.txt
	rm -rf ./C/data/temptemperature.csv
	rm -rf ./C/data/temppressure.csv
	rm -rf ./C/data/tempwind.csv
	rm -rf ./C/data/tempheight.csv
	rm -rf ./C/data/tempmoisture.csv
	rm -rf ./Gnuplot/data/*.csv
