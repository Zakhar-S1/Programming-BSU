echo "Введите первое число:"
read a
echo "Введите второе число:"
read b 
test $a -gt $b && echo "Большее число a=$a" || echo "Большое число b=$b" 



