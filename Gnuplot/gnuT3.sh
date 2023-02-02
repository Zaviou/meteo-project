reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000
set output "load_T3"

# Putting a legend.
set title "Graph temprature versus time"
set xlabel ' Time '
set ylabel ' Temperatures '

#Settings the format of date.
set xdata time
set timefmt '"%Y-%m-%d"'
set format x "%d/%m/%Y"

plot 'Gnuplot/data/temp_T.csv' using 1:3:4 with linespoints lc palette z title "Hours"
