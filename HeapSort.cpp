#include "HeapSort.h"
#include<iostream>

using namespace std;

//Construtor
HeapSort::HeapSort(int maxItems, ItemType* items, int length){
	this->items = new ItemType[maxItems];
	this->length = length;
	this->maxItems = maxItems;
	
	//faz uma copia do vetor para items
	for(int i=0; i<length; i++){
		this->items[i] = items[i];
	}
	
	//cria a Heap
	int ultimoPai = ((length)/2) -1;
	for(int i=ultimoPai; i>=0; i--){
		descida(i, length);
	}
}

//Destrutor
HeapSort::~HeapSort(){
	delete [] items;
}

//Verifica vazio
bool HeapSort::isEmpty() const {
	return (this->length == 0);
}

//Verifica cheio
bool HeapSort::isFull() const {
	return (this->maxItems == this->length);
}

//Inserir no topo
void HeapSort::enqueue(ItemType itemType){
	if(isFull()){	
		return;
	}

	this->items[this->length++] = itemType;
	//Subir na Heap	
	subida(0, this->length-1);
}

//Retirar item do topo
ItemType HeapSort::dequeue(){
	if(isEmpty()){
		return ItemType();
	}

	ItemType itemRemoved = items[0];
	items[0] = items[--length];
	descida(0, length-1);	
	return (itemRemoved);
}



/*
 *Sobe o elemento até a posição certa dele seguindo as ordens da Heap
 */
void HeapSort::subida(int root, int index){		
	ItemType pai = items[index/2-1];
	if(items[index] > pai){
		items[index/2-1] = items[index];
		items[index] = pai; 
		subida(root, index/2-1);
	}
}

/*
 *Desce o elemento até a posição certa dele seguindo as ordens da Heap
 */

void HeapSort::descida(int index, int bottom){
	//filho é a posição do filho da esquerda de index
	int filho = 2*index + 1;
	
	if(filho < bottom ){
		//Se existe o filho da esquerda
		if(filho+1 < bottom && items[filho] < items[filho+1]){
				//se existe o filho da esquerda e o da direita e o da direita for maior
				//que o filho da esquerda
				//pega o maior filho
				filho++;
		}
		
		if(items[filho] > items[index]){
			//Se o filho for maior que o pai, troca ele de posição
			ItemType aux = items[index];
			items[index] = items[filho];
			items[filho] = aux;
			//desce o filho com o tamanho da lista
			descida(filho, bottom);
		}
		
	}	 	
}

/**
 *Ordena a Heap em ordem crescente
 *
 */
 
void HeapSort::sort(){
	//int bottom - tamanho da lista, vai decrescentando conforme o ultimo elemento foi ordenado
	int bottom = length;
	while(bottom > 0){
	//troca a posição do primeiro elemento com o ultimo elemento da lista 
	//decresce o bottom conforme o ultimo elemento for ordenado
		ItemType aux = items[0];
		items[0] = items[bottom-1];
		items[bottom-1] = aux;
		bottom--;
		descida(0,bottom);
	}
}
