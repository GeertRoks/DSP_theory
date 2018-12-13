# png
set terminal pngcairo size 1500,700 enhanced font 'Verdana,10'
set output 'sinetest.png'

set title "Plot of Sine approximation with Taylor series (n=9) - Geert Roks, 2018"

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
set xtics pi
set mxtics 4
set format x '%0.Pπ'
set ytics 1
set tics scale 0.75

set xrange [0:20*pi]
set yrange [-1.5:1.5]
set grid
set key
plot 'sinetest.dat' index 0 with linespoints linestyle 1 title "Sine (50Hz @ 48kHz)", \
      ''            index 1 with linespoints linestyle 2 title "2", \
      ''            index 2 with linespoints linestyle 3 title "3"
unset key
unset grid
