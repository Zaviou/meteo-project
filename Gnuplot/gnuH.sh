reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000
set output "load_H"

# Putting a legend.
set title "Carte interpolée et colorée altitude"
set xlabel ' Longitude '
set ylabel ' Latitude '

plot 'data/temp_H.csv' using 1:2:3 with circles fillstyle solid lc palette title "Height"
