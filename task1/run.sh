# getting parametres
path=$1
dot=$2
backup=$3
targz=$4

# create directory to copy all files
mkdir $backup

#tar -c -f $targz
# find all files and copy them into all_files
for fn in $(find $path -type f -name "*.$dot")
do
  cp $fn $backup
  tar -r -f $targz $fn
done

# make .tar.gz
#tar -c -f $targz $backup

# end of program
echo done
