#include <iostream>
using namespace std;

class Media {
    private:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;
    bool availability;

    public:
    Media (string title, string publicationDate, int uniqueID, string publisher, bool availability = true) 
    : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher), availability(availability) {};

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl; 
        cout << "Publication Date: " << publicationDate << endl;      
    }
    void checkOut() {
        if (availability) {
            availability = false;
            cout << title << " is available.\n";
        } else {
            cout << title << " is not available.\n";
        }
    }
    void returnItem() {
        availability = true;
        cout << title << " has been returned.\n";
    }
    

};

class Book : public Media {
    private:
    string author;
    string _ISBN;
    int noOfPages;

    public:
    Book  (string title, string publicationDate, int uniqueID, string publisher, bool availability, string author, string _ISBN, int noOfPages )
    : Media (title, publicationDate, uniqueID,  publisher, availability), author(author), _ISBN(_ISBN), noOfPages(noOfPages) {}
    
    void displayInfo() {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << _ISBN << endl;
        cout << "No of Pages: " << noOfPages << endl;
    } 

};

class DVD : public Media {
    private:
    string diractor; 
    double duration;
    int rating;

    public:
    DVD  (string title, string publicationDate, int uniqueID, string publisher, bool availability , string diractor, double duration, int rating )
    : Media (title, publicationDate, uniqueID,  publisher, availability), diractor(diractor), duration(duration), rating(rating) {}
    
    void displayInfo() {
        Media::displayInfo();
        cout << "Diracter: " << diractor << endl;
        cout << "Duration: " << duration << endl;
        cout << "Rating: " << rating << endl;
    } 

};

class CD : public Media {
    private:
    string artist; 
    int noOfTracks;
    string genre;

    public:
    CD (string title, string publicationDate, int uniqueID, string publisher, bool availability , string artist, int noOfTracks, string genre)
    : Media (title, publicationDate, uniqueID,  publisher, availability), artist(artist), noOfTracks(noOfTracks), genre(genre) {}
    
    void displayInfo() {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "No of tracks: " << noOfTracks << endl;
        cout << "Genre: " << genre << endl;
    } 

};

int main() {
    Media* media[4]; 

    media[0] = new Book("Harry Potter", "12-10-2020", 101, "O'Reilly", false,"J.K.Rowling", "978-3-16-148410-0", 450);
    media[1] = new DVD("Inception", "16-07-2010", 102, "Warner Bros", true,"Christopher Nolan", 2.5, 8.8);
    media[2] = new CD ("Thriller", "30-11-1982", 103, "Epic Records", true, "Michael Jackson", 9, "Pop");
 
 
    for (int i = 0; i < 3; i++) {
        media[i]->displayInfo();
        cout << "\n";
    }
 
    media[0]->checkOut();
    media[0]->returnItem(); 
    media[0]->checkOut();
    cout << endl;
 
    for (int i = 0; i < 3; i++) {
        delete media[i];
    }

    return 0;
}
