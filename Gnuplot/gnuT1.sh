reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000	
set output "load_T1"

# Putting a legend.
set title "Error lines graph T1"
set xlabel ' Id sation'
set ylabel ' Temperatures '

plot 'C/data/temp_T1.csv' using 1:3:2 with filledcurve title "Max and min temperature" lc rgb "orange",\
	'C/data/temp_T1.csv' using 1:4 with linespoints title "Average temperature" lc rgb "green"
