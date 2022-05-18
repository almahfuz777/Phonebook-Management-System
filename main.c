#include<stdio.h>
#include <stdlib.h>
#include<string.h>

//func prototypes
void start();           // landing page
void createacc();       // creates an account
void filecheck();       // checks file for user info
void login();           // matches the user input with the existing info for login
void mainmenu();        // a list of choices for the use of phonebook
void contactlist();     // displays the list of contacts
void addcontact();      // adds a new contact to the list
void searchcontact();   // searches any particular contact by name or phone number
void deletecontact();   // deletes a single contact
void editcontact();     // edits information of any contact
void deleteall();       // deletes all the data of the phonebook
void changepass();      // changes login password

//structure for login details
struct user{
    char username[100];
    char password[100];
};
//structure for contact details
struct contact{
    char name[50];
    long int contact_no;
    char address[100];
    char mail[100];
};

int main()
{
    system("color 3f");
    start();

    return 0;
}


// landing page
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
    case 2: filecheck();break;
    case 3: return;
    default: printf("\t\tInvalid Input\n");break;
    }
}
//filecheck
void filecheck(){
    FILE *check;
    check=fopen("login.txt","r");
    if(check==NULL)createacc();
    else{
        fseek(check,0,SEEK_END); //checking for existing account
        long size=ftell(check);
        if(size==0)createacc();
        else{
        printf("\n\t\tAccount already exists. Do you want to overwrite?\n");
        printf("\t\t!>Previous data will be lost<!\n\n");
        printf("\t\t\t1) YES, overwrite\n\t\t\t2) Login to my acc\n\t\t\t3) Exit\n\n");
        int select;
        printf("\t\tEnter your choice: ");
        scanf("%d",&select);

        switch(select){
            case 1: createacc();break;
            case 2: login();break;
            case 3: return;
            default: printf("\t\t>Invalid Input\n");
        }
        }
    }
    fclose(check);
}
// new account creation
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
    fclose(signup);
}
//3 login page
void login(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                         LOGIN                                *\n");
    printf("\t\t****************************************************************\n\n");
    
    struct user u;
    FILE *signin;
    signin=fopen("login.txt","r");
    //checking for the file existence
    if(signin==NULL){
        printf("\t\tNo existing account found.\n\n");
        printf("\t\t\t1) Create an account\n\t\t\t2) Exit\n\n");
        printf("\t\tEnter Your Choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: createacc();break;
            case 2: return;
            default: printf("\t\tInvalid Input\n");break;
        }
    }
    //checking whether the file is empty
    else {
        fseek(signin,0,SEEK_END);
        long size=ftell(signin);
        if(size==0){
            printf("\t\tNo existing account found.\n\n");
            printf("\t\t\t1) Create an account\n\t\t\t2) Exit\n\n");
            printf("\t\tEnter Your Choice: ");
            int choice;
            scanf("%d",&choice);
            switch(choice){
            case 1: createacc();break;
            case 2: return;
            default: printf("\t\tInvalid Input\n");break;
            }
        }
        //taking login info from user if the file is not empty
        else
        {
        fseek(signin,0,SEEK_SET); //back to the begin of the file
        
        char user[100],pass[100];
        printf("\t\t\tEnter login credentials: \n\n");
        printf("\t\t\tusername: ");
        scanf("%s",user);
        printf("\t\t\tpassword: ");
        scanf("%s",pass);

        //matching the user input with the existing values in the file
        fscanf(signin,"%s %s",u.username,u.password);

        if(strcmp(u.username,user)==0&&strcmp(u.password,pass)==0){
            printf("\t\tSuccessful login. Press any key to continue\n\n");
            getchar(); //>not working..need to be fixed<//
            mainmenu();
        }
        //if the input doesnt match
        else{
            printf("\n\t\t>Incorrect Username or Password :( \n");
            printf("\t\t\t1) Try again\n\t\t\t2) Exit\n\n");
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

    }
    fclose(signin);
}
// mainmenu
void mainmenu(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                       MAIN MENU                              *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) Contact List\n\n");
    printf("\t\t\t2) Add contact\n\n");
    printf("\t\t\t3) Search for a contact\n\n");
    printf("\t\t\t4) Edit contact\n\n");
    printf("\t\t\t5) Delete a contact\n\n");
    printf("\t\t\t6) Delete All\n\n");
    printf("\t\t\t7) Change password\n\n");
    printf("\t\t\t8) Exit \n\n\n");

    int n;
    printf("\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n){
    case 1: contactlist();break;
    case 2: addcontact();break;
    case 3: searchcontact();break;
    case 4: editcontact();break;
    case 5: deletecontact();break;
    case 6: deleteall();break;
    case 7: changepass();break;
    case 8: return;
    default: printf("\t\tInvalid Input\n");break;
    }
}


void contactlist(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                      CONTACT LIST                            *\n");
    printf("\t\t****************************************************************\n\n");
    
    struct contact c[100];
    FILE *fp;
    fp=fopen("contact.txt","r");

    //checking for the file existence
    if(fp==NULL){
        printf("\t\tNo contact found.\n\n");
        printf("\t\t\t1) Create new contact\n\t\t\t2) Mainmenu\n\t\t\t3) Exit\n\n");
        printf("\t\tEnter Your Choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: addcontact();break;
            case 2: mainmenu();break;
            case 3: return;
            default: printf("\t\tInvalid Input\n");break;
        }
    }
    else{
        fseek(fp,0,SEEK_END);
        long size=ftell(fp);
        if(size==0){ 
           printf("\t\tNo contact found.\n\n");
            printf("\t\t\t1) Create new contact\n\t\t\t2) Mainmenu\n\t\t\t3) Exit\n\n");
            printf("\t\tEnter Your Choice: ");
            int choice;
            scanf("%d",&choice);
            switch(choice){
            case 1: addcontact();break;
            case 2: mainmenu();break;
            case 3: return;
            default: printf("\t\tInvalid Input\n");break;
            }
        }
        //taking login info from user
        else{
            fseek(fp,0,SEEK_SET); //back to the begin of the file
            int i,count; //total number of contacts
            fscanf(fp,"%d",&count);
            for(i=0;i<count;i++)
            fscanf(fp,"%s %ld %s %s",c[i].name,&c[i].contact_no,c[i].address,c[i].mail);
            printf("\t\t%-10s %-15s %-15s %-15s\n\n","NAME","CONTACT NO","ADDRESS","E-MAIL");
            for(i=0;i<count;i++)
            printf("\t\t%-10s %011ld     %-15s %-15s\n",c[i].name,c[i].contact_no,c[i].address,c[i].mail);

            printf("\n\n\n\t\t\t1) add another contact\n\t\t\t2) Return to mainmenu\n\t\t\t3) exit\n\n");
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
        fclose(fp);
    }
}
void addcontact(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                    ADD NEW CONTACT                           *\n");
    printf("\t\t****************************************************************\n\n");

    struct contact c[100];
    FILE *fr;
    fr=fopen("contact.txt","r");

    int i,count=0; 
    fscanf(fr,"%d",&count);
    for(i=0;i<count&&count>0;i++)
    fscanf(fr,"%s %ld %s %s",c[i].name,&c[i].contact_no,c[i].address,c[i].mail);

    printf("\t\t\tEnter name : ");
    scanf("%s",c[count].name);
    printf("\t\t\tEnter mobile no : +880");
    scanf("%ld",&c[count].contact_no);
    printf("\t\t\tEnter Address: ");
    scanf("%s",c[count].address);
    printf("\t\t\tEnter email : ");
    scanf("%s",c[count].mail);
    count++;

    FILE *fp;
    fp=fopen("contact.txt","w");
    fprintf(fp,"%d\n",count);
    for(i=0;i<count;i++)
    fprintf(fp,"%s %011ld %s %s\n",c[i].name,c[i].contact_no,c[i].address,c[i].mail);
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
    fclose(fr);
    fclose(fp);
}
void searchcontact(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                    SEARCH A CONTACT                          *\n");
    printf("\t\t****************************************************************\n\n");
    struct contact c[100];
    char nm[50];
    FILE *fr;
    fr=fopen("contact.txt","r");
    int i,count,flag=0;
    long int num;
    fscanf(fr,"%d",&count);
    for(i=0;i<count&&count>0;i++)
    fscanf(fr,"%s %ld %s %s",c[i].name,&c[i].contact_no,c[i].address,c[i].mail);


    printf("\n\t\t\t1) Search by Name\n\t\t\t2) Search by Phone no.\n\t\t\t3) exit\n\n\n");
    int choice;
    printf("\t\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: 
            printf("\t\tEnter the name you want to search: ");
            scanf("%s",nm);
            for(i=0;i<count;i++){
                if(strcmp(c[i].name,nm)==0){ //comparing the name 
                    flag=1;break;
                }
            }
            if(flag==1){
                printf("\n\t\t\tName: %s\n\t\t\tPhone No: %011ld\n\t\t\tAddress: %s\n\t\t\tMail: %s\n",c[i].name,c[i].contact_no,c[i].address,c[i].mail);

                printf("\n\n\t\t1) search another contact\n\t\t2) Return to mainmenu\n\t\t3) exit\n\n");
                printf("\t\tEnter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                case 1: searchcontact();break;
                case 2: mainmenu();
                case 3: return;
                default: printf("\t\tInvalid Input\n");break;
                }
            }
            else{
                printf("\n\n\t\tContact Not Found\n\n");
                printf("\t\t\t1) Search Again\n\t\t\t2) Return to Mainmenu\n\t\t\t3) Exit\n\n");
                int x;
                printf("\t\tEnter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                case 1: searchcontact();break;
                case 2: mainmenu(); break;
                case 3: return;
                default: printf("\t\tInvalid Input\n");break;
                }
            }
            break;
            
        case 2:
            flag=0; 
            printf("\t\tEnter the number you want to search: ");
            scanf("%ld",&num);
            for(i=0;i<count;i++){
                if(c[i].contact_no==num){
                    flag=1;break;
                }
            }
            if(flag==1){
                printf("\n\t\t\tName: %s\n\t\t\tPhone No: %011ld\n\t\t\tAddress: %s\n\t\t\tMail: %s\n",c[i].name,c[i].contact_no,c[i].address,c[i].mail);

                printf("\n\n\t\t1) search another contact\n\t\t2) Return to mainmenu\n\t\t3) exit\n\n");
                printf("\t\tEnter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                case 1: searchcontact();break;
                case 2: mainmenu();
                case 3: return;
                default: printf("\t\tInvalid Input\n");break;
                }

            }
            else{
                printf("\n\n\t\tContact Not Found\n\n");
                printf("\t\t\t1) Try again\n\t\t\t2) Return to Mainmenu\n\t\t\t3) Exit\n\n");
                printf("\t\tEnter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                case 1: searchcontact();break;
                case 2: mainmenu(); break;
                case 3: return;
                default: printf("\t\tInvalid Input\n");break;
                }
            }
            break;

        case 3: return;
        default: printf("\t\tInvalid Input\n");searchcontact();break;
    }
    
    fclose(fr);
    
}
void deletecontact(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                    DELETE A CONTACT                          *\n");
    printf("\t\t****************************************************************\n\n");
    struct contact c[100];
    char nm[50];
    FILE *fr;
    fr=fopen("contact.txt","r");
    int i,count,flag=0;
    fscanf(fr,"%d",&count);
    for(i=0;i<count&&count>0;i++)
    fscanf(fr,"%s %ld %s %s",c[i].name,&c[i].contact_no,c[i].address,c[i].mail);
    
    printf("\t\tEnter the name you want to delete: ");
    scanf("%s",nm);
    for(i=0;i<count;i++){
        if(strcmp(c[i].name,nm)==0){
            flag=1;break;
        }
    }
    //if the contact is found
    if(flag==1){ 
        printf("\n\t\t\tName: %s\n\t\t\tPhone No: %011ld\n\t\t\tAddress: %s\n\t\t\tMail: %s\n",c[i].name,c[i].contact_no,c[i].address,c[i].mail);
        printf("\n\t\tAre you sure want to delete this contact?\n\t\t\t1) YES\n\t\t\t2) NO\n");
        printf("\t\tEnter your choice: ");
        int choice;
        scanf("%d",&choice);
        if(choice==1){
            FILE *fw;
            fw=fopen("contact.txt","w");
            fprintf(fw,"%d\n",count-1);
            for(int j=0;j<count;j++){
                if(j!=i)
                fprintf(fw,"%s %011ld %s %s\n",c[j].name,c[j].contact_no,c[j].address,c[j].mail);
            }
            fclose(fw);
            printf("\n\t\tContact deleted successfully\n");

            printf("\n\t\t\t1) Delete Another Contact\n\t\t\t2) Return to Mainmenu\n\t\t\t3) Exit\n\n\n");
            int choice;
            printf("\t\tEnter your choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 1: deletecontact();break;
                case 2: mainmenu();break;
                case 3: return;
            }
        }
        else mainmenu();
    }
    //if the contact is not found
    else{
        printf("\n\t\tContact Not Found\n\n");
        printf("\t\t\t1) Try Again\n\t\t\t2) Mainmenu\n\t\t\t3) Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: deletecontact();break;
            case 2: mainmenu();break;
            case 3: return;
            default: printf("\n\t\tInvalid Input\n");
        }
    }        
    fclose(fr);
}
void editcontact(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                    EDIT A CONTACT                            *\n");
    printf("\t\t****************************************************************\n\n");
    struct contact c[100];
    char nm[50];
    FILE *fr;
    fr=fopen("contact.txt","r");
    int i,count,flag=0;
    fscanf(fr,"%d",&count);
    for(i=0;i<count&&count>0;i++)
    fscanf(fr,"%s %ld %s %s",c[i].name,&c[i].contact_no,c[i].address,c[i].mail);
    
    printf("\t\tEnter the name you want to edit: ");
    scanf("%s",nm);
    for(i=0;i<count;i++){
        if(strcmp(c[i].name,nm)==0){
            flag=1;break;
        }
    }
    if(flag==1){
        printf("\n\t\t\tName: %s\n\t\t\tPhone No: %011ld\n\t\t\tAddress: %s\n\t\t\tMail: %s\n\n",c[i].name,c[i].contact_no,c[i].address,c[i].mail);
        printf("\t\tEnter updated information about %s\n",nm);
        printf("\t\t\tEnter mobile no : +880");
        scanf("%ld",&c[i].contact_no);
        printf("\t\t\tEnter Address: ");
        scanf("%s",c[i].address);
        printf("\t\t\tEnter email : ");
        scanf("%s",&c[i].mail);

        FILE *fw;
        fw=fopen("contact.txt","w");
        fprintf(fw,"%d\n",count);
        for(int j=0;j<count;j++)
            fprintf(fw,"%s %011ld %s %s\n",c[j].name,c[j].contact_no,c[j].address,c[j].mail);
        fclose(fw);
        printf("\n\t\tInformation Updated Successfully\n");

        printf("\n\t\t\t1) Edit another contact\n\t\t\t2) Return to Mainmenu\n\t\t\t3) Exit\n\n\n");
        int choice;
        printf("\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: editcontact();break;
        case 2: mainmenu();break;
        case 3: return;
        }
    }
    else{
        printf("\n\t\tContact Not Found\n");
        printf("\n\n\t\t\t1) Try Again\n\t\t\t2) Return to Mainmenu\n\t\t\t3) Exit\n\n\n");
        int choice;
        printf("\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: editcontact();break;
        case 2: mainmenu();break;
        case 3: return;
        }
    }
    fclose(fr);  
}
//erase all files
void deleteall(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                    ERASE EVERYTHING                          *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\n\t\tAre you sure want to erase everything?\n\t\t\t1) YES\n\t\t\t2) NO");
    int select;
    printf("\t\tEnter your choice: ");
    scanf("%d",&select);
    switch(select){
    case 1: 
        remove("login.txt"); //doesnt work. dont know why
        remove("contact.txt");
        printf("\t\tAll data in the phonebook deleted successfully\n\n");
        start();
        break;
    default: mainmenu();break;
    }
}
void changepass(){
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                     CHANGE PASSWORD                          *\n");
    printf("\t\t****************************************************************\n\n");
    char un[50],pass[50],oldpass[50],newpass[50];
    FILE *fp;
    fp=fopen("login.txt","r");
    fscanf(fp,"%s%s",un,pass);
    fclose(fp);
    printf("\t\tEnter old password: ");
    scanf("%s",oldpass);
    printf("\t\tEnter new password: ");
    scanf("%s",newpass);
    if(strcmp(oldpass,pass)==0){
        FILE *fw;
        fw=fopen("login.txt","w");
        fprintf(fw,"%s %s",un,newpass);
        fclose(fw);
        printf("\n\n\t\tPassword Changed Successfully");
        printf("\n\n\t\t\t1) Return to Mainmenu\n\t\t\t3) Exit\n\n");
        int choice;
        printf("\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: mainmenu();break;
        case 2: return;
        default: printf("\n\t\tInvalid input\n");break;
        }
    }
    else{
        printf("\n\n\t\tIncorrect old Password");
        printf("\n\n\t\t\t1) Try Again\n\t\t\t2) Return to Mainmenu\n\t\t\t3) Exit\n\n\n");
        int choice;
        printf("\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: changepass();break;
        case 2: mainmenu();break;
        case 3: return;
        }
    }
}