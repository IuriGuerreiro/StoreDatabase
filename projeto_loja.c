#include <strings.h>
#include <locale.h>
#include <stdio.h>
#include <ctype.h>//manipulação de caracters
#include <sys/stat.h>//manipulação de permisoes para criar uma pasta tbm deixa manipular o tempo e outras coisas

typedef struct clientes{
	char name[20];
	int num_tel;
	
}dados;
 
dados clientes;

typedef struct produtos{
	int quantidade;
	float preco;
	char cor[10],tipo[20],modelo[20],nome[20];
}dados1;

dados1 produtos;


int num_pro=0;//numero total de clientes e de produtos
int num_cli=0;


FILE *fp;
FILE *Fp;


char produto[40]="";
char cliente[40]="";


int login(){
	int buf=0,cont=0,i;
	char linha[1024],pass[8],utili[20],veri_p[8];
	system("cls");
	printf(" _             _       \n");
    printf("| |           (_)      \n");
    printf("| | ___   __ _ _ _ __  \n");
    printf("| |/ _ \\ / _` | | '_ \\ \n");
    printf("| | (_) | (_| | | | | |\n");
    printf("|_|\\___/ \\__, |_|_| |_|\n");
    printf("          __/ |        \n");
    printf("         |___/         \n");

	fp = fopen ("utilizadores.txt","r");
	do{
		rewind(fp);
		printf("\nNome de utilizador: ");
		fflush(stdin);
		gets (utili);
		printf("\nPassword: ");
		gets(pass);
		cont=0;
		buf=0;
		if (fp==NULL){
			printf ("\nNão foi possivel abrir o ficheiro");
			getch();
			return 0;
		}
		else{//pesqusisar no ficheiro as informações 
			while(fgets(linha,1024,fp)!=NULL){// para não dar erro na password porque se a pass for 123 e meter 12 entra
				if (!strstr(linha,utili)==0||buf==1){
					i=strlen (utili);
					i+=1;
					strncpy(veri_p ,linha + i, 8);// para copiar o conteudo da pass para outra variavel 
					buf=1;
					int len = strlen(veri_p);
    				if (veri_p[len-1] == '\n') 
        					veri_p[len-1] = '\0';
					if (!strcmp(veri_p, pass)==1){// para comparar a pass com a dos ficheiros 
						cont++;
						break;
					}
				}
			}
		}
		if (cont==0)
			printf ("\nA password está errada");
	}while(cont!=1);
	strcat(produto, utili);
	strcat(produto,"\\produtos.txt");
	strcat(cliente, utili);
	strcat(cliente,"\\clientes.txt");
	fclose(fp);
	cont=2;
	return cont;
}







int sing_in(){
	int buf=0,cont=0,pasta;
	char linha[1024],pass[8],pass1[8],utili[20];
	fp = fopen ("utilizadores.txt","r");
	system("cls");
	printf("         oo                      oo          \n");
	printf("                                            \n");
	printf(".d8888b. dP .d8888b. 88d888b.    dP 88d888b. \n");
	printf("Y8ooooo. 88 88'  `88 88'  `88    88 88'  `88 \n");
	printf("      88 88 88.  .88 88    88    88 88    88 \n");
	printf("`88888P' dP `8888P88 dP    dP    dP dP    dP \n");
	printf("                 .88                         \n");
	printf("             d8888P                          \n");
	
	
	do{
		
		printf("\nNome de utilizador: ");
		fflush(stdin);
		gets (utili);
		cont=0;
		
		if (fp==NULL){
			printf ("\nNão foi possivel abrir o ficheiro");
			getch();
			return 0;
		}
		else{//ver se o utilizador ja existe
		
			while(fgets(linha,1024,fp)!=NULL){//verificar se o nome de utilizador já existe
				if (!strstr(linha,utili)==0){
					buf=1;
				}
			}
		}
		
		if (buf==1){
			printf("\nEsse utilizador já existe");
			buf=0;
		}else
		
			cont++;
	}while(cont!=1);
	
	fclose(fp);
	fp = fopen ("utilizadores.txt","a");
	
	do{//para ter uma password e para confirmar a password
		buf=0;
		printf("\nPassword: ");
		gets(pass);
		printf("\nConfirme a Password: ");
		gets(pass1);
		cont =strlen(pass);
		
		if (cont>8||cont<=2){//caso seja maior que o limite de caracters
			printf ("\n O máximo de caracters da password é 8 e tem de ter pelo menos 2");
			buf=0;
		}else
			buf=1;
			
		if (!strstr(pass,pass1)==1)//ver se as passwords são iguais
			printf ("\nAs passwords são diferentes!!");
			
	}while(!strstr(pass,pass1)!=1&&buf!=1);
	
	fprintf (fp,"\n%s %s",utili,pass);
	
	strcat(produto, utili);//criar variavel com o caminho do ficheiro 
	strcat(produto,"\\produtos.txt");
	strcat(cliente, utili);
	strcat(cliente,"\\clientes.txt");
	
	pasta = mkdir(utili);//cria uma pasta com o nome do utilizador
    if (pasta != 0) {//verifica se a pasta foi criada para o utilizador
        printf("\nErro a fazer login");
        getch();
        return 1;
    }
	fclose(fp);
	cont=2;
	return cont;
}






int veri(int proCli){//verificação se existe esse cliente ou produto procli é um numero 1 ou 2  ira ser ou produto ou cliente
	int buf=0;
	int num;
	do{
		if (proCli==1){
			printf ("\nQual é o numero do produto: ");
			fflush(stdin);
			scanf ("%d",&num);
		}else if(proCli==2){
			printf ("\nQual é o numero do cliente: ");
			fflush(stdin);
			scanf ("%d",&num);
		}
		
		if (proCli==1&&num<0||proCli==1&&num>=num_pro){
			printf("\nEsse produto não existe\n");
			getch();
		}else if(proCli==2&&num<=0||proCli==2&&num>=num_cli){
			printf("\nEsse cliente não existe\n");
			getch();
		}else
			buf=1;
	}while(buf!=1);
	return num;
}









int main(){//adicionar verificação se ja existe informação introduzida pelo utilizador no ficheiro
	int opc, len;
	char conta[20], cont,conta2 ;
	setlocale(LC_ALL,"portuguese");
		do{
		system ("cls");
		printf("$$$$$$$\\                                           $$\\                 $$\\                 \n");
	    printf("$$  __$$\\                                          \\__|                $$ |                \n");
	   	printf("$$ |  $$ | $$$$$$\\  $$$$$$\\$$$$\\        $$\\    $$\\ $$\\ $$$$$$$\\   $$$$$$$ | $$$$$$\\        \n");
	   	printf("$$$$$$$\\ |$$  __$$\\ $$  _$$  _$$\\       \\$$\\  $$  |$$ |$$  __$$\\ $$  __$$ |$$  __$$\\       \n");
	   	printf("$$  __$$\\ $$$$$$$$ |$$ / $$ / $$ |       \\$$\\$$  / $$ |$$ |  $$ |$$ /  $$ |$$ /  $$ |      \n");
	   	printf("$$ |  $$ |$$   ____|$$ | $$ | $$ |        \\$$$  /  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |      \n");
	   	printf("$$$$$$$  |\\$$$$$$$\\ $$ | $$ | $$ |         \\$  /   $$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$  |      \n");
	   	printf("\\_______/  \\_______|\\__| \\__| \\__|          \\_/    \\__|\\__|  \\__| \\_______| \\______/       \n");
	   	
	 	printf ("\nJá tens uma conta? Se não cria uma !! S/N: ");
	    gets (conta);
	    len=strlen(conta);
	    if (len==1){
	    	conta2=conta[0];
			if (conta2=='n'||conta2=='N'){
		    	cont=sing_in();
			}else if(conta2=='s'||conta2=='S'){
				cont=login();
			}else{
				printf ("\nEssa opção não existe");
				getch();
			}
		}else{
			printf ("\nResponda S/N ");
			getch();
		}
	    
	}while(cont!=2);
	loading();
	do{
		getch();
		system("cls");
	    printf("  ____    __  ____    _____   __  __  ______    __    \n");
	    printf(" |    \\  /  ||    \\  |     | |  |/ / |   ___| _|  |_  \n");
	    printf(" |     \\/   ||     \\ |     \\ |     \\ |   ___||_    _| \n");
	    printf(" |__/\\__/|__||__|\\__\\|__|\\__\\|__|\\__\\|______|  |__|\n");	
		printf ("\n\n\n    ___________________     ___________________     ___________________     __________________");
		printf ("\n   |                   |   |                   |   |                   |   |                  |");
		printf ("\n   |    1-Adicionar    |   |     2-listagem    |   |      3-Alterar    |   |      0-Sair      |"); 	
		printf ("\n   |___________________|   |___________________|   |___________________|   |__________________|");
		printf ("\n\n\n                                          Opção - ");
		scanf("%d",&opc);
		switch(opc){
			case 1:{
				system("cls");
				printf ("\n1-Adicionar produto");
				printf ("\n\n2-Adicionar cliente\n");
				scanf("%d",&opc);
			if(opc==1)
					add_produto();
				if(opc==2)
					add_cliente();
				break;}
			case 2:{
				if( num_cli<=1 && num_pro<=1){//caso ainda n exista produtos ou clientes
					printf ("\n\nIntroduza um produto ou cliente primeiro");
				}else{
					system("cls");
					printf ("\n1-litagem produto");
					printf ("\n\n2-listagem cliente\n");
					scanf("%d",&opc);
							
						
						
						
					if(opc==1){
						if(num_pro<=1){//caso n exista produtos
							printf("\n\nIntroduza um cliente primeiro");
						}else{
							system("cls");
							printf ("\n1-litagem por codigo");
							printf ("\n\n2-listagem todos\n");
							scanf("%d",&opc);
							if(opc==1)
								list_cod_pro();
							if(opc==2)
								list_pro();
						}
						break;	
						
						
						
						
					}
					if(opc==2){
						if(num_cli<=1)//caso ainda n exista um cliente 
							printf ("\n\nIntroduza um cliente primeiro");
						else{
							system("cls");
							printf ("\n1-litagem por codigo");
							printf ("\n\n2-listagem todos\n");
							scanf("%d",&opc);
							if(opc==1)
								list_cod_cli();
							if(opc==2)
								list_cli();
						}	
						break;
					}
				}
					
			break;}
			case 3:{
				system("cls");
				
				
				if( num_cli<=1 && num_pro<=1)
					printf ("\nIntroduza um produto ou cliente primeiro");
				else{
					printf ("\n1-Alterar informação do produto");
					printf ("\n\n2-Alterar informção dos clientes\n");
					scanf("%d",&opc);
					
					if(opc==1){
						if (num_pro<=1){
							printf("\n\nIntroduza um produto primeiro");
							getch();
							break;
						}else{
							alterar_pro();
						}
					}
						
					if(opc==2)
						if (num_cli<=1){
							printf("\n\nIntroduza um cliente primeiro");
							getch();
							break;
						}else{
							alterar_cli();
						}
				}
			break;}

		}
		if (opc<0 ||opc>3)
			printf("\nNão existe essa opção");
	}while (opc!=0);
	
	return 0;
}







int loading(){
	char linha[1024];
	system("cls");
	printf ("CARREGANDO...");
	sleep(2);
	fp = fopen(produto, "a+");
	
	if(fp==NULL){
		printf ("\nFicheiro não encontrado");
		getch();
		return(1);
	}else{
		while(fgets(linha,1024,fp)!=NULL){//para ler o ficheiro todo
			if (!strstr(linha,"Produto-")==0)//compara os caracters do pedaço da string que retirei de linha
				num_pro++;
		}
	}
	fclose(fp);//contar o numero de clientes que ja existem 
	fp = fopen(cliente, "a+");
		
	if(fp==NULL){
		printf ("\nFicheiro não encontrado");
		return(1);	
	}else{
		while(fgets(linha,1024,fp)!=NULL){//para ler o ficheiro todo
			if (!strstr(linha, "Clientes-")==0)//compara os caracters do pedaço da string que retirei de linha
				num_cli++;
		}
	}
	num_cli++;
	num_pro++;
	fclose(fp);
	return 0;
}





int add_produto(){
	system("cls");
	
	printf ("\n		Produto- %d",num_pro);
	printf ("\n\nIntroduza o nome do produto: ");
	fflush(stdin);
	gets(produtos.nome);
	printf ("\nIntroduza o modelo do produto: ");
	gets(produtos.modelo);
	printf ("\nIntroduza o tipo (ex:eletrodomestico): ");
	gets(produtos.tipo);
	printf ("\nIntroduza o cor: ");
	gets(produtos.cor);
	printf ("\nIntroduza o preço: ");
	scanf("%f",&produtos.preco);
	printf ("\nIntroduza o quantidade do produto: ");
	scanf("%d",&produtos.quantidade);	
	
	fp=fopen(produto, "a");
	if (fp==NULL)
		printf ("\nNão foi possivel abrir o ficheiro");
	else{
		fprintf (fp,"\n		Produto- %d",num_pro);
		fprintf (fp,"\n\nnome: %s",produtos.nome);
		fprintf (fp,"\nmodelo: %s",produtos.modelo);
		fprintf (fp,"\ntipo (ex:eletrodomestico): %s",produtos.tipo);
		fprintf (fp,"\ncor: %s",produtos.cor);
		fprintf (fp,"\npreco: %.2f",produtos.preco);
		fprintf (fp,"\nquantidade: %d",produtos.quantidade);
		num_pro++;
	}
	getch();
	fclose(fp);
	return 0;
}





int add_cliente(){//adicionar clientes similar a de cima
	system("cls");
	
	printf ("		Clientes- %d",num_pro);
	printf ("\n\nIntroduza o nome do cliente ");
	fflush(stdin);
	gets(clientes.name);
	printf ("\nIntroduza o numero de telemovel: ");
	scanf("%d",&clientes.num_tel);

	
	fp=fopen(cliente, "a");
	if (fp==NULL)
		printf ("\nNão foi possivel abrir o ficheiro");
	else{
		fprintf (fp,"\n		Clientes- %d",num_cli);
		fprintf (fp,"\n\nnome: %s",clientes.name);
		fprintf (fp,"\nnumero de telemovel: %d",clientes.num_tel);
		num_cli++;
	}
	getch();
	fclose(fp);
	return 0;
}






int list_cod_pro(){
	char linha [1024],num[20];
	int i,buf=0;
	char search[20]="Produto- ";
	system("cls");
	buf=veri(1);
	sprintf(num,"%d",buf);//convert um inteiro para uma string 
	strcat(search,num);
	buf =0;
	fp=fopen(produto,"r");
	if (fp==NULL){//caso n seja abrir o ficheiro 
		printf ("\nNão foi possivel abrir o ficheiro");
		getch();
		return 0;
	}	
	else{//pesqusisar no ficheiro as informações 
		while(fgets(linha, 1024, fp)!=NULL){
			if (!strstr(linha, search)==0||buf==1){//comparar para fazer printf das informações dos produtos
				if (!strstr(linha, "Produto- ")==0)
					buf++;
				else
					printf ("%s",linha);	
			}
		}
	}
	getch();
	return 0;
}








int list_pro(){
	char linha [1024];
	system("cls");
	fp=fopen(produto,"r");
	if (fp==NULL)
		printf ("\nNão foi possivel abrir o ficheiro");
	else{
		while(fgets(linha,1024,fp)!=NULL)
			if (!strstr(linha, "Produto-")==0)
				printf ("\n%s",linha);
			else
				printf ("%s",linha);
	}
	getch();
	fclose(fp);
	return 0;
}








int list_cod_cli(){
	char linha [1024],num[20];
	int buf=0;
	char search[20]="Clientes- ";
	system("cls");
	buf=veri(2);
	sprintf(num,"%d",buf);//convert um inteiro para uma string 
	strcat(search,num);
	buf =0;
	fp=fopen(cliente,"r");
	if (fp==NULL){
		printf ("\nNão foi possivel abrir o ficheiro");
		getch();
		return 0;
	}
	else{//pesqusisar no ficheiro as informações 
		while(fgets(linha,1024,fp)!=NULL){
			if (!strstr(linha,search)==0||buf==1){
				if (!strstr(linha,"Clientes- ")==0)
					buf++;
				else
					printf ("%s",linha);
			}
		}
	}
	getch();
	return 0;
}







int list_cli(){
	char linha [1024];
	system("cls");
	fp=fopen(cliente,"r");
	if (fp==NULL)
		printf ("\nNão foi possivel abrir o ficheiro");
	else{
		while(fgets(linha,1024,fp)!=NULL)
			if (!strstr(linha, "Clientes-")==0)
				printf ("\n%s",linha);
			else
				printf ("%s",linha);
	}
	getch();
	fclose(fp);
	return 0;
}






int alterar_pro(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	char linha [1024],num[20],mudar[20];
	int i,buf=0;
	char search[40];
	system("cls");
	buf=veri(1);
	sprintf(num,"%d",buf);//convert um inteiro para uma string 
	strcat(search,num);
	buf =0;
	fp=fopen(produto,"r");
	if (fp==NULL){//caso n seja abrir o ficheiro 
		printf ("\nNão foi possivel abrir o ficheiro");
		getch();
		return 0;
	}	
	else{//pesqusisar no ficheiro as informações 
		while(fgets(linha, 1024, fp)!=NULL){
			if (!strstr(linha, search)==0||buf==1){//comparar para fazer printf das informações dos produtos
				if (!strstr(linha, "Produto- ")==0)
					buf++;
				else
					printf ("%s",linha);
			}
		}
		buf=0;
		do{
			printf ("\n\nIntroduza o parametro que quer mudar: ");
			fflush(stdin);
			gets(mudar);
			strlwr(mudar);
			if (!strstr(mudar, "nome")==0||!strstr(mudar, "quantidade")==0||!strstr(mudar, "cor")==0||!strstr(mudar, "modelo")==0||!strstr(mudar, "tipo")==0||!strstr(mudar, "preco")==0){//para verificar se o parametro existe
				printf ("qual é o novo %s: ",mudar);
				fflush(stdin);
				gets(num);//reutilizar a variavel pq ja n é mais precisa o contedo esta em search
				buf=1;
			}else
				printf ("\nEsse parametro não existe");
		}while(buf!=1);//para repetir ate 
		rewind(fp);
		Fp=fopen ("temp.txt","w");
		buf=0;//para o proximo ciclo 
		while(fgets(linha,1024,fp)!=NULL){//introduzir os com a mudança num ficheiro
			if (!strstr(linha,search)==0||buf==1){//para quando encontrar o numero do produto mudar a linha que tiver o parametro 
				buf=1;
				if (!strstr(linha,mudar)==0&&buf==1){
					buf++;
					fprintf (Fp,"%s %s\n",mudar,num);//para mudar o conteudo do parametro 
				}
				
				else
					fprintf (Fp,"%s",linha);
			}
			else
				fprintf (Fp,"%s",linha);
		}
		
	}
	fclose(fp);
	fclose(Fp);
	
	rename(produto,"temp2.txt");//para dar rename do ficheiro para as outras funções funcionarem 
	if (!rename("temp.txt", produto)==1){
		printf("\nAlterações feitas!!");
		remove("temp2.txt");
	}else{
		printf ("\nErro a fazer as alterações");
		remove("temp.txt");
		remove("temp2.txt");
	}
	getch();
	return 0;
}







int alterar_cli(){//copi paste da anterior
	char linha [1024],num[20],mudar[20];
	int i,buf=0;
	char search[20]="Clientes- ";
	system("cls");
	buf=veri(2);
	sprintf(num,"%d",buf);//convert um inteiro para uma string 
	strcat(search,num);
	buf =0;
	fp=fopen(cliente,"r");
	if (fp==NULL){
		printf ("\nNão foi possivel abrir o ficheiro");
		getch();
		return 0;
	}
	else{//pesqusisar no ficheiro as informações 
		while(fgets(linha,1024,fp)!=NULL){
			if (!strstr(linha,search)==0||buf==1){
				if (!strstr(linha,"Clientes- ")==0)
					buf++;
				else
					printf ("%s",linha);
			}
		}
		buf=0;
		do{
			printf ("\n\nIntroduza o parametro que quer mudar: ");
			fflush(stdin);
			gets(mudar);
			strlwr(mudar);
			if (!strstr(mudar,"nome")==0||!strstr(mudar,"numero de telemovel")==0){
				printf ("qual é o novo %s: ",mudar);
				fflush(stdin);
				gets(num);//reutilizar a variavel pq ja n é mais precisa o contedo esta em search
				buf=1;
			}else
				printf ("\nEsse parametro não existe");
		}while(buf!=1);
		rewind(fp);
		Fp=fopen ("temp.txt","w");
		buf=0;

		while(fgets(linha,1024,fp)!=NULL){//introduzir os com a mudança num ficheiro
			if (!strstr(linha,search)==0||buf==1){//para quando encontrar o numero do produto mudar a linha que tiver o parametro 
				buf=1;
				if (!strstr(linha,mudar)==0&&buf==1){
					buf++;
					fprintf (Fp,"%s %s\n",mudar,num);//para mudar o conteudo do parametro 
				}
				
				else
					fprintf (Fp,"%s",linha);
			}
			else
				fprintf (Fp,"%s",linha);
		}
		
	}
	fclose(fp);
	fclose(Fp);
	
	rename(cliente,"temp2.txt");
	if (!rename("temp.txt", cliente)==1){
		printf("\nAlterações feitas!!");
		remove("temp2.txt");
		
	}else{
		printf ("\nErro a fazer as alterações");
		remove("temp.txt");
		remove("temp2.txt");
	}
		
	getch();
	return 0;
}
