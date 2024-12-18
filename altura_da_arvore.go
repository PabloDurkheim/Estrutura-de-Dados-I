package main

import (
	"fmt"
	"math"
)

// Estrutura de um nó da árvore binária
type NoBst struct {
	Val int
	Esq *NoBst
	Dir *NoBst
}

// Função auxiliar que verifica se a árvore é uma BST
func verificaBst(raiz *NoBst, min, max int) bool {
	if raiz == nil {
		return true
	}
	// Verifica se o valor do nó atual está fora dos limites válidos
	if raiz.Val <= min || raiz.Val >= max {
		return false
	}
	// Verifica recursivamente para os filhos esquerdo e direito
	return verificaBst(raiz.Esq, min, raiz.Val) && verificaBst(raiz.Dir, raiz.Val, max)
}

// Função principal para verificar se a árvore é uma BST
func ehBst(raiz *NoBst) bool {
	return verificaBst(raiz, math.MinInt, math.MaxInt)
}

// Função para criar um novo nó
func novoNo(val int) *NoBst {
	return &NoBst{Val: val, Esq: nil, Dir: nil}
}

// Função para inserir um valor na BST
func inserir(raiz *NoBst, val int) *NoBst {
	if raiz == nil {
		return novoNo(val)
	}
	if val < raiz.Val {
		raiz.Esq = inserir(raiz.Esq, val)
	} else {
		raiz.Dir = inserir(raiz.Dir, val)
	}
	return raiz
}

// Função para contar a quantidade de elementos em uma BST
func contarElementos(raiz *NoBst) int {
	if raiz == nil {
		return 0
	}
	// Conta o nó atual e soma recursivamente os nós das subárvores esquerda e direita
	return 1 + contarElementos(raiz.Esq) + contarElementos(raiz.Dir)
}

// Função para calcular a altura da árvore
func calcularAltura(raiz *NoBst) int {
	if raiz == nil {
		return 0
	}
	// Calcula a altura das subárvores esquerda e direita
	alturaEsq := calcularAltura(raiz.Esq)
	alturaDir := calcularAltura(raiz.Dir)
	// A altura da árvore é o maior valor entre as duas subárvores, mais 1 (o nó atual)
	return 1 + int(math.Max(float64(alturaEsq), float64(alturaDir)))
}

func main() {
	// Inicializa a árvore com os valores fornecidos
	valores := []int{50, 30, 45, 32, 10, 90, 55, 49, -5, 88, 110, 40}
	var raiz *NoBst
	for _, val := range valores {
		raiz = inserir(raiz, val)
	}

	// Verifica se a árvore é uma BST
	if ehBst(raiz) {
		fmt.Println("A árvore é uma BST.")
	} else {
		fmt.Println("A árvore NÃO é uma BST.")
	}

	// Calcula e imprime a quantidade de elementos na árvore
	totalElementos := contarElementos(raiz)
	fmt.Printf("A árvore tem %d elementos.\n", totalElementos)

	// Calcula e imprime a altura da árvore
	altura := calcularAltura(raiz)
	fmt.Printf("A altura da árvore é %d.\n", altura)
}
