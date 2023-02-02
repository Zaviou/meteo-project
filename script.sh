#!/bin/bash
#  \   `   |  ~   []  {}


# This function prints an help message presenting the features of CY-Meteo in the terminal.
helpmessage()
{
	echo "CY-METEO is a program designed to make graphics out of meteorological measurements."
	echo " "
	echo "If you just used the program and want to remove temporary files, use the command 'make clean'."
	echo " "
	echo "The program is ready to run. Use the command 'bash script.sh [options]' to start."
	echo " "
	echo "Please note that using -f is mandatory ; that using at least one option between -t -p -w -m -h is mandatory ; that a mode needs to be specified with -t and -p ; that you can't use two options or more for the place (-Q -A -O -F -S -G)."
	echo " "
	echo "This program creates temporary files which are located in the C directory. If you have a data protector or any other protection active when using CY-MÉTÉO, make sure file manipulation can be done in that directory to avoid errors."
	echo " "
	echo "LIST OF OPTIONS :"
	echo " "
	echo "-f : serves to specify the path to the meteorological data file. Not using it will cause an error."
	echo " "
	echo "--avl : data is sorted by using AVL trees. If no sorting mode is specified, this is the default mode."
	echo " "
	echo "--abr : data is sorted by using ABR/BST trees."
	echo " "
	echo "--tab : data is sorted by using lists."
	echo " "
	echo "--help : puts a help message on the terminal."
	echo " "
	echo "-r : the sorting order will be reversed (ascending order becomes descending and descending becomes ascending)."
	echo " "
	echo "-t : the program will produce graphics on temperature in French regions."
	echo "You need to specify a mode as an argument."
	echo "Use -t 1 to get average, minimum and maximum temperature for each station."
	echo "Use -t 2 to get worldly average temperatures for each date and time."
	echo "Use -t 3 to get temperature measurements for each station, date and time."
	echo " "
	echo "-p : the program will produce graphics on pressure in French regions."
	echo "You need to specify a mode as an argument."
	echo "Use -p 1 to get average, minimum and maximum pressure for each station."
	echo "Use -p 2 to get worldly average pressure measurements for each date and time."
	echo "Use -p 3 to get pressure measurements for each station, date and time."
	echo " "
	echo "-w : the program will produce graphics on wind in French regions."
	echo "The output will be a vector map representing average wind measurements in each region of the world."
	echo " "
	echo "-h : the program will produce graphics on the height of meteorological stations in French regions."
	echo "The output will be a map with colors representing heights in each region."
	echo " "
	echo "-m : the program will produce graphics on moisture levels in French regions."
	echo "The output will be a map with colors representing moisture levels in each region."
	echo " "
	echo "-d : allows to specify a time interval from which the data used will come."
	echo "The format of the time interval is 'YYYY-MM-DDYYYY-MM-DD'."
	echo " "
	echo "-F : the data used will only be from the stations located in metropolitan France and Corsa."
	echo " "
	echo "-G : the data used will only be from stations located in French Guiana."
	echo " "
	echo "-A : the data used will only be from stations located in the West Indies."
	echo " "
	echo "-S : the data used will only be from the meteorological station of St-Pierre et Miquelon."
	echo " "
	echo "-Q : the data used will only be from stations located in Antarctica."
	echo " "
	echo "-O : the data used will only be from stations located in the Indian Ocean."
	echo " "
	echo "USE EXAMPLES :"
	echo "1)"
	echo " "
	echo "bash script.sh -f meteo.csv -p 3 --abr -d 2003-12-082004-01-01"
	echo "make clean"
	echo " "
	echo " "
	echo " "
	echo "2)"
	echo " "
	echo "bash script.sh -f meteo_filtered_data_v1.csv -t 1 -w -r -Q"
	echo "make clean"
	echo " "
}

echo "Welcome to CY-Météo !"

# 1) READING OPTIONS
# The first thing the script does is getting all the options from the user's command. Its behaviour will change depending on them.

# Initialisation of variables. Here, we will use various integers to keep track of the user's choices and check for errors. 
sort=0
descendingsort=0
place=0
file=0
filename=0
dates=0
date1=0
date2=0
wind=0
pressure=0
pressuremode=0
moisture=0
temperature=0
temperaturemode=0
height=0
tempfile=0

# This loop runs until all the options and their arguments have been read. Inside, we specify what happens for each given option.
# The string below is the list of the accepted options. They are followed by ':' if they need arguments.
while getopts ":f:t:p:whmFGSAOQd:-:o:r" option
do
	case $option in
		-)                         # The hyphen is a special case, we used it here to handle long options like --help.
			case "$OPTARG" in  #The first - says it is an option, the second - is the option itself, the rest is the argument of the - option.
				avl)       # Hence the use of cases inside the case of -. 
					if [ $sort -ne 0 ] # We use this test for each sorting option to know if the user already selected one.
					then               # When a sorting option is selected, the value of the sort variable changes to a non-zero.
						echo "Error : two different sorting modes were selected."
 						exit 1 
					fi
					sort=1
					echo "AVL sorting mode."
					;;
				abr)
					if [ $sort -ne 0 ]
					then
						echo "Error : two different sorting modes were selected."
 						exit 1 
					fi
					sort=2
					echo "ABR sorting mode."
					;;
				tab)
					if [ $sort -ne 0 ]
					then
						echo "Error : two different sorting modes were selected."
 						exit 1 
					fi
					sort=3
					echo "Array sorting mode."
					;;
				help)
					helpmessage
					exit 0
					;;
				*)  # If the argument for the -- option is anything other than what is possible, an error occurs.
					echo "Error : unknown option."
					exit 1
					;;
			esac
			;;	
		f)  # The -f option handles access to the data file. The user specifies the path to the file in its argument.
			if [ $file -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			filename=$OPTARG
			file=1
			;;
		r)  # If a descending sort is selected with -r, the associated variable goes from 0 to 1.
			if [ $descendingsort -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			descendingsort=1
			;;
		t)  # The temperature option. Again, we use cases because it needs a mode that is specified by the user in its argument.
			if [ $temperature -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			temperature=1
			case "$OPTARG" in
				1)
					temperaturemode=1
					;;
				2)
					temperaturemode=2
					;;
				3)
					temperaturemode=3
					;;
				*)  # The specified mode can only be 1,2 or 3. Anything else will cause an error.
					echo "Error : temperature mode wasn't specified or is incorrect."
					exit 1
					;;
			esac
			;;
		p) # The pressure option. Same structure as the -t option.
			if [ $pressure -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			pressure=1
			case "$OPTARG" in
				1)
					pressuremode=1
					;;
				2)
					pressuremode=2
					;;
				3)
					pressuremode=3
					;;
				*)
					echo "Error : pressure mode wasn't specified or is incorrect."
					exit 1
					;;
			esac
			;;
		w) # The wind option.
			if [ $wind -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			wind=1
			;;
		h) # The height option.
			if [ $height -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			height=1
			;;
		m) # The moisture option.
			if [ $moisture -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
			moisture=1
			;;
		d)                    
			if [ $dates -eq 1 ]
			then
				echo "You selected the same option twice !"
				exit 1
			fi
		                              # The time option.Two dates are to be given by the user in this format : YYYY-MM-DDYYYY-MM-DD.
			lenght=${#OPTARG}     # It is a time interval, the first date needs to come before the second.
			if [ $lenght -ne 20 ] # If the format is incorrect or if the first date comes after the second, an error occurs.
			then
				echo "Error : format of given dates is incorrect for the -d option (lenght)."
 				exit 1 
			fi
			if [ ${OPTARG:4:1} != "-" ] || [ ${OPTARG:7:1} != "-" ] || [ ${OPTARG:14:1} != "-" ] || [ ${OPTARG:17:1} != "-" ]
			then
				echo "Error : format of given dates is incorrect for the -d option (hyphens)."
 				exit 1
			fi

			date1=${OPTARG:0:10}
			date2=${OPTARG:10:10}

			if [ ${date1:0:4} -gt ${date2:0:4} ]
			then
				echo "Error : the first date comes after the second."
				exit 1
			else 
				if [ ${date1:0:4} -eq ${date2:0:4} ]
				then
					if [ ${date1:5:2} -gt ${date2:5:2} ]
					then
						echo "Error : the first date comes after the second."
						exit 1
					else
						if [ ${date1:5:2} -eq ${date2:5:2} ]
						then
							if [ ${date1:8:2} -gt ${date2:8:2} ]
							then
								echo "Error : the first date comes after the second."
								exit 1
							fi
						fi
					fi
				fi
			fi
			dates=1
			;;
		F) # The options for places. As with sorting modes, the user cannot select two.
			if [ $place -ne 0 ]
			then
				echo "Error : two different places were selected."
 				exit 1 
			fi
			place=1
			echo "You chose France."
			;;		
		G)
			if [ $place -ne 0 ]
			then
				echo "Error : two different places were selected."
 				exit 1 
			fi
			place=2
			echo "You chose french Guiana."
			;;
		S)
			if [ $place -ne 0 ]
			then
				echo "Error : two different places were selected."
 				exit 1 
			fi
			place=3
			echo "You chose Saint-Pierre et Miquelon."
			;;
		A)
			if [ $place -ne 0 ]
			then
				echo "Error : two different places were selected."
 				exit 1 
			fi
			place=4
			echo "You chose the West Indies."
			;;
		O)
			if [ $place -ne 0 ]
			then
				echo "Error : two different places were selected."
 				exit 1 
			fi
			place=5
			echo "You chose the Indian Ocean."
			;;
		Q)
			if [ $place -ne 0 ]
			then
				echo "Error : two different places were selected."
 				exit 1 
			fi
			place=6
			echo "You chose Antarctica."
			;;
		?) # This case is special for everything that is not in the list of accepted options. Accepted options without needed arguments also count.
			echo "Error : unknown option or need for argument. ($OPTARG)"
			exit 1
			;;
	esac
done

if [ $file -eq 0 ] # The user needs to use the -f option. If he doesn't, an error occurs.
then
	echo "Error : -f option is mandatory."
	exit 1
fi

if [ $sort -eq 0 ] # If the user does not chose a type of sort, AVL is selectionned by default.  
then
	echo "AVL sorting mode."
	sort=1
fi

if [ $temperature -eq 0 ] && [ $pressure -eq 0 ] && [ $wind -eq 0 ] && [ $height -eq 0 ] && [ $moisture -eq 0 ]
then
	echo "Error : one option is at least needed between -t -p -w -h -m."
 	exit 1
fi

echo "All options are correct."

# We delete the first line of the data file.
tail --lines=+2 $filename > ./C/data/file.txt

# 2) TIME AND PLACE OPTIONS
# After having got all the options, the script changes the original file if the user selected a specific time interval or place. 

# This function takes 3 dates (YYYY-MM-DD) as arguments and returns 1 if the date 3 is between date 1 and date 2.
timeinterval()
{
	# We isolate each year, month, day for each date.
	year1=${1:0:4}
	month1=${1:5:2}
	day1=${1:8:2}
	year2=${2:0:4}
	month2=${2:5:2}
	day2=${2:8:2}
	year3=${3:0:4}
	month3=${3:5:2}
	day3=${3:8:2}
	
	# The function then checks if date 3 is after date 1. If anything indicates it is not, 0 is returned. 
	if [ $year3 -lt $year1 ]
	then
		return 0
	else
		if [ $year3 -eq $year1 ]
		then
			if [ $month3 -lt $month1 ]
			then
				return 0
			else
				if [ $month3 -eq $month1 ]
				then
					if [ $day3 -lt $day1 ]
					then
						return 0
					fi
				fi
			fi
		fi
	fi

	# In another step, it checks if date 3 is before date 2. If anything indicates it is not, 0 is returned. 
	if [ $year3 -gt $year2 ]
	then
		return 0
	else
		if [ $year3 -eq $year2 ]
		then
			if [ $month3 -gt $month2 ]
			then
				return 0
			else
				if [ $month3 -eq $month2 ]
				then
					if [ $day3 -gt $day2 ]
					then
						return 0
					fi
				fi
			fi
		fi
	fi
	
	# When all the tests are done, 1 is returned.
	return 1
}

# If a place or a time interval was specified, the script activates the tempfile variable which means filtering is to be done.
if [ $place -gt 0 ] || [ $dates -eq 1 ]
then
	tempfile=1
	# Previous files are removed as a security measure.
	if [ -e ./C/data/tempplace.txt ]
	then
		rm ./C/data/tempplace.txt
	fi
	if [ -e ./C/data/temptimeandplace.txt ]
	then
		rm ./C/data/temptimeandplace.txt
	fi
	# The script creates files which serve to filter separately the places and the dates.
	touch ./C/data/tempplace.txt
	touch ./C/data/temptimeandplace.txt
	
	# First is the place filter
	# If a place was selected, the script reads each line and includes the line depending on the value of the station ID.
	# (see our PDF to see how we know which IDs correspond to which places)
	if [ $place -gt 0 ]
	then
		if [ $place -eq 1 ]
		then
			# Reading all lines with separator ; and all 15 fields
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -le 40349 ]
				then
					# Line is transferred to tempplace.txt if the station ID is correct.
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/tempplace.txt
				fi
			done < ./C/data/file.txt
			# The input is file.txt, the data file without the first line.
		fi

		if [ $place -eq 2 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -gt 80000 ] && [ $f1 -lt 88999 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/tempplace.txt
				fi
			done < ./C/data/file.txt
		fi

		if [ $place -eq 3 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -eq 71805 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/tempplace.txt
				fi
			done < ./C/data/file.txt
		fi

		if [ $place -eq 4 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -gt 78000 ] && [ $f1 -lt 79000 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/tempplace.txt
				fi
			done < ./C/data/file.txt
		fi

		if [ $place -eq 5 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -gt 61000 ] && [ $f1 -lt 67006 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/tempplace.txt
				fi
			done < ./C/data/file.txt
		fi

		if [ $place -eq 6 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -eq 89642 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/tempplace.txt
				fi
			done < ./C/data/file.txt
		fi
	# If no place was selected, the file is simply copied because no filtering needs to be done.
	else
		cat ./C/data/file.txt >> ./C/data/tempplace.txt
	fi

	# If the user specified a time interval, the filtering is done the same as with places.
	if [ $dates -eq 1 ]
	then
		# Each line is read. If the date in the line is in the chosen time interval, the program includes the line in temptimeandplace.txt 
		while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
		do
			timeinterval $date1 $date2 $f2
			# b is a variable used to get the return value of the function "timeinterval". We need to use $? to have the value written in b.
			b=$?
			if [ $b -eq 1 ]
			then
				echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> ./C/data/temptimeandplace.txt
			fi
		done < ./C/data/tempplace.txt
	# If the user didn't write dates, the first filtered file is just copied and becomes the second.
	else
		cat ./C/data/tempplace.txt >> ./C/data/temptimeandplace.txt
	fi
fi




# 3) CREATING TEMPORARY FILES
# After having done the options and the filtering if needed, the program filters the data file depending on the needed fields for each option.

# We create files for each possible choice. 
echo "" > ./C/data/temptemperature.csv
echo "" > ./C/data/temppressure.csv
echo "" > ./C/data/tempwind.csv
echo "" > ./C/data/tempheight.csv
echo "" > ./C/data/tempmoisture.csv

# If dates or place were not selected, the script works directly on file.txt (data file without the fields' names)
# A number is going to be the first line of each of these files. It will indicate to the C program what sort it needs to do.
# List of these numbers :
# Temperature mode 1 : 1100000
# Temperature mode 2 : 1200000
# Temperature mode 3 : 1300000
# Pressure mode 1    : 0011000
# Pressure mode 2    : 0012000
# Pressure mode 3    : 0013000
# Wind               : 0000100
# Height             : 0000010 
# Moisture           : 0000001
if [ $tempfile -eq 0 ]
then
	# Data is added to a specific file if the user chose the associated option. 
	# Temperature : 
	if [ $temperature -eq 1 ]
	then
		if [ $temperaturemode -eq 1 ]
		then
			# This echo will serve the C program in the next step.
			echo "1100000" > ./C/data/temptemperature.csv
			# We use cut to filter the needed fields
			# Temperature mode 1 fields : ID,temperature,minimal temperature over 24hrs, maximal temperature over 24hrs
			cut --delimiter=";" --fields=1,11,12,13 ./C/data/file.txt >> ./C/data/temptemperature.csv
		else
			if [ $temperaturemode -eq 2 ]
			then
				echo "1200000" > ./C/data/temptemperature.csv
				# Temperature mode 2 fields : Time,temperature
				cut --delimiter=";" --fields=2,11 ./C/data/file.txt >> ./C/data/temptemperature.csv
			else
				echo "1300000" > ./C/data/temptemperature.csv
				# Temperature mode 3 fields : ID,time,temperature
				cut --delimiter=";" --fields=1,2,11 ./C/data/file.txt >> ./C/data/temptemperature.csv
			fi
		fi
	fi

	# Pressure : 

	if [ $pressure -eq 1 ]
	then
		if [ $pressuremode -eq 1 ]
		then
			echo "0011000" > ./C/data/temppressure.csv
			# Pressure mode 1 fields : ID,pressure
			cut --delimiter=";" --fields=1,7 ./C/data/file.txt >> ./C/data/temppressure.csv
		else
			if [ $pressuremode -eq 2 ]
			then
				echo "0012000" > ./C/data/temppressure.csv
				# Pressure mode 2 fields : Time,pressure
				cut --delimiter=";" --fields=2,7 ./C/data/file.txt >> ./C/data/temppressure.csv
			else
				echo "0013000" > ./C/data/temppressure.csv
				# Pressure mode 3 fields : ID,time,pressure,
				cut --delimiter=";" --fields=1,2,7 ./C/data/file.txt >> ./C/data/temppressure.csv
			fi
		fi
	fi

	# Wind : 

	if [ $wind -eq 1 ]
	then
		echo "0000100" > ./C/data/tempwind.csv
		# Wind fields : ID, average wind orientation over 10 min, average wind speed over 10 min
		cut --delimiter=";" --fields=1,4,5 ./C/data/file.txt >> ./C/data/tempwind.csv
	fi

	# Height : 

	if [ $height -eq 1 ]
	then
		echo "0000010" > ./C/data/tempheight.csv
		# Height fields : ID, height
		cut --delimiter=";" --fields=1,14 ./C/data/file.txt >> ./C/data/tempheight.csv
	fi

	# Moisture : 

	if [ $moisture -eq 1 ]
	then
		echo "0000001" > ./C/data/tempmoisture.csv
		# Moisture fields : ID,moisture
		cut --delimiter=";" --fields=1,6 ./C/data/file.txt >> ./C/data/tempmoisture.csv
	fi

# If the user selected dates or a place, the same operations are done on the filtered file (temptimeandplace.txt) 
else
	# Temperature : 

	if [ $temperature -eq 1 ]
	then
		if [ $temperaturemode -eq 1 ]
		then
			echo "1100000" > ./C/data/temptemperature.csv
			cut --delimiter=";" --fields=1,11,12,13 ./C/data/temptimeandplace.txt >> ./C/data/temptemperature.csv
		else
			if [ $temperaturemode -eq 2 ]
			then
				echo "1200000" > ./C/data/temptemperature.csv
				cut --delimiter=";" --fields=2,11 ./C/data/temptimeandplace.txt >> ./C/data/temptemperature.csv
			else
				echo "1300000" > ./C/data/temptemperature.csv
				cut --delimiter=";" --fields=1,2,11 ./C/data/temptimeandplace.txt >> ./C/data/temptemperature.csv
			fi
		fi
	fi

	# Pressure : 

	if [ $pressure -eq 1 ]
	then
		if [ $pressuremode -eq 1 ]
		then
			echo "0011000" > ./C/data/temppressure.csv
			cut --delimiter=";" --fields=1,7 ./C/data/temptimeandplace.txt >> ./C/data/temppressure.csv
		else
			if [ $pressuremode -eq 2 ]
			then
				echo "0012000" > ./C/data/temppressure.csv
				cut --delimiter=";" --fields=2,7 ./C/data/temptimeandplace.txt >> ./C/data/temppressure.csv
			else
				echo "0013000" > ./C/data/temppressure.csv
				cut --delimiter=";" --fields=1,2,7 ./C/data/temptimeandplace.txt >> ./C/data/temppressure.csv
			fi
		fi
	fi

	# Wind : 

	if [ $wind -eq 1 ]
	then
		echo "0000100" > ./C/data/tempwind.csv
		cut --delimiter=";" --fields=1,4,5 ./C/data/temptimeandplace.txt >> ./C/data/tempwind.csv
	fi

	# Height : 

	if [ $height -eq 1 ]
	then
		echo "0000010" > ./C/data/tempheight.csv
		cut --delimiter=";" --fields=1,14 ./C/data/temptimeandplace.txt >> ./C/data/tempheight.csv
	fi

	# Moisture : 

	if [ $moisture -eq 1 ]
	then
		echo "0000001" > ./C/data/tempmoisture.csv
		cut --delimiter=";" --fields=1,6 ./C/data/temptimeandplace.txt >> ./C/data/tempmoisture.csv
	fi
fi


# 4) CALLING C PROGRAMS
# With the files created, the C programs are called to sort all the files, depending on the sorting mode selected.

check_C(){
	# The programs has to stop if the C code return something else than 0 (means an error has occured).
	if [ $? -ne 0 ]
	then
		exit $?
	fi
}

# We first compile the C code using make.
make CY-METEO

# descendingsort = 0 <==> -r will not be activated
if [ $descendingsort -eq 0 ]
then

	if [ $temperature -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/temptemperature.csv" -o "./C/data/temp_T.csv" --avl
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/temptemperature.csv" -o "./C/data/temp_T.csv" --abr
				check_C
			else
				./C/CY-METEO -f "./C/data/temptemperature.csv" -o "./C/data/temp_T.csv" --tab
				check_C
			fi
		fi
	fi
		

	# Pressure : 
	if [ $pressure -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/temppressure.csv" -o "./C/data/temp_P.csv" --avl
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/temppressure.csv" -o "./C/data/temp_P.csv" --abr
				check_C
			else
				./C/CY-METEO -f "./C/data/temppressure.csv" -o "./C/data/temp_P.csv" --tab
				check_C
			fi
		fi
	fi

	# Wind : 
	if [ $wind -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/tempwind.csv" -o "./C/data/temp_W.csv" --avl
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/tempwind.csv" -o "./C/data/temp_W.csv" --abr
				check_C
			else
				./C/CY-METEO -f "./C/data/tempwind.csv" -o "./C/data/temp_W.csv" --tab
				check_C
			fi
		fi
	fi

	# Height : 
	if [ $height -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/tempheight.csv" -o "./C/data/temp_H.csv" --avl
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/tempheight.csv" -o "./C/data/temp_H.csv" --abr
				check_C
			else
				./C/CY-METEO -f "./C/data/tempheight.csv" -o "./C/data/temp_H.csv" --tab
				check_C
			fi
		fi
	fi

	# Moisture : 
	if [ $moisture -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/tempmoisture.csv" -o "./C/data/temp_M.csv" --avl
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/tempmoisture.csv" -o "./C/data/temp_M.csv" --abr
				check_C
			else
				./C/CY-METEO -f "./C/data/tempmoisture.csv" -o "./C/data/temp_M.csv" --tab
				check_C
			fi
		fi
	fi

# descendingsort = 1 <==> -r will be activated
else
	if [ $temperature -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/temptemperature.csv" -o "./C/data/temp_T.csv" --avl -r
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/temptemperature.csv" -o "./C/data/temp_T.csv" --abr -r
				check_C
			else
				./C/CY-METEO -f "./C/data/temptemperature.csv" -o "./C/data/temp_T.csv" --tab -r
				check_C
			fi
		fi
	fi
		

	# Pressure : 
	if [ $pressure -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/temppressure.csv" -o "./C/data/temp_P.csv" --avl -r
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/temppressure.csv" -o "./C/data/temp_P.csv" --abr -r
				check_C
			else
				./C/CY-METEO -f "./C/data/temppressure.csv" -o "./C/data/temp_P.csv" --tab -r
				check_C
			fi
		fi
	fi

	# Wind : 
	if [ $wind -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/tempwind.csv" -o "./C/data/temp_W.csv" --avl -r
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/tempwind.csv" -o "./C/data/temp_W.csv" --abr -r
				check_C
			else
				./C/CY-METEO -f "./C/data/tempwind.csv" -o "./C/data/temp_W.csv" --tab -r
				check_C
			fi
		fi
	fi

	# Height : 
	if [ $height -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/tempheight.csv" -o "./C/data/temp_H.csv" --avl -r
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/tempheight.csv" -o "./C/data/temp_H.csv" --abr -r
				check_C
			else
				./C/CY-METEO -f "./C/data/tempheight.csv" -o "./C/data/temp_H.csv" --tab -r
				check_C
			fi
		fi
	fi

	# Moisture : 
	if [ $moisture -eq 1 ]
	then
		if [ $sort -eq 1 ]
		then
			./C/CY-METEO -f "./C/data/tempmoisture.csv" -o "./C/data/temp_M.csv" --avl -r
			check_C
		else
			if [ $sort -eq 2 ]
			then
				./C/CY-METEO -f "./C/data/tempmoisture.csv" -o "./C/data/temp_M.csv" --abr -r
				check_C
			else
				./C/CY-METEO -f "./C/data/tempmoisture.csv" -o "./C/data/temp_M.csv" --tab -r
				check_C
			fi
		fi
	fi
fi


# 5) USING GNUPLOT

# It first needs access to the data, that's why we move every temporary file in ./Gnuplot/data
if [ -e "./C/data/temp_T.csv" ]
then
	mv ./C/data/temp_T.csv ./Gnuplot/data/temp_T.csv
fi

if [ -e "./C/data/temp_P.csv" ]
then
	mv ./C/data/temp_P.csv ./Gnuplot/data/temp_P.csv
fi

if [ -e "./C/data/temp_W.csv" ]
then
	mv ./C/data/temp_W.csv ./Gnuplot/data/temp_W.csv
fi

if [ -e "./C/data/temp_H.csv" ]
then
	mv ./C/data/temp_H.csv ./Gnuplot/data/temp_H.csv
fi

if [ -e "./C/data/temp_M.csv" ]
then
	mv ./C/data/temp_M.csv ./Gnuplot/data/temp_M.csv
fi

# Gnuplot is then used on the sorted files to produce graphics
if [ $temperature = "1" ];then
	if [ $temperaturemode = "1" ];then
				gnuplot "./Gnuplot/gnuT1.sh"
				eog 'load_T1'
	elif [ $temperaturemode = "2" ];then
				# Last minute bug fix for T2 (and P2)
				if [ $descendingsort -eq 0 ]
				then
					tail --lines=+3 ./Gnuplot/data/temp_T.csv > ./Gnuplot/data/temppp.csv
					rm -rf ./Gnuplot/data/temp_T.csv
					mv ./Gnuplot/data/temppp.csv ./Gnuplot/data/temp_T.csv
					gnuplot "./Gnuplot/gnuT2.sh"
					eog 'load_T2'
				else
					head --lines=-2 ./Gnuplot/data/temp_T.csv > ./Gnuplot/data/temppp.csv
					rm -rf ./Gnuplot/data/temp_T.csv
					mv ./Gnuplot/data/temppp.csv ./Gnuplot/data/temp_T.csv
					gnuplot "./Gnuplot/gnuT2.sh"
					eog 'load_T2'
				fi
	elif [ $temperaturemode = "3" ];then
				gnuplot "./Gnuplot/gnuT3.sh"
				eog 'load_T3'
	fi
fi

if [ $pressure = "1" ];then
	if [ $pressuremode = "1" ];then
				gnuplot "./Gnuplot/gnuP1.sh"
				eog 'load_P1'
	elif [ $pressuremode = "2" ];then
				if [ $descendingsort -eq 0 ]
				then
					tail --lines=+3 ./Gnuplot/data/temp_P.csv > ./Gnuplot/data/temppp.csv
					rm -rf ./Gnuplot/data/temp_P.csv
					mv ./Gnuplot/data/temppp.csv ./Gnuplot/data/temp_P.csv
					gnuplot "./Gnuplot/gnuP2.sh"
					eog 'load_P2'
				else
					head --lines=-2 ./Gnuplot/data/temp_P.csv > ./Gnuplot/data/temppp.csv
					rm -rf ./Gnuplot/data/temp_P.csv
					mv ./Gnuplot/data/temppp.csv ./Gnuplot/data/temp_P.csv
					gnuplot "./Gnuplot/gnuP2.sh"
					eog 'load_P2'
				fi
				
	elif [ $pressuremode = "3" ];then
				gnuplot "./Gnuplot/gnuP3.sh"
				eog 'load_P3'
	fi
fi

if [ $wind = "1" ];then
	gnuplot "./Gnuplot/gnuW.sh"
	eog 'load_W'
fi

if [ $height = "1" ];then
	gnuplot "./Gnuplot/gnuH.sh"
	eog 'load_H'
fi

if [ $moisture = "1" ];then
	gnuplot "./Gnuplot/gnuM.sh"
	eog 'load_M'
fi

# If no error occured, then the program comes to its end with a 0 exit.
echo " "
echo "The program executed successfully."
exit 0
