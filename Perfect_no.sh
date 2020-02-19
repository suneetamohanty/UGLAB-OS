echo Enter a number
read n
num=$n
f=0
i=1
sum=0

echo Checking Perfect number

while [ $i -lt $n ]
do
t=`expr $n % $i`
if [ $t -eq 0 ] 
then
echo $i
sum=`expr $sum + $i`
fi
i=`expr $i + 1`
done

echo Summation $sum

if [ $num -eq $sum ]
then
echo Perfect Number
else
echo Not a perfect number
fi



