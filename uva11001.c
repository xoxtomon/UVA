#include <stdio.h>
#include <math.h>


int main(){
	int vto,vo;
	
	while( scanf("%d %d", &vto, &vo) != EOF){
		if( (vto ==0) && (vo == 0) ){
			break;
		}
		
		int i, div = 0, bandera = 0;
		double v, x, len_max = 0, len_tmp;
	
		for(i = 0; i < vto; i++){
			v = (double)vto/i;
			if(v > vo){
				x = 0.3 * sqrt(v - vo);
				len_tmp = i * x;
				
				if(len_tmp >= len_max){
					if(fabs(len_tmp - len_max) < 1e-9){
						bandera = 1;
					}
					else{
						len_max = len_tmp;
						div = i;
					}
				}
			}
			else break;
		}
		
		if(bandera == 1){
			printf("0\n");
		}
		else{
			printf("%d\n",div);
		}
	}
}
