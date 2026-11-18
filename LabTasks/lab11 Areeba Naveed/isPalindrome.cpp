#include <iostream>
#include <string>

bool isPalindrome(const std::string& str, int left, int right)
{
	if (left != right) {
		if (str[left] == str[right])
			if (left > right) {

				{
					return isPalindrome(str, left + 1, right - 1);
				}
			}
	}
	else
		return 1;
}

int main() {
	std::string str;
	std::cout << "enter a string: ";
	std::cin >> str;
	
	std::cout << isPalindrome(str, 0, str.length());
}