#include <iostream>
#include <string>
#include <Windows.h>
#include "Array.h"
#include "Vector.h"

using namespace std;

template <typename type>
type get_user_input()
{
    type input;
    getline(cin, input);
    return input;
}

template <typename T>
class Special_Char_Array : public Array<T>
{
private:
    const string allowed_chars = "‘₴1234567890-=!\"No;%:?()_+/*\\,.";
    const int allowed_chars_size = allowed_chars.length();
    string invalid_chars;

    string remove_invalid_chars(const string& input)
    {
        string result;

        for (char ch : input)
        {
            if (check_char(ch))
                result += ch;
            else if (!check_char(ch) && ch != ' ')
                invalid_chars += ch;
        }

        return result;
    }

    bool check_char(T elem)
    {
        for (int i = 0; i < allowed_chars_size; ++i)
        {
            if (elem == allowed_chars[i])
                return true;
        }
        return false;
    }

public:
    void display_allowed_chars()
    {
        cout << "Allowed list of characters: " << allowed_chars << endl;
    }

    string get_invalid_chars() { return invalid_chars; }

    void add_chars(const string& input)
    {
        string filtered_input = remove_invalid_chars(input);

        for (char ch : filtered_input)
            Array<T>::addElem(ch);
    }    
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string user_input;
    Special_Char_Array<char> char_array;

    cout << "Enter characters from the allowed list\n";
    char_array.display_allowed_chars();

    cout << "Enter: ";
    user_input = get_user_input<string>();

    char_array.add_chars(user_input);

    cout << char_array;

    if (!char_array.get_invalid_chars().empty())
    {
        cout << "\nInvalid chars from input: " << char_array.get_invalid_chars();
    }

    return 0;
}
