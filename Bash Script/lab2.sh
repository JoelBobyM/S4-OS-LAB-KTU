a=$1
b=$2
while((b!=0))
do
  ((t=b))
  ((b=a%b))
  ((a=t))
done
echo $a
  
