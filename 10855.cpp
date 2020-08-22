#include <stdio.h>
#include <math.h>
#include <string.h>

/* LA compejidad de este algoritmo si estuviera terminado seria de O(n**2), ya que se nesecitarian dos ciclos para voltear
Y encontrear los cuadrados dentro del mas grande*/

int main(){

	char cuadro1[100][100], cuadro2[100][100];
	int c1, c2;
	
	while(scanf("%d %d",&c1, &c2) && c1 != 0){
		
		for(int i = 0; i < c1; i++){
			scanf("%s", cuadro1[i][500]);
		}
		
		for(int i = 0; i < c1; i++){
			scanf("%s", cuadro2 [i][500]);
		}
	}

return 0;
}
