echo -n "enter a number:"
read n

a=0
b=1
((c=a+b))
((n=n-2))
echo "series:"
echo $a
echo $b
for((i=1;i<=n;i++))
do
    echo $c
    ((a=b))
    ((b=c))
    ((c=a+b))
done
