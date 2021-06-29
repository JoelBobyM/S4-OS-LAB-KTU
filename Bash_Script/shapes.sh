echo "1.Area of circle"
echo "2.Circumference of circle"
echo "3.Area of reactangle"
echo "4.Area of square"
echo -n "Enter choice:"
read ch

if((ch==1))
then
  echo -n "Enter Radius:"
  read r
  ((a=((22/7))*r*r))
  echo "Area=$a"
elif((ch==2))
then
  echo -n "Enter Radius:"
  read r
  ((a=2*22/7*r))
  echo "Circumference=$a"
elif((ch==3))
then
  echo -n "Enter length:"
  read l
  echo -n "Enter breadth:"
  read b
  ((a=l*b))
  echo "Area of rectangle=$a"
elif((ch==4))
then
  echo -n "Enter side:"
  read s
  ((a=s*s))
  echo "Area of square=$a"
else
  echo "Invalid Choice"
fi
