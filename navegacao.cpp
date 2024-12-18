#include <iostream> // Correto: inclui a biblioteca para entrada e saída
#include <string>   // Necessário para trabalhar com strings
using namespace std;

// Estrutura do nó da árvore
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Função para inserir um nó na árvore
Node* insert(Node* root, char value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Função de navegação em pré-ordem
void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Função de navegação em-ordem
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Função de navegação em pós-ordem
void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    string letters = "JUCINARDSL";

    // Inserir as letras na árvore
    for (char letter : letters) {
        root = insert(root, letter);
    }

    // Imprimir as navegações
    cout << "Pré-ordem: ";
    preOrder(root);
    cout << endl;

    cout << "Em ordem: ";
    inOrder(root);
    cout << endl;

    cout << "Pós-ordem: ";
    postOrder(root);
    cout << endl;

    return 0;
}
