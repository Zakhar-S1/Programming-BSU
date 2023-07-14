echo "Введите число:"
read n1
echo "Введите исходную систему счисления:"
read n2
echo "Введите желаемую систему счисления:"
read n3
echo "ibase=$n2;obase=$n3;$n1" | bc  
