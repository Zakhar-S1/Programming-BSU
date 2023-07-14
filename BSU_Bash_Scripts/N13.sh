echo "Введите координату x:"
read x
echo "Введите координату y:"
read y
if (( $(echo "$x > 0" | bc -l) )); 
then if (( $(echo "$y > 0" | bc -l) ));   
     then echo "Точка принадлежит 1-ому квадранту."
     else 
         if (( $(echo "$y < 0" | bc -l) ));
         then echo "Точка принадлежит 4-ому квадранту."
         else 
                 if (( $(echo "$y == 0" | bc -l) ));
                 then echo "Точка лежит на абсциссе между 1-ым и 4-ым квадрантами."
                 fi
         fi
     fi
else 
     if (( $(echo "$x < 0" | bc -l) ));
     then if (( $(echo "$y > 0" | bc -l) ));
          then echo "Точка принадлежит 2-ому квадранту."
          else 
             if (( $(echo "$y < 0" | bc -l) ));
             then echo "Точка принадлежит 3-ему квадранту."
             else 
                 if (( $(echo "$y == 0 | bc -l")) );
                 then echo "Точка лежит на абсциссе между 2-ым и 3-им квадрантами."
                 fi
             fi
         fi
     fi
fi

if (( $(echo "$x == 0" | bc -l) ));
then if (( $(echo "$y > 0" | bc -l) ));
     then echo "Точка лежит между 1-ым и 2-ым квадрантами."
     else 
         if (( $(echo "$y < 0" | bc -l) ));
         then echo "Точка лежит между 3-им и 4-ым квадрантами."
         fi
     fi     
fi

if (( $(echo "$x == 0 && $y == 0" | bc -l) ));
then echo "Точка лежит в начале координат."
fi