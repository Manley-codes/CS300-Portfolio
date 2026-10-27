
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>

// Stores course information and prerequisite numbers
struct Course {
    std::string courseNumber;
    std::string courseName;
    std::vector<std::string> prerequisites;
};

// Represents a node in the Binary Search Tree
struct Node {
    Course course;
    Node* left;
    Node* right;
};

// Binary Search Tree for organizing and searching courses
class CourseTree {
private:
    Node* root = nullptr;
    int courseCount = 0;

    // Print courses in alphanumeric order
    static void inOrder(const Node* node) {
        if (node == nullptr) return;

        inOrder(node->left);
        std::cout << node->course.courseNumber << ", "
                  << node->course.courseName << '\n';
        inOrder(node->right);
    }

    // Release memory allocated for tree nodes
    static void destroy(Node* node) {
        if (node == nullptr) return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    CourseTree() = default;

    // Prevent accidental copying of tree pointers
    CourseTree(const CourseTree&) = delete;
    CourseTree& operator=(const CourseTree&) = delete;

    ~CourseTree() {
        destroy(root);
    }

    // Insert courses according to their course numbers
    bool insert(const Course& course) {
        Node** current = &root;

        while (*current != nullptr) {
            if (course.courseNumber < (*current)->course.courseNumber) {
                current = &((*current)->left);
            }
            else if (course.courseNumber > (*current)->course.courseNumber) {
                current = &((*current)->right);
            }
            else {
                return false; // Duplicate course
            }
        }

        *current = new Node{course, nullptr, nullptr};
        ++courseCount;
        return true;
    }

    // Search the tree for an individual course
    const Course* find(const std::string& number) const {
        const Node* current = root;

        while (current != nullptr) {
            if (number == current->course.courseNumber) {
                return &current->course;
            }
            if (number < current->course.courseNumber) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return nullptr;
    }

    void printSorted() const {
        inOrder(root);
    }

    bool empty() const {
        return courseCount == 0;
    }

    int size() const {
        return courseCount;
    }

    // Replace the old tree after successful file loading
    void swap(CourseTree& other) {
        std::swap(root, other.root);
        std::swap(courseCount, other.courseCount);
    }
};

// Remove unnecessary spaces from CSV fields
std::string trim(const std::string& value) {
    size_t start = value.find_first_not_of(" \t\r\n");

    if (start == std::string::npos) return "";

    size_t end = value.find_last_not_of(" \t\r\n");
    return value.substr(start, end - start + 1);
}

// Make course-number searches case-insensitive
std::string toUpper(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::toupper(c));
        });
    return value;
}

// Read the CSV file and load courses into the tree
bool loadCourses(const std::string& fileName, CourseTree& courses) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cout << "Error: Could not open file.\n";
        return false;
    }

    CourseTree newCourses;
    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        ++lineNumber;

        if (trim(line).empty()) continue;

        std::stringstream row(line);
        std::string number, name, prerequisite;

        // Read the two required fields
        if (!std::getline(row, number, ',') ||
            !std::getline(row, name, ',')) {
            std::cout << "Invalid data on line "
                      << lineNumber << ".\n";
            return false;
        }

        Course course;
        course.courseNumber = toUpper(trim(number));
        course.courseName = trim(name);

        if (course.courseNumber.empty() || course.courseName.empty()) {
            std::cout << "Missing course information on line "
                      << lineNumber << ".\n";
            return false;
        }

        // Read all prerequisites, ignoring empty CSV fields
        while (std::getline(row, prerequisite, ',')) {
            prerequisite = toUpper(trim(prerequisite));

            if (!prerequisite.empty()) {
                course.prerequisites.push_back(prerequisite);
            }
        }

        if (!newCourses.insert(course)) {
            std::cout << "Duplicate course on line "
                      << lineNumber << ".\n";
            return false;
        }
    }

    if (newCourses.empty()) {
        std::cout << "Error: No courses found.\n";
        return false;
    }

    courses.swap(newCourses);

    std::cout << courses.size()
              << " courses loaded successfully!\n";
    return true;
}

// Display an individual course and prerequisite details
void printCourse(const CourseTree& courses, const std::string& number) {
    const Course* course = courses.find(toUpper(trim(number)));

    if (course == nullptr) {
        std::cout << "Course not found.\n";
        return;
    }

    std::cout << course->courseNumber << ", "
              << course->courseName << '\n';

    std::cout << "Prerequisites: ";

    if (course->prerequisites.empty()) {
        std::cout << "None\n";
        return;
    }

    for (size_t i = 0; i < course->prerequisites.size(); ++i) {
        if (i > 0) std::cout << ", ";

        const std::string& number = course->prerequisites[i];
        const Course* prerequisite = courses.find(number);

        std::cout << number;

        // Include the prerequisite course title when available
        if (prerequisite != nullptr) {
            std::cout << " (" << prerequisite->courseName << ")";
        }
    }

    std::cout << '\n';
}

int main() {
    CourseTree courses;
    int choice = 0;

    std::cout << "Welcome to the course planner.\n\n";

    // Repeat the menu until the user selects Exit
    do {
        std::cout << "\n1. Load Data Structure.\n";
        std::cout << "2. Print Course List.\n";
        std::cout << "3. Print Course.\n";
        std::cout << "9. Exit\n\n";

        std::cout << "What would you like to do? ";

        std::string input;
        if (!std::getline(std::cin, input)) break;

        // Validate numeric input before processing
        std::stringstream menuInput(input);
        char extra;

        if (!(menuInput >> choice) || (menuInput >> extra)) {
            std::cout << "Invalid menu input.\n";
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1: {
            std::string fileName;

            std::cout << "Enter the course file name: ";
            std::getline(std::cin, fileName);

            loadCourses(trim(fileName), courses);
            break;
        }

        case 2:
            if (courses.empty()) {
                std::cout << "Please load the course file first.\n";
            }
            else {
                std::cout << "\nHere is a sample schedule:\n\n";
                courses.printSorted();
            }
            break;

        case 3: {
            if (courses.empty()) {
                std::cout << "Please load the course file first.\n";
                break;
            }

            std::string courseNumber;

            std::cout << "What course do you want to know about? ";
            std::getline(std::cin, courseNumber);

            printCourse(courses, courseNumber);
            break;
        }

        case 9:
            std::cout << "Thank you for using the course planner!\n";
            break;

        default:
            std::cout << choice << " is not a valid option.\n";
            break;
        }

    } while (choice != 9);

    return 0;
}