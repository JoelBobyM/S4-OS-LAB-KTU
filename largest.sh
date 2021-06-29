echo -n "enter number 1:"
read n1
echo -n "enter number 2:"
read n2
echo -n "enter number 3:"
read n3
if ((n1>n2)) && ((n1>n3))
then
  echo $n1 "is the largest number"
elif ((n1<n2)) && ((n2>n3))
then
  echo $n2 "is the largest number"
elif ((n3>n1)) && ((n3>n2))
then
  echo $n3 "is the largest number"
fi
