#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numero_cidades = 29;
int inicial = 1;

//----------------------------------------------------------------------------------------------

double **alocarMatriz();
void inicializar(double **matriz);
void preencheMatrizDistancia(double **matriz_distancias, double coordenadas[][numero_cidades]);
void preenche(double **coordenadas, double **matriz_distancia, int controle);
void imprimeMatriz(double ** matriz);
void distanciaEuclidiana(double **coordenadas, double **MatrizDistancia);
//----------------------------------------------------------------------------------------------
int main(){

	double **Matriz = alocarMatriz();
	double **MatrizDistancia = alocarMatriz();
	double **coordenadas = alocarMatriz();

	inicializar(Matriz);
	inicializar(MatrizDistancia);
	preenche(coordenadas,MatrizDistancia);

	if(numero_cidades == 15 || numero_cidades == 29 || numero_cidades == 38){
		distanciaEuclidiana(coordenadas,MatrizDistancia);
	} 

	imprimeMatriz(Matriz);
	imprimeMatriz(MatrizDistancia);
	imprimeMatriz(coordenadas);

}

//----------------------------------------------------------------------------------------------
double **alocarMatriz(){
    int i;
    double **matriz = (double**)malloc(numero_cidades*sizeof(double*));
    for(i=0;i<numero_cidades;i++){
        matriz[i] = (double*)malloc(numero_cidades*sizeof(double));
    }
    return matriz;
}
//----------------------------------------------------------------------------------------------
void inicializar(double **matriz){
    int i,j;
    for(i=0;i<numero_cidades;i++){
        for(j=0;j<numero_cidades;j++){
            if(i!=j)
                matriz[i][j] = inicial;
            else
                matriz[i][j] = 0.0;
        }
    }
}
//----------------------------------------------------------------------------------------------
void preencheMatrizDistancia(double **matriz_distancias, double coordenadas[][numero_cidades]){
    int i,j;
    for(i=0;i<numero_cidades;i++){
        matriz_distancias[i][i] = 0;
        for(j=0;j<i;j++){
            matriz_distancias[i][j] = sqrt((powf(coordenadas[0][i]-coordenadas[0][j],2.0)+powf(coordenadas[1][i]-coordenadas[1][j],2.0)));
            matriz_distancias[j][i] = matriz_distancias[i][j];
        }
    }
}
//----------------------------------------------------------------------------------------------
void preenche(double **coordenadas, double **matriz_distancia){

	if(numero_cidades == 5){
    double matriz_distancias[5][5] = {
                                   {0.0,1.0,2.2,2.0,4.1},
                                   {1.0,0.0,1.4,2.2,4.0},
                                   {2.2,1.4,0.0,2.2,3.2},
                                    {2.0,2.2,2.2,0.0,2.2},
                                    {4.1,4.0,3.2,2.2,0.0}
                                    };
	}

	if(numero_cidades == 6){
    double matriz_distancias[6][6] = {
                                {0,353,582,372,641,559},
                                {353,0,231,99,426,502},
                                {582,231,0,331,326,750},
                                {372,99,331,0,269,403},
                                {641,426,326,269,0,424},
                                {559,502,750,403,424,0}
                                };
}
	if(numero_cidades == 15){
    double coordenadas[2][15] = {
                            {200, 300, 300, 1000, 600, 1700, 1400, 1200, 200, 1200, 500, 1000, 1900, 400, 1600},
                            {300, 700, 1700, 1900, 1400, 1600, 800, 500, 1000, 1100, 900, 900, 1000, 500, 200}
                            };

    }

    if(numero_cidades == 29){
    double coordenadas[2][29] = {
                            {20833.3333,20900.0000,21300.0000,21600.0000,21600.0000,21600.0000,22183.3333,22583.3333,22683.3333,23616.6667,
                             23700.0000,23883.3333,24166.6667,25149.1667,26133.3333,26150.0000,26283.3333,26433.3333,26550.0000,26733.3333,
                             27026.1111,27096.1111,27153.6111,27166.6667,27233.3333,27233.3333,27266.6667,27433.3333,27462.5000},
                            {17100.0000,17066.6667,13016.6667,14150.0000,14966.6667,16500.0000,13133.3333,14300.0000,12716.6667,15866.6667,
                             15933.3333,14533.3333,13250.0000,12365.8333,14500.0000,10550.0000,12766.6667,13433.3333,13850.0000,11683.3333,
                             13051.9444,13415.8333,13203.3333,9833.3333,10450.0000,11783.3333,10383.3333,12400.0000,12992.2222}
                            };
                        }

      if(numero_cidades == 38){
    double coordenadas[2][38] = {
                            {11003.611100,11108.611100,11133.333300,11155.833300,11183.333300,11297.500000,11310.277800,11416.666700,11423.888900,11438.333300,
                             11461.111100,11485.555600,11503.055600,11511.388900,11522.222200,11569.444400,11583.333300,11595.000000,11600.000000,11690.555600,
                             11715.833300,11751.111100,11770.277800,11785.277800,11822.777800,11846.944400,11963.055600,11973.055600,12058.333300,12149.444400,
                             12286.944400,12300.000000,12355.833300,12363.333300,12372.777800,12386.666700,12421.666700,12645.000000},
                            {42102.500000,42373.888900,42885.833300,42712.500000,42933.333300,42853.333300,42929.444400,42983.333300,43000.277800,42057.222200,
                             43252.777800,43187.222200,42855.277800,42106.388900,42841.944400,43136.666700,43150.000000,43148.055600,43150.000000,42686.666700,
                             41836.111100,42814.444400,42651.944400,42884.444400,42673.611100,42660.555600,43290.555600,43026.111100,42195.555600,42477.500000,
                             43355.555600,42433.333300,43156.388900,43189.166700,42711.388900,43334.722200,42895.555600,42973.333300}
                            };
      }
}
//----------------------------------------------------------------------------------------------
void imprimeMatriz(double **matriz){
    int i,j;
    for(i=0;i<numero_cidades;i++){
        for(j=0;j<numero_cidades;j++){
 		printf("Matriz[%d][%d] = %f", i,j, matriz[i][j]);

    	}
    	printf("\n");
	}
}
//----------------------------------------------------------------------------------------------
void distanciaEuclidiana(double **coordenadas,double **MatrizDistancia){

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < numero_cidades; y++)
		{
			if (i != j)		
				MatrizDistancia[i][j] =sqrt(abs(coordenadas[x][y+1]-coordenadas[x][y])*abs(coordenadas[x][y+1]-coordenadas[y][y+1]));
		}		
	}
}
