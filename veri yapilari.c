/* Klavyeden -1 girilinceye kadar, girilen tüm tek sayilari listenin basina, çift sayilari ise
listenin sonuna ekleyen fonksiyonu yaziniz*/

#include <stdio.h>
#include <stdlib.h>

// Dügüm yapisi
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir dügüm olusturur
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Tek sayilari listenin basina, çift sayilari ise listenin sonuna ekler
void addNumbers(struct Node** head) {
    int num;
    while (1) {
        printf("Bir sayi girin (-1 girerek çikis yapin): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        struct Node* newNodePtr = newNode(num);

        if (num % 2 == 1) {
            newNodePtr->next = *head;
            *head = newNodePtr;
        } else {
            if (*head == NULL) {
                *head = newNodePtr;
            } else {
                struct Node* current = *head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNodePtr;
            }
        }
    }
}

// Liste içerigini ekrana basar
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    addNumbers(&head);

    printf("\nListe içerigi:\n");
    printList(head);

    return 0;
}

/*- Listeye rastgele üretilmis 100 sayi eklensin, girilen tüm sayilari büyükten küçüge siralayan
ve ekrana basan c kodunu yaziniz.
Çikti : 54->58->62->65->71->73->……102*/

#include <stdio.h>
#include <stdlib.h>

// Bagli liste dügüm yapisi
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir dügüm olusturur
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Bagli listeye yeni bir dügüm ekler
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Bagli listeyi büyükten küçüge siralar
void sortList(struct Node** head) {
    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;

    if (*head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Bagli listeyi ekrana basar
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) {
            printf("->");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int i, num;

    // Rastgele 100 sayiyi bagli listeye ekle
    for (i = 0; i < 100; i++) {
        num = rand() % 1000; // 0-999 arasinda rastgele bir sayi üret
        insert(&head, num);
    }

    // Bagli listeyi büyükten küçüge sirala
    sortList(&head);

    // Bagli listeyi ekrana bas
    printList(head);

    return 0;
}

/* Ögrenci numarasi, isim ve yasinin sakli tutuldugu, listedeki tüm dügümleri Dolasan,
ögrenci bilgilerinin tümünü ekrana yazan ve sayan fonksiyonu yaziniz.
Çikti ekranda söyle gözükmelidir : 1- Saliha 27 201
 2- Ece 19 203*/
#include <stdio.h>
#include <stdlib.h>

// Ögrenci dügüm yapisi
struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};

// Yeni bir ögrenci dügümü olusturur
struct Student* newStudent(int number, char name[], int age) {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    student->number = number;
    strcpy(student->name, name);
    student->age = age;
    student->next = NULL;
    return student;
}

// Ögrenci listesini dolasarak bilgileri ekrana yazdirir ve sayar
void printAndCountStudents(struct Student* head) {
    struct Student* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        printf("%d- %s %d %d\n", current->number, current->name, current->age, current->number);
        current = current->next;
    }

    printf("Toplam ögrenci sayisi: %d\n", count);
}

int main() {
    struct Student* head = newStudent(201, "Saliha", 27);
    head->next = newStudent(203, "Ece", 19);

    printf("Ögrenci bilgileri:\n");
    printAndCountStudents(head);

    return 0;
}

/*Listede ögrenci adina göre kayit arama yapan fonksiyonu yaziniz*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    char grade;
};

struct Student search_student(struct Student records[], int size, const char* name) {
    struct Student not_found = {"", 0, '\0'};
    
    for (int i = 0; i < size; i++) {
        if (strcmp(records[i].name, name) == 0) {
            return records[i];
        }
    }
    
    return not_found;
}

int main() {
    struct Student student_records[] = {
        {"Ali", 20, 'A'},
        {"Ayse", 19, 'B'},
        {"Mehmet", 21, 'C'},
        {"Zeynep", 20, 'A'}
    };
    
    int size = sizeof(student_records) / sizeof(student_records[0]);
    
    char search_name[50];
    printf("Aranacak ögrenci adini girin: ");
    scanf("%s", search_name);
    
    struct Student found_student = search_student(student_records, size, search_name);
    
    if (strcmp(found_student.name, "") != 0) {
        printf("Aranan ögrenci bulundu: %s\n", found_student.name);
        printf("Yasi: %d\n", found_student.age);
        printf("Notu: %c\n", found_student.grade);
    } else {
        printf("Aranan ögrenci bulunamadi.\n");
    }
    
    return 0;
}

/*Listede aranan ögrenci adinin yer aldigi dügümden bir sonraki dügümü silen fonksiyonu
yaziniz.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

void delete_next_node(struct Node* node, const char* search_name) {
    struct Node* temp;
    
    while (node != NULL && node->next != NULL) {
        if (strcmp(node->name, search_name) == 0) {
            temp = node->next;
            node->next = temp->next;
            free(temp);
            return;
        }
        node = node->next;
    }
}

void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%s ", node->name);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    strcpy(head->name, "Ali");
    strcpy(second->name, "Ayse");
    strcpy(third->name, "Mehmet");
    
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    printf("Liste: ");
    print_list(head);
    
    const char* search_name = "Ayse";
    delete_next_node(head, search_name);
    
    printf("Liste (sonraki dügüm silindi): ");
    print_list(head);
    
    return 0;
}

/*Listede en uzun ismin oldugu kaydi yazdiran fonksiyonu yaziniz.
Cikti : listedeki en uzun isim : Abdurrahmangazi
Uzunluk : 15 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

void find_longest_name(struct Node* node) {
    char longest_name[50];
    int max_length = 0;
    
    while (node != NULL) {
        int current_length = strlen(node->name);
        if (current_length > max_length) {
            max_length = current_length;
            strcpy(longest_name, node->name);
        }
        node = node->next;
    }
    
    printf("Listedeki en uzun isim: %s\n", longest_name);
    printf("Uzunluk: %d\n", max_length);
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    strcpy(head->name, "Ali");
    strcpy(second->name, "Ayse");
    strcpy(third->name, "Abdurrahmangazi");
    
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    find_longest_name(head);
    
    return 0;
}




