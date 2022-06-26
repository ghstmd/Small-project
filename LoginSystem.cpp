#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool IsLoggedIn(){
    string username,password,un,pw;
    cout<< "Enter username: ";cin>>username;
    cout<< "Enter password: ";cin>>password;
    ifstream read("c:\\users\\admin\\desktop\\github" + username + ".txt");
    getline(read,un);
    getline(read,pw);
    if(un ==username && pw==password){
        return true;
    }
    else
        return false;
}
int main(){
    int choice;
    string username,password;
    cout<< "1:Register\n2:Login\nYour choice: ";cin>>choice;
    if(choice==1){
        cout<<"select a username: ";cin>>username;
        cout<<"select a password: ";cin>>password;
        ofstream file;
        file.open("c:\\users\\admin\\desktop\\github"+username+".txt");
        file<<username<<endl<<password;
        file.close();
        main();
    }
    else if(choice==2){
        bool status=IsLoggedIn();
        if(!status){
            cout<<"Wrong username or password"<<endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout<<"Successfully logged in!"<<endl;
            system("PAUSE");
            return 1;
        }
    }
}
