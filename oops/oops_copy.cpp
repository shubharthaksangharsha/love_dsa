#include<iostream>
#include<cstring>
using namespace std;

class hero{
    int health;
    public:
    char level;
    char *name;
    
    hero(){
        cout<<"Deafualt counstructor is called"<<endl;
        name = new char[100];

    }
    hero(int health){
        this->health = health;
    }
    hero(int health, char level){
        this->health = health;
        this->level = level;
    }
    hero( hero& temp){
        char *ch;
        ch = new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
        cout<<"copy constructor called" <<endl;
    }
    void print(){
        cout<<name<< " ";
        cout << health<< " ";
        cout<< level<<endl;
    }

    int gethealth(){
        return health;
    }

    void sethealth(int h){
        health = h;
    }
    void setname(char name[]){
        strcpy(this->name, name);
    }

};

int main(){
    hero s; 
    s.sethealth(90);
    s.level = 'D';
    char name[9] = "Pranchal";
    s.setname(name);
    s.print();
    cout <<endl;
    hero c(s);
    c.print();
    s.name[0] = 'S';

    s.print();
    c.print();
}