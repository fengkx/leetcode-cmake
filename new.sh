if [ -z "$1" ]
then
	echo 'ERROR: need paramter `./new.sh <problem name>`'
	exit 1 
fi
DIRNAME=$(dirname $0)
path="$DIRNAME/problems/$1"
echo $path
if [ -d $path ]
then
	echo "ERROR: directory $path has existed"
	exit 1
fi
cp -r "$DIRNAME/problem_template" $path
mv "$path/TTT.cpp" "$path/$1.cpp"
sed -i "s/TTT/$1/g" "$path/$1.cpp"
sed -i "s/TTT/$1/g" "$path/CMakeLists.txt"

