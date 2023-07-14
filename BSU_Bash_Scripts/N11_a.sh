echo "Введите первое число"
read n1 
echo "Введите второе число"
read n2 
if (( $(echo "$n1 > $n2" | bc -l) )); 
then echo "n1=$n1>n2=$n2"
else
    if (( $(echo "$n1 < $n2" | bc -l) ));
    then echo "n1=$n1<n2=$n2"
    else 
        echo "n1=$n1=n2=$n2"
    fi
fi