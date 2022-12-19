#!/bin/bash
#  \   `   |  ~   []  {}

echo "Welcome to CY-Météo !"

# Initialisation of variables. Here, we use various integers to keep track of the user's choices and check for errors. 
sort=0
place=0
file=0
filename=0
date1=0
date2=0
wind=0
pressure=0
pressuremode=0
moisture=0
temperature=0
temperaturemode=0
height=0

# This loop runs until all the options and their arguments have been read. Inside, we specify what happens for each given option.
# The string below is the list of the accepted options. They are followed by ':' if they need arguments.
while getopts ":f:t:p:whmFGSAOQd:-:" option
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
		f)  # The -f option handles the data file access. The user specifies the path to the file in its argument.
			filename=$OPTARG
			file=1
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
					pressure mode=1
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

if [ $sort -eq 0 ] # Same for a sorting mode.
then
	echo "Error : a sort option is mandatory."
	exit 1
fi

# If no error occured, then the program comes to its end with a 0 exit.
echo "The program executed successfully."
exit 0
