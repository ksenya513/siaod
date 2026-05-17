#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

struct Node {
    char* string;
    Node* next;
} *h = NULL;

int simple[10] = {11, 13, 17, 19, 23, 29, 53, 61, 73, 101};

void random_string(char *res, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; ++i) {
        res[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    res[length] = '\0';
}

int hash(char *str, int m) {
    int h_val = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        h_val = (h_val * 256 + str[i]) % m;
    }
    return (h_val % m + m) % m;
}

int add_linear(char* str, char** table, int m) {
    int base_hash = hash(str, m);
    for (int i = 0; i < m; i++) {
        int hash_idx = (base_hash + i) % m;
        if (table[hash_idx] == NULL) {
            table[hash_idx] = str;
            return i;
        }
    }
    return 0;
}

int add_quadratic(char* str, char** table, int m) {
    int base_hash = hash(str, m);
    for (int i = 0; i < m; i++) {
        int hash_idx = (base_hash + i * i) % m;
        if (table[hash_idx] == NULL) {
            table[hash_idx] = str;
            return i;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int num_elements = 500;
    int len = 7;
    
    for (int s = 0; s < num_elements; s++) {
        Node *p = new Node;
        p->string = (char *)malloc(len + 1);
        random_string(p->string, len);
        p->next = h;
        h = p;
    }

    printf("|==================================================|\n");
    printf("| Размер  | Кол-во  |    Кол-во коллизий Кф        |\n");
    printf("|  хэш-   | исходн. |==============================|\n");
    printf("| таблицы | строк   | Линейные пробы | Квадрат.    |\n");
    printf("|==================================================|\n");

    char* table[101];

    for (int i = 0; i < 10; i++)
    {
        int m = simple[i];
        int total_col_linear = 0;
        int total_col_quadratic = 0;

        memset(table, 0, m * sizeof(char*));
        for (Node* curr = h; curr != NULL; curr = curr->next) {
            total_col_linear += add_linear(curr->string, table, m);
        }

        memset(table, 0, m * sizeof(char*));
        for (Node* curr = h; curr != NULL; curr = curr->next) {
            total_col_quadratic += add_quadratic(curr->string, table, m);
        }

        printf("| %7d | %7d | %14d | %11d |\n", m, num_elements, total_col_linear, total_col_quadratic);
    }
    printf("|==================================================|\n");

    while(h) {
        Node* temp = h;
        h = h->next;
        free(temp->string);
        delete temp;
    }

    return 0;
}
