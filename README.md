# AES Wrapper

## Description

AES Wrapper is a powerful and easy-to-use C++ library that provides AES (Advanced Encryption Standard) encryption and decryption functionalities. It is a wrapper around the Poco C++ Libraries, designed to offer a simplified and straightforward interface for secure cryptographic operations.

## Features

- Easy-to-use API for AES encryption and decryption.
- Utilizes the robust Poco C++ Libraries for cryptographic operations.
- Cross-platform support.

## Getting started

### Prerequisites

Before you begin, ensure you have met the following requirements:

- A modern C++ compiler that supports C++23.
- CMake version 3.26 or higher.
- Git for cloning the repository.

### Installation

To install AES Wrapper, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/Braun-Alex/aes-wrapper.git
```

2. Navigate to the cloned directory:
```bash
cd aes-wrapper
```

3. Create a new directory for the build:
```bash
mkdir build
```

4. Enter it:
```bash
cd build
```

5. Generate the Makefile using CMake:
```bash
sudo cmake ..
```

6. To run the unit tests:
```bash
./libtest
```

7. Compile and install the library:
```bash
sudo make install
```

This process will compile and install the AES Wrapper on your system, making it available for linking in your C++ projects.

### Using AES Wrapper in your project

After installing AES Wrapper, you can easily integrate it into your C++ project.
Here's how to set up your `CMakeLists.txt` to include and link against AES Wrapper:

1. Specify the minimum required version of CMake and define your project name:
```cmake
cmake_minimum_required(VERSION 3.26)
project(ProjectName)
```

2. Set the C++ standard for your project:
```cmake
set(CMAKE_CXX_STANDARD 23)
```

3. List your project's files:
```cmake
set(HEADERS example.h)
set(SOURCES example.cpp main.cpp)
```

4. Fetch and make available the required libraries:
```cmake
include(FetchContent)
FetchContent_Declare(
        Poco
        URL https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.5-release.zip
)
FetchContent_MakeAvailable(Poco)
```

5. Create an executable target for your project:
```cmake
set(${PROJECT_NAME} ${HEADERS} ${SOURCES})
```

6. Link against AES Wrapper and the required libraries:
```cmake
target_link_libraries(${PROJECT_NAME} PUBLIC aes_wrapper Poco::Crypto Poco::Util)
```

After installing and configuring the AES Wrapper, you can use it in your C++ application to encrypt and decrypt data. Here is an example:

```c++
#include "AES.h"
#include <iostream>

int main() {
    const std::string name = "Alex Braun", passphrase = "AlAzazaAl123";
    const std::string encryptedData = AES::encrypt(name, passphrase);
    std::cout << "Data: \"" << name << "\"\n"
    << "Passphrase: \"" << passphrase << "\"\n"
    << "Encrypted data: \"" << encryptedData << "\"\n"
    << "Decrypted data: \"" << AES::decrypt(encryptedData, passphrase) << "\"";
}
```
