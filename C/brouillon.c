  f =fopen(nom_fichier, "r");
if (f==NULL){
	exit(2);
}

  o =fopen(nom_fichier, "w");
if (o==NULL){
	exit(3);
}

"data/temp_T1.csv"

**AVL**

	* T
sort_T1(f, o, int r)
sort_T2(f, o, int r)
sort_T3(f, o, int r)

	*P
sort_P1(f, o, int r)
sort_P2(f, o, int r)
sort_P3(f, o, int r)

	* W-H-M
sort_W(f, o, int r)
sort_H(f, o, int r)
sort_M(f, o, int r)

**LIST**

	** T
tabT1sort1(o,linkedlist_T1(f))
tabT1sort2(o,linkedlist_T1(f))	-r

tabT2sort1(o,linkedlist_T2(f))
tabT2sort2(o,linkedlist_T2(f))	-r

tabT3sort1(o,linkedlist_T3(f))
tabT3sort2(o,linkedlist_T3(f))	-r

	** P
tabP1sort1(o,linkedlist_P1(f))
tabP1sort2(o,linkedlist_P1(f))	-r

tabP2sort1(o,linkedlist_P2(f))
tabP2sort2(o,linkedlist_P2(f))	-r

tabP3sort1(o,linkedlist_P3(f))
tabP3sort2(o,linkedlist_P3(f))	-r

	** W-H-M
tabWsort1(o, linkedlist_W(f))
tabWsort2(o, linkedlist_W(f))	-r

tabHsort1(o,linkedlist_H(f))
tabHsort2(o,linkedlist_H(f))	-r

tabMsort1(o,linkedlist_M(f))
tabMsort2(o,linkedlist_M(f))	-r
