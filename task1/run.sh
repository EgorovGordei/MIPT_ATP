# getting parametres
path=$1
dot=$2
backup=$3
targz=$4

# create directory to copy all files
mkdir $backup

# find all files and copy them into all_files
for fn in $(find $path -type f -name "*.$dot")
do
  cp $fn $backup
done

# make .tar.gz
tar -c -f $targz $backup

# end of program
echo done
