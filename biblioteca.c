/**/
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream.h>//BIBLIOTECA ARQUIVO
// #include <ctype.h>
// #include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

// ESTRUTURA PARA O ALUNO
typedef struct Aluno{
	   char matricula[10];
	   char nome[50];
	   char curso[50];
	   char turma[10];
	   char periodo[10];

} Aluno;
//ESTRUTURA PARA LIVRO
typedef struct Livro{
	   char isbn[20];
	   char titulo[80];
	   char autor[50];
	   char editora[50];
	   int ano;

} Livro;
//EXTRUTURA DE UM IMPRESTIMO
typedef struct Emprestimo{
	   char matricula[10];
	   char isbn[20];
	   char data_emprestimo[10];
	   char data_devolucao[10];
} Emprestimo;
// VETOR PARA GUARDAR ALUNOS
Aluno vetAlunos[3];
// VETOR PARA GUARDAR OS LIVROS
Livro vetLivros[3];
// VETOR DE EMPRESTIMOS
Emprestimo vetEmprestimo[6];

int vIndice_Aluno;
int vIndice_Acervo;
int vIndice_Emprestimo;

// MENU DO SISTEMA
int geraMenu(){

	int Opcao;
	printf("\t\t\t\t\tMENU \n\n");
	printf("\t1 - Adicionar Novo Aluno ");
	printf("\n\t2 - Listar Todos os Alunos ");
	printf("\n\t3 - Mostrar informacoes salvas do arquivo aluno.txt ");
	printf("\n\t4 - Adicionar Livro ");
	printf("\n\t5 - Listar Livro ");
	printf("\n\t6 - Pesquisar Livro por Editora  ");
	printf("\n\t7 - Emprestimo ");
	printf("\n\t8 - Listar Emprestimo ");
	printf("\n\t9 - Sair \n");
	printf("\n\n ");
	printf("\n\tDigite uma Opcao: ");

	scanf ("%d",&Opcao);

	return Opcao;

}

// CLASSE TITULO DO SISTEMA
void titulo (){
	 system ("cls");
	 printf("#**************************************************************************#\n");
	 printf("#                                                                          #\n");
	 printf("#                            SISTEMA DE BIBLIOTECA                         #\n");
	 printf("#                             ESTRUTURA DE DADOS                           #\n");
	 printf("#                                                                          #\n");
	 printf("#**************************************************************************#\n");
}

// CLASSE DE CADASTRO DE ALUNO
void cadastrar_Aluno (){

	 if (vIndice_Aluno < 5){
		titulo();
		printf("\n\n \tCADASTRO DE ALUNO\n\n");	 //SDFSDFASFDAS
		Aluno vAlunoBuffer;

		printf("Informe a Matricula do Aluno: ");
		//fflush(stdin);

        setbuf(stdin, NULL);

		scanf("%s", vAlunoBuffer.matricula);
		//gets(vAlunoBuffer.matricula);
		printf("Informe o Nome do Aluno: ");
		setbuf(stdin, NULL);
		scanf("%[^\n]s", vAlunoBuffer.nome);
		//gets(vAlunoBuffer.nome);//A fun��o gets no gcc (linux) n�o funciona, no borland c++ (windows) funciona. Usa a fun��o scanf.

		printf("Informe o Curso: ");
		scanf("%s", vAlunoBuffer.curso);
		//gets(vAlunoBuffer.curso);

		printf("Informe a Turma: ");
		scanf("%s", vAlunoBuffer.turma);
		//gets(vAlunoBuffer.turma);

		printf("Informe o Periodo:");
		scanf("%s", vAlunoBuffer.periodo);
		//gets(vAlunoBuffer.periodo);

		vetAlunos [vIndice_Aluno] = vAlunoBuffer;

		vIndice_Aluno++;

		printf("\n\n Aluno Adicionado com sucesso.\n");

        FILE *arq = NULL;
        if ((arq = fopen("Arquivo_Aluno.txt", "a")) == NULL)	//O modo de abertura "a" abre o arquivo para escrita no fim do arquivo.
            printf("Erro: %s\n", strerror(errno));
        else {
            fprintf(arq, "%s\n", vAlunoBuffer.matricula);
            fprintf(arq, "%s\n", vAlunoBuffer.nome);
            fprintf(arq, "%s\n", vAlunoBuffer.curso);
            fprintf(arq, "%s\n", vAlunoBuffer.turma);
            fprintf(arq, "%s\n", vAlunoBuffer.periodo);
        }

        if (arq != NULL)
            fclose(arq);

	 }else{
		printf("\n\n Limite de Alunos Ultrapassado...\n");
	 }

}
// CLASSE DE LISTA DE ALUNOS
void listar_Alunos(){
	 titulo();
	 int i;
	 for(i = 0; i < vIndice_Aluno; i++){

			printf("\n DADOS DO ALUNO: Matricula: %s - Nome do Aluno%s\n", vetAlunos[i].matricula, vetAlunos[i].nome);
			printf("______________________________________________________\n");
			printf("Curso: \n");
			printf("%s \n", vetAlunos[i].curso);
			printf("______________________________________________________\n");
			printf("Turma:\n ");
			printf("%s \n", vetAlunos[i].turma);
			printf("______________________________________________________\n");
			printf("Periodo:\n ");
			printf("%s \n", vetAlunos[i].periodo);
			printf("======================================================\n");

	 }

	 puts("\n\n");

}
// CLASSE DE CONSULTA DE ALUNO
void pesquisar_Aluno(){

	 titulo();

	 //printf("\n\n Pesquisar por Nome.\n");
	 printf("\n\n Pesquisar por codigo do aluno.\n");
	 char vExpressaoBusca[20];
	 //printf("\n\n Digite o Nome do Aluno a pesquisar: ");
	 printf("\n\n Digite a matricula do aluno a pesquisar: ");
	 fflush (stdin);
	 scanf("%s", vExpressaoBusca);
	 //gets(vExpressaoBusca);
	 int i;
	 for(i = 0; i < vIndice_Aluno; i++){
		   if(strcasecmp(vExpressaoBusca,vetAlunos[i].matricula) == 0){
			   printf("\n DADOS DO ALUNO: Matricula: %s - Nome do Aluno: %s\n", vetAlunos[i].matricula, vetAlunos[i].nome);
			   printf("______________________________________________________\n");
			   printf("Curso: \n");
			   printf("%s \n", vetAlunos[i].curso);
			   printf("______________________________________________________\n");
			   printf("Turma:\n ");
			   printf("%s \n", vetAlunos[i].turma);
				 printf("______________________________________________________\n");
			   printf("Periodo:\n ");
			   printf("%s \n", vetAlunos[i].periodo);
			   printf("======================================================\n");

		   }
	 }
	 puts("\n\n");

}

void aluno_arq_texto(){

	// fprintf(arq, "%s\n", vAlunoBuffer.matricula);
	// fprintf(arq, "%s\n", vAlunoBuffer.nome);
	// fprintf(arq, "%s\n", vAlunoBuffer.curso);
	// fprintf(arq, "%s\n", vAlunoBuffer.turma);
	// fprintf(arq, "%s\n", vAlunoBuffer.periodo);


	printf("Conteudo do Arquivo: \n");

	FILE *arquivo = fopen("Arquivo_Aluno.txt", "r"); 		//Abre o arquivo como somente-leitura

	if (arquivo == NULL)									//Verifica se teve algum erro ao abrir o arquivo
		printf("Erro: %s\n", strerror(errno));				//Informa o erro
	else {
		char texto[200];									//Variável "grande" o suficiente para comportar todos os caracteres
		while (fscanf(arquivo, "%s", texto) != EOF) {		//Faz um loop dentro do arquivo. Enquanto a função retornar diferente de EOF (End Of File) ele vai fazer a leitura da linha
			printf("Matricula: %s\n", texto);				//Imprime o valor que foi armazenado na variável texto[]

			fscanf(arquivo, "%s", texto);					//Faz novamente a leitura
			printf("Nome: %s\n", texto);					//Imprime novamente o valor e assim por diante até o fim do loop.

			fscanf(arquivo, "%s", texto);
			printf("Curso: %s\n", texto);

			fscanf(arquivo, "%s", texto);
			printf("Turma: %s\n", texto);

			fscanf(arquivo, "%s", texto);
			printf("Periodo: %s\n\n", texto);
		}
	}
}


/* CLASSE DE CONSULTA DE ALUNO
void pesquisar_Aluno(){

	 titulo();

	 printf("\n\n Pesquisar por Matricula.\n");
	 char vExpressaoBusca[20];
	 printf("\n\n Digite o numero da matricula a pesquisar: ");
	 fflush (stdin);
	 gets(vExpressaoBusca);
	 int i;
	 for(i = 0; i < vIndice_Aluno; i++){
		   if(strcasecmp(vExpressaoBusca,vetAlunos[i].nome) == 0){
			   printf("\n DADOS DO ALUNO: %s - %s\n", vetAlunos[i].matricula, vetAlunos[i].nome);
			   printf("______________________________________________________\n");
			   printf("Curso: \n");
			   printf("%s \n", vetAlunos[i].curso);
			   printf("______________________________________________________\n");
			   printf("Turma:\n ");
			   printf("%s \n", vetAlunos[i].turma);
			   printf("======================================================\n");

		   }
	 }
	 puts("\n\n");

}*/
//CLASSE DE CADASTRO DE ACERVO
void cadastrar_Acervo (){

	 titulo();

	 if (vIndice_Acervo < 2){
		printf("\n\n \tCADASTRO DE LIVRO AO ACERVO\n\n");

		Livro vAcervoBuffer;

		printf("Informe o ISBN do Livro: ");
		fflush(stdin);
		scanf("%s", vAcervoBuffer.isbn);
		//gets(vAcervoBuffer.isbn);

		printf("Informe o Titulo do Livro: ");
		scanf("%s", vAcervoBuffer.titulo);
		//gets(vAcervoBuffer.titulo);

		printf("Informe a Editora do Livro: ");
		scanf("%s", vAcervoBuffer.editora);
		//gets(vAcervoBuffer.editora);

		printf("Informe o Autor do Livro: ");
		scanf("%s", vAcervoBuffer.autor);
		//gets(vAcervoBuffer.autor);


		printf("Informe o Ano de publicacao do Livro: ");
		scanf("%i",&vAcervoBuffer.ano);


		vetLivros[vIndice_Acervo] = vAcervoBuffer;

		vIndice_Acervo++;


		printf("\n\n Livro Adicionado com sucesso.\n");

		    FILE *arq = NULL;
        if ((arq = fopen("Arquivo_Livro.txt", "w+")) == NULL)
            printf("Erro: %s\n", strerror(errno));
        else {
            fprintf(arq, "ISBN: %s\n", vAcervoBuffer.isbn);
            fprintf(arq, "Título do Livro: %s\n", vAcervoBuffer.titulo);
            fprintf(arq, "Editora: %s\n", vAcervoBuffer.editora);
            fprintf(arq, "Autor: %s\n", vAcervoBuffer.autor);
            fprintf(arq, "ANO: %i\n", vAcervoBuffer.ano);
        }

        if (arq != NULL)
            fclose(arq);

	 }else{
		printf("\n\n Limite de Livros Ultrapassado...\n");
	 }

}

//LISTAR ACERVO
void listar_Acervo(){

	  titulo();

	 int i;
	 printf("\n LIVROS CADASTRADAS: \n");
	 printf("############################################################\n");
	 for(i = 0; i < vIndice_Acervo; i++){


			printf("LIVRO: \n\n");
			printf("ISBN .................: %s \n", vetLivros[i].isbn);
			printf("Titulo ...............: %s \n", vetLivros[i].titulo);
			printf("Editora ..............: %s \n", vetLivros[i].editora);
			printf("Autor ................: %s \n", vetLivros[i].autor);
			printf("Ano de Publicacao.....: %i \n\n", vetLivros[i].ano);

	 }
	 printf("############################################################\n");

	 puts("\n\n");

}

// CLASSE DE CONSULTA AO ACERVO
void pesquisar_Acervo(){

	 titulo();

	 printf("\n\n Pesquisar por Editora do Livro.\n");
	 char vExpresBusca[20];
	 printf("\n\n Digite o Nome da  Editora do Livro a Pesquisar: ");
	 fflush (stdin);
	 scanf("%s", vExpresBusca);
	 //gets(vExpresBusca);
	 int i;

	 for(i = 0; i < vIndice_Acervo; i++){
		   if(strcasecmp(vExpresBusca,vetLivros[i].editora) == 0){
				printf("\n DADOS DO LIVRO: ISBN: %s - NOME DO LIVRO: %s\n", vetLivros[i].isbn, vetLivros[i].titulo);
			   printf("############################################################\n\n");
			   printf("LIVRO: \n\n");
			   printf("ISBN .................: %s \n", vetLivros[i].isbn);
			   printf("Titulo ...............: %s \n", vetLivros[i].titulo);
			   printf("Editora ..............: %s \n", vetLivros[i].editora);
			   printf("Autor ................: %s \n", vetLivros[i].autor);
			   printf("Ano de Publicacao.....: %i \n\n", vetLivros[i].ano);
			   printf("############################################################\n");

		   }else {
			   printf("\n Livro nao encontrado ou nao Cadastrado\n");
		   }
	 }
	 puts("\n\n");


}
void cadastrar_Emprestimo (){

	 titulo();

	 if (vIndice_Emprestimo < 7){
		printf("\n\n \t EMPRESTIMO \n\n");

		Emprestimo vEmprestimoBuffer;

		printf("Informe o ISBN do Livro: ");
		fflush(stdin);
		scanf("%s", vEmprestimoBuffer.isbn);
		//gets(vEmprestimoBuffer.isbn);

		printf("Informe a matricula do aluno: ");
		scanf("%s", vEmprestimoBuffer.matricula);
		//gets(vEmprestimoBuffer.matricula);

		printf("Informe a data de emprestimo: ");
		scanf("%s", vEmprestimoBuffer.data_emprestimo);
		//gets(vEmprestimoBuffer.data_emprestimo);

		printf("Informe a data de devolucao: ");
		scanf("%s", vEmprestimoBuffer.data_devolucao);
		//gets(vEmprestimoBuffer.data_devolucao);

		vetEmprestimo[vIndice_Acervo] = vEmprestimoBuffer;

		vIndice_Emprestimo++;

		printf("\n\n Emprestimo realizado com sucesso.\n");

           FILE *arq = NULL;
        if ((arq = fopen("Arquivo Emprestimo.txt", "w+")) == NULL)
            printf("Erro: %s\n", strerror(errno));
        else {
            fprintf(arq, "ISBN: %s\n", vEmprestimoBuffer.isbn);
            fprintf(arq, "MATRICULA DO ALUNO: %s\n", vEmprestimoBuffer.matricula);
            fprintf(arq, "DATA DE EMPRESTIMO: %s\n", vEmprestimoBuffer.data_emprestimo);
            fprintf(arq, "DATA DE DEVOLUCAO: %s\n\n", vEmprestimoBuffer.data_devolucao);
        }

        if (arq != NULL)
            fclose(arq);

	 }else{
		printf("\n\n Limite de Emprestimo Ultrapassado...\n");
	 }

}

void listar_Emprestimo(){

	 titulo();

	 int i;
	 char nome_aluno[50];
	 char livro_titulo[80];

	 printf("\n EMPRESTIMO REALIZADO: \n");
	 printf("############################################################\n");
	 for(i = 0; i < vIndice_Emprestimo; i++){

			//1 mostrar o nome do aluno usando o for
			 //mostrar o titulo do livro

			printf("EMPRESTIMO: \n\n");
			printf("Aluno ................: %s - %s \n", vetEmprestimo[i].matricula, nome_aluno);
			printf("Livro ................: %s - %s\n", vetEmprestimo[i].isbn, livro_titulo);
			printf("Data de Emprestimo ...: %s \n", vetEmprestimo[i].data_emprestimo);
			printf("Data de Devolucao ....: %s \n\n", vetEmprestimo[i].data_devolucao);

	 }
	 printf("############################################################\n");

	 puts("\n\n");

}

void ordenar_var_aluno_selection(Aluno *aluno_, int quant){
	Aluno swap;
	int x, y, menor;
	unsigned int i;

	for (x = 0; x < quant; x++) {
		menor = x;
		for (y = x; y < quant; y++) {
			for (i = 0; i < strlen(vetAlunos[y].nome); i++) {
				if ( (y+1) < quant) {
					if (vetAlunos[y+1].nome[i] < vetAlunos[menor].nome[i]) {
						menor = y+1;
					}
				}
			}
		}
		if (x != menor) {
			swap = aluno_[x];
			(aluno_)[x] = aluno_[menor];
			(aluno_)[menor] = swap;
		}
	}
}

void alimenta_var_aluno(){

	//printf("Conteúdo do arquivo: \n");

	FILE *arquivo = fopen("Arquivo_Aluno.txt", "r"); 		//Abre o arquivo como somente-leitura

	if (arquivo == NULL)									//Verifica se teve algum erro ao abrir o arquivo
		printf("Erro: %s\n", strerror(errno));				//Informa o erro
	else {
		//char texto[200];									//Variável "grande" o suficiente para comportar todos os caracteres
		int i = 0;
		while (fscanf(arquivo, "%s", vetAlunos[i].matricula) != EOF) {		//Faz um loop dentro do arquivo. Enquanto a função retornar diferente de EOF (End Of File) ele vai fazer a leitura da linha
			//printf("Matricula: %s\n", vetAlunos[i].matricula);				//Imprime o valor que foi armazenado na variável

			fscanf(arquivo, "%s", vetAlunos[i].nome);					//Faz novamente a leitura
			//printf("Nome: %s\n", vetAlunos[i].nome);					//Imprime novamente o valor e assim por diante até o fim do loop.

			fscanf(arquivo, "%s", vetAlunos[i].curso);
			//printf("Curso: %s\n", vetAlunos[i].curso);

			fscanf(arquivo, "%s", vetAlunos[i].turma);
			//printf("Turma: %s\n", vetAlunos[i].turma);

			fscanf(arquivo, "%s", vetAlunos[i].periodo);
			//printf("Periodo: %s\n\n", vetAlunos[i].periodo);
			i++;
		}
		vIndice_Aluno = i;
	}

}

void imprimir_var_alunos() {
	int i;
	for(i = 0; i < vIndice_Aluno; i++) {
		printf("Matriula: %s\n", vetAlunos[i].matricula);
		printf("Nome: %s\n", vetAlunos[i].nome);
		printf("Curso: %s\n", vetAlunos[i].curso);
		printf("Turma: %s\n", vetAlunos[i].turma);
		printf("Periodo: %s\n\n", vetAlunos[i].periodo);
	}
}

// FUNCAO PRINCIPAL DO SISTEMA
int main ()
{

	alimenta_var_aluno(); 										//Alienta a variável vetAlunos[]
	ordenar_var_aluno_selection(vetAlunos, vIndice_Aluno);		//Ordena a variável vetAlunos[] no modo selection sort
	imprimir_var_alunos();										//Imprime o conteúdo da variável

	system ("color 1F");

	vIndice_Aluno = 0;
	vIndice_Acervo= 0;
	vIndice_Emprestimo= 0;

	int vOpcao;

	while (true){
		  titulo();
		  vOpcao = geraMenu(); // como sendo um subalgoritimo
		  system("cls");
		  switch (vOpcao){

				 case 1:
					  cadastrar_Aluno();

					  system ("PAUSE");
					  break;

				 case 2:
					  listar_Alunos();
					  system ("PAUSE");
					  break;
				 case 3:
					  //pesquisar_Aluno();
					  aluno_arq_texto();
					  system ("PAUSE");
					  break;
				 case 4:
					  cadastrar_Acervo();
					  system ("PAUSE");
					  break;
				 case 5:
					  listar_Acervo();
					  system ("PAUSE");
					  break;
				 case 6:
					  pesquisar_Acervo();
					  system ("PAUSE");
					  break;
				 case 7:
					  cadastrar_Emprestimo();
					  system ("PAUSE");
					  break;
				 case 8:
					  listar_Emprestimo();
					  system ("PAUSE");
					  break;
				 case 9:
					  exit(0);

				 default:
					  printf("Opcao invalida.\nTente novamente.\n\n");
					  system ("PAUSE");
					  break;
		  }
	}
	system ("PAUSE");


	return EXIT_SUCCESS;
}
