echo Enter a number
read n
num=$n
rev=0
r=0
while [ $n -gt 0 ]
do
r=`expr $n % 10`
rev=`expr $rev \* 10 + $r`
n=`expr $n / 10`
done

if [ $rev -eq $num ]
then
echo Palindrome
else
echo Not a palindrome
fi   
