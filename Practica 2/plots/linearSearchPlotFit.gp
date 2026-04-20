# ======= Ajustes de ejes y estilo (idénticos a tu script) =======
set xrange [0:110000] 
set yrange [-10:]
set xtics 20000
set ytics 10
set xlabel "Size"
set ylabel "Microseconds"
set key left
set grid

# ======= generar el PDF =======
set term pdfcairo enhanced color solid
set output "plots/linearSearch.pdf"

plot "plots/linearSearch.out" using 1:2 title "Best case" with points, \
     "plots/linearSearch.out" using 1:3 title "Worst case" with points, \
     "plots/linearSearch.out" using 1:4 title "Average case" with points

f(x) = a*x+b
fit f(x) "plots/linearSearch.out" using 1:3 via a,b 
replot f(x)

g(x) = c*x+d
fit g(x) "plots/linearSearch.out" using 1:4 via c,d 
replot g(x)

# Cerrar correctamente el PDF para evitar que quede dañado
unset output

# ======= 2) Fase interactiva: ventana para ver y pausar =======
set term qt  # o wxt, según tu entorno

# Replot muestra el último gráfico en el nuevo terminal
replot

pause -1 "Press ENTER to continue ... "

print "f(", 10**9, ") = ", f(10**9)
print "g(", 10**9, ") = ", g(10**9)

pause -1 "Press ENTER to continue ... "
