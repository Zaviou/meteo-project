reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000	
set output "load_T1"

# Putting a legend.
set title "Temperature error bars"
set xlabel ' Id sation'
set ylabel ' Temperatures '

plot 'Gnuplot/data/temp_T.csv' using 1:3:2 with filledcurve title "Max and min temperature" lc rgb "orange",\
	'Gnuplot/data/temp_T.csv' using 1:4 with linespoints title "Average temperature" lc rgb "green"
