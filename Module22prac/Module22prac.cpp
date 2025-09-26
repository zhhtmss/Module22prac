#include <iostream>
#include <stdexcept>

int stringToInt(const char* str)
{
    using namespace std;
    if (str == nullptr)
    {
        throw invalid_argument("Input string is empty");
	}

    if (str[0] == '\0')
    {
        throw invalid_argument("Input string is empty");
	}

	int start = 0;
    bool isNegative = false;
    if (str[0] == '-')
    {
        isNegative = true;
        start++;
    }
    else if (str[0] == '+')
    {
        start++;
    }

    int result = 0;
    for (int i = start; str[i] != '\0'; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            throw invalid_argument("Input string contains non-digit characters");
        }
        int digit = str[i] - '0';
        if (result > (numeric_limits<int>::max() - digit) / 10)
        {
            throw out_of_range("Integer overflow");
        }
        result = result * 10 + digit;
    }
    return result;
}


int main()
{
    const char* testCases[] = { "123",
        "-456",
        "789abc",
        "",
        "2147483648",
        "+42",
        nullptr
    };


    int numCases = sizeof(testCases) / sizeof(testCases[0]);
    for (int i = 0; i < numCases; i++) {
        try {
			int result = stringToInt(testCases[i]);
			std::cout << "String: " << testCases[i] 
                << " -> Integer: " << result << std::endl;
		}
        catch (const std::exception& e) {
            if (testCases[i] != nullptr)
            {
                std::cout << "String: \"" << testCases[i]
                    << "\" -> Error: " << e.what() << std::endl;
            }
            else
            {
                std::cout << "String: nullptr -> Error: " << e.what() << std::endl;
            }
        }
    }
}
