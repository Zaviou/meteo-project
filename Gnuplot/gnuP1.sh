reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000
set output "load_P1"

# Putting a legend.
set title "to complete"
set xlabel ' Id sation '
set ylabel ' Pressure '

plot 'data/temp_T1.csv' using 1:3:2 with filledcurve title "Max and min pressure" lc rgb "orange",\
	'data/temp_T1.csv' using 1:4 with linespoints title "Average pressure" lc rgb "green"
