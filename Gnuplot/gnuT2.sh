reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000	
set output "load_T2"

# Putting a legend.
set title "Simples lignes graph T2"
set xlabel ' Date '
set ylabel ' Temperatures '

#Settings the format of date.
set xdata time
set timefmt '"%Y-%m-%d %H:%M:%S"'
set format x "day %d\n%Hh"

plot 'C/data/temp_T2.csv' using 1:2 with linespoints title "Average temperature"
