# png
set terminal pngcairo size 1500,700 enhanced font 'Verdana,10'
set output 'envelope.png'

set title "Envelope folower based on Hilbert Transfrom on a kickdrum sample - Geert Roks, 2018"

set border linewidth 1.5
# Set first two line styles to blue (#0060ad) and red (#dd181f)
set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 0 linewidth 2 \
    pointtype -1
set style line 2 \
    linecolor rgb '#ff0000' \
    linetype 1 linewidth 2 \
    pointtype -1
set style line 3 \
    linecolor rgb '#3cef39' \
    linetype 1 linewidth 2 \
    pointtype -1

set  xlabel "Samples"
set ytics 1
set tics scale 0.75

set xrange [0:1000]
set yrange [-1.5:1.5]
set grid
set key
plot 'envelope.dat' index 0 with linespoints linestyle 3 title "Kicksample", \
      ''            index 1 with linespoints linestyle 2 title "Hilbert transfrom", \
      ''            index 2 with linespoints linestyle 3 title "3"
unset key
unset grid
