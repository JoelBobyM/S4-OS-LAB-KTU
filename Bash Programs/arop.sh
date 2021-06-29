 echo -n "enter first number:"
read a
echo -n "enter second number:"
read b
echo -n "enter operator:"
read op
if [[ $op == "+" ]]
 then
   ((c=a+b))
elif [[ $op == "-" ]]
then
    ((c=a-b))
elif [[ $op == "*" ]]
then
    ((c=a*b))
elif [[ $op == "/" ]]
then
    ((c=a/b))
elif [[ $op == "%" ]]
then
    ((c=a%b))
fi
echo "result=$c"
