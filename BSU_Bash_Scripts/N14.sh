echo "Введите год:"
read year

if (( $(echo "$year % 400 == 0") ));
then echo "Заданный год является високосным."
else 
    if (( $(echo "$year % 4 == 0 && $year % 100 != 0") ));
     then echo "Заданный год является високосным."
    else 
     echo "Заданный год не является високосным."
     fi
fi
    
 




