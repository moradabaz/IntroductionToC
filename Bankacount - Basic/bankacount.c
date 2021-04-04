#include <stdio.h>
#include <string.h>

typedef struct User
{
    char name[50];
    int age;
    float money;
}User;

User create_user(char * name, int age, int money) {
    User user;
    strcpy(user.name, name);
    user.age = age;
    user.money = money;
    return user;
}

void print_options() {
    printf("Press the Key\n");
    printf("[1] - Insert money\n");
    printf("[2] - Draw money\n");
    printf("[3] - Show information\n");
    printf("[4] - Exit\n");
}

float insert_money(User user) {
    float money;
    printf("How much money do you want to insert?\n");
    scanf("%f", &money);
    return money;
}

float draw_money(User user) {
    float money;
    printf("How much money do you want to draw?\n");
    scanf("%f", &money);
    while (money > user.money) {
        printf("Sorry, but you don't have enough balance to draw that amount\n");
        scanf("%f", &money);
    }
    return money;
}

void show_information(User user) {
    printf("Your information\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Current Savings: %f\n", user.money);
}



int main() {

    char name[50];
    int age;
    float savings;

    printf("WELCOME TO YOUR BANK\n");
    printf("Please, Insert your name\n");
    scanf("%s", name);
    printf("Please, Insert you age\n");
    scanf("%d", &age);
    printf("Please, Insert your savings\n");
    scanf("%f", &savings);

    User user = create_user(name, age, savings);

    int option = 5;
    float money;
    do {
        print_options();
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                money = insert_money(user);
                user.money += money;
                printf("Transaction executed successfully\n");
                break;
            case 2:
                money = draw_money(user);
                user.money -= money;
                printf("Transaction executed successfully\n");
                break;
            case 3:
                show_information(user);
                break;
            default:
                option = 6;
                break;
        }
    } while(option > 0 && option < 4);
    return 0;
}