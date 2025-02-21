#include <iostream>
using namespace std;

class Movie {
	public:
		string title;
		string director;
		double duration; 
		
	Movie () {}
	
	Movie (string title, string director, double duration)
		: title(title), director(director), duration(duration) {}
		
	void movieDetail() {
		cout << "Title: " << title << endl;
		cout << "Director: " << director << endl;
		cout << "Duration: " << duration << " hr."<< endl;
		cout << endl;
	}
		
};

class CinemaHall {
	public:
		
	Movie movies[10];
	Movie recentMovies[3];
	string cinemaName;
	string cinemaLocation;
	
	CinemaHall () {}
	
	CinemaHall (string cinemaName, string cinemaLocation) 
		: cinemaName(cinemaName), cinemaLocation(cinemaLocation) {}
	
	void listOfMovies() {
	    movies[0] = Movie("Harry Potter", "J.K. Rowling", 2.57);
	    movies[1] = Movie("Inception", "Christopher Nolan", 2.28);
	    movies[2] = Movie("Titanic", "James Cameron", 3.15);
	    movies[3] = Movie("The Godfather", "Francis Ford Coppola", 2.92);
	    movies[4] = Movie("Avatar", "James Cameron", 2.42);
	    movies[5] = Movie("The Dark Knight", "Christopher Nolan", 2.32);
	    movies[6] = Movie("Interstellar", "Christopher Nolan", 2.49);
	    movies[7] = Movie("Forrest Gump", "Robert Zemeckis", 2.22);
	    movies[8] = Movie("The Matrix", "Lana Wachowski & Lilly Wachowski", 2.30);
	    movies[9] = Movie("The Lion King", "Roger Allers & Rob Minkoff", 1.88);
	}
	
	void displayListOfMovies() {
		for (int i = 0; i < 10; i++) {
			movies[i].movieDetail();
		}
	}
	
	void recentlistMovies() {
		recentMovies[0] = Movie("Spider-Man: No Way Home", "Jon Watts", 2.28);
        recentMovies[1] = Movie("Shutter Island", "Martin Scorsese", 2.18);
        recentMovies[2] = Movie("Gladiator", "Ridley Scott", 2.35);
	}
	
	void displayRecentMovies() {
		for (int i = 0; i < 3; i++) {
			recentMovies[i].movieDetail();
		}
	}
	
	void cinemaDetail() {
		cout << "Cinema Name: " << cinemaName << endl;
		cout << "Cinema Location: " << cinemaLocation << endl;  
	}
 
	
};


int main() {
	CinemaHall cinema("Grand Cinema", "New York");
	cinema.listOfMovies();
	cinema.displayListOfMovies();
	
	cout << endl;
	cout << "_____________________________________________________________\n\n";
	cinema.cinemaDetail();
	cout << "_____________________________________________________________\n\n";
	cout << "List of Movies recently screening: \n\n";
	cinema.recentlistMovies();
	cinema.displayRecentMovies();
	
	return 0;
}