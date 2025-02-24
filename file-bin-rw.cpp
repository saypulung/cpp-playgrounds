/*
In this file, writen how to convert binary to the struct file
Most of the other programming language have complex flow to do this

We have struct Person have property for example id with unsigned int (4 bytes)
If we convert to this struct by hex value [0x0b 0x00 0x00 0x00........another_hex_values_until_166bytes....]
Then the ID will be have value "11" in integer

You can see the output of data.bin by Pilot Edit lite, then click menu bar Edit and select HEX mode.
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

enum {
    SUCCESS,
    FAIL_OPEN_FILE,
    FILE_NOT_EXISTS,
    QUIT_BY_USER
};

typedef struct {
    unsigned int id;	// 4 bytes
    char name[100];		// 100 bytes
    char nick[50];		// 50 bytes
    unsigned int dob;	// 4 bytes
    unsigned int mob;	// 4 bytes
    unsigned int yob;	// 4 bytes
    // ----------------- 166 bytes
} Person;


void printOptions()
{
    cout<<"==================== Select feature ===================="<<endl;
    cout<<"1) Write Data"<<endl;
    cout<<"2) Read Data"<<endl;
    cout<<"3) Quit"<<endl;
    cout<<"========================================================"<<endl;
}

char option = 'Y';

void readData()
{
    FILE* file = fopen("data.bin", "rb");

    // check if the file was successfully opened
    if (file == NULL) {
        cerr<<"Failed to open file";
        exit(FAIL_OPEN_FILE);
    }

    Person p;

    // Read the structs present in the file
    while (fread(&p, sizeof(Person), 1, file)
           == 1) {
        // Process the read data (e.g., print or manipulate)
        cout<<"ID : "<<p.id<<endl;
        cout<<"Name : "<<p.name<<endl;
        cout<<"Nick : "<<p.nick<<endl;
        cout<<"DoB : "<<p.dob<<endl;
        cout<<"MoB : "<<p.mob<<endl;
        cout<<"YoB : "<<p.yob<<endl;
    }
    // close the file
    fclose(file);
}

void writeData()
{
    Person p;
    cout<<"Type person ID: ";
    cin>>p.id;
    cout<<"Type person Name: ";
    cin>>p.name;
    cout<<"Type person Nick: ";
    cin>>p.nick;
    cout<<"Type person Date birthday (1-31): ";
    cin>>p.dob;
    cout<<"Type person Month birthday (1-12): ";
    cin>>p.mob;
    cout<<"Type person Year birthday: ";
    cin>>p.yob;
    FILE* outfile;
    outfile = fopen("data.bin", "wb");
    if (outfile == NULL) {
        cout<<"Fail to open file";
        exit(FAIL_OPEN_FILE);
    }

    int flag = 0;
    flag = fwrite(&p, sizeof(Person), 1,
                  outfile);
    if (flag) {
        cout<<"Contents of the structure written "
               "successfully";
    }
    else
        cout<<"Error Writing to File!";
    fclose(outfile);
}


int main()
{
    char action = 'y';

    do {
        system("cls");
        printOptions();
        cout<<"Type action: ";
        cin>>action;
        switch (action) {
        case '1':
            system("cls");
            cout<<"Write data"<<endl;
            writeData();
            break;
        case '2':
            system("cls");
            cout<<"Read data"<<endl;
            readData();
            break;
        default:
            break;
        }
        cout<<"------------------------------------------------"<<endl;
        cout<<"Lanjut? ";
        cin>>option;
    } while (option == 'Y' || option == 'y');

    return SUCCESS;
}
