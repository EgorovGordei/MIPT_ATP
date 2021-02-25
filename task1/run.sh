# getting parametres
path=$1
path_len=${#path}
dot=$2
backup=$3
targz=$4

# create directory to copy all files
mkdir -p $backup

# find all files
nice_files=$(find $path -type f -name "*.$dot")

# copy files
#tmp=123456
#echo $nice_files
for fn in $nice_files
do
  crr_dir=$(dirname $fn)
  dir_without_start=${crr_dir:$path_len}
  dir_without_start=${dir_without_start:1}

  #echo "$backup/$dir_without_start"
  #mkdir "$backup/$crr_dir"
  mkdir -p "$backup/$dir_without_start"
  #cp $fn "$backup/$crr_dir/"
  cp $fn "$backup/$dir_without_start"
done
tar -zcf $targz $nice_files

# end of program
echo "done"
