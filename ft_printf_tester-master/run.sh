red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
purple='\033[0;35m'
bold='\033[1m'
none='\033[00m'
underline='\033[4m'

#-----------------------D_SPECIFIER----------------------

gcc -w d_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w d_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}D_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi

#-----------------------S_SPECIFIER----------------------

gcc -w s_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w s_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}S_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi

#-----------------------C_SPECIFIER----------------------

gcc -w c_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w c_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}C_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi

#-----------------------%_SPECIFIER----------------------

gcc -w %_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w %_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}%_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi

#-----------------------U_SPECIFIER----------------------

gcc -w u_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w u_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}U_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi


#-----------------------Xx_SPECIFIER----------------------

gcc -w Xx_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w Xx_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}X_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi

#-----------------------X_SPECIFIER----------------------

gcc -w x_main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc -w x_main.c libftprintf.a && ./a.out > theirs.txt

echo -e "${purple}${underline}${bold}x_SPECIFIER${none}\n"

DIFF=$(diff mine.txt theirs.txt)

if [ "$DIFF" == "" ]
then
	echo -e "${green}${bold}SUCCESS${none}\n"
else
	echo -e "${red}${bold}RETARD${none}\n"
fi

rm ./a.out
rm mine.txt
rm theirs.txt
