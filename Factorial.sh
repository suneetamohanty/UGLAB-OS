echo Enter a number
read n
num=$n
f=0
i=1

echo The factorials of $n are

while [ $i -le $n ]
do
t=`expr $n % $i`
if [ $t -eq 0 ] 
then
echo $i
fi
i=`expr $i + 1`
done



