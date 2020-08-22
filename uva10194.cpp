#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//La complejidad de este algoritmo es de O(n^3).

typedef struct{
	int ptos,
		partidos,
		g,
		p,
		e,
		difg,
		golMarc,
		golEnc;
	char nombre[30];
}Equipo;

void sortArray(Equipo arr[], int size){
	bool swapped;
	do{
		swapped = false;
		int i;
		for(i=0;i<(size-1);i++){
			if(arr[i].ptos < arr[i+1].ptos){
				swap(arr[i],arr[i+1]);
				swapped = true;
			}
			else{
				if(arr[i].ptos == arr[i+1].ptos){
					if(arr[i].g < arr[i+1].g){
						swap(arr[i],arr[i+1]);
						swapped = true;
					}
					else{
						if(arr[i].g == arr[i+1].g){
							if(arr[i].difg < arr[i+1].difg){
								swap(arr[i],arr[i+1]);
								swapped = true;
							}
							else{
								if(arr[i].difg == arr[i+1].difg){
									if(arr[i].golMarc < arr[i+1].golMarc){
										swap(arr[i],arr[i+1]);
										swapped = true;
									}
									else{
										if(arr[i].golMarc == arr[i+1].golMarc){
											if(arr[i].partidos > arr[i+1].partidos){
												swap(arr[i],arr[i+1]);
												swapped = true;
											}
											else{
												if(strcasecmp(arr[i].nombre,arr[i+1].nombre) > 0){
													swap(arr[i],arr[i+1]);
													swapped = true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	while(swapped);
}

int main(){
	int casos,x;
	scanf("%d",&casos);  
	for(x=0;x<casos;x++){
		/*char buf[100], prueba[10], prueba2[10];
  		int i,j=2;
  		Equipo arr[30];
  		for(i=0;i<j;i++){
		scanf("%[^\n]%*c",arr[i].nombre);
		}*/
  		/*gets(buf);*/
		/*sscanf(buf,"%[^#]#%d@%d#%[^\n]",prueba,&i,&j,prueba2);*/
		/*printf("%s\n",prueba);*/
		/*printf("%d\n",i);*/
		/*printf("%d\n",j);*/
	
		/*for(i=0;i<j;i++){
			printf("%s\n",arr[i].nombre);
		}*/

		char torneo[100];
		Equipo *arr = (Equipo*)malloc(30*sizeof(Equipo));
		int nroTeams,part,i;
		scanf(" %[^\n]%*c",&torneo);
		scanf("%d",&nroTeams);
		for(i=0;i<nroTeams;i++){
			scanf(" %[^\n]%*c",&arr[i].nombre);
			arr[i].partidos=0;
			arr[i].ptos=0;
			arr[i].g=0;
			arr[i].e=0;
			arr[i].p=0;
			arr[i].difg=0;
			arr[i].golMarc=0;
			arr[i].golEnc=0;
		}
		/*for(i=0;i<nroTeams;i++){
			printf("%s\n",arr[i].nombre);
		}*/
		scanf("%d",&part);
		for(i=0;i<part;i++){
			char buf[100],eq1[30], eq2[30];
			int geq1,geq2,j;
			scanf("%s",&buf);
			sscanf(buf,"%[^#]#%d@%d#%[^\n]",eq1,&geq1,&geq2,eq2);
			//printf("%s-%d\n%d-%s\n",&eq1,geq1,geq2,&eq2);
			for(j=0;j<nroTeams;j++){
				if(strcmp(arr[j].nombre,eq1)==0){
				//	printf("%d\n",arr[j].difg);
					arr[j].partidos+=1;
					arr[j].golMarc+=geq1;
					arr[j].golEnc+=geq2;
					arr[j].difg+=(geq1-geq2);
					if(geq1>geq2){
						arr[j].ptos+=3;
						arr[j].g+=1;
					}
					if(geq1==geq2){
						arr[j].ptos+=1;
						arr[j].e+=1;
					}
					if(geq1<geq2){
					//	arr[j].ptos+=0;
						arr[j].p+=1;
					}
					//printf("%d\n",arr[j].difg);
				}
				if(strcmp(arr[j].nombre,eq2)==0){
				//	printf("%d\n",arr[j].difg);
					arr[j].partidos+=1;
					arr[j].golMarc+=geq2;
					arr[j].golEnc+=geq1;
					arr[j].difg+=(geq2-geq1);
					if(geq2>geq1){
						arr[j].ptos+=3;
						arr[j].g+=1;
					}
					if(geq1==geq2){
						arr[j].ptos+=1;
						arr[j].e+=1;
					}
					if(geq2<geq1){
					//	arr[j].ptos+=0;
						arr[j].p+=1;
					}
					//printf("%d\n",arr[j].difg);
				}				
			}
		}
		
		sortArray(arr,nroTeams);
		
		printf("%s\n",torneo);
		int j=1;
		for(i=0;i<(nroTeams);i++){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",j,arr[i].nombre,arr[i].ptos,arr[i].partidos,arr[i].g,arr[i].e,arr[i].p,
			arr[i].difg,arr[i].golMarc,arr[i].golEnc);
			j++;
		}
		free(arr);
	}	
  }
