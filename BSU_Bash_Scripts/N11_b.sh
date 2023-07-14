echo "Введите первое число n1:"
read n1
echo "Введите второе число n2:"
read n2
echo "Введите третье число n3:"
read n3
if (( $(echo "$n1 > $n2 && $n1 > $n3" | bc -l) ));
    then echo "Наибольшее число n1=$n1"
else 
    if (( $(echo "$n2 > $n1 && $n2 > $n3" | bc -l) ));
        then echo "Наибольшее число n2=$n2"
    else 
        if (( $(echo "$n3 > $n1 && $n3 > $n2" | bc -l) ));
           then echo "Наибольшее число n3=$n3"
        else 
            if (( $(echo "$n1 == $n2 && $n3 > $n2" | bc -l) ));
                then echo "Наибольшее число n3=$n3"
            else 
                if (( $(echo "$n1 == $n3 && $n2 > $n3" | bc -l) ));
                    then echo "Наибольшее число n2=$n2"
                else 
                    if (( $(echo "$n2 == $n3 && $n1 > $n3" | bc -l) ));
                        then echo "Наибольшее число n1=$n1"
                    else 
                        echo "Все числа равны."
                    fi 
                fi
            fi
        fi
    fi 
fi  