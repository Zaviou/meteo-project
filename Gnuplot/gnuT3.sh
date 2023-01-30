reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000
set output "load_T3"

# Putting a legend.
set title "Multiples lignes graph T3"
set xlabel ' Station '
set ylabel ' Temperatures '

#Settings the format of date.
set xdata time
set timefmt '"%Y-%m-%d"'
set format x "%d/%m/%Y"

plot 'data/temp_T3.csv' using 1:3:4 with linespoints lc palette z title "Hours"
