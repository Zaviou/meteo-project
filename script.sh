#!/bin/bash
#  \   `   |  ~   []  {}

echo "Welcome to CY-Météo !"

# 1) OPTIONS READING

# Initialisation of variables. Here, we use various integers to keep track of the user's choices and check for errors. 
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
					echo "Help message."
					exit 0
					;;
				*)  # If the argument for the -- option is anything other than what is possible, an error occurs.
					echo "Error : unknown option."
					exit 1
					;;
			esac
			;;	
		f)  # The -f option handles access to the data file. The user specifies the path to the file in its argument.
			filename=$OPTARG
			file=1
			;;
		r)  # If a descending sort is selected with -r, the associated variable goes from 0 to 1.
			descendingsort=1
			;;
		t)  # The temperature option. Again, we use cases because it needs a mode that is specified by the user in its argument.
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
			wind=1
			;;
		h) # The height option.
			height=1
			;;
		m) # The moisture option.
			moisture=1
			;;
		d)                            # The time option.Two dates are to be given by the user in this format : YYYY-MM-DDYYYY-MM-DD.
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

tail --lines=+2 $filename > file.txt

# 2) TIME AND PLACE OPTIONS

if [ $place -gt 0 ] || [ $dates -eq 1 ]
then
	tempfile=1
	touch tempplace.txt
	touch temptimeandplace.txt

	if [ $place -gt 0 ]
	then
		if [ $place -eq 1 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -le 40349 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> tempplace.txt
				fi
			done < file.txt
		fi

		if [ $place -eq 2 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -gt 80000 ] && [ $f1 -lt 88999 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> tempplace.txt
				fi
			done < file.txt
		fi

		if [ $place -eq 3 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -eq 71805 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> tempplace.txt
				fi
			done < file.txt
		fi

		if [ $place -eq 4 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -gt 78000 ] && [ $f1 -lt 79000 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> tempplace.txt
				fi
			done < file.txt
		fi

		if [ $place -eq 5 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -gt 61000 ] && [ $f1 -lt 67006 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> tempplace.txt
				fi
			done < file.txt
		fi

		if [ $place -eq 6 ]
		then
			while IFS=";" read -r f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15
			do
				if [ $f1 -eq 89642 ]
				then
					echo "$f1;$f2;$f3;$f4;$f5;$f6;$f7;$f8;$f9;$f10;$f11;$f12;$f13;$f14;$f15" >> tempplace.txt
				fi
			done < file.txt
		fi
	else
		cat file.txt >> tempplace.txt
	fi

	if [ $dates -eq 1 ]
	then
		cat tempplace.txt >> temptimeandplace.txt
	else
		cat tempplace.txt >> temptimeandplace.txt
	fi
fi




# 3) CREATING TEMPORARY FILES

if [ $tempfile -eq 0 ]
then
	# Temperature : 

	if [ $temperature -eq 1 ]
	then
		if [ $temperaturemode -eq 1 ]
		then
			echo "1100000" > temptemperature.txt
			cut --delimiter=";" --fields=1,11,12,13 file.txt >> temptemperature.txt
		else
			if [ $temperaturemode -eq 2 ]
			then
				echo "1200000" > temptemperature.txt
				cut --delimiter=";" --fields=2,11 file.txt >> temptemperature.txt
			else
				echo "1300000" > temptemperature.txt
				cut --delimiter=";" --fields=1,2,11 file.txt >> temptemperature.txt
			fi
		fi
	fi

	# Pressure : 

	if [ $pressure -eq 1 ]
	then
		if [ $pressuremode -eq 1 ]
		then
			echo "0011000" > temppressure.txt
			cut --delimiter=";" --fields=1,7 file.txt >> temppressure.txt
		else
			if [ $pressuremode -eq 2 ]
			then
				echo "0012000" > temppressure.txt
				cut --delimiter=";" --fields=2,7 file.txt >> temppressure.txt
			else
				echo "0013000" > temppressure.txt
				cut --delimiter=";" --fields=1,2,7 file.txt >> temppressure.txt
			fi
		fi
	fi

	# Wind : 

	if [ $wind -eq 1 ]
	then
		echo "0000100" > tempwind.txt
		cut --delimiter=";" --fields=1,4,5 file.txt >> tempwind.txt
	fi

	# Height : 

	if [ $height -eq 1 ]
	then
		echo "0000010" > tempheight.txt
		cut --delimiter=";" --fields=1,14 file.txt >> tempheight.txt
	fi

	# Moisture : 

	if [ $moisture -eq 1 ]
	then
		echo "0000001" > tempmoisture.txt
		cut --delimiter=";" --fields=1,6 file.txt >> tempmoisture.txt
	fi

else
	# Temperature : 

	if [ $temperature -eq 1 ]
	then
		if [ $temperaturemode -eq 1 ]
		then
			echo "1100000" > temptemperature.txt
			cut --delimiter=";" --fields=1,11,12,13 temptimeandplace.txt >> temptemperature.txt
		else
			if [ $temperaturemode -eq 2 ]
			then
				echo "1200000" > temptemperature.txt
				cut --delimiter=";" --fields=2,11 temptimeandplace.txt >> temptemperature.txt
			else
				echo "1300000" > temptemperature.txt
				cut --delimiter=";" --fields=1,2,11 temptimeandplace.txt >> temptemperature.txt
			fi
		fi
	fi

	# Pressure : 

	if [ $pressure -eq 1 ]
	then
		if [ $pressuremode -eq 1 ]
		then
			echo "0011000" > temppressure.txt
			cut --delimiter=";" --fields=1,7 temptimeandplace.txt >> temppressure.txt
		else
			if [ $pressuremode -eq 2 ]
			then
				echo "0012000" > temppressure.txt
				cut --delimiter=";" --fields=2,7 temptimeandplace.txt >> temppressure.txt
			else
				echo "0013000" > temppressure.txt
				cut --delimiter=";" --fields=1,2,7 temptimeandplace.txt >> temppressure.txt
			fi
		fi
	fi

	# Wind : 

	if [ $wind -eq 1 ]
	then
		echo "0000100" > tempwind.txt
		cut --delimiter=";" --fields=1,4,5 temptimeandplace.txt >> tempwind.txt
	fi

	# Height : 

	if [ $height -eq 1 ]
	then
		echo "0000010" > tempheight.txt
		cut --delimiter=";" --fields=1,14 temptimeandplace.txt >> tempheight.txt
	fi

	# Moisture : 

	if [ $moisture -eq 1 ]
	then
		echo "0000001" > tempmoisture.txt
		cut --delimiter=";" --fields=1,6 temptimeandplace.txt >> tempmoisture.txt
	fi
fi


# 4) CALLING C PROGRAMS


# 5) USING GNUPLOT


# If no error occured, then the program comes to its end with a 0 exit.
echo "The program executed successfully."
exit 0
