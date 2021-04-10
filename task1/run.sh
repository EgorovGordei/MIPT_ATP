# getting parametres
#path=$1
#path_len=${#path}
#dot=$2
#backup=$3
#targz=$4

# create directory to copy all files
mkdir -p $3

# find all files
nice_files=$(find $1 -type f -name "*.$2")

# copy files
#tmp=123456
#echo $nice_files
for fn in $nice_files
do
  crr_dir=$(dirname $fn)
  dir_without_start=${crr_dir:${#$1}}
  dir_without_start=${dir_without_start:1}

  mkdir -p "$3/$dir_without_start"
  cp $fn "$3/$dir_without_start"
done
tar -zcf $4 $nice_files

# end of program
echo "done"
