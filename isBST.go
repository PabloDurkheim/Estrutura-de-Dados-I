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

// Função para contar a quantidade de elementos em uma BST
func contarElementos(raiz *NoBst) int {
	if raiz == nil {
		return 0
	}
	// Conta o nó atual e soma recursivamente os nós das subárvores esquerda e direita
	return 1 + contarElementos(raiz.Esq) + contarElementos(raiz.Dir)
}

func main() {
	// Exemplo de árvore
	/*
	              10
	             /  \
	            5    20
	           / \   / \
	          3   7 15  30
	*/
	raiz := novoNo(10)
	raiz.Esq = novoNo(5)
	raiz.Dir = novoNo(20)
	raiz.Esq.Esq = novoNo(3)
	raiz.Esq.Dir = novoNo(7)
	raiz.Dir.Esq = novoNo(15)
	raiz.Dir.Dir = novoNo(30)

	// Verifica se a árvore é uma BST
	if ehBst(raiz) {
		fmt.Println("A árvore é uma BST.")
	} else {
		fmt.Println("A árvore NÃO é uma BST.")
	}

	// Calcula e imprime a quantidade de elementos na árvore
	totalElementos := contarElementos(raiz)
	fmt.Printf("A árvore tem %d elementos.\n", totalElementos)
}
