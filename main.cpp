#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
using namespace std;
int num_of_user=0;
int num_of_writer=0;
int num_library_book=0;
string user_pass;
string user_username;
string user_name;
void second_page();
void menu_item();
void menu_Choice();
struct pages{
    int NumberOfPage;
    string words;
};
struct books{
    string NameOfBook;
    string NameOfWriter;
    string publisher;
    string ISBN;
    int year;
    int NumOfPage;
    pages page[100];
    string status = "Not borrowed";
};
struct writers{
    string NameOfWriter;
    string ID;
    books book[100];
    int NumOfBook=0;
}writer[100];
struct library{
    books book[100];
}Library[100];
struct members{
    string Name;
    string User;
    string pass;
}member[500];
void header2() {
    cout << "-------------------------------------------------------------------" << endl;
}
void header(){
    cout << "===================================================================" << endl ;
}

//________________________________________________FIRST-PAGE____________________________________________________________

void welcome() {
    //system("color 4");
    cout << char(186) << "                    WELCOME TO OUR LIBRARY                       " << char(186) << endl;
}

void type_of_login() {
    system("color 3");
    cout  << char(124) << "                   What do you want to do ?:>>                   " << char(124) << endl
          << char(124) << "                                                                 " << char(124) << endl;
    cout  << char(124) << "    1" << char(17) << " add a new account                                         " << char(124) << endl
          << char(124) << "    2" << char(17) << " connect an existing account                               " << char(124) << endl;
    //red();
    cout  << char(124) << "    3" << char(17) << " EXIT                                                      " << char(124) << endl;
}

void pass_new() {
    cout << char(43) << " Enter a password. It should contain one number , one of a-z and one of A-Z. " << endl;
    string password;
    cin >> password;
    bool contain_num = false, contain_word = false, contain_WORD = false;
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= '0' && password[i] <= '9')
            contain_num = true;
        if (password[i] >= 'a' && password[i] <= 'z')
            contain_word = true;
        if (password[i] >= 'A' && password[i] <= 'Z')
            contain_WORD = true;
    }
    if (contain_num == true && contain_word == true && contain_WORD == true) {
        cout << "Enjoy Reading:) We glad to find you as a new friend. " << char(03) << endl;
        member[num_of_user - 1].pass = password;
        user_pass = password;        //we need it in global version
    } else {
        cout << "EROR! TRY AGAIN..." << endl;
        pass_new();
    }
}

void login() {
    cout << "Please enter your username." << endl;
    string username;
    cin >> username;
    user_username = username;          //we need it in global version
    cout << "Please enter your password." << endl;
    string password;
    cin >> password;
    user_pass = password;                  //we need it in global version
    bool find = false;
    int index_name;
    for (int i = 0; i < num_of_user; i++) {
        if (member[i].User == username) {
            if (member[i].pass == password) {
                find = true;
                index_name=i;
            }
        }
    }
    user_name = member[index_name].Name;     //we need it in global version
    if (find == true)
        menu_item();
    else {
        cout << "TRY AGAIN...! ";
        login();
    }
}

void get_information() {
    //system("cls");
    int type_of;
    cin >> type_of;
    if (type_of == 1) {
        cout << char(43) << " What is your name?:> " << endl;
        string full_name;
        cin.ignore();
        getline(cin, full_name);
        user_name = full_name;                    //we need it in global version
        cout << char(43) << " Please enter your username. We will know you by that. " << endl;
        string username;
        cin >> username;
        user_username = username;                //we need it in global version
        num_of_user++;
        pass_new();
        member[num_of_user - 1].Name = full_name;
        member[num_of_user - 1].User = username;
    } else if (type_of == 2) {
        login();
    } else if (type_of == 3) {
        exit(0);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void first_page() {
    header();
    welcome();
    header();
    cout << char(179) << "                                                                 " << char(179) << endl;
    type_of_login();
    cout << char(179) << "                                                                 " << char(179) << endl;
    header2();
    get_information();
    second_page();
}

//____________________________________________________SECOND-PAGE_______________________________________________________

void second_page() {

    header();
    cout << char(124) << "                                                                 " << char(124) << endl;
    cout << char(124) << "                           Now you can :                         " << char(124) << endl
         << char(124) << "                                                                 " << char(124) << endl;
    cout << char(124) << "    1" << char(17) << " back to first page                                        " << char(124) << endl
         << char(124) << "    2" << char(17) << " go to the library menu                                    " << char(124) << endl
         << char(124) << "    3" << char(17) << " EXIT                                                      " << char(124) << endl;
    cout << char(124) << "                                                                 " << char(124) << endl;
    header2();

    int secondchice;
    cin >> secondchice;
    switch (secondchice) {
        case 1:
            first_page();
            break;
        case 2:
            menu_item();
            break;
        case 3:
            exit(0);
            break;
        default:
            second_page();
            break;
    }
}

//____________________________________________________MENU-LIBRARY______________________________________________________

void menu_item(){
    system("color 4");

    cout << char(15) << "-----------------------------------------------------------------" << char(15) << endl;
    cout << char(124) <<"                    What do you want to do ?:>>                   " << char(124) << endl ;
    cout << char(124) <<"                                                                  " << char(124) << endl;
    cout << char(124) <<"     1" << char(17) << " add a new writer                                          " << char(124) << endl
         << char(124) <<"     2" << char(17) << " add book to an existing writer                            " << char(124) << endl
         << char(124) <<"     3" << char(17) << " remove book from an existing writer                       " << char(124) << endl
         << char(124) <<"     4" << char(17) << " add book to the library                                   " << char(124) << endl
         << char(124) <<"     5" << char(17) << " remove book from the library                              " << char(124) << endl
         << char(124) <<"     6" << char(17) << " edit an existing writer's information                     " << char(124) << endl
         << char(124) <<"     7" << char(17) << " edit an existing book's information                       " << char(124) << endl
         << char(124) <<"     8" << char(17) << " show my account's information                             " << char(124) << endl
         << char(124) <<"     9" << char(17) << " show all books                                            " << char(124) << endl
         << char(124) <<"    10" << char(17) << " filter books by their name of writer                      " << char(124) << endl
         << char(124) <<"    11" << char(17) << " filter books by their year of print                       " << char(124) << endl
         << char(124) <<"    12" << char(17) << " filter books by their publisher                           " << char(124) << endl
         << char(124) <<"    13" << char(17) << " search and find book by their name                        " << char(124) << endl
         << char(124) <<"    14" << char(17) << " search and find book by their writer's name               " << char(124) << endl
         << char(124) <<"    15" << char(17) << " sort books by their year of print                         " << char(124) << endl
         << char(124) <<"    16" << char(17) << " search phrase in special book                             " << char(124) << endl
         << char(124) <<"    17" << char(17) << " print page that you want                                  " << char(124) << endl
         << char(124) <<"    18" << char(17) << " borrow books :>                                           " << char(124) << endl
         << char(124) <<"    19" << char(17) << " Exit                                                      " << char(124) << endl;
    cout << char(15) << "-----------------------------------------------------------------" << char(15) << endl;
    menu_Choice();
}

//----------------------------------------------------------------------------------------------------------------------

void add_new_writer(){              //get info and put them in right place (writer arr, lib arr)
    cout << " name: ";
    cin.ignore();
    getline(cin,writer[num_of_writer].NameOfWriter);
    cout << " ID: ";
    getline(cin,writer[num_of_writer].ID);

    //I should know the num of book for each writer cuz when I add book I need the index of last book

    cout << "How many books do you wanna add?  ";
    int num_book;
    cin >> num_book;
    cin.ignore();
    cout << endl << "please enter the information of each book :)" << endl;
    for (int i = 0  ; i < num_book ; i++){                //I get information of each book
        string book_name;
        cout << "-book name: ";
        getline(cin,book_name);
        writer[num_of_writer].book[i].NameOfBook = book_name;
        writer[num_of_writer].book[i].NameOfWriter = writer[num_of_writer].NameOfWriter;
        //**************************************************************************************************************
        Library->book[num_library_book+i].NameOfBook = book_name;
        Library->book[num_library_book+i].NameOfWriter = writer[num_of_writer].NameOfWriter;
        //**************************************************************************************************************
        cout << "-publisher: ";
        getline(cin,writer[num_of_writer].book[i].publisher);
        //**************************************************************************************************************
        Library->book[num_library_book+i].publisher = writer[num_of_writer].book[i].publisher;
        //**************************************************************************************************************
        cout << "-ISBN: ";
        getline(cin,writer[num_of_writer].book[i].ISBN);
        //**************************************************************************************************************
        Library->book[num_library_book+i].ISBN = writer[num_of_writer].book[i].ISBN;
        //**************************************************************************************************************
        cout << "-year: ";
        cin >> writer[num_of_writer].book[i].year ;
        cout << endl ;
        //**************************************************************************************************************
        Library->book[num_library_book+i].year = writer[num_of_writer].book[i].year;
        //**************************************************************************************************************
        cout << "How many page does it have? ";
        int num_of_page;
        cin >> num_of_page;
        writer[num_of_writer].book[i].NumOfPage=num_of_page;
        //**************************************************************************************************************
        Library->book[num_library_book+i].NumOfPage = num_of_page;
        //**************************************************************************************************************
        cin.ignore();
        for (int index=0;index<num_of_page;index++){                                //index+1=num_of_page=Number
            writer[num_of_writer].book[i].page[index].NumberOfPage = index+1;
            //**********************************************************************************************************
            Library->book[num_library_book+i].page[index].NumberOfPage = index+1;
            //**********************************************************************************************************
            string page_of_book;
            getline(cin,page_of_book);
            writer[num_of_writer].book[i].page[index].words = page_of_book;
            //**********************************************************************************************************
            Library->book[num_library_book+i].page[index].words = page_of_book;
            //**********************************************************************************************************
        }
    }

    writer[num_of_writer].NumOfBook = writer[num_of_writer].NumOfBook + num_book;
    //******************************************************************************************************************
    num_library_book = num_library_book + num_book;
    //******************************************************************************************************************
    num_of_writer++;

    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void add_book_to_writer(){
    cout << " Which writer? ";
    string writer_name;
    cin.ignore();
    getline(cin,writer_name);

    int index_writer;                                            //find the writer index
    for (int i=0;i< num_of_writer;i++){
        if (writer[i].NameOfWriter == writer_name){
            index_writer=i;
            break;
        }
    }
    //add new book to index writer of WRITER[] and book last index+1(or last num)
    cout << "-book name: ";
    getline(cin,writer[index_writer].book[writer[index_writer].NumOfBook].NameOfBook);
    writer[index_writer].book[writer[index_writer].NumOfBook].NameOfWriter = writer_name;
    //******************************************************************************************************************
    Library->book[num_library_book].NameOfBook = writer[index_writer].book[writer[index_writer].NumOfBook].NameOfBook ;
    Library->book[num_library_book].NameOfWriter = writer_name;
    //******************************************************************************************************************
    cout << "-publisher: ";
    getline(cin,writer[index_writer].book[writer[index_writer].NumOfBook].publisher);
    //******************************************************************************************************************
    Library->book[num_library_book].publisher = writer[index_writer].book[writer[index_writer].NumOfBook].publisher;
    //******************************************************************************************************************
    cout << "-ISBN: ";
    getline(cin,writer[index_writer].book[writer[index_writer].NumOfBook].ISBN);
    //******************************************************************************************************************
    Library->book[num_library_book].ISBN = writer[index_writer].book[writer[index_writer].NumOfBook].ISBN;
    //******************************************************************************************************************
    cout << "-year: ";
    cin >> writer[index_writer].book[writer[index_writer].NumOfBook].year;
    cout << endl;
    //******************************************************************************************************************
    Library->book[num_library_book].year = writer[index_writer].book[writer[index_writer].NumOfBook].year;
    //******************************************************************************************************************
    cout << "How many page does it have?";
    int num_of_page;
    cin >> num_of_page;
    writer[index_writer].book[writer[index_writer].NumOfBook].NumOfPage = num_of_page;
    //******************************************************************************************************************
    Library->book[num_library_book].NumOfPage = num_of_page;
    //******************************************************************************************************************
    cin.ignore();
    for (int index=0;index<num_of_page;index++){                                                                        //index+1=num_of_page
        writer[index_writer].book[writer[index_writer].NumOfBook].page[index].NumberOfPage = index+1;
        getline(cin,writer[index_writer].book[writer[index_writer].NumOfBook].page[index].words);
        //**************************************************************************************************************
        Library->book[num_library_book].page[index].NumberOfPage = index+1;
        Library->book[num_library_book].page[index].words = writer[index_writer].book[writer[index_writer].NumOfBook].page[index].words;
        //**************************************************************************************************************
    }

    writer[index_writer].NumOfBook = writer[index_writer].NumOfBook + 1;
    //******************************************************************************************************************
    num_library_book++;
    //******************************************************************************************************************
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void remove_book_from_writer(){
    string writer_name;
    cout << " Which writer do you wanna remove his/her book? ";
    cin.ignore();
    getline(cin,writer_name);
    //find index writer
    int index_writer;
    for (int i=0;i< num_of_writer;i++){
        if (writer[i].NameOfWriter == writer_name){
            index_writer=i;
            break;
        }
    }

    string book_name;
    cout << " Which book? ";
    getline(cin,book_name);
    //find index book
    int index_book;
    for (int i=0; i < writer[index_writer].NumOfBook ;i++){
        if (writer[index_writer].book[i].NameOfBook == book_name){
            index_book=i;
            break;
        }
    }
    //we need to put index i+1 in i (from index book to last one)
    for (int i= index_book ; i < writer[index_writer].NumOfBook ; i++ ){

        writer[index_writer].book[i].NameOfBook = writer[index_writer].book[i+1].NameOfBook;
        writer[index_writer].book[i].NameOfWriter = writer[index_writer].book[i+1].NameOfWriter;
        writer[index_writer].book[i].publisher = writer[index_writer].book[i+1].publisher;
        writer[index_writer].book[i].ISBN = writer[index_writer].book[i+1].ISBN;
        writer[index_writer].book[i].year = writer[index_writer].book[i+1].year;
        writer[index_writer].book[i].NumOfPage = writer[index_writer].book[i+1].NumOfPage;
        writer[index_writer].book[i].status = writer[index_writer].book[i+1].status;

        for (int j=0;j<writer[index_writer].book[index_book].NumOfPage;j++){
            writer[index_writer].book[i].page[j].NumberOfPage = writer[index_writer].book[i+1].page[j].NumberOfPage;
            writer[index_writer].book[i].page[j].words = writer[index_writer].book[i+1].page[j].words;
        }
    }
    writer[index_writer].NumOfBook--;

    //******************************************************************************************************************
    //find index book in library with its name
    int index_library;
    for (int i=0;i< num_library_book ;i++){
        if ( Library->book[i].NameOfBook == book_name){
            index_library=i;
            break;
        }
    }

    for (int i = index_library ; i < num_library_book; i++) {
        Library->book[i].NameOfBook = Library->book[i + 1].NameOfBook;
        Library->book[i].NameOfWriter = Library->book[i + 1].NameOfWriter;
        Library->book[i].publisher = Library->book[i + 1].publisher;
        Library->book[i].ISBN = Library->book[i + 1].ISBN;
        Library->book[i].year = Library->book[i + 1].year;
        Library->book[i].NumOfPage = Library->book[i + 1].NumOfPage;
        Library->book[i].status = Library->book[i + 1].status;
        for (int j = 0; j < Library->book[i].NumOfPage; j++) {
            Library->book[i].page[j].NumberOfPage = Library->book[i +1].page[j].NumberOfPage;
            Library->book[i].page[j].words = Library->book[i + 1].page[j].words;
        }
    }

    num_library_book--;
    //******************************************************************************************************************
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void add_to_library(){
    cout << " name: ";
    cin.ignore();
    getline(cin,Library->book[num_library_book].NameOfBook);
    cout << " writer: ";
    getline(cin,Library->book[num_library_book].NameOfWriter);
    string ID_writer;
    cout << " writer's ID: ";
    getline(cin,ID_writer);
    cout << "-publisher: ";
    getline(cin,Library->book[num_library_book].publisher);
    cout << "-ISBN: ";
    getline(cin,Library->book[num_library_book].ISBN);
    int book_year;
    cout << "-year: ";
    cin >> book_year;
    cout << endl;
    Library->book[num_library_book].year = book_year;

    cout << "How many page does it have?";
    int num_of_page;
    cin >> num_of_page;
    cin.ignore();
    Library->book[num_library_book].NumOfPage=num_of_page;
    for (int index=0; index < num_of_page ;index++){                                                                        //index+1=num_of_page
        string page_of_book;
        getline(cin,page_of_book);
        Library->book[num_library_book].page[index].words = page_of_book;
        Library->book[num_library_book].page[index].NumberOfPage = index+1;
    }

    //we should know we have this writer or not?
    bool find = false;
    for (int i=0 ; i<num_of_writer ; i++){
        if (writer[i].NameOfWriter == Library->book[num_library_book].NameOfWriter)
            find = true;
    }

    //if we have him or her:
    if (find==true) {
        //find the index of writer
        int index_writer;
        for (int i = 0; i < num_of_writer ; i++) {
            if (writer[i].NameOfWriter == Library->book[num_library_book].NameOfWriter) {
                index_writer = i;
                break;
            }
        }
        //book index is numbook cuz we are not ++ it yet
        writer[index_writer].book[writer[index_writer].NumOfBook].NameOfBook = Library->book[num_library_book].NameOfBook;                  //num_book-1=index
        writer[index_writer].book[writer[index_writer].NumOfBook].NameOfWriter = Library->book[num_library_book].NameOfWriter;
        writer[index_writer].book[writer[index_writer].NumOfBook].publisher = Library->book[num_library_book].publisher;
        writer[index_writer].book[writer[index_writer].NumOfBook].ISBN = Library->book[num_library_book].ISBN;
        writer[index_writer].book[writer[index_writer].NumOfBook].year = Library->book[num_library_book].year;
        writer[index_writer].book[writer[index_writer].NumOfBook].NumOfPage = Library->book[num_library_book].NumOfPage;

        for (int index=0;index<num_of_page;index++){                                                                    //index+1=num_of_page

            writer[index_writer].book[writer[index_writer].NumOfBook].page[index].NumberOfPage = Library->book[num_library_book].page[index].NumberOfPage;
            writer[index_writer].book[writer[index_writer].NumOfBook].page[index].words = Library->book[num_library_book].page[index].words;

        }
        //one book was add to this writer so num of writer's book++
        writer[index_writer].NumOfBook= writer[index_writer].NumOfBook +1 ;
    }
        // we don't have him/her
    else{
        //we should add it in writer arr so the index is num of them (we do not ++ yet)
        //book index is 0
        writer[num_of_writer].NameOfWriter = Library->book[num_library_book].NameOfWriter;
        writer[num_of_writer].ID = ID_writer;
        writer[num_of_writer].book[0].NameOfBook = Library->book[num_library_book].NameOfBook;
        writer[num_of_writer].book[0].NameOfWriter = Library->book[num_library_book].NameOfWriter;
        writer[num_of_writer].book[0].publisher = Library->book[num_library_book].publisher;
        writer[num_of_writer].book[0].ISBN = Library->book[num_library_book].ISBN;
        writer[num_of_writer].book[0].year = book_year;
        writer[num_of_writer].book[0].NumOfPage = num_of_page;
        for (int index=0;index<num_of_page;index++){                                                                        //index+1=num_of_page

            writer[num_of_writer].book[0].page[index].NumberOfPage = Library->book[num_library_book].page[index].NumberOfPage;
            writer[num_of_writer].book[0].page[index].words = Library->book[num_library_book].page[index].words;

        }
        num_of_writer++;
        writer[num_of_writer].NumOfBook++;
    }

    num_library_book++;
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void show_my_info(){      //I have global string for info when you log in
    cout << endl << "-------------------------------------------" << endl;
    cout << "-YOUR NAME: " << user_name << endl;
    cout << "-YOUR USERNAME: " << user_username << endl;
    cout << "-YOUR PASSWORD: " << user_pass << endl;
    cout << "-YOUR BOOK: " << endl << endl;
    for (int i=0 ; i < num_library_book ; i++){
        if ( Library->book[i].status == user_username) {
            cout << "*******************************" << endl;
            cout << "-Book Name: " << Library->book[i].NameOfBook << endl;
            cout << "-Writer Name: " << Library->book[i].NameOfWriter << endl;
            cout << "-Publisher: " << Library->book[i].publisher << endl;
            cout << "-ISBN: " << Library->book[i].ISBN << endl;
            cout << "-Year: " << Library->book[i].year << endl;
        }
    }
    cout << "*******************************" << endl;
    menu_item();
}
//----------------------------------------------------------------------------------------------------------------------

void show_library(){
    for (int i=0 ; i < num_library_book ; i++) {
        cout << "-Book Name: " << Library->book[i].NameOfBook << endl;
        cout << "-Writer Name: " <<Library->book[i].NameOfWriter << endl;
        cout << "-Publisher: " <<Library->book[i].publisher << endl;
        cout << "-ISBN: " <<Library->book[i].ISBN << endl;
        cout << "-Year: " <<Library->book[i].year << endl;
        cout << endl << " * Status: " << Library->book[i].status << endl;
        cout << "---------------------------------------" << endl ;
    }
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void filter_by_nameofwriter(){
    cout << "Enter the writer's name: ";
    string writer_name;
    cin.ignore();
    getline(cin,writer_name);
    for (int i= 0 ; i < num_library_book ; i++) {
        if (Library->book[i].NameOfWriter == writer_name) {
            cout << "-Book Name: " << Library->book[i].NameOfBook << endl;
            cout << "-Writer Name: " << Library->book[i].NameOfWriter << endl;
            cout << "-Publisher: " << Library->book[i].publisher << endl;
            cout << "-ISBN: " << Library->book[i].ISBN << endl;
            cout << "-Year: " << Library->book[i].year << endl;
            cout << "---------------------------------------" << endl;
        }
    }
    menu_item();
}
//----------------------------------------------------------------------------------------------------------------------

void filter_by_yearofprint(){
    cout << "Enter year of print: ";
    int print_year;
    cin >> print_year;
    for (int i=0 ; i < num_library_book ; i++) {
        if (Library->book[i].year == print_year) {
            cout << "-Book Name: " << Library->book[i].NameOfBook << endl;
            cout << "-Writer Name: " << Library->book[i].NameOfWriter << endl;
            cout << "-Publisher: " << Library->book[i].publisher << endl;
            cout << "-ISBN: " << Library->book[i].ISBN << endl;
            cout << "-Year: " << Library->book[i].year << endl;
            cout << "---------------------------------------" << endl;
        }
    }
    menu_item();
}
//----------------------------------------------------------------------------------------------------------------------

void filter_by_publisher(){
    cout << "Enter the publisher: ";
    string book_publisher;
    cin.ignore();
    getline(cin,book_publisher);
    for (int i=0 ; i < num_library_book ; i++) {
        if (Library->book[i].publisher == book_publisher) {
            cout << "-Book Name: " << Library->book[i].NameOfBook << endl;
            cout << "-Writer Name: " << Library->book[i].NameOfWriter << endl;
            cout << "-Publisher: " << Library->book[i].publisher << endl;
            cout << "-ISBN: " << Library->book[i].ISBN << endl;
            cout << "-Year: " << Library->book[i].year << endl;
            cout << "---------------------------------------" << endl;
        }
    }
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void search_bookbyname(){
    cout << "Enter the book name: ";
    string book_name;
    cin.ignore();
    getline(cin,book_name);
    for (int i=0 ; i < num_library_book ; i++) {
        if (Library->book[i].NameOfBook == book_name) {
            cout << "-Book Name: " << Library->book[i].NameOfBook << endl;
            cout << "-Writer Name: " << Library->book[i].NameOfWriter << endl;
            cout << "-Publisher: " << Library->book[i].publisher << endl;
            cout << "-ISBN: " << Library->book[i].ISBN << endl;
            cout << "-Year: " << Library->book[i].year << endl;
            cout << "---------------------------------------" << endl;
            for (int j=0 ; j < Library->book[i].NumOfPage ; j++) {
                cout << Library->book[i].page[j].NumberOfPage << endl;
                cout << Library->book[i].page[j].words << endl;
            }
        }
    }
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void search_writerbyname(){
    cout << "Enter the writer's name: ";
    string writer_name;
    cin.ignore();
    getline(cin,writer_name);
    for (int i=0 ; i < num_of_writer ; i++) {
        if (writer[i].NameOfWriter == writer_name) {
            cout << "Writer Name: " << writer[i].NameOfWriter << endl;
            cout << "Writer ID: " << writer[i].ID << endl;
            for (int j = 0; j < writer[i].NumOfBook; j++) {
                cout << "-Book Name: " << writer[i].book[j].NameOfBook << endl;
                cout << "-Publisher: " << writer[i].book[j].publisher << endl;
                cout << "-ISBN: " << writer[i].book[j].ISBN << endl;
                cout << "-Year: " << writer[i].book[j].year << endl;
                for (int k = 0; k < writer[i].book[j].NumOfPage; k++) {
                    cout << writer[i].book[j].page[k].NumberOfPage << endl;
                    cout << writer[i].book[j].page[k].words << endl;
                }
            }
        }
    }
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void sort_byyear(){              //babel sort hobabi

    struct books tmp;
    for (int i=0 ; i < num_library_book-1 ; i++){
        for (int j=0 ; j< num_library_book-i-1 ; j++){
            if ( Library->book[j].year > Library->book[j+1].year ){
                tmp = Library->book[j];
                Library->book[j]=Library->book[j+1];
                Library->book[j+1]=tmp;
            }
        }
    }
    menu_item();
}
//----------------------------------------------------------------------------------------------------------------------

void edit_writerinfo(){
    cout << "Which writer do you wanna edit? ";
    string writer_name;
    cin.ignore();
    getline(cin,writer_name);
    //we need writer index to change info
    int index_writer;
    for (int i=0;i< num_of_writer;i++){
        if (writer[i].NameOfWriter == writer_name){
            index_writer=i;
            break;
        }
    }

    cout << "Enter the correct name: " ;
    getline(cin,writer[index_writer].NameOfWriter);
    cout << "Enter the correct ID: " ;
    getline(cin,writer[index_writer].ID);
    //******************************************************************************************************************

    for (int i=0;i< num_library_book ;i++){
        if ( Library->book[i].NameOfWriter == writer_name){
            Library->book[i].NameOfWriter = writer[index_writer].NameOfWriter;
        }
    }

    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void edit_bookinfo(){
    cout << "Which book do you wanna edit? ";
    string book_name;
    cin.ignore();
    getline(cin,book_name);

    //find the index of book in library
    int index_library;
    for (int i=0;i< num_library_book ;i++){
        if ( Library->book[i].NameOfBook == book_name){
            index_library=i;
            break;
        }
    }

    cout << "Enter the correct book name: " ;
    getline(cin,Library->book[index_library].NameOfBook);
    cout << "Enter the correct publisher: " ;
    getline(cin,Library->book[index_library].publisher);
    cout << "Enter the correct ISBN: " ;
    getline(cin,Library->book[index_library].ISBN);
    cout << "Enter the correct year of print: " ;
    int book_year;
    cin >> book_year;
    Library->book[index_library].year = book_year;
    cout << endl;

    //find writer and edit his/her book
    cout << "Who wrote this? ";
    string writer_name;
    cin.ignore();
    getline(cin,writer_name);
    //we need writer index to change info
    int index_writer;
    for (int i=0;i< num_of_writer;i++){
        if (writer[i].NameOfWriter == writer_name){
            index_writer=i;
            break;
        }
    }
    //we need index book in writer info
    int index_book_writer;
    for (int i=0;i< writer[index_writer].NumOfBook;i++){
        if (writer[index_writer].book[i].NameOfBook == book_name){
            index_book_writer=i;
            break;
        }
    }
    writer[index_writer].book[index_book_writer].NameOfBook = Library->book[index_library].NameOfBook;
    writer[index_writer].book[index_book_writer].publisher = Library->book[index_library].publisher;
    writer[index_writer].book[index_book_writer].ISBN = Library->book[index_library].ISBN;
    writer[index_writer].book[index_book_writer].year = Library->book[index_library].year;

    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void search_words(){
    cout << "Which book do you wanna search in? ";
    string book_name;
    cin.ignore();
    getline(cin,book_name);

    //find the index of book in library
    int index_library;
    for (int i=0;i< num_library_book ;i++){
        if ( Library->book[i].NameOfBook == book_name){
            index_library=i;
            break;
        }
    }

    cout << "Enter the phrase that you want: ";
    string search;
    getline(cin,search);

    for (int i=0;i < Library->book[index_library].NumOfPage ; i++ ){
        char* find;
        find = strstr( (Library->book[index_library].page[i].words).c_str() , search.c_str()  );
        if(find){
            cout << Library->book[index_library].page[i].NumberOfPage << "  ";
        }
    }
    cout << endl;
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void page_print(){
    cout << "Which book do you wanna print? ";
    string book_name;
    cin.ignore();
    getline(cin,book_name);

    //find the index of book in library
    int index_library;
    for (int i=0;i< num_library_book ;i++){
        if ( Library->book[i].NameOfBook == book_name){
            index_library=i;
            break;
        }
    }

    cout << "Which page? ";
    int num_page;
    cin >> num_page;
    cout << Library->book[index_library].page[num_page-1].words;
    cout << endl;
    menu_item();
}
//----------------------------------------------------------------------------------------------------------------------

void borrow_books(){
    cout << "Which book do you wanna borrow? ";
    string book_name;
    cin.ignore();
    getline(cin,book_name);

    //find the index of book in library
    int index_library;
    for (int i=0;i< num_library_book ;i++){
        if ( Library->book[i].NameOfBook == book_name){
            index_library=i;
            break;
        }
    }

    //cout << "Please enter your username: ";
    //string username;
    //getline(cin,username);
    Library->book[index_library].status = user_username ;

    int index_writer;
    for (int i=0;i< num_of_writer ;i++){
        if ( Library->book[index_library].NameOfWriter == writer[i].NameOfWriter){
            index_writer=i;
            break;
        }
    }

    int index_book;
    for (int i=0;i< writer[index_writer].NumOfBook ;i++){
        if ( Library->book[index_library].NameOfBook == writer[index_writer].book[i].NameOfBook){
            index_book=i;
            break;
        }
    }
    writer[index_writer].book[index_book].status = Library->book[index_library].status;

    cout << "ENJOY READING :>" << endl;
    menu_item();
}

//----------------------------------------------------------------------------------------------------------------------

void print(){
    for (int i=0;i<num_of_writer;i++){
        cout << writer[i].NameOfWriter << endl;
        cout << writer[i].ID << endl;
        for (int j=0 ; j < writer[i].NumOfBook ;j++){
            cout << writer[i].book[j].NameOfBook << endl;
            cout << writer[i].book[j].publisher << endl;
            cout << writer[i].book[j].ISBN << endl;
            cout << writer[i].book[j].year << endl;
            cout << writer[i].book[j].status << endl;
            for (int k=0;k < writer[i].book[j].NumOfPage ; k++){
                cout << writer[i].book[j].page[k].NumberOfPage << endl;
                cout << writer[i].book[j].page[k].words << endl;
            }
        }
    }
    cout << "---------------------------------------------------" << endl;
    for (int i=0 ; i < num_library_book ; i++){
        cout <<  Library->book[i].NameOfBook << endl;
        cout <<  Library->book[i].NameOfWriter << endl;
        cout <<  Library->book[i].publisher << endl;
        cout <<  Library->book[i].ISBN << endl;
        cout <<  Library->book[i].year << endl;
        cout <<  Library->book[i].status << endl;
        for (int j=0 ; j < Library->book[i].NumOfPage ; j++){
            cout <<  Library->book[i].page[j].NumberOfPage << endl;
            cout <<  Library->book[i].page[j].words << endl;
        }
    }
    menu_item();
}
void menu_Choice(){
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: add_new_writer();
            break;
        case 2: add_book_to_writer();
            break;
        case 3: remove_book_from_writer();
            break;
        case 4: add_to_library();
            break;
        case 5: remove_book_from_writer();
            break;
        case 6: edit_writerinfo();
            break;
        case 7: edit_bookinfo();
            break;
        case 8:   show_my_info();
            break;
        case 9: show_library();
            break;
        case 10: filter_by_nameofwriter();
            break;
        case 11: filter_by_yearofprint();
            break;
        case 12: filter_by_publisher();
            break;
        case 13: search_bookbyname();
            break;
        case 14: search_writerbyname();
            break;
        case 15: sort_byyear();
            break;
        case 16: search_words();
            break;
        case 17: page_print();
            break;
        case 18: borrow_books();
            break;
        case 19: first_page();
            break;
        case 21: print();
            break;
        default: menu_item();
            break;
    }
}

int main() {
    first_page();
}