a=$1
b=$2
while((a!=b))
do
  if((a>b))
  then
   ((a=a-b))
  else
   ((b=b-a))
  fi
done
echo $a
