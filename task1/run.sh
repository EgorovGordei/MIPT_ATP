# getting parametres
path=$1
dot=$2
backup=$3
targz=$4

# create directory to copy all files
mkdir $backup

# find all files and copy them into all_files
nice_files=$(find $path -type f -name "*.$dot")
for fn in $nice_files
do
  cp $fn $backup
done
tar -zcf $targz $nice_files
#rm tmp_12345678913579

# make .tar.gz
#tar -c -f $targz $backup

# end of program
echo "done"
