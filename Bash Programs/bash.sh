dir="bash"
if [ -d $dir ]
then 
  echo "directory exists"
else
  echo "directory doesnot exist"
  echo "creating directory..."
  mkdir $dir
  echo "directory created"
fi
ls

