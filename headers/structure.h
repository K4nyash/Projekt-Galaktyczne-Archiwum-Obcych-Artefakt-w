struct Node{
    char name[100];
    char origin[30];
    char creatorCiv[50];
    int dangerLevel;
    int discoveryYear;
    char status[30];
    struct Node *next;
};
struct Node* CreateNode(char name[100], char origin[100], char creatorCiv[100], int dangerLevel, int discoveryYear, char status[100]);
void Insert(struct Node** head);
void InsertData(struct Node** head, char name[], char origin[], char creatorCiv[], int dangerLevel, int discoveryYear, char status[]);
void DeleteFromFirst(struct Node** head);
void Delete(struct Node** head);
void Update(struct Node** head);
void Print(struct Node* head);