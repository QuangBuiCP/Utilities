# pwd
# echo
filename=$1
basename=${filename%.cpp}

flags="g++ -std=c++17 -o $basename.sout $filename -DLOCAL -ggdb3 -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -fsanitize=address -fsanitize=undefined -fstack-protector"
# flags="g++ -std=c++17 -o $%file%$ $%full%$ -ggdb3 -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -fsanitize=address -fsanitize=undefined -fstack-protector"

echo $flags

$flags

val=$?

RED='\033[1;31m'
GREEN="\033[1;32m"

echo 

if [ $val == 0 ]
then
	echo -e "${GREEN}Compilation ${GREEN}finished ${GREEN}successfully"
	exit 0
else
	echo -e "${RED}Compilation ${RED}failed"
	exit 1
fi
