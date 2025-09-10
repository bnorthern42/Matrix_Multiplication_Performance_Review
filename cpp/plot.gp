# Set the output file type and name
set terminal pngcairo size 800,600 enhanced font 'Verdana,10'
set output 'openmp_performance.png'

# Set graph title and axis labels
set title "OpenMP Performance: Time vs. Number of Cores"
set xlabel "Number of Cores"
set ylabel "Time (Sec)"

# Tell gnuplot that the data file is comma-separated
set datafile separator ","

# Add a grid to the plot for easier reading
set grid

# Plot the data from 'TimesParallel.csv'
# 'using 1:2' means use column 1 for the x-axis and column 2 for the y-axis
# 'with linespoints' will draw lines connecting the data points and also show the points
# 'lw 2' sets the line width to 2
# 'pt 7' sets the point type to a filled circle
# 'lc rgb "blue"' sets the line color to blue
# 'title "Execution Time"' adds a legend entry
plot 'TimesParallel.csv' using 1:2 with linespoints lw 2 pt 7 lc rgb "blue" title "Execution Time"
