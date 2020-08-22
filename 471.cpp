/*

punto 2 # 471: Magic numbers

la complejidad de este algoritmo se basa en el limite que es 9876543210 ya que este es
el numero mas grande que se puede conseguir sin que se repitan sus digitos, por ende en
la funcion comparar el maximo de veces que se harian las respectivas comprovaciones es de
100(10 * 10) debido a los digitos de los numeros.

tambien depende de los casos que decida el usuario.


*/
#include <cstdio>

int comparar(long long num){	
	int digit;
	long long aux;
	
    while(num){

        digit = num % 10;
        num = num / 10;
        aux = num;
        while(aux){
        	
            if((aux % 10) == digit){
                return 0;

            }
            else{
            aux = aux / 10;
            }
        }
    }
    
    if(num == 0){
        return 1;
    }
	
}

int main(){
	
	int casos;
	scanf("%d", &casos);
	
	long long s1, s2 = 1, cont, maximo = 9876543210;
	
	while(casos--){
		
		scanf("%lld", &s1);
		
		
		//printf("%lld %d\n" ,s1, comparar(s1));
		
		for(int cont = 1; s1 * cont <= maximo; cont++){
			
			s2 = s1 * cont;
			//printf("hola");
			
			if(comparar(cont) && comparar(s2))
				printf("%lld / %lld = %lld\n", s2, cont, s1);
					
		}
		if(casos)
			printf("\n");
	}
	
	
	return 0;
}
