

CY-METEO: ./C/main.o
	gcc -o ./C/CY-METEO ./C/main.o

main.o: ./C/main.c ./C/shared.c ./C/shared.h ./C/abr.c ./C/avl.c ./C/tab.c ./C/tab.h ./C/abr.h ./C/avl.h
	gcc -o ./C/main.o -c ./C/main.c 

clean:
	rm -rf ./C/*.o
	rm -rf ./C/tempplace.txt
	rm -rf ./C/temptimeandplace.txt
	rm -rf ./C/file.txt
	rm -rf ./C/temptemperature.txt
	rm -rf ./C/temppressure.txt
	rm -rf ./C/tempwind.txt
	rm -rf ./C/tempheight.txt
	rm -rf ./C/tempmoisture.txt
	rm -rf ./C/CY-METEO
