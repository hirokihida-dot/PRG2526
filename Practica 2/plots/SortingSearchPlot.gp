set xrange [0:10000] 
set yrange [0:]
set xtics 200
set ytics 6
set xlabel "Size"
set ylabel "Microseconds"
set key left
set grid
plot "plots/SortingSearch.out" using 1:2 title "Average case" with points
