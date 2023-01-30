reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000	
set output "load_W"

# Putting a legend.
set title "Flêches graph W"
set xlabel ' Coordonate X '
set ylabel ' Coordonate Y '

plot 'C/data/temp_W.csv' using 1:2:($3*cos($4/180*pi)):($3*sin($4/180*pi)) with vectors head filled lt 2 title "Direction of wind"
