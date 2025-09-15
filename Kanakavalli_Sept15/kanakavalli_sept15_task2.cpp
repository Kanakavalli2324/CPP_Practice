#include<iostream>
enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY};
    
class Book{
    private:
    int bookId;;
    float rating;
    double price;
    char availability;
    bool isReferenceOnly;
    std::string title;
    Genre genre;
    public:
    //default constructor
    Book(){
        bookId=0;
        rating=0.0;
        price=0.0;
        availability='A';
        isReferenceOnly=false;
        title="Untitled";
        genre=FICTION;
    }
    //parameterized constructor
    Book(int id,float rate,double cost,char avail,bool ref,std::string name,Genre gen){
        bookId=id;
        rating=rate;
        price=cost;
        availability=avail;
        isReferenceOnly=ref;
        title=name;
        genre=gen;
    }
    ~Book(){
        std::cout<<"Book object has been destroyed for Book ID: "<<bookId<<std::endl;
    }
    //getter methods
    int getBookId()const{
        return bookId;
    }
    float getRating()const{
        return rating;
    }
    double getPrice()const{
        return price;
    }
    char getAvailability()const{
        return availability;
    }
    bool getIsReferenceOnly()const{
        return isReferenceOnly;
    }
    std::string getTitle()const{
        return title;
    }
    Genre getGenre()const{
        return genre;
    }
    //setter methods
    void setBookId(int id){
        bookId=id;
    }
    void setRating(float rate){
        rating=rate;
    }
    void setPrice(double cost){
        price=cost;
    }
    void setAvailability(char avail){
        availability=avail;
    }
    void setIsReferenceOnly(bool ref){
        isReferenceOnly=ref;
    }
    void setTitle(std::string name){
        title=name;
    }
    void setGenre(Genre gen){
        genre=gen;
    }
    //updating status
    void updateAvailability(bool isBorrowed){
        if(isBorrowed){
            availability='B';
        }
        else{
            availability='A';
        }
    }
    //display
    void displayInfo() const{
        std::cout<<"Book ID: "<<bookId<<std::endl;
        std::cout<<"Title: "<<title<<std::endl;
        std::cout<<"Rating: "<<rating<<std::endl;
        std::cout<<"Price: "<<price<<std::endl;
        std::cout<<"Availability: "<<availability<<std::endl;
        std::cout<<"Is Reference Only: "<<(isReferenceOnly ? "Yes" : "No")<<std::endl;
        std::cout<<"Genre: ";
        //using switch as this is an enum also it's a const method
        switch(genre){
            case FICTION:
                std::cout<<"Fiction"<<std::endl;
                break;
            case NONFICTION:
                std::cout<<"Non-Fiction"<<std::endl;
                break;
            case SCIENCE:
                std::cout<<"Science"<<std::endl;
                break;
            case HISTORY:
                std::cout<<"History"<<std::endl;
                break;
            case TECHNOLOGY:
                std::cout<<"Technology"<<std::endl;
                break;
        }
    }
};
//global fn
void markAsReferenceOnly(Book &b){
    b.setIsReferenceOnly(true);
    std::cout<<"Book ID: "<<b.getBookId()<<" marked as Reference Only."<<std::endl;
}
bool isaffordable(const Book &b, const double budget){
    return b.getPrice()<=budget;
}
void printFormattedBookList(const Book books[], const int size) {
    
    std::cout << "ID  | Title            | Price   | Rating | Status | Reference |" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << books[i].getBookId() << " | ";
        std::cout << std::left << books[i].getTitle().substr(0, 14) << " | ";
        std::cout << std::left << books[i].getPrice() << " | ";
        std::cout << std::left << books[i].getRating() << " | ";
        std::cout << std::left << books[i].getAvailability()<< " | ";
        std::cout << std::left << (books[i].getIsReferenceOnly()? "Yes" : "No") << " |" << std::endl;
    }
}
int main() {
    const int num_books = 3;
    Book library[num_books];
    int current_book_index = 0;

    // Initialize with sample data
    library[0] = Book(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY);
    library[1] = Book(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE);

    int choice;
    do {
        std::cout << "\n--- Library Management System Menu ---" << std::endl;
        std::cout << "1. Add a new book" << std::endl;
        std::cout << "2. Mark a book as reference-only" << std::endl;
        std::cout << "3. Check if a book is affordable" << std::endl;
        std::cout << "4. Update book availability" << std::endl;
        std::cout << "5. Display details of a specific book" << std::endl;
        std::cout << "6. Display all books in formatted list" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        

        if (choice >= 1 && choice <= 6) {
            std::cout << "Enter book index (0-" << num_books - 1 << "): ";
            std::cin >> current_book_index;
            
            if (current_book_index < 0 || current_book_index >= num_books) {
                std::cout << "Invalid book index. Please try again." << std::endl;
                continue;
            }
        }

        switch (choice) {
            case 1: {
                if (current_book_index < num_books) {
                    int id, genre_choice;
                    float rating;
                    double price;
                    std::string title;
                    bool is_ref_only;
                    
                    std::cout << "Enter book ID: ";
                    std::cin >> id;
                    

                    std::cout << "Enter title: ";
                    std::getline(std::cin, title);
                    if (title.empty()) {
                        std::cout << "Title cannot be empty. Aborting." << std::endl;
                        break;
                    }

                    std::cout << "Enter rating (0.0-5.0): ";
                    std::cin >> rating;
                    if (rating < 0.0 || rating > 5.0) {
                        std::cout << "Invalid rating. Aborting." << std::endl;
                        break;
                    }

                    std::cout << "Enter price (must be positive): ";
                    std::cin >> price;
                    if (price <= 0.0) {
                        std::cout << "Price must be positive. Aborting." << std::endl;
                        break;
                    }

                    std::cout << "Enter genre (0=FICTION, 1=NONFICTION, 2=SCIENCE, 3=HISTORY, 4=TECHNOLOGY): ";
                    std::cin >> genre_choice;
                    if (genre_choice < 0 || genre_choice > 4) {
                        std::cout << "Invalid genre choice. Aborting." << std::endl;
                        break;
                    }

                    std::cout << "Is it reference-only? (1 for Yes, 0 for No): ";
                    std::cin >> is_ref_only;

                    library[current_book_index] = Book(id, rating, price, 'A', is_ref_only, title, static_cast<Genre>(genre_choice));
                    std::cout << "Book added successfully." << std::endl;
                } else {
                    std::cout << "Array is full. Cannot add more books." << std::endl;
                }
                break;
            }
            case 2:
                markAsReferenceOnly(library[current_book_index]);
                break;
            case 3: {
                double budget;
                std::cout << "Enter your budget: $";
                std::cin >> budget;
                if (isaffordable(library[current_book_index], budget)) {
                    std::cout << "'" << library[current_book_index].getTitle() << "' is within your budget." << std::endl;
                } else {
                    std::cout << "'" << library[current_book_index].getTitle() << "' is not affordable with your budget." << std::endl;
                }
                break;
            }
            case 4: {
                bool is_borrowed;
                std::cout << "Is the book borrowed? (1 for Yes, 0 for No): ";
                std::cin >> is_borrowed;
                library[current_book_index].updateAvailability(is_borrowed);
                std::cout << "Availability updated." << std::endl;
                break;
            }
            case 5:
                library[current_book_index].displayInfo();
                break;
            case 6:
                printFormattedBookList(library, num_books);
                break;
            case 7:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
    

