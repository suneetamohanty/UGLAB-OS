echo Enter a number
read n
num=$n
f=0
i=1


while [ $i -le $n ]
do
t=`expr $n % $i`
if [ $t -eq 0 ] 
then
f=`expr $f + 1`
fi
i=`expr $i + 1`
done


if [ $f -gt 2 ]
then
echo Not a prime
else
echo Prime
fi


