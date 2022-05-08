#include<stdio.h>
#include <stdlib.h>
#include<string.h>

//func prototypes
void start();
void createacc();
void login();
void mainmenu();

void contactlist();
void addcontact();
void searchcontact();
void deletecontact();
void editcontact();
void deleteall();

//struct
struct user{
    char username[100];
    char password[100];
};
struct contact{
    char name[50];
    long int contact_no;
    char address[100];
    char mail[100];
};

int main()
{
    start();

    return 0;
}


//2 verification
void start(){
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  WELCOME TO YOUR PHONEBOOK                   *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) Login\n\t\t\t2) Create Account\n\t\t\t3) Exit\n\n");
    int n;
    printf("\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n){
    case 1: login();break;
    case 2: createacc();break;
    case 3: return;
    default: printf("\t\tInvalid Input\n");break;
    }
}
//3 new account creation
void createacc(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  CREATE A NEW ACCOUNT                         *\n");
    printf("\t\t****************************************************************\n\n");
    struct user u;
    printf("\t\t\tEnter username: ");
    scanf("%s",u.username);
    printf("\t\t\tEnter pass: ");
    scanf("%s",u.password);
    FILE *signup;
    signup=fopen("login.txt","w");
    fprintf(signup,"%s %s",u.username,u.password);
    fclose(signup);
    printf("\n\t\tAccount created succesfully\n\n");
    printf("\t\t\t1) Login\n\t\t\t2) Exit\n\n");
    int n;
    printf("\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n){
    case 1: login();break;
    case 2: return;
    default: printf("\t\tInvalid Input\n");break;
    }
}
//3 login page
void login(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                         LOGIN                                *\n");
    printf("\t\t****************************************************************\n\n");
    char user[100],pass[100];
    printf("\t\t\tEnter login credentials: \n\n");
    printf("\t\t\tusername: ");
    scanf("%s",user);
    printf("\t\t\tpassword: ");
    scanf("%s",pass);

    struct user u;
    FILE *signin;
    signin=fopen("login.txt","r");
    fscanf(signin,"%s %s",u.username,u.password);

    if(strcmp(u.username,user)==0&&strcmp(u.password,pass)==0){
        printf("\t\tSuccessful login. Press any key to continue\n\n");
        getchar();
        mainmenu();
    }
    else{
        printf("\n\t\tIncorrect Username or Password :( \n\n");
        printf("\t\t\t1) Try again\n\t\t\t2) Exit\n");
        int n;
        printf("\t\tEnter your choice: ");
        scanf("%d",&n);
        switch(n){
        case 1: login();break;
        case 2: return;
        default: printf("\t\tInvalid Input\n");break;
        }
    }
}
//4 mainmenu
void mainmenu(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                       MAIN MENU                              *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) Contact List\n\n");
    printf("\t\t\t2) Add contact\n\n");
    printf("\t\t\t3) Search contact Details\n\n");
    printf("\t\t\t4) Delete contact\n\n");
    printf("\t\t\t5) Edit contact\n\n");
    printf("\t\t\t6) Delete All\n\n");
    printf("\t\t\t7) Exit \n\n\n");

    int n;
    printf("\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n){
    case 1: contactlist();break;
    case 2: addcontact();break;
    case 3: searchcontact();break;
    case 4: deletecontact();break;
    case 5: editcontact();break;
    case 6: deleteall();break;
    case 7: return;
    default: printf("\t\tInvalid Input\n");break;
    }
}


void contactlist(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                      CONTACT LIST                            *\n");
    printf("\t\t****************************************************************\n\n");
    struct contact c;
    FILE *fp;
    fp=fopen("contact.txt","r");
    fscanf(fp,"%s %ld %s %s",c.name,&c.contact_no,c.address,c.mail);
    printf("\t\t\t%s %ld %s %s\n",c.name,c.contact_no,c.address,c.mail);

    printf("\n\n\n\t\t\t1) add another contact\n\t\t\t2) Return to mainmenu\n\t\t\t3) exit\n");
    int n;
    printf("\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n){
        case 1: addcontact();break;
        case 2: mainmenu();
        case 3: return;
        default: printf("\t\tInvalid Input\n");break;
    }

}
void addcontact(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                    ADD NEW CONTACT                           *\n");
    printf("\t\t****************************************************************\n\n");

    struct contact c;

    printf("\t\t\tEnter name : ");
    scanf("%s",c.name);
    printf("\t\t\tEnter mobile no : ");
    scanf("%ld",&c.contact_no);
    printf("\t\t\tEnter Address: ");
    scanf("%s",c.address);
    printf("\t\t\tEnter email : ");
    scanf("%s",&c.mail);

    FILE *fp;
    fp=fopen("contact.txt","a");
    fprintf(fp,"%s %ld %s %s\n",c.name,c.contact_no,c.address,c.mail);
    printf("\n\t\tContact added succesfully\n\n");

    printf("\t\t\t1) add another contact\n\t\t\t2) Return to mainmenu\n\t\t\t3) exit\n\n\n");
    int n;
    printf("\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n){
        case 1: addcontact();break;
        case 2: mainmenu();
        case 3: return;
        default: printf("\t\tInvalid Input\n");break;
    }
}
void searchcontact(){

}
void deletecontact(){

}
void editcontact(){

}
void deleteall(){

}


