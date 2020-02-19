echo hello
a=10
b=20
echo value of a is $a
echo value of b is $b
c=`expr $a + $b`
echo summation of a and b is $c

fname=tanny
lname=mondal

echo fullname is $fname $lname

echo square is `expr $a \* $a`

echo cube is `expr $a \* $a \* $a`

total=`expr 1 + 2 + 3 + 4 + 5`
echo `expr  $total / 5`

days=73

d=`expr $days % 30`
m=`expr $days / 30`

echo $m months $d days

money=700

i=`expr $money % 100`

if [ $i -eq 0 ]
then
echo divisible
else
echo not multiple
fi
