echo -n "Enter no:of integers:"
read n
sum=0
for((i=1;i<=n;i++))
do
  echo -n "Enter number $i:"
  read num
  ((sum=sum+num))
done
((avg=sum/n))
echo "Average=$avg"
