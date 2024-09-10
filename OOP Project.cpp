#include<iostream> 
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

class Book {
	private:
		string isbn,title,author,edition,publication; 
	public:
		
		void setIsbn(string a){isbn = a;}
		void setTitle(string b){title = b;}
		void setAuthor(string c){author = c;}
		void setEdition(string d){edition = d;}
		void setPublication(string e){publication = e;}
		
		string getIsbn(){return isbn;}
		string getTitle(){return title;}
		string getAuthor(){return author;}
		string getEdition(){return edition;}
		string getPublication(){return publication;}
};

void searchBook(int counter);
void viewAllBooks(int counter);
void quit();
void borrowBook();
void returnBook();

int counter=0;


void increment(int a){
	a++;
	counter=a;
}


void decrement(int a){
	a--;
	counter=a;
}

Book books[10];

int main(){
	
	
	
	
int choice1= 0;

while (choice1 != 9)
{

system ("cls");

cout << "\n\t\t\t Library Management System \n\n";

cout << "\n\t\t1. Librarian";

cout << "\n\t\t2. Student";

cout << "\n\t\t9. Exit";

cout << "\n\nEnter your choice : ";

cin >> choice1;


if (choice1 == 1)

{	

int choice2 = 0;

while (choice2 != 9)
{

system("CLS");
cout<<"\n\t\t\tLibrarian\n";
cout<<"\t\t[1]ADD BOOK\n";	
cout<<"\t\t[2]DELETE BOOK\n";	
cout<<"\t\t[3]EDIT BOOK\n";	
cout<<"\t\t[4]SEARCH BOOK\n";	
cout<<"\t\t[5]VIEW ALL BOOKS\n";	
cout<<"\t\t[6]QUIT\n\n";

cout<<"ENTER CHOICE: ";

cin>>choice2;
system("CLS");
ofstream out;
fstream myfile;
if(choice2==1){
	
	string isbn,title,author,edition,publication;
	cout<<"\t\t\tADD BOOK\n\n";
	if(counter<10){
		cout<<"\t\tEnter ISBN: ";
		cin>>isbn;

		cout<<"\t\tEnter Title: ";
        cin>>title;
		cout<<"\t\tEnter Author: ";
        cin>>author;
 		cout<<"\t\tEnter Edition: ";
		cin>>edition;
		cout<<"\t\tEnter Publication: ";
		cin>>publication;
		books[counter].setIsbn(isbn); 
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);	
		out.open("abc.txt" );
		out<<"\t\tAdd Book\n\n";
		out <<"ISBN: "<<books[counter].getIsbn() << "\t\t" <<"Title: "<<books[counter].getTitle() << "\t\t" <<"Author: "<<books[counter].getAuthor() << "\t\t" <<"Edition: "<<books[counter].getEdition()<< "\t\t" <<"Publication: "<<books[counter].getPublication()<< endl;
		out.close();
		cout << "\t\t\tBook Added in Inventory\n" << endl;
		out << "\t\t\tBook Added in Inventory\n" << endl;
		increment(counter);	
		cout<<"\n\t\t\tBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"\t\t\tYOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\n\t\tPress any key to continue . . .";
		_getch();
		main();
	}
 
}		
else if(choice2==2){	
	string isbn;
	int choice;
	cout<<"\t\t\tDELETE BOOK\n\n";
	if(counter==0){
		cout<<"\t\tTHERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
     cin>>isbn;
	for(int i=0;i<counter;i++){
		
		if(books[i].getIsbn()==isbn){
			cout<<"\t\tBOOK FOUND\n\n";
			cout<<"\t\tDo you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin>>choice;
			if(choice==1){
				books[i].setIsbn(""); 
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				for(int a=i;a<counter;a++){
					books[a] = books[a+1];
				}
				books[9].setIsbn(""); 
				books[9].setTitle("");
				books[9].setAuthor("");
				books[9].setEdition("");
				books[9].setPublication("");
				decrement(counter); 
				
				cout<<"\t\t\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\t\t\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
	
}

else if(choice2==3){
	system("CLS");
	string editIsbn,choice;
	string isbn,title,author,edition,publication;
	cout<<"\nEDIT BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	cin>>editIsbn;
	for(int i=0;i<counter;i++){
		
		if(books[i].getIsbn()==editIsbn){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
			cout<<"TITLE: "<<books[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
			cout<<"EDITION: "<<books[i].getEdition()<<endl;
			cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
			cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			cin>>choice;
			if(choice=="1"){
				cout<<"Enter ISBN: ";
				cin>>isbn;
				cout<<"Enter Title: ";
				cin>>title;
				cout<<"Enter Author: ";
				cin>>author;
				cout<<"Enter Edition: ";
				cin>>edition;
				cout<<"Enter Publication: ";
				cin>>publication;
				books[i].setIsbn(isbn);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);
				out<<"\nEDIT BOOK\n\n";
				out.open("abc.txt" );
				out<<"\nEDIT BOOK\n\n";
			out <<"ISBN: "<<books[counter].getIsbn() << "\t\t" <<"Title: "<<books[counter].getTitle() << "\t\t" <<"Author: "<<books[counter].getAuthor() << "\t\t" <<"Edition: "<<books[counter].getEdition()<< "\t\t" <<"Publication: "<<books[counter].getPublication()<< endl;
			out.close();
				out<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				
			}
			else{
				main();
			}			
		}
}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}

else if(choice2==4){
	searchBook(counter); 	
}
else if(choice2==5){
	viewAllBooks(counter); 	
}
else if(choice2==6){
	quit();	 
}
else{
	main();  
_getch();
}
}
}
else if(choice1==2){
	int choice3 = 0;

while (choice3 != 9)
{

system ("cls");

cout<<"\t\t\tStudent\n\n";
cout << "\n\t\t1. Borrow a Book";

cout << "\n\t\t2. Return a Book";

cout << "\n\t\t9. Exit";

cout << "\n\n Enter your choice : ";

cin >> choice3;


switch (choice3)
{

case 1:
borrowBook ();
break;

case 2:
returnBook ();
break;
case 9:
break;

default:
cout <<
"\n\n\t\t Error: Invalid Choice. Please enter the valid one";

getchar ();
getchar ();

}
}
}
else if (choice1 != 9)
{

cout << "\n\n\t\t Invalid choice. Press any key to continue..";

getchar ();
getchar ();

} else {

cout << "\n\n Thank you for using it !! Press any key to exit";

getchar ();
getchar ();

}


}
return 0;
}





void searchBook(int counter){
	string isbn;
	int choice;
	bool print = false; 
	cout<<"SEARCH BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	cin>>isbn;
	for(int i=0;i<counter;i++){
	
		if(books[i].getIsbn()==isbn){ 
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
			cout<<"TITLE: "<<books[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
			cout<<"EDITION: "<<books[i].getEdition()<<endl;
			cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
			print = true;
		}
	}
	if(print){
		cout<<"\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	
	else{
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();		
	}
}
void viewAllBooks(int counter){
	
	ofstream file("abc.txt");
	file<<"VIEW ALL BOOKS\n\n";
	cout<<"VIEW ALL BOOKS\n\n";
	for(int i=0;i<counter;i++){
		cout<<"BOOK DETAILS\n\n";
		cout<<"ISBN: "<<books[i].getIsbn()<<endl;
		cout<<"TITLE: "<<books[i].getTitle()<<endl;
		cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
		cout<<"EDITION: "<<books[i].getEdition()<<endl;
		cout<<"PUBLICATION: "<<books[i].getPublication()<<endl<<endl;
		file<<"BOOK DETAILS\n\n";
		file<<"ISBN: "<<books[i].getIsbn()<<endl;
		file<<"TITLE: "<<books[i].getTitle()<<endl;
		file<<"AUTHOR: "<<books[i].getAuthor()<<endl;
		file<<"EDITION: "<<books[i].getEdition()<<endl;
		file<<"PUBLICATION: "<<books[i].getPublication()<<endl<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
	file.close();
}
void quit(){

	_exit(1);
}
void borrowBook ()
{
	int id;
	string name;
	ofstream file("abc.txt");
	file<<"\t\tBorrow Book\n\n"<<endl;
	cout<<"\t\tBorrow Book\n\n"<<endl;
	cout<<"Enter Student id: "<<endl;
	cin>>id;
	cout<<"Enter Student Name: "<<endl;
	cin>>name;
	cout<<"Book Borrowed By "<<name<<" "<<id<<" Successfully!"<<endl;
	file<<"Book Borrowed By "<<name<<" "<<id<<" Successfully!"<<endl;	
	cout<<"Press any key to continue . . .";
	file.close();
	_getch();
	main();
}

void returnBook ()
{
		int id;
	string name;
	ofstream file("abc.txt");
	file<<"\t\tReturn Book\n\n"<<endl;
	cout<<"\t\tReturn Book\n\n"<<endl;
	cout<<"Enter Student id: "<<endl;
	cin>>id;
	cout<<"Enter Student Name: "<<endl;
	cin>>name;
	cout<<"Book Returned By "<<name<<" "<<id<<" Successfully!"<<endl;
	file<<"Book Returned By "<<name<<" "<<id<<" Successfully!"<<endl;	
	cout<<"Press any key to continue . . .";
	file.close();
	_getch();
	main();
}

