#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

std::string readFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string content;
    std::string line;

    if (file.is_open())
    {
        bool first = true;
        while (std::getline(file, line))
        {
            if (!first)
                content += "\n";
            content += line;
            first = false;
        }
        file.close();
    }
    return(content);
}

bool fileExists(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    bool exists;
    exists = file.good();
    file.close();
    return (exists);
}

void    runTest(const std::string& testName,
                const std::string& inputFile,
                const std::string& s1,
                const std::string& s2,
                const std::string& expectedOutput){
    
    std::cout << "Test " << testName << std::endl;
    std::cout << "File source: " << inputFile << std::endl;
    std::cout << "Replace <" << s1 << "> with <" << s2 << ">" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Result :" << std::endl;

    std::string outputFile = inputFile + ".replace";
    std::string cmd = "./replace " + inputFile + " \"" + s1 + "\" \"" + s2 + "\" > /dev/null 2>&1";
    std::system(cmd.c_str());
    if (!fileExists(outputFile))
    {
        std::cerr << "FAIL: Output file does not exist." << std::endl;
        return ;
    }
    std::string result = readFile(outputFile);
    if (result == expectedOutput)
        std::cout << "TEST PASSED!" << std::endl;
    else
    {
        std::cout << "TEST FAIL!" << std::endl;
        std::cout << "  Expected:" << std::endl;
        std::cout << "  \"" << expectedOutput << "\"" << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    std::cout << " ----------------- " << std::endl;
    std::cout << "|      TESTS      |" << std::endl;
    std::cout << " ----------------- " << std::endl;
   
    if (!fileExists("tests/test1.txt") || !fileExists("tests/test2.txt") || !fileExists("tests/test3.txt"))
    {
        std::cerr << "Error: test files (test1.txt, test2.txt, test3.txt) not found!" << std::endl;
        std::cerr << "Please create them before running tests." << std::endl;
        return 1;
    }
    std::cout << "TEST 1 :" << std::endl;
    runTest("- Basic Replacement",
            "tests/test1.txt",
            "123",
            "def",
            "abcdef");
    std::cout << " --------------------------------------------- " << std::endl;
    std::cout << "TEST 2 :" << std::endl;
    runTest("- Multiple replacements",
            "tests/test2.txt",
            "x",
            "l",
            "Hello world !");
    std::cout << " --------------------------------------------- " << std::endl;
    std::cout << "TEST 3 :" << std::endl;
    runTest("- Multi lines",
            "tests/test3.txt",
            "test",
            "TEST",
            "line1: TEST\nline2: Test\nline3: TESTTEST !");
    std::cout << " --------------------------------------------- " << std::endl;
    std::cout << "TEST 4 :" << std::endl;
    runTest("- No input file",
            "nonexistent.txt",
            "test",
            "TEST",
            "");
    std::cout << " --------------------------------------------- " << std::endl;
    std::cout << "TEST 5 :" << std::endl;
    runTest("- Empty s1",
            "tests/test1.txt",
            "",
            "TEST",
            "");
    std::cout << " --------------------------------------------- " << std::endl;
    return (0);
        
}
