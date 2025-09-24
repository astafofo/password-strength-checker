# Password Strength Tester

A comprehensive C++ application that validates password strength against industry-standard security criteria. This tool helps users create secure passwords by providing real-time feedback and guidance.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Code Structure](#code-structure)
- [Testing](#testing)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)
- [FAQ](#faq)

## Features

### Core Security Requirements
- **Length Validation**: Minimum 8 characters
- **Character Diversity**: Requires uppercase, lowercase, digits, and special characters
- **Special Characters**: Supports `!@#$%^&*()-_+=<>?/` and more
- **Real-time Feedback**: Instant validation with specific failure reasons

### Advanced Features
- **Interactive Loop**: Continues prompting until password meets all criteria
- **Input Masking**: Secure password entry (platform-dependent)
- **Modular Design**: Separate functions for each validation rule
- **Cross-Platform**: Compatible with Windows, Linux, and macOS
- **User-Friendly Interface**: Clear instructions and colored output

### Smart Features
- **Detailed Feedback**: Specific reasons for password weaknesses
- **Security-First**: No password storage or logging
- **Fast Processing**: Instant validation results
- **Maintainable Code**: Well-documented and organized structure

## Requirements

### System Requirements
- **Operating System**: Windows 10/11, Linux (Ubuntu 18.04+), or macOS 10.14+
- **RAM**: 256 MB minimum, 512 MB recommended
- **Storage**: 10 MB free space
- **Display**: 800x600 minimum resolution

### Software Requirements
- **C++ Compiler**: g++ (MinGW), Clang, or Visual Studio C++
- **Build Tools**: Make or CMake (optional)
- **Terminal/Command Prompt**: For compilation and execution

### Dependencies
- Standard C++ Library (STL) - included with all C++ compilers
- Platform-specific headers:
  - Windows: `<conio.h>` for input masking
  - Unix/Linux: `<termios.h>` and `<unistd.h>` for input masking

## Installation

### Method 1: Using Git (Recommended)
```bash
git clone https://github.com/astafofo/password-strength-checker.git
cd password-strength-tester
```

### Method 2: Direct Download
1. Download `password_strength_tester.cpp` and `README.md`
2. Place them in your desired directory
3. Navigate to the directory in your terminal

### Compilation

#### Windows (Command Prompt/PowerShell)
```bash
# Using MinGW (recommended)
g++ -o password_strength_tester.exe password_strength_tester.cpp

# Using Visual Studio Developer Command Prompt
cl /EHsc /Fe:password_strength_tester.exe password_strength_tester.cpp
```

#### Linux/macOS (Terminal)
```bash
# Using g++
g++ -o password_strength_tester password_strength_tester.cpp

# Using Clang
clang++ -o password_strength_tester password_strength_tester.cpp
```

#### Advanced Compilation (with optimizations)
```bash
g++ -O2 -Wall -Wextra -std=c++17 -o password_strength_tester password_strength_tester.cpp
```

## Usage

### Basic Usage
1. **Compile** the program using instructions above
2. **Run** the executable:
   ```bash
   ./password_strength_tester
   ```
3. **Follow** the on-screen instructions
4. **Enter** your password when prompted
5. **Review** the feedback and improve your password if needed

### Command Line Options
```bash
# Run with custom welcome message (future enhancement)
./password_strength_tester --welcome

# Run in quiet mode (future enhancement)
./password_strength_tester --quiet
```

### Interactive Flow
1. Program displays password requirements
2. User enters password (characters are masked)
3. Program validates against all criteria
4. Results are displayed with specific feedback
5. If weak, process repeats until strong password is created

## Examples

### Example 1: Weak Password
```
Password Strength Tester
Password must be at least 8 characters long and contain:
- At least one uppercase letter
- At least one lowercase letter
- At least one digit
- At least one special character (!@#$%^&*()-_+=<>?/ )

Enter password: ********

Weak password
Reasons:
- Missing uppercase letter
- Missing special character

Enter password: **********

Strong password
Great! Your password meets all security requirements!
```

### Example 2: Strong Password
```
Password Strength Tester
Password must be at least 8 characters long and contain:
- At least one uppercase letter
- At least one lowercase letter
- At least one digit
- At least one special character (!@#$%^&*()-_+=<>?/ )

Enter password: ************

Strong password
Great! Your password meets all security requirements!
```

### Test Cases

| Password | Strength | Reason |
|----------|----------|---------|
| `123` | Weak | Too short, missing letters, missing special chars |
| `password` | Weak | Missing uppercase, digit, special char |
| `PASSWORD123` | Weak | Missing lowercase, special char |
| `Pass123` | Weak | Too short, missing special char |
| `MyStr0ng!P@ssw0rd` | Strong | Meets all criteria |
| `C++17Rocks!2023` | Strong | Meets all criteria |

## Code Structure

### File Organization
```
password-strength-tester/
├── password_strength_tester.cpp  # Main source file
├── README.md                     # This documentation
└── .gitignore                   # Git ignore rules (optional)
```

### Function Breakdown

#### Core Validation Functions
- `isLengthValid()`: Checks minimum length requirement
- `hasUppercase()`: Validates presence of uppercase letters
- `hasLowercase()`: Validates presence of lowercase letters
- `hasDigit()`: Validates presence of numeric digits
- `hasSpecialChar()`: Validates presence of special characters

#### Main Functions
- `isPasswordStrong()`: Orchestrates all validation checks
- `getMaskedInput()`: Handles secure password input
- `main()`: Program entry point and user interaction loop

### Dependencies
- `<iostream>`: Input/output operations
- `<string>`: String manipulation
- `<cctype>`: Character classification functions
- `<vector>`: Dynamic arrays for storing validation results
- Platform-specific headers for input masking

### C++ Features Used
- **C++11/14**: Range-based for loops, auto keyword
- **STL Containers**: std::string, std::vector
- **Character Functions**: std::isupper(), std::islower(), std::isdigit()
- **Platform Detection**: Preprocessor directives for cross-platform compatibility

## Testing

### Manual Testing
1. Compile the program
2. Run the executable
3. Test various password combinations
4. Verify correct validation and feedback

### Automated Testing (Future Enhancement)
```bash
# Unit tests for each validation function
# Integration tests for complete password validation
# Cross-platform compatibility tests
```

### Test Coverage
- Length validation (boundary testing)
- Character type validation
- Input masking functionality
- Error message accuracy
- Loop behavior until strong password

## Troubleshooting

### Compilation Issues

#### "g++: command not found"
**Solution**: Install a C++ compiler
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install g++

# CentOS/RHEL
sudo yum install gcc-c++

# macOS (with Homebrew)
brew install gcc

# Windows
# Download and install MinGW or use Visual Studio
```

#### "undefined reference" errors
**Solution**: Ensure all required headers are included
- Check for missing `#include` statements
- Verify platform-specific headers are correct

#### Input masking not working
**Solution**: Platform-specific implementation
- Windows: Ensure `<conio.h>` is available
- Linux/macOS: Ensure `<termios.h>` and `<unistd.h>` are available
- Fallback: Program will work without masking if headers are unavailable

### Runtime Issues

#### Program doesn't accept input
**Solution**: Check terminal/IDE settings
- Ensure console input is enabled
- Try running from command prompt instead of IDE

#### Infinite loop
**Solution**: Check validation logic
- Ensure at least one validation function can return true
- Test with known strong passwords

### Platform-Specific Notes

#### Windows
- Use Command Prompt or PowerShell
- Input masking requires `<conio.h>`
- Compile with MinGW or Visual Studio

#### Linux
- Use any terminal emulator
- Input masking requires `<termios.h>`
- Most distributions include g++ by default

#### macOS
- Use Terminal.app or iTerm2
- Input masking requires `<termios.h>`
- Install Xcode command line tools: `xcode-select --install`

## Contributing

We welcome contributions! Please follow these guidelines:

### How to Contribute
1. **Fork** the repository
2. **Create** a feature branch: `git checkout -b feature-name`
3. **Make** your changes
4. **Test** thoroughly
5. **Commit** with clear messages: `git commit -m "Add feature description"`
6. **Push** to your branch: `git push origin feature-name`
7. **Submit** a pull request

### Contribution Guidelines
- Follow C++ best practices and coding standards
- Add comments for complex logic
- Include test cases for new features
- Update documentation for any changes
- Ensure cross-platform compatibility
- Maintain backward compatibility

### Development Setup
```bash
# Clone your fork
git clone https://github.com/astafofo/password-strength-checker.git
cd password-strength-tester

# Create development environment
mkdir build && cd build
cmake ..  # or use your preferred build system
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2024 Password Strength Tester

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## FAQ

### General Questions

**Q: Why do I need a strong password?**
A: Strong passwords protect against brute force attacks, dictionary attacks, and credential stuffing. This tool helps you create passwords that meet modern security standards.

**Q: Can this program store or log my passwords?**
A: No! The program never stores, saves, or transmits passwords. All validation happens in memory and passwords are immediately discarded after validation.

**Q: Does this work on all operating systems?**
A: Yes! The program is designed to work on Windows, Linux, and macOS with appropriate compilers.

### Technical Questions

**Q: What C++ standard does this use?**
A: The program uses C++11/14 features but is compatible with C++17. It requires minimal dependencies.

**Q: Why doesn't input masking work on my system?**
A: Input masking requires platform-specific headers. If they're not available, the program will still function but without masking.

**Q: Can I modify the password requirements?**
A: Yes! You can easily modify the validation functions in the source code to change requirements.

**Q: How can I add more special characters?**
A: Edit the `specialChars` string in the `hasSpecialChar()` function to include additional characters.

### Security Questions

**Q: Is this tool secure to use?**
A: Yes, the tool follows security best practices:
- No password storage
- No network communication
- Secure input handling
- Memory-safe operations

**Q: What makes a password "strong"?**
A: A strong password should be:
- Long (minimum 8 characters)
- Complex (mix of character types)
- Unique (not used elsewhere)
- Unpredictable (not based on personal information)

### Usage Questions

**Q: How do I compile this on Windows without MinGW?**
A: You can use:
- Visual Studio Community Edition (free)
- Online C++ compilers
- Windows Subsystem for Linux (WSL)

**Q: Can I run this in an IDE?**
A: Yes! The program works in any C++ development environment including:
- Visual Studio Code
- Visual Studio
- Code::Blocks
- Eclipse CDT

## Additional Resources

- [OWASP Password Guidelines](https://owasp.org/www-community/password-special-characters)
- [NIST Password Guidelines](https://pages.nist.gov/800-63-3/sp800-63b.html)
- [C++ Reference Documentation](https://en.cppreference.com/)
- [Password Security Best Practices](https://haveibeenpwned.com/Passwords)

## Version History

### v1.0.0 (Current)
- Initial release
- Core password validation functionality
- Cross-platform input masking
- Interactive user interface
- Comprehensive documentation

### Future Enhancements
- Password strength scoring (0-100)
- Password generation feature
- Configuration file support
- GUI interface
- Multi-language support
- Unit tests
- Performance optimizations

---

**Made with dedication to secure password practices**
