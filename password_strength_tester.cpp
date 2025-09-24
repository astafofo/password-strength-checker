#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// Function declarations
bool isLengthValid(const std::string& password);
bool hasUppercase(const std::string& password);
bool hasLowercase(const std::string& password);
bool hasDigit(const std::string& password);
bool hasSpecialChar(const std::string& password);
bool isPasswordStrong(const std::string& password, std::vector<std::string>& reasons);
std::string getMaskedInput();

int main() {
    std::string password;
    std::vector<std::string> reasons;
    bool isStrong = false;

    std::cout << "🧪 Password Strength Tester" << std::endl;
    std::cout << "Password must be at least 8 characters long and contain:" << std::endl;
    std::cout << "- At least one uppercase letter" << std::endl;
    std::cout << "- At least one lowercase letter" << std::endl;
    std::cout << "- At least one digit" << std::endl;
    std::cout << "- At least one special character (!@#$%^&*()-_+=<>?/)" << std::endl;
    std::cout << std::endl;

    while (!isStrong) {
        std::cout << "Enter password: ";

        // Use masked input for security
        password = getMaskedInput();

        std::cout << std::endl;

        reasons.clear();
        isStrong = isPasswordStrong(password, reasons);

        if (isStrong) {
            std::cout << "Strong password ✅" << std::endl;
        } else {
            std::cout << "Weak password ❌" << std::endl;
            std::cout << "Reasons:" << std::endl;
            for (const auto& reason : reasons) {
                std::cout << "- " << reason << std::endl;
            }
            std::cout << std::endl;
        }
    }

    std::cout << "Great! Your password meets all security requirements!" << std::endl;
    return 0;
}

// Function implementations
bool isLengthValid(const std::string& password) {
    return password.length() >= 8;
}

bool hasUppercase(const std::string& password) {
    for (char c : password) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

bool hasLowercase(const std::string& password) {
    for (char c : password) {
        if (std::islower(c)) {
            return true;
        }
    }
    return false;
}

bool hasDigit(const std::string& password) {
    for (char c : password) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool hasSpecialChar(const std::string& password) {
    std::string specialChars = "!@#$%^&*()-_+=<>?/";
    for (char c : password) {
        if (specialChars.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool isPasswordStrong(const std::string& password, std::vector<std::string>& reasons) {
    bool valid = true;

    if (!isLengthValid(password)) {
        reasons.push_back("Password is too short (minimum 8 characters required)");
        valid = false;
    }

    if (!hasUppercase(password)) {
        reasons.push_back("Missing uppercase letter");
        valid = false;
    }

    if (!hasLowercase(password)) {
        reasons.push_back("Missing lowercase letter");
        valid = false;
    }

    if (!hasDigit(password)) {
        reasons.push_back("Missing digit");
        valid = false;
    }

    if (!hasSpecialChar(password)) {
        reasons.push_back("Missing special character (!@#$%^&*()-_+=<>?/)");
        valid = false;
    }

    return valid;
}

std::string getMaskedInput() {
    std::string input = "";

#ifdef _WIN32
    // Windows implementation
    char ch;
    while ((ch = _getch()) != '\r') {  // '\r' is Enter key
        if (ch == '\b' && !input.empty()) {  // Backspace
            input.pop_back();
            std::cout << "\b \b";  // Erase the character from console
        } else if (ch != '\b') {
            input += ch;
            std::cout << '*';  // Display asterisk
        }
    }
#else
    // Unix/Linux implementation
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char ch;
    while (std::cin.get(ch) && ch != '\n') {
        if (ch == 127 && !input.empty()) {  // Backspace (127 is ASCII for DEL)
            input.pop_back();
            std::cout << "\b \b";
        } else if (ch != 127) {
            input += ch;
            std::cout << '*';
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

    return input;
}
