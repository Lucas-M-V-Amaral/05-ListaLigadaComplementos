#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else if (posicaoElemento(novo->valor) == NULL)
	{
		NO* aux = primeiro;

		if (aux->valor > novo->valor) {
			novo->prox = aux;
			primeiro = novo;
		}

		else {
			while (aux->prox != NULL) {
				if (aux->valor > novo->valor) {
					break;
				}
				aux = aux->prox;
			}

			if (aux->valor > novo->valor) 
			{
				NO* aux2 = primeiro;

				while (aux2->prox != aux)
				{
					aux2 = aux2->prox;
				}

				if (aux2->prox == aux)
				{
					novo->prox = aux2->prox;
					aux2->prox = novo;
				}
			} 

			else if (aux->prox == NULL) 
			{ 
				aux->prox = novo;  
			}
		}
	}
	else {
		cout << "O elemento ja esta na lista!" << endl;
	}
}

void excluirElemento()
{
	int num;
	cout << "Digite o elemento que deseja excluir:";
	cin >> num;

	if (posicaoElemento(num) == NULL) {
		cout << "ELEMENTO NAO ENCONTRADO" << endl;
	}
	else {
		NO* aux = primeiro; 
		NO* nd = posicaoElemento(num); 

		if (nd == primeiro) {
			primeiro = primeiro->prox; 
		}
		else {

			while (aux->prox != nd) { 
				aux = aux->prox; 
			}

			aux->prox = nd->prox;
			free(nd);
		}
	}
}

void buscarElemento()
{
	int num;

	cout << "Digite o elemento a ser buscado:";
	cin >> num;

	if (posicaoElemento(num) != NULL) {
		cout << "ENCONTRADO" << endl;
	}

	else {
		cout << "ELEMENTO NAO ENCONTRADO" << endl;
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;

	while (aux != NULL) {
		if (aux->valor == numero) 
		{
			break;
		}
		aux = aux->prox; 
	}

	return aux;
}

/* 
*/