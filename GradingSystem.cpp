#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<std::string, int>> students;
    std::string name;
    int marks;
    char choice;
    
    do {
        std::cout << "Enter student name: ";
        std::cin >> name;
        
        std::cout << "Enter marks (between 0 to 100): ";
        std::cin >> marks;
        
        if (marks < 0 || marks > 100) {
            std::cout << "Marks should be between 0 to 100. Please try again.\n";
            continue;
        }
        
        students.push_back(std::make_pair(name, marks));
        
        std::cout << "Do you want to add another student? (y/n): ";
        std::cin >> choice;
    } while (choice != 'n' && choice != 'N');
    
    if (students.empty()) {
        std::cout << "No students entered. Exiting...\n";
        return 0;
    }
    
    int sum = 0;
    int highest = students[0].second;
    int lowest = students[0].second;
    
    for (const auto& student : students) {
        sum += student.second;
        if (student.second > highest)
            highest = student.second;
        if (student.second < lowest)
            lowest = student.second;
    }
    
    double average = static_cast<double>(sum) / students.size();
    
    std::cout << "\nHighest grade: " << highest << std::endl;
    std::cout << "Lowest grade: " << lowest << std::endl;
    std::cout << "Average grade: " << average << std::endl;

    return 0;
}
