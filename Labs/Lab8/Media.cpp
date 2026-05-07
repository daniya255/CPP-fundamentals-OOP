#include <iostream>
#include <string>

using namespace std;

class Media {
protected:
    string title;
    bool isBorrowed;
public:
    Media(string t) : title(t), isBorrowed(false) {}
    virtual void borrowMedia() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is already out." << endl;
        }
    }
    virtual void returnMedia() {
        isBorrowed = false;
        cout << title << " has been returned." << endl;
    }
    virtual void display() = 0;
    virtual ~Media() {}
};

class BookAttr {
protected:
    string author;
public:
    BookAttr(string a) : author(a) {}
};

class MagazineAttr {
protected:
    int issueNumber;
public:
    MagazineAttr(int i) : issueNumber(i) {}
};

class DVDAttr {
protected:
    string director;
public:
    DVDAttr(string d) : director(d) {}
};

class Book : public Media, public BookAttr {
public:
    Book(string t, string a) : Media(t), BookAttr(a) {}
    void display() override {
        cout << "[Book] Title: " << title << ", Author: " << author 
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class Magazine : public Media, public MagazineAttr {
public:
    Magazine(string t, int i) : Media(t), MagazineAttr(i) {}
    void display() override {
        cout << "[Magazine] Title: " << title << ", Issue: " << issueNumber 
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class DVD : public Media, public DVDAttr {
public:
    DVD(string t, string d) : Media(t), DVDAttr(d) {}
    void display() override {
        cout << "[DVD] Title: " << title << ", Director: " << director 
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

int main() {
    Book b("The C++ Programming Language", "Bjarne Stroustrup");
    Magazine m("National Geographic", 202);
    DVD d("Inception", "Christopher Nolan");

    Media* library[3] = {&b, &m, &d};

    for (int i = 0; i < 3; i++) {
        library[i]->display();
    }

    b.borrowMedia();
    m.borrowMedia();
    b.display();

    return 0;
}