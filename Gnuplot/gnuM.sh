reset

# Settings of the saving file (type, size and name).
set terminal png size 1800,1000
set output "load_M"

# Putting a legend.
set title "Carte interpolée et colorée moisture"
set xlabel ' Longitude '
set ylabel ' Latitude '

plot 'data/temp_M.csv' using 1:2:3 with circles fillstyle solid lc palette title "Moisture"
