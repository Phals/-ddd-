#include <stdio.h>
#include <math.h>

int get_qtd_int(){
	
	int qtdInt;
	
	printf("\n\nQuantidade de interacoes: ");
	scanf("%d", &qtdInt);
	
	return qtdInt;
	
}

int metodos_series_infinitas(){
	
	int opc_metodo;
	
	printf("\n================ Metodos de series infinitas ================");
	
	printf("\n\n");
	
	printf("1 - Metodo de John Wallis");
	printf("\n2 - Metodo de Francois Viete");
	printf("\n3 - Metodo de Leibniz/Taylor");
	printf("\n4 - Metodo de Newton-Rhapson");
	
	opc_metodo = get_opc();
	
	switch(opc_metodo){
		case 1:
			john_wallis();
			break;
		case 2:
			francois_viete();
			break;
		case 3:
			leibniz_taylor();
			break;
		case 4:
			newton_rhapson();
			break;
		default:
			printf("ERRO");
			break;
	}
	
	return 0;
	
}

int metodos_estatisticos(){
	
	int opc_metodo;
	
	printf("\n================ Metodos estatisticos ================");
	
	printf("\n\n");
	
	printf("1 - Metodo de Monte Carlos");
	printf("\n2 - Metodo Agulha de Buffon");
	
	opc_metodo = get_opc();
	
	switch(opc_metodo){
		case 1:
			monte_carlos();
			break;
		case 2:
			agulha_buffon();
			break;
		default:
			printf("ERRO");
			break;
	}
	
	return 0;
	
}

int monte_carlos(){
	
	printf("\n=============== Metodo estatisticos - Monte Carlos ===============");
	
	printf("\nMonte Carlos - Em desenvolvimento\n");
	
	return 0;
	
}

int agulha_buffon(){
	
	printf("\n=============== Metodo estatisticos -  Agulha de Buffon ===============");
	
	printf("\nAgulha de Buffon - Em desenvolvimento\n");
	
	return 0;
	
}

int leibniz_taylor(){
	
	printf("\n=============== Series infinitas -  Leibniz/Taylor ===============");
	
	int aux = 1;
	int qtdInt = get_qtd_int();
	
	double a = 1;
	
	double pi = 0.0, serie = 0.0;
	
	while(aux <= qtdInt){
		
		if(aux%2 == 0){
			serie -= 1 / a;
		}else{
			serie += 1 / a;
		}
		
		pi = serie * 4;
		
		printf("%.20lf\n", pi);
		
		a += 2; 
		
		aux++;
		
	}
	
	return 0;
	
}

int john_wallis(){
	
	printf("\n=============== Series infinitas - John Wallis ===============");
	
	int aux;
	int qtdInt = get_qtd_int();
	
	double a = 2, b = 1;
	
	double pi = 0.0, serie = 1.0;
	
	for(aux=1; aux<=qtdInt; aux++){
		
		serie = serie * (a/b);
		
		pi = serie * 2;
		
		printf("%.20lf\n", pi);
		
		if(aux%2 == 0){
			a += 2;
		}else{
			b += 2;
		}
		
	}
	
	return 0;
	
}

int newton_rhapson(){
	
	printf("\n=============== Series infinitas - Newton-Rhapson ===============");
	
	int aux;
	int qtdInt = get_qtd_int();
	
	double x0 = 0.57079632679489661923;
	
	for(aux=1; aux<=qtdInt; aux++){
	
	   x0 = x0 - sin(x0)/cos(x0);
	   
 	   printf("%.20lf\n", x0);
 	   
    }
	
	return 0;
	
}

int francois_viete(){

	printf("\n=============== Series infinitas - Francois Viete ===============");

	int aux;
	int qtdInt = get_qtd_int();
	
	double x = sqrt(2), temp = sqrt(2);
	
	double pi = 0.0, serie = 0.0;
	
	for(aux=1; aux<=qtdInt; aux++){
		
		serie = x / pow(2, aux);
		
		pi = 2 / serie;
		
		printf("%.20lf\n", pi);
		
		temp = sqrt(2 + temp);
		
		x *= temp;
		
	}
	
	return 0;

}

int get_opc(){
	
	int opc;
	
	printf("\n\nDigite uma opcao: ");
	scanf("%d", &opc);
	
	return opc;
	
}

int main(){
	
	printf("\n=================== CALCULAR PI ===================");
	
	int opc_metodo;
	
	printf("\n\n1 - Metodos de series infinitas");
	printf("\n2 - Metodos  estatisticos");
	
	opc_metodo = get_opc();
	
	switch(opc_metodo){
		case 1:
			metodos_series_infinitas();
			break;
		case 2:
			metodos_estatisticos();
			break;
		default:
			printf("ERRO");
			break;
	}
	
	return 0;
	
}
