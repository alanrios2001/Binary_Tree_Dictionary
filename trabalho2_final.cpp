#include <iostream>
#include <string>
using namespace std;

class Tree {
    //lista encadeada traduçao
    typedef struct Node_translate {
        char text[50];
        struct Node_translate* next;
    }Node_translate;

    //arvore binaria
    typedef struct Node_tree {
        char text[30];
        int type;
        struct Node_translate* translates;
        struct Node_tree* right;
        struct Node_tree* left;
    }Node_tree;

    //lista encadeada idiomas de origem
    typedef struct Node_linked {
        char text[30];
        int type;
        struct Node_translate* translates;
        struct Node_linked* next;
    }Node_linked;

public:

    void run_debug() {
        int opc = 4;
        while (opc != 2) {
            cout << "---- debug ----" << endl;
            cout << "0 - sem traduções" << endl;
            cout << "1 - com traduções e tipos" << endl;
            cout << "2 - sair" << endl;
            cout << "--------------------------" << endl;
            cin >> opc;
            if (opc == 0) {
                cout << "--------------------------" << endl;
                cout << "0 - in_ordem" << endl;
                cout << "1 - pre_ordem" << endl;
                cout << "2 - pos_ordem" << endl;
                cout << "3 - sair" << endl;
                cout << "--------------------------" << endl;
                int opc2 = 5;
                cout << "----- estrutura de dados -- Arvore BB -----" << endl;
                Node_tree* head = node_tree;
                while (opc2 != 3) {
                    cin >> opc2;
                    if (opc2 == 0) {
                        cout << "--------------------------" << endl;
                        in_ord(head);
                        cout << "--------------------------" << endl;
                    }
                    else if (opc2 == 1) {
                        cout << "--------------------------" << endl;
                        pre_ord(head);
                        cout << "--------------------------" << endl;
                    }
                    else if (opc2 == 2) {
                        cout << "--------------------------" << endl;
                        pos_ord(head);
                        cout << "--------------------------" << endl;
                    }
                }
            }
            if (opc == 1) {
                int opc2 = 5;
                cout << "----- estrutura de dados -- Arvore BB -----" << endl;
                Node_tree* head = node_tree;
                while (opc2 != 3) {
                    cout << "--------------------------" << endl;
                    cout << "0 - in_ordem" << endl;
                    cout << "1 - pre_ordem" << endl;
                    cout << "2 - pos_ordem" << endl;
                    cout << "3 - sair" << endl;
                    cout << "--------------------------" << endl;
                    cin >> opc2;
                    if (opc2 == 0) {
                        cout << "--------------------------" << endl;
                        in_ord_trad(head);
                        cout << "--------------------------" << endl;
                    }
                    else if (opc2 == 1) {
                        cout << "--------------------------" << endl;
                        pre_ord_trad(head);
                        cout << "--------------------------" << endl;
                    }
                    else if (opc2 == 2) {
                        cout << "--------------------------" << endl;
                        pos_ord_trad(head);
                        cout << "--------------------------" << endl;
                    }
                }
            }
        }
    }

    Node_tree* node_tree;
    Node_linked* node_linked;

    Tree() {
        node_tree = NULL;
        node_linked = NULL;
    }

    //////////////////////////////////////////////////
    /////////////////funcoes debug////////////////////
    //////////////////////////////////////////////////

    void in_ord(Node_tree* node) {
        if (node != NULL) {
            in_ord(node->left);
            cout << node->text << endl;
            in_ord(node->right);
        }
    }

    void pos_ord(Node_tree* node) {
        if (node != NULL) {
            pos_ord(node->left);
            pos_ord(node->right);
            cout << node->text << endl;
        }
    }

    void pre_ord(Node_tree* node) {
        if (node != NULL) {
            cout << node->text << endl;
            pre_ord(node->left);
            pre_ord(node->right);
        }
    }

    void in_ord_trad(Node_tree* node) {
        if (node != NULL) {
            in_ord_trad(node->left);
            cout << node->text << endl;
            cout << "tipo: " << format_type(node->type) << endl;
            cout << "traduções: " << endl;
            Node_translate* head = node->translates;
            while (head != NULL) {
                cout << head->text << endl;
                head = head->next;
            }
            in_ord_trad(node->right);
        }
    }

    void pos_ord_trad(Node_tree* node) {
        if (node != NULL) {
            pos_ord_trad(node->left);
            pos_ord_trad(node->right);
            cout << node->text << endl;
            cout << "tipo: " << format_type(node->type) << endl;
            cout << "traduções: " << endl;
            Node_translate* head = node->translates;
            while (head != NULL) {
                cout << head->text << endl;
                head = head->next;
            }
        }
    }

    void pre_ord_trad(Node_tree* node) {
        if (node != NULL) {
            cout << node->text << endl;
            cout << "tipo: " << format_type(node->type) << endl;
            cout << "traduções: " << endl;
            Node_translate* head = node->translates;
            while (head != NULL) {
                cout << head->text << endl;
                head = head->next;
            }
            pre_ord_trad(node->left);
            pre_ord_trad(node->right);
        }
    }
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    bool get(string target_word) {
        Node_tree* head = node_tree;
        //percurso de busca de palavra no idioma de origem
        while (head != NULL) {
            if (head->text == target_word) {
                return true;
            }
            if (target_word.compare(head->text) > 0) {
                head = head->right;
            }
            else if (target_word.compare(head->text) < 0) {
                head = head->left;
            }
        }
        return false;
    }

    bool insert(string origin_word, string type, int n_translates) {
        //cria arvore de palavras no idioma de origem
        Node_tree* new_node = (Node_tree*)malloc(sizeof(Node_tree));
        //cria lista encadeada de palavras no idioma de origem simultaneamente
        Node_linked* new_node_linked = (Node_linked*)malloc(sizeof(Node_linked));
        //a lista encadeada e a arvore são preenchidas na mesma função
        strcpy_s(new_node->text, origin_word.c_str());
        strcpy_s(new_node_linked->text, origin_word.c_str());
        int type_n = 0;
        //converte tipos em numeros
        if (type == "s") {
            type_n = 0;
        }
        else if (type == "a") {
            type_n = 1;
        }
        else if (type == "v") {
            type_n = 2;
        }
        new_node->type = type_n;
        new_node_linked->type = type_n;
        //cria no de traduções
        Node_translate* translates_list = create_translates_node(n_translates);
        new_node->translates = translates_list;
        new_node_linked->translates = translates_list;
        //define apontadores iniciais como nulos
        new_node->left = NULL;
        new_node->right = NULL;

        Node_linked* head_linked = node_linked;
        //verifica se existem elementos na lista encadeada
        if (head_linked == NULL) {
            new_node_linked->next = head_linked;
            node_linked = new_node_linked;
        }
        //se a lista encadeada nao estiver vazia, armazena respeitando a ordem decrescente
        else {
            Node_linked* head_linked_ant = NULL;
            while (head_linked != NULL && origin_word.compare(head_linked->text) < 0) {
                head_linked_ant = head_linked;
                head_linked = head_linked->next;
            }
            if (head_linked_ant == NULL) {
                new_node_linked->next = head_linked;
                node_linked = new_node_linked;
            }
            else {
                head_linked_ant->next = new_node_linked;
                new_node_linked->next = head_linked;
            }
        }
        //verifica se a arvore está vazia
        if (node_tree == NULL) {
            node_tree = new_node;
            return true;
        }
        //se a arvore possuir elementos faz percurso de busca de espaço nulo disponivel
        Node_tree* head = node_tree;
        Node_tree* head_ant = NULL;
        //percurso de busca de comparação
        while (head != NULL) {
            if (origin_word.compare(head->text) > 0) {
                head_ant = head;
                head = head->right;
            }
            else if (origin_word.compare(head->text) < 0) {
                head_ant = head;
                head = head->left;
            }
        }
        //cnfigura os apontadores para o novo nó
        if (origin_word.compare(head_ant->text) > 0) {
            head_ant->right = new_node;
            return true;
        }
        else if (origin_word.compare(head_ant->text) < 0) {
            head_ant->left = new_node;
            return true;
        }


    }

    string format_type(int n) {
        if (n == 0) {
            return "substantivo";
        }
        else if (n == 1) {
            return "adjetivo";
        }
        else {
            return "verbo";
        }
    }

    Node_translate* create_translates_node(int n_translates) {
        Node_translate* translates;
        translates = NULL;
        int i = 0;
        //recebe entradas e armazena na lista encadeada de traduções de uma palavra
        while (i != n_translates+1) {
            Node_translate* new_translate = (Node_translate*)malloc(sizeof(Node_translate));
            string translate;
            getline(cin, translate);
            if (translate.length() > 0) {
                strcpy_s(new_translate->text, translate.c_str());
                new_translate->next = translates;
                translates = new_translate;
            }
            
            i += 1;
        }

        return translates;
    }

    Node_tree* retorna_head_tree(string word) {
        Node_tree* head = node_tree;
        //faz percurso de busca de uma palavra
        while (head != NULL && head->text != word) {
            if (word.compare(head->text) > 0) {
                head = head->right;
            }
            else if (word.compare(head->text) < 0) {
                head = head->left;
            }
        }
        return head;

    }

    //retorna lista encadeada das traduções de uma palavra
    Node_translate* retorna_head_trad(Node_tree* head) {
        Node_translate* head_trans = head->translates;
        return head_trans;

    }

    void imprimir_decrescente() {
        Node_linked* head = node_linked;
        //percorre lista encadeada dos idiomas de origem
        while (head != NULL) {
            cout << head->text << endl;
            head = head->next;
        }

    }

    void imprimir_crescente() {
        //percorre arvore em in-ordem
        if (node_tree != NULL) {
            in_ord(node_tree->left);
            cout << node_tree->text << endl;
            in_ord(node_tree->right);
        }
    }

    void imprimir_traduções(string word) {
        Node_translate* head = retorna_head_trad(retorna_head_tree(word));
        //percorre lista encadeada das traduções de uma palavra
        while (head != NULL) {
            cout << head->text << endl;
            head = head->next;
        }
    }

    string imprimir_classe(string word) {
        //busca no da palavra
        Node_tree* head = retorna_head_tree(word);
        //transforma tipo morfologico armazenado numericamente em string para display
        return format_type(head->type);
    }

    void imprimir_arvore(Node_tree* node) {
        //imprime arvore em pre-ordem
        if (node != NULL) {
            cout << "chave: " << node->text << " " << "fesq: ";
            if (node->left == NULL) {
                cout << "nil"<<" "<<"fdir: ";
            }
            else {
                cout << node->left->text << " " << "fdir: ";
            }
            if (node->right == NULL) {
                cout << "nil" << endl;
            }
            else {
                cout << node->right->text << endl;;
            }
            imprimir_arvore(node->left);
            imprimir_arvore(node->right);
        }
    }

    void imprimir_tipo_crescente(Node_tree* node,int tipo) {
        //percorre arvore em-ordem
        if (node != NULL) {
            imprimir_tipo_crescente(node->left, tipo);
            if (node->type == tipo) {
                cout << node->text << endl;
            }
            imprimir_tipo_crescente(node->right, tipo);
        }
    }

    void imprimir_tipo_decrescente(int tipo) {
        Node_linked* head = node_linked;
        //percorre lista encadeada
        while (head != NULL) {
            if (head->type == tipo) {
                cout << head->text << endl;
            }
            head = head->next;
        }
    }

    void remover(Node_tree* node, Node_tree* node_ant, string word) {
        if (node->text == word) {
            //remover folha
            if (node->left == NULL && node->right == NULL) {
                //verifica se o nó é a raiz principal para evitar erro de nullpointer
                if (node_ant != NULL) {
                    if (node_ant->left == node) {
                        node_ant->left = NULL;
                    }
                    else if (node_ant->right == node) {
                        node_ant->right = NULL;
                    }
                    free(node);
                }
                else {
                    free(node);
                    node_tree = NULL;
                }
                cout << "palavra removida: " << word << endl;
            }
            else {
                //no com um filho a esquerda
                if (node->left != NULL && node->right == NULL) {
                    Node_tree* node_aux = node->left;
                    Node_tree* node_aux_ant = NULL;
                    while (node_aux->right != NULL) {
                        node_aux_ant = node_aux;
                        node_aux = node_aux->right;
                    }
                    //o filho é o maior a esquerda
                    if (node_aux_ant == NULL) {
                        strcpy_s(node->text, node_aux->text);
                        node->translates = node_aux->translates;
                        node->type = node_aux->type;
                        node->left = node_aux->left;
                        free(node_aux);
                        cout << "palavra removida: " << word << endl;
                    }
                    //o filho possui maiores
                    else {
                        strcpy_s(node->text, node_aux->text);
                        node->translates = node_aux->translates;
                        node->type = node_aux->type;
                        node_aux_ant->right = node_aux->left;
                        free(node_aux);
                        cout << "palavra removida: " << word << endl;
                    }
                }
                //no com um filho a direita
                else if (node->left == NULL && node->right != NULL) {
                    Node_tree* node_aux = node->right;
                    Node_tree* node_aux_ant = NULL;
                    while (node_aux->left != NULL) {
                        node_aux_ant = node_aux;
                        node_aux = node_aux->left;
                    }
                    //o filho é o menor a direita
                    if (node_aux_ant == NULL) {
                        strcpy_s(node->text, node_aux->text);
                        node->translates = node_aux->translates;
                        node->type = node_aux->type;
                        node->right = node_aux->right;
                        free(node_aux);
                        cout << "palavra removida: " << word << endl;
                    }
                    //o filho possui menores
                    else {
                        strcpy_s(node->text, node_aux->text);
                        node->translates = node_aux->translates;
                        node->type = node_aux->type;
                        node_aux_ant->left = node_aux->right;
                        free(node_aux);
                        cout << "palavra removida: " << word << endl;
                    }

                }
                //no com 2 filhos
                else if (node->left != NULL && node->right != NULL) {
                    //busca o menor a direita
                    Node_tree* node_aux = node->right;
                    Node_tree* node_aux_ant = NULL;
                    while (node_aux->left != NULL) {
                        node_aux_ant = node_aux;
                        node_aux = node_aux->left;
                    }
                    //o filho é o menor a direita
                    if (node_aux_ant == NULL) {
                        strcpy_s(node->text, node_aux->text);
                        node->translates = node_aux->translates;
                        node->type = node_aux->type;
                        node->right = node_aux->right;
                        free(node_aux);
                        cout << "palavra removida: " << word << endl;
                    }
                    //o filho possui menores
                    else {
                        strcpy_s(node->text, node_aux->text);
                        node->translates = node_aux->translates;
                        node->type = node_aux->type;
                        node_aux_ant->left = node_aux->right;
                        free(node_aux);
                        cout << "palavra removida: " << word << endl;
                    }
                }
            }

        }
        else {
            //verifica se a chave é maior ou menor
            if (word.compare(node->text) > 0) {
                remover(node->right, node, word);
            }
            else {
                remover(node->left, node, word);
            }
        }

    }

};

class App {

public:
    Tree tree;
    App(int debug = false) {
        string input;
        //captura de comandos encerra com input = e
        while (input != "e") {
            getline(cin, input);
            comands(input);
        }
        //funcao de debug do codigo
        if (debug == true) {
            tree.run_debug();
        }
    }

    void comands(string comand) {
        //comando i
        if (comand == "i") {
            string origin_word;
            string type;
            int n_translates;
            getline(cin, origin_word);
            //verifica se a palavra existe
            if (tree.get(origin_word) == false) {
                getline(cin, type);
                cin >> n_translates;
                tree.insert(origin_word, type, n_translates);
                cout << "palavra inserida no dicionario:" <<" "<<origin_word<< endl;
            }
            else {
                cout << "palavra ja existente:" << " " << origin_word << endl;
            }

        }
        //comando l
        if (comand == "l") {
            string l_input;
            getline(cin, l_input);
            if (l_input == "c") {
                tree.imprimir_crescente();
            }
            else if (l_input == "d") {
                tree.imprimir_decrescente();
            }
        }
        //comando t
        if (comand == "t") {
            string word;
            getline(cin, word);
            //verifica se palavra existe
            if (tree.get(word) == false) {
                cout << "palavra inexistente no dicionario: " << word << endl;
            }
            else {
                cout << "traducoes da palavra: " << word << endl;
                tree.imprimir_traduções(word);
            }
        }
        //comando c
        if (comand == "c") {
            string word;
            getline(cin, word);
            if (tree.get(word) == false) {
                cout << "palavra inexistente no dicionario: " << word << endl;
            }
            else {
                cout << "classe da palavra: " << word << ": " << tree.imprimir_classe(word) << endl;
            }
        }
        //comando p
        if (comand == "p") {
            tree.imprimir_arvore(tree.node_tree);
        }
        //comando a
        if (comand == "a") {
            string opc1;
            string opc2;
            getline(cin, opc1);
            getline(cin, opc2);
            // opcao 1 substantivo
            if (opc1 == "s") {
                //opcao 2 crescente
                if (opc2 == "c") {
                    tree.imprimir_tipo_crescente(tree.node_tree,0);
                }
                //opcao 2 decrescente
                else if (opc2 == "d") {
                    tree.imprimir_tipo_decrescente(0);
                }
            }
            // opcao 1 adjetivo
            if (opc1 == "a") {
                //opcao 2 crescente
                if (opc2 == "c") {
                    tree.imprimir_tipo_crescente(tree.node_tree,1);
                }
                //opcao 2 decrescente
                else if (opc2 == "d") {
                    tree.imprimir_tipo_decrescente(1);
                }
            }
            // opcao 1 verbo
            if (opc1 == "v") {
                //opcao 2 crescente
                if (opc2 == "c") {
                    tree.imprimir_tipo_crescente(tree.node_tree,2);
                }
                //opcao 2 decrescente
                else if (opc2 == "d") {
                    tree.imprimir_tipo_decrescente(2);
                }
            }
        }
        //comando r
        if (comand == "r") {
            string word;
            getline(cin, word);
            //verifica se palavra existe
            if (tree.get(word) == false) {
                cout << "palavra inexistente no dicionario:" << " " << word << endl;
            }
            else {
                tree.remover(tree.node_tree, NULL, word);
            }
        }
    }
};

int main()
{
    //inicializa classe
    bool debug = false; //true for debug
    App app(debug);
}
