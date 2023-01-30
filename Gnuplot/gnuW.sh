reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000	
set output "load_W"

# Putting a legend.
set title "Graph in vectors of wind"
set xlabel ' Latitude '
set ylabel ' Longitude '

plot 'data/temp_W.csv' using 1:2:($3*cos($4/180*pi)):($3*sin($4/180*pi)) with vectors head filled lt 2 title "Direction of wind"
