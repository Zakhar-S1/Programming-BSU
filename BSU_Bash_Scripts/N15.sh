echo "Введите сторону A:"
read A
echo "Введите сторону B:"
read B
echo "Введите сторону C:"
read C

if (( $(echo "$A == $B == $C" | bc -l) ));
then echo "Треугольник является равносторонним."
