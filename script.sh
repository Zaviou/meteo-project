#!/bin/bash
#  \   `   |  ~   []  {}

echo "Bienvenue dans CY-Météo !"

trichoisi=0
lieuchoisi=0
fichier=0
nomfichier=0
date1=0
date2=0
vent=0
pression=0
modepression=0
humidite=0
temperature=0
modetemperature=0
altitude=0

while getopts ":f:t:p:whmFGSAOQd:-:" option
do
	case $option in
		-)
			case "$OPTARG" in
				avl)
					if [ $trichoisi -ne 0 ]
					then
						echo "Erreur : Vous avez choisi deux options de tri."
 						exit 1 
					fi
					trichoisi=1
					echo "Tri AVL."
					;;
				abr)
					if [ $trichoisi -ne 0 ]
					then
						echo "Erreur : Vous avez choisi deux options de tri."
 						exit 1 
					fi
					trichoisi=2
					echo "Tri ABR."
					;;
				tab)
					if [ $trichoisi -ne 0 ]
					then
						echo "Erreur : Vous avez choisi deux options de tri."
 						exit 1 
					fi
					trichoisi=3
					echo "Tri tableau."
					;;
				help)
					echo "Ceci devrait vous aider."
					exit 0
					;;
				*)
					echo "Erreur : option non reconnue."
					exit 1
					;;
			esac
			;;	
		f)
			nomfichier=$OPTARG
			fichier=1
			;;
		t)
			temperature=1
			case "$OPTARG" in
				1)
					modetemperature=1
					;;
				2)
					modetemperature=2
					;;
				3)
					modetemperature=3
					;;
				*)
					echo "Erreur : le mode pour la température n'a pas été spécifié ou est erroné."
					exit 1
					;;
			esac
			;;
		p)
			pression=1
			case "$OPTARG" in
				1)
					modepression=1
					;;
				2)
					modepression=2
					;;
				3)
					modepression=3
					;;
				*)
					echo "Erreur : le mode pour la pression n'a pas été spécifié ou est erroné."
					exit 1
					;;
			esac
			;;
		w)
			vent=1
			;;
		h)
			altitude=1
			;;
		m)
			humidite=1
			;;
		d)
			lg=${#OPTARG}
			if [ $lg -ne 20 ]
			then
				echo "Erreur : format des dates incorrect pour l'option d (longueur)."
 				exit 1 
			fi
			if [ ${OPTARG:4:1} != "-" ] || [ ${OPTARG:7:1} != "-" ] || [ ${OPTARG:14:1} != "-" ] || [ ${OPTARG:17:1} != "-" ]
			then
				echo "Erreur : format des dates incorrect pour l'option d (tirets)."
 				exit 1
			fi

			date1=${OPTARG:0:10}
			date2=${OPTARG:10:10}

			if [ ${date1:0:4} -gt ${date2:0:4} ]
			then
				echo "Erreur : la première date est après la seconde."
				exit 1
			else 
				if [ ${date1:0:4} -eq ${date2:0:4} ]
				then
					if [ ${date1:5:2} -gt ${date2:5:2} ]
					then
						echo "Erreur : la première date est après la seconde."
						exit 1
					else
						if [ ${date1:5:2} -eq ${date2:5:2} ]
						then
							if [ ${date1:8:2} -gt ${date2:8:2} ]
							then
								echo "Erreur : la première date est après la seconde."
								exit 1
							fi
						fi
					fi
				fi
			fi
			;;
		F)
			if [ $lieuchoisi -ne 0 ]
			then
				echo "Erreur : Vous avez choisi deux lieux différents."
 				exit 1 
			fi
			lieuchoisi=1
			echo "Vous avez choisi le lieu F."
			;;		
		G)
			if [ $lieuchoisi -ne 0 ]
			then
				echo "Erreur : Vous avez choisi deux lieux différents."
 				exit 1 
			fi
			lieuchoisi=2
			echo "Vous avez choisi le lieu G."
			;;
		S)
			if [ $lieuchoisi -ne 0 ]
			then
				echo "Erreur : Vous avez choisi deux lieux différents."
 				exit 1 
			fi
			lieuchoisi=3
			echo "Vous avez choisi le lieu S."
			;;
		A)
			if [ $lieuchoisi -ne 0 ]
			then
				echo "Erreur : Vous avez choisi deux lieux différents."
 				exit 1 
			fi
			lieuchoisi=4
			echo "Vous avez choisi le lieu A."
			;;
		O)
			if [ $lieuchoisi -ne 0 ]
			then
				echo "Erreur : Vous avez choisi deux lieux différents."
 				exit 1 
			fi
			lieuchoisi=5
			echo "Vous avez choisi le lieu O."
			;;
		Q)
			if [ $lieuchoisi -ne 0 ]
			then
				echo "Erreur : Vous avez choisi deux lieux différents."
 				exit 1 
			fi
			lieuchoisi=6
			echo "Vous avez choisi le lieu Q."
			;;
		?)
			echo "Erreur : option non reconnue ou requiert un argument. ($OPTARG)"
			exit 1
			;;
	esac
done

if [ $fichier -eq 0 ]
then
	echo "Erreur : vous n'avez pas renseigné l'option obligatoire -f."
	exit 1
fi

if [ $trichoisi -eq 0 ]
then
	echo "Erreur : vous n'avez pas spécifié d'option de tri."
	exit 1
fi



echo "Traitement terminé."
exit 0
