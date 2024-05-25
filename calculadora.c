#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>

int fatorial(int consta){
    int fat = 1;
    int i;
	           
    for(i = consta; i > 1; i--) {
        fat *= i;
    }
    return fat;
}

int fibonacci(int termo){
    int proxTermo = 0;
    int atualTermo = 1;
    int anteriorTermo = 0;
    int i;
    
    atualTermo = termo;
    anteriorTermo = atualTermo - 1;
    
    if(termo <= 1)
        return 1;
        
    for(i = 1; i <= termo; i++){
        proxTermo = atualTermo + anteriorTermo;
        anteriorTermo = atualTermo;
        atualTermo = proxTermo;
    }
    return atualTermo;
}

void fettuccine(int nTermos, int termoA, int termoB, int i) {
    
    int calcularFettuccine;
    printf("%d ", termoA);

    for (i = 1; i < nTermos; i++) {
        calcularFettuccine = termoA + termoB * i; 
        printf("%d ", calcularFettuccine); 
        termoA = termoB; 
        termoB = calcularFettuccine; 
    }
}

int exponenciacao(int base, int expoente){
    int resultado = 1;
    int i;
    
    for(i = 0; i < expoente; i++) {
        resultado *= base; 
    } 
    return resultado;
}

void converteBaseNumerica(int baseNumerica, int numeroConversaoBase){
    
    int auxConversaoBase, restoConversaoBase, i;
    char caracteres[36] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char resultadoConversaoBase[100];
    
    memset(resultadoConversaoBase, '\0', sizeof(resultadoConversaoBase)); // Inicializando com caracteres nulos
    
    if(baseNumerica == 8){
        printf("%i na base 8 = %o\n", numeroConversaoBase, numeroConversaoBase);
    } else if(baseNumerica == 16){
        printf("%i na base 16 = %X\n", numeroConversaoBase, numeroConversaoBase);
    } else{
        auxConversaoBase = numeroConversaoBase;
        for (i = 0; auxConversaoBase!=0; i++){
            restoConversaoBase = auxConversaoBase % baseNumerica;
            resultadoConversaoBase[i] = caracteres[restoConversaoBase];
            auxConversaoBase -= restoConversaoBase;
            auxConversaoBase /= baseNumerica;
        }
        printf("\n%d na base de %d: ", numeroConversaoBase, baseNumerica);
        for(i=strlen(resultadoConversaoBase)-1; i>=0; i--)
            printf("%c", resultadoConversaoBase[i]);
    }
}

float areaQuadrado(float baseQuadrado, float alturaQuadrado){
    float resultadoAreaQuadrado;
    
    resultadoAreaQuadrado = baseQuadrado * alturaQuadrado;
    return resultadoAreaQuadrado;
}

float areaTriangulo(float baseTriangulo, float alturaTriangulo){
    float resultadoAreaTriangulo;
    
    resultadoAreaTriangulo = (baseTriangulo * alturaTriangulo)/2.0;
    return resultadoAreaTriangulo;
}

float areaCirculo(float raioCirculo){
    float pi, resultadoAreaCirculo;
    
    pi = 3.14;
    raioCirculo = pow(raioCirculo, 2.0);
    resultadoAreaCirculo = raioCirculo * pi;
    
    return resultadoAreaCirculo;
}

float areaTrapezio(float baseMaiorTrapezio, float baseMenorTrapezio, float alturaTrapezio){
    float resultadoAreaTrapezio;
    
    resultadoAreaTrapezio = ((baseMenorTrapezio + baseMaiorTrapezio) * alturaTrapezio)/2.0;
    
    return resultadoAreaTrapezio;
}

void calculoEletrico(float tensaoEletrica, float correnteEletrica, float resistenciaEletrica, float potenciaEletrica){
    resistenciaEletrica = tensaoEletrica / correnteEletrica;
	potenciaEletrica = tensaoEletrica * correnteEletrica;
	printf("Tensao do circuito: %.2f volts\n", tensaoEletrica);
	printf("Corrente do circuito: %.2f amperes\n", correnteEletrica);
	printf("Resistencia do circuito: %.2f ohms\n", resistenciaEletrica);
	printf("Potencia do circuito: %.2f watts\n", potenciaEletrica);
}

#define ROWS 3
#define COLS 3
void elementWiseMultiplication(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}

void printMatrix(int mat[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void primo(){
    int min, max, i, ctr, ctr2;
    printf("Numero primo ate numero: ");
   	scanf("%i", &max);
	max++;
   	printf("Numeros primos ate %i: ", max-1);

	ctr2=0;
	min=2;

 	 while (min < max) {
	    ctr = 0;
	     
	    for (i = 2; i <= min / 2; i++) {
	         if (min % i == 0) {
	            ctr = 1;
	            break;
	         }
	    }
	
	    if (ctr == 0){
	       printf("%d ", min);
		   ctr2++;
		}
	    min++;
	 }

   	printf("\nTotal de numeros: %i\n", ctr2);

}

void quadradperf(){
	int num, i, flag, flag2, raizint;
	
	double raiz;
	printf("Numeros de quadrado perfeito ate o numero: ");
	scanf("%i", &num);
	printf("Numeros de quadrados perfeitos ate %i: ", num);
	
	flag2=0;
	
	for(i=1;i<=num;i++){
		raiz=(sqrt(i));
		raizint = raiz;
		if(raizint == raiz){
		printf("%i ", i);
		flag2++;}
	}
	
	printf("\nTotal de numeros: %i\n", flag2);
}
int main(void)
{
    int opcaoMenu;
    int continua = 1;
    int i, j;

    do{
        printf("\n\nMENU\n---------------------------");
        printf("\n[1] - Fatorial");
        printf("\n[2] - Fibonacci");
        printf("\n[3] - Fettuccine");
        printf("\n[4] - Potencia");
        printf("\n[5] - Torricelli");
        printf("\n[6] - Conversao de Base Numerica");
        printf("\n[7] - Areas de figuras planas");
        printf("\n[8] - Calculo eletrico");
        printf("\n[9] - Calculo de Fisica Mecanica");
        printf("\n[10] - Multiplica Matriz");
        printf("\n[11] - Calcula Quantidade de Numeros Primos e Quais sao");
        printf("\n[12] - Calcula Quantos Quadrados Perfeitos Ate Determinado Numero e Quais Sao");
        printf("\n\n[0] - SAIR");
        printf("\n---------------------------\nEscolha qual calculo realizar:");
        scanf("%i", &opcaoMenu);
        system("cls");

        switch(opcaoMenu){
            case 0: 
            	printf("Saindo do Programa...\n");
                continua = 0;
            break;
            
            case 1: {
			    int numeroFatorial;
			    printf("\nFatorial\nInsira um numero:");
			    scanf("%i", &numeroFatorial);
			    numeroFatorial = fatorial(numeroFatorial);
			    printf("Fatorial : %i", numeroFatorial);
			} break;
      
            
            case 2: {
                int termoFibonacci;
                
                printf("\nFibonacci\nInsira um numero:");
                scanf("%i", &termoFibonacci);
                termoFibonacci = fibonacci(termoFibonacci);
                printf("Fibonacci : %i", termoFibonacci);
            } break;
            
            case 3: {
			    int nTermos, termoA, termoB;
                i = 0;
        
                printf("Fettuccine\nInsira o numero de termos: ");
                scanf("%i", &nTermos);
                printf("Insira o primeiro termo: ");
                scanf("%i", &termoA);
                printf("Insira o segundo termo: ");
                scanf("%i", &termoB);
                fettuccine(nTermos, termoA, termoB, i);
            } break;
            
            case 4: {
                int base, expoente, resultado; 
                
                printf("Calcula Potencia\n");
                printf("Insira a base: ");
                scanf("%i", &base);
                printf("Insira o expoente: ");
                scanf("%i", &expoente);
                resultado = exponenciacao(base, expoente);
                printf("O resultado é: %i\n", resultado);
           	} break;
            
            //não está como função
            case 5: {
                int continuaTorricelli = 1;
                float velocidadeFinal;
                float velocidadeInicial;
                float deslocamento;
                float aceleracao; 
                int opcaoTorricelli;
                do {
                    printf("\n\nMENU TORRICELLI\n---------------------------");
                    printf("\n[0] - SAIR\n");
                    printf("[1] - Calcular Velocidade Final\n");
                    printf("[2] - Calcular Velocidade Inicial\n");
                    printf("[3] - Calcular Deslocamento\n");
                    printf("[4] - Calcular Aceleracao\n");
                    printf("\n---------------------------\nEscolha qual variavel calcular:");
                    scanf("%d", &opcaoTorricelli);
                    
                    system("cls");
            
                    switch (opcaoTorricelli) {
                        case 0:
                            continuaTorricelli = 0;
                        break;
                        case 1:
                            printf("Velocidade Final\n");
                            printf("Informe a Velocidade Inicial m/s: ");
                            scanf("%f", &velocidadeInicial); 
                            printf("Informe o deslocamento em metros: ");
                            scanf("%f", &deslocamento); 
                            printf("Informe a aceleracao em metros/segundo²: ");
                            scanf("%f", &aceleracao);
                            
                            velocidadeFinal = sqrt((velocidadeInicial * velocidadeInicial) + (2 * aceleracao * (deslocamento)));
                            printf("Velocidade Final: %.2f\n", velocidadeFinal); 
                        break;
                            
                        case 2:
                            printf("Velocidade Inicial\n");
                            printf("Informe a Velocidade Final em m/s: ");
                            scanf("%f", &velocidadeFinal); 
                            printf("Informe o deslocamento inicial em metros: ");
                            scanf("%f", &deslocamento);  
                            printf("Informe a aceleracao em metros/segundo²: ");
                            scanf("%f", &aceleracao);
                            
                            velocidadeInicial = sqrt(velocidadeFinal * velocidadeFinal - 2 * aceleracao * deslocamento);
                            printf("Velocidade Inicial: %.2f\n", velocidadeInicial); 
                        break;
                            
                        case 3:
                            printf("Calcular Deslocamento\n");
                            printf("Informe a Velocidade Inicial m/s: ");
                            scanf("%f", &velocidadeInicial); 
                            printf("Informe a Velocidade Final em m/s: ");
                            scanf("%f", &velocidadeFinal);
                            printf("Informe a aceleracao em metros/segundo²: ");
                            scanf("%f", &aceleracao);
                            
                            deslocamento = (velocidadeFinal * velocidadeFinal - velocidadeInicial * velocidadeInicial) / (2 * aceleracao);
                            printf("Deslocamento: %.2f\n", deslocamento); 
                        break;
                            
                        case 4:
                            printf("Calcular Aceleracao\n");
                            printf("Informe a Velocidade Inicial m/s: ");
                            scanf("%f", &velocidadeInicial); 
                            printf("Informe a Velocidade Final em m/s: ");
                            scanf("%f", &velocidadeFinal);
                            printf("Informe o deslocamento em metros: ");
                            scanf("%f", &deslocamento); 
                            
                            aceleracao = (velocidadeFinal * velocidadeFinal - velocidadeInicial * velocidadeInicial) / (2 * deslocamento);
                            printf("Aceleracao: %.2f\n", aceleracao); 
                        break;
                            
                        default:
                            printf("Opcao invalida!\n");
                        break;
                    }
                } while (continuaTorricelli);
            } break;
            
            case 6: {
                int baseNumerica, numeroConversaoBase;
                printf("Conversao de Base Numerica\n");
                printf("Digite para qual base deseja converter:");
                scanf("%d", &baseNumerica);
                printf("Insira o numero:");
                scanf("%d", &numeroConversaoBase);
                converteBaseNumerica(baseNumerica, numeroConversaoBase);
            } break;
            
            case 7:{
                int continuaAreas = 1;
                int opcaoArea;
                do{
                    printf("\n\nMENU AREAS\n---------------------------");
                    printf("\n[0] - SAIR");
                    printf("\n[1] - area do Retangulo/Quadrado");
                    printf("\n[2] - area do Triangulo");
                    printf("\n[3] - area do Circulo");
                    printf("\n[4] - area do Trapezio");
                    printf("\n---------------------------\nEscolha qual area calcular:");
                    scanf("%i", &opcaoArea);
                    
                    system("cls");

                    switch(opcaoArea){
                        case 0:
                            continuaAreas = 0;
                        break;
                        case 1: {
                            float baseAreaQuadrado;
                            float alturaAreaQuadrado;
                            float resultadoAreaQuadrado;
                            
                            printf("\nArea do Retangulo/Quadrado\nInsira a base: ");
                            scanf("%f", &baseAreaQuadrado);
                            printf("Insira a altura do quadrado:");
                            scanf("%f", &alturaAreaQuadrado);
                            resultadoAreaQuadrado = areaQuadrado(baseAreaQuadrado, alturaAreaQuadrado);
                            printf("Area do quadrado: %.2f", resultadoAreaQuadrado);
                        } break;
                        
                        case 2:{
						    float baseAreaTriangulo;
                            float alturaAreaTriangulo;
                            float resultadoAreaTriangulo;
                            
                            printf("\nArea do Triangulo\nInsira a base: ");
                            scanf("%f", &baseAreaTriangulo);
                            printf("Insira a altura do triangulo:");
                            scanf("%f", &alturaAreaTriangulo);
                            resultadoAreaTriangulo = areaTriangulo(baseAreaTriangulo, alturaAreaTriangulo);
                            printf("Area do triangulo: %.2f", resultadoAreaTriangulo);
                        } break;
                        
                    	case 3: {
						    float raioCirculo;
						    float resultadoAreaCirculo;
						    
						    printf("\nArea do Circulo\nInsira o raio: ");
						    scanf("%f", &raioCirculo);
						    resultadoAreaCirculo = areaCirculo(raioCirculo);
						    printf("Area do circulo: %.2f", resultadoAreaCirculo);
						} break;
						
						case 4: {
						    float baseMenorTrapezio;
						    float baseMaiorTrapezio;
						    float alturaTrapezio;
						    float resultadoAreaTrapezio;
						    
						    printf("\nArea do Trapezio\nInsira a base maior:");
						    scanf("%f", &baseMaiorTrapezio);
						    printf("Insira a base menor:");
						    scanf("%f", &baseMenorTrapezio);
						    printf("Insira a altura:");
						    scanf("%f", &alturaTrapezio);
						    resultadoAreaTrapezio = areaTrapezio(baseMaiorTrapezio, baseMenorTrapezio, alturaTrapezio);
						    printf("Area do trapezio: %.2f", resultadoAreaTrapezio);
						} break;
						
						default:
						    system("cls");
						    printf("Opcao invalida!");
						break;

                    }
                }while(continuaAreas);
            } break;
            
            case 8: {
                float tensaoEletrica, correnteEletrica, resistenciaEletrica, potenciaEletrica;
            	printf("Calculo Eletrico\n");
            	printf("Digite o valor da tensao (em volts): ");
            	scanf("%f", &tensaoEletrica);
            	printf("Digite o valor da corrente (em amperes): ");
            	scanf("%f", &correnteEletrica);
            	calculoEletrico(tensaoEletrica, correnteEletrica, resistenciaEletrica, potenciaEletrica);
            } break;
            default:
                system("cls");
                printf("Opcao invalida!");
            break;
            
            //não está como função
            case 9: {
                int opcaoFisicaMec, energiaMec, energiaPot, energiaCin, massaFisicaMec, velocidadeFisicaMec; 
                int energiaPotGrav, aceleracaoGrav, alturaFisicaMec, calorEsp, variaTemp, calorFisicaMec;
                int continuaFisicaMec = 1;
                do{
                    printf("\n\nMENU CALCULO DE FISICA MECANICA\n---------------------------");
                    printf("\n[0] - SAIR\n");
                    printf("[1] - Energia Mecanica\n");	
                    printf("[2] - Energia Cinetica\n");	
                    printf("[3] - Energia Potencial Gravitacional\n");	
                    printf("[4] - Quantidade de Calor\n");
                    printf("\n---------------------------\nEscolha qual calculo realizar:");
                    scanf("%i", &opcaoFisicaMec);
                    system("cls");
                    switch(opcaoFisicaMec){
                        case 0:
                            continuaFisicaMec = 0;
                        break;
                        case 1:
                            printf("Energia Mecanica\n");
                            printf("\nQual o valor da energia potencial? ");
                            scanf("%i", &energiaPot);
                            printf("Qual o valor da energia cinetica? ");
                            scanf("%i", &energiaCin);
                            energiaMec = energiaPot + energiaCin;
                            printf("Energia mecanica: %i\n", energiaMec);   
                        break;
                        
                        case 2:
                            printf("Energia Cinetica\n");
                            printf("\nQual o valor da massa (kg)? ");
                            scanf("%i", &massaFisicaMec);
                            printf("Qual o valor da velocidade (m/s)? ");
                            scanf("%i", &velocidadeFisicaMec);
                            energiaCin = (massaFisicaMec * (velocidadeFisicaMec * velocidadeFisicaMec))/2;
                            printf("Energia cinetica: %i\n", energiaCin);
                        break;
                
                        case 3: 
                            printf("Energia Potencial Gravitacional\n");
                            printf("\nQual o valor da massa (kg)? ");
                            scanf("%i", &massaFisicaMec);
                            printf("Qual o valor da aceleracao gravitacional (m/s)? ");
                            scanf("%i", &aceleracaoGrav);
                            printf("Qual o valor da altura (metros)? ");
                            scanf("%i", &alturaFisicaMec);
                            energiaPotGrav = massaFisicaMec * aceleracaoGrav * alturaFisicaMec;
                            printf("Energia potencial gravitacional: %i\n", energiaPotGrav);
                        break;
                
                        case 4: 
                            printf("Quantidade de Calor\n");
                            printf("\nQual o valor da massa(kg)? ");
                            scanf("%i", &massaFisicaMec);
                            printf("Qual o valor do calor especifico? ");
                            scanf("%i", &calorEsp);
                            printf("Qual o valor da variacao de temperatura? ");
                            scanf("%i", &variaTemp);
                            calorFisicaMec = massaFisicaMec * calorEsp * variaTemp;
                            printf("Quantidade de calor: %i\n", calorFisicaMec);
                        break;
                        
                        default:
                            system("cls");
                            printf("Opcao invalida!");
                        break;
                    }
                }while(continuaFisicaMec);
            } break;
            case 10:{
                int mat1[ROWS][COLS], mat2[ROWS][COLS], result[ROWS][COLS];
                j = 0;;
                i = 0;
                printf("Multiplica Matriz\n");
                printf("Digite os valores para a primeira matriz:\n");
                for (i = 0; i < ROWS; i++) {
                    for (j = 0; j < COLS; j++) {
                        printf("Digite o valor para a posicao (%d, %d): ", i + 1, j + 1);
                        scanf("%d", &mat1[i][j]);
                    }
                }
            
                printf("Digite os valores para a segunda matriz:\n");
                for (i = 0; i < ROWS; i++) {
                    for (j = 0; j < COLS; j++) {
                        printf("Digite o valor para a posição (%d, %d): ", i + 1, j + 1);
                        scanf("%d", &mat2[i][j]);
                    }
                }
            
                elementWiseMultiplication(mat1, mat2, result);
            
                printf("Resultado da multiplicacao elemento por elemento:\n");
                printMatrix(result);
            } break;
            case 11: {
                primo();
            } break;
            
            case 12: {
                quadradperf();
            } break;
        }
    }while(continua);

    return 0;
}
