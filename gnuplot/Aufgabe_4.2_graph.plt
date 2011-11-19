set title 'Der Kern und das Bild der Matrix A'
set xrange [0:5]
set yrange [0:5]
set zrange [0:5]

set terminal latex
set output 'Aufgabe_4.2_graph.tex'
set ticslevel 0

splot 'VektorenA' with vector
