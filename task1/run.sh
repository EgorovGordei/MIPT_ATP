# getting parametres
path=$1
dot=$2
backup=$3
targz=$4

# create directory to copy all files
mkdir $backup

# find all files
nice_files=$(find $path -type f -name "*.$dot")

# copy files
#tmp=123456
#echo $nice_files
for fn in $nice_files
do
  crr_dir=$(dirname $fn)
  #echo $crr_dir
  #echo $fn
  mkdir "$backup/$crr_dir"
  cp $fn "$backup/$crr_dir/"
done
tar -zcf $targz $nice_files

# end of program
echo "done"
