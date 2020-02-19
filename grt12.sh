echo Enter first number
read a
echo Enter second number
read b 

i=0
sum=1
while [ $i -lt $a ]
do
sum=`expr $sum \* $b`
i=`expr $i + 1`
done

echo $sum Result is of $a and $b
