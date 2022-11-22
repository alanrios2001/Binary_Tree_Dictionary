#include <iostream>
#include <string>
using namespace std;

class Tree {

    typedef struct Node_translate {
        char text[50];
        struct Node_translate* next;
    }Node_translate;

    typedef struct Node_tree {

        char text[30];
        int type;
        struct Node_translate* translates;
        struct Node_tree* right;
        struct Node_tree* left;
    }Node_tree;

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

    bool get(string target_word) {
        Node_tree* head = node_tree;
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
        Node_tree* new_node = (Node_tree*)malloc(sizeof(Node_tree));
        Node_linked* new_node_linked = (Node_linked*)malloc(sizeof(Node_linked));
        strcpy_s(new_node->text, origin_word.c_str());
        strcpy_s(new_node_linked->text, origin_word.c_str());
        int type_n = 0;
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

        Node_translate* translates_list = create_translates_node(n_translates);
        new_node->translates = translates_list;
        new_node_linked->translates = translates_list;

        new_node->left = NULL;
        new_node->right = NULL;

        Node_linked* head_linked = node_linked;
        if (head_linked == NULL) {
            new_node_linked->next = head_linked;
            node_linked = new_node_linked;
        }
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

        if (node_tree == NULL) {
            node_tree = new_node;
            return true;
        }

        Node_tree* head = node_tree;
        Node_tree* head_ant = NULL;

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

        if (origin_word.compare(head_ant->text) > 0) {
            head_ant->right = new_node;
            return true;
        }
        else if (origin_word.compare(head_ant->text) < 0) {
            head_ant->left = new_node;
            return true;
        }


    }

    Node_translate* create_translates_node(int n_translates) {
        Node_translate* translates;
        translates = NULL;
        int i = 0;
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

    Node_translate* retorna_head_trad(Node_tree* head) {
        Node_translate* head_trans = head->translates;
        return head_trans;

    }

    void criar_linked_d(Node_tree* tree,Node_linked* node_linked) {
        
    }

    void imprimir_decrescente() {
        Node_linked* head = node_linked;
        while (head != NULL) {
            cout << head->text << endl;
            head = head->next;
        }

    }

    void imprimir_crescente() {
        if (node_tree != NULL) {
            in_ord(node_tree->left);
            cout << node_tree->text << endl;
            in_ord(node_tree->right);
        }
    }

    void imprimir_traduções(string word) {
        Node_translate* head = retorna_head_trad(retorna_head_tree(word));
        while (head != NULL) {
            cout << head->text << endl;
            head = head->next;
        }
    }

    string imprimir_classe(string word) {
        Node_tree* head = retorna_head_tree(word);
        return format_type(head->type);
    }

    void imprimir_arvore(Node_tree* node) {
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
        while (head != NULL) {
            if (head->type == tipo) {
                cout << head->text << endl;
            }
            head = head->next;
        }
    }

    void remover(string word) {
        Node_tree* head = node_tree;
        Node_tree* head_ant = NULL;
        
        while (head->text != word) {
            head_ant = head;
            if (word.compare(head->text) > 0) {
                head = head->right;
            }
            else if (word.compare(head->text) < 0) {
                head = head->left;
            }
        }
        
        //o nó a ser removido é a raiz
        if (head_ant == NULL) {
            if (head->right != NULL) {
                Node_tree* head_menor_dir = head->right;
                Node_tree* head_menor_dir_ant = NULL;
                while (head_menor_dir->left != NULL) {
                    head_menor_dir_ant = head_menor_dir;
                    head_menor_dir = head_menor_dir->left;
                }
                if (head_menor_dir_ant == NULL) {
                    head_menor_dir->left = head->left;
                    free(head);
                    node_tree = head_menor_dir;
                    cout << "palavra removida: " << word << endl;
                }
                else {
                    head_menor_dir_ant->left = head_menor_dir->right;
                    head_menor_dir->left = head->left;
                    head_menor_dir->right = head->right;
                    free(head);
                    node_tree = head_menor_dir;
                    cout << "palavra removida: " << word << endl;
                }
            }
            else if (head->left != NULL) {
                Node_tree* head_maior_esq = head->left;
                Node_tree* head_maior_esq_ant = NULL;
                while (head_maior_esq->right != NULL) {
                    head_maior_esq_ant = head_maior_esq;
                    head_maior_esq = head_maior_esq->right;
                }
                if (head_maior_esq_ant == NULL) {
                    head_maior_esq->right = head->right;
                    free(head);
                    node_tree = head_maior_esq;
                    cout << "palavra removida: " << word << endl;
                }
                else {
                    head_maior_esq_ant->right = head_maior_esq->left;
                    head_maior_esq->left = head->left;
                    head_maior_esq->right = head->right;
                    free(head);
                    node_tree = head_maior_esq;
                    cout << "palavra removida: " << word << endl;
                }
            }
            else {
                node_tree = NULL;
                free(head);
                cout << "palavra removida: " << word << endl;
            }
        }
        //o nó não é a raiz
        else {
            if (head->right != NULL) {
                Node_tree* head_menor_dir = head->right;
                Node_tree* head_menor_dir_ant = NULL;
                while (head_menor_dir->left != NULL) {
                    head_menor_dir_ant = head_menor_dir;
                    head_menor_dir = head_menor_dir->left;
                }
                if (head_menor_dir_ant == NULL) {
                    head_menor_dir->left = head->left;
                    
                    if (head_ant->right = head) {
                        head_ant->right = head_menor_dir;
                    }
                    else {
                        head_ant->left = head_menor_dir;
                    }
                    free(head);
                    cout << "palavra removida: " << word << endl;
                }
                else {
                    head_menor_dir_ant->left = NULL;
                    head_menor_dir->left = head->left;
                    head_menor_dir->right = head->right;
                    if (head_ant->left == head) {
                        head_ant->left = head_menor_dir;
                    }
                    else {
                        head->right = head_menor_dir;
                    }
                    free(head);
                    cout << "palavra removida: " << word << endl;
                }
            }
            else if (head->left != NULL) {
                Node_tree* head_maior_esq = head->left;
                Node_tree* head_maior_esq_ant = NULL;
                while (head_maior_esq->right != NULL) {
                    head_maior_esq_ant = head_maior_esq;
                    head_maior_esq = head_maior_esq->right;
                }

                if (head_maior_esq_ant == NULL) {
                    head_maior_esq->right = head->right;

                    if (head_ant->right = head) {
                        head_ant->right = head_maior_esq;
                    }
                    else {
                        head_ant->left = head_maior_esq;
                    }
                    free(head);
                    cout << "palavra removida: " << word << endl;
                }
                else {
                    head_maior_esq_ant->right = NULL;
                    head_maior_esq->left = head->left;
                    head_maior_esq->right = head->right;
                    if (head_ant->left == head) {
                        head_ant->left = head_maior_esq;
                    }
                    else {
                        head->right = head_maior_esq;
                    }
                    free(head);
                    cout << "palavra removida: " << word << endl;
                }

                
            }
            else {
                if (head_ant->right == head) {
                    head_ant->right = NULL;
                    free(head);
                    cout << "palavra removida: " << word << endl;
                }
                if (head_ant->left == head) {
                    head_ant->left = NULL;
                    free(head);
                    cout << "palavra removida: " << word << endl;
                }
            }
        }

        

    }

};

class App {

public:
    Tree tree;
    App(int debug = false) {
        string input;
        while (input != "e") {
            getline(cin, input);
            comands(input);
        }
        if (debug == true) {
            tree.run_debug();
        }
    }

    void comands(string comand) {
        if (comand == "i") {
            string origin_word;
            string type;
            int n_translates;
            getline(cin, origin_word);
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
        if (comand == "t") {
            string word;
            getline(cin, word);
            if (tree.get(word) == false) {
                cout << "palavra inexistente no dicionario: " << word << endl;
            }
            else {
                cout << "traducoes da palavra: " << word << endl;
                tree.imprimir_traduções(word);
            }
        }
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
        if (comand == "p") {
            tree.imprimir_arvore(tree.node_tree);
        }
        if (comand == "a") {
            string opc1;
            string opc2;
            getline(cin, opc1);
            getline(cin, opc2);
            if (opc1 == "s") {
                if (opc2 == "c") {
                    tree.imprimir_tipo_crescente(tree.node_tree,0);
                }
                else if (opc2 == "d") {
                    tree.imprimir_tipo_decrescente(0);
                }
            }
            if (opc1 == "a") {
                if (opc2 == "c") {
                    tree.imprimir_tipo_crescente(tree.node_tree,1);
                }
                else if (opc2 == "d") {
                    tree.imprimir_tipo_decrescente(1);
                }
            }
            if (opc1 == "v") {
                if (opc2 == "c") {
                    tree.imprimir_tipo_crescente(tree.node_tree,2);
                }
                else if (opc2 == "d") {
                    tree.imprimir_tipo_decrescente(2);
                }
            }
        }
        if (comand == "r") {
            string word;
            getline(cin, word);
            if (tree.get(word) == false) {
                cout << "palavra inexistente no dicionario:" << " " << word << endl;
            }
            else {
                tree.remover(word);
            }
        }
    }
};

int main()
{
    bool debug = false; //true for debug
    App app(debug);
}